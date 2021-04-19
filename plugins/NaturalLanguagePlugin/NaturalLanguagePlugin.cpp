#include "NaturalLanguagePlugin.h"
#include "TextHighLight.h"
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QMainWindow>
#include <string>

// Expresia regulata care detecteaza formatul de tip data din text
QString regex = "((((0[1-9])|((1|2)\\d)|(3[0,1]))[\\/, \\-,\\.]((0[1-9])|(1[0-2]))[\\/, \\-,\\.]\\d\\d\\d\\d)|(\\d\\d\\d\\d[\\/, \\-,\\.]((0[1-9])|(1[0-2]))[\\/, \\-,\\.]((0[1-9])|((1|2)\\d)|(3[0,1]))))";
void NaturalLanguagePlugin::setProperties(QMenuBar* menuBar, QTabWidget* tabWidget, Theme* theme) {
    this->menuBar = menuBar;
    this->tabWidget = tabWidget;
    this->theme = theme;
    //crearea actiunilor
    //Capitalize
    actionCapitalize = new QAction("Capitalize");
    actions.append(actionCapitalize);

    //Padding
    actionPadding = new QAction("Padding");
    actions.append(actionPadding);

    //Trim
    actionTrim = new QAction("Trim");
    actions.append(actionTrim);

    // dot little endian
    actiondot_little_endian = new QAction("DD.MM.YYYY");
    actions.append(actiondot_little_endian);

    // slash little endian
    actionslash_little_endian = new QAction("DD/MM/YYYY");
    actions.append(actionslash_little_endian);

    // line little endian
    actionline_little_endian = new QAction("DD-MM-YYYY");
    actions.append(actionline_little_endian);

    // dot big endian
    actiondot_big_endian = new QAction("YYYY.MM.DD");
    actions.append(actiondot_big_endian);

    // slash big endian
    actionslash_big_endian = new QAction("YYYY/MM/DD");
    actions.append(actionslash_big_endian);

    // line big endian
    actionline_big_endian = new QAction("YYYY-MM-DD");
    actions.append(actionline_big_endian);

    setIcons(); // setarea imaginilor in functie de tema aplicatiei
}

void NaturalLanguagePlugin::setActions(){
    // adaugam actiunile intr-un meniu
    QMenu* wordEdit = new QMenu("Word Edit", menuBar);
    wordEdit->addAction(actionCapitalize);
    wordEdit->addAction(actionPadding);
    wordEdit->addAction(actionTrim);
    QMenu* changeDateFormat = new QMenu("Change Date Format", menuBar);
    changeDateFormat->addAction(actiondot_little_endian);
    changeDateFormat->addAction(actionslash_little_endian);
    changeDateFormat->addAction(actionline_little_endian);
    changeDateFormat->addAction(actiondot_big_endian);
    changeDateFormat->addAction(actionslash_big_endian);
    changeDateFormat->addAction(actionline_big_endian);
    wordEdit->addMenu(changeDateFormat);
    // adaugam meniul in bara de submeniul "Plugins"
    auto list = menuBar->findChildren<QMenu*>();
    for(QMenu* submenu : list){
        if(submenu->objectName()== "menuPlugins"){
            submenu->addMenu(wordEdit);

        }
    }
    // inseram functionanilatile pentru fiecare actiune
    connect(actionCapitalize, &QAction::triggered, this, &NaturalLanguagePlugin::on_actionCapitalize_triggered);
    connect(actionPadding, &QAction::triggered, this, &NaturalLanguagePlugin::on_actionPadding_triggered);
    connect(actionTrim, &QAction::triggered, this, &NaturalLanguagePlugin::on_actionTrim_triggered);

    connect(actiondot_little_endian, &QAction::triggered,
            this, &NaturalLanguagePlugin::on_actiondot_little_endian_triggered);
    connect(actionslash_little_endian, &QAction::triggered,
            this, &NaturalLanguagePlugin::on_actionslash_little_endian_triggered);
    connect(actionline_little_endian, &QAction::triggered,
            this, &NaturalLanguagePlugin::on_actionline_little_endian_triggered);
    connect(actiondot_big_endian, &QAction::triggered,
            this, &NaturalLanguagePlugin::on_actiondot_big_endian_triggered);
    connect(actionslash_big_endian, &QAction::triggered,
            this, &NaturalLanguagePlugin::on_actionslash_big_endian_triggered);
    connect(actionline_big_endian, &QAction::triggered,
            this, &NaturalLanguagePlugin::on_actionline_big_endian_triggered);


}

void NaturalLanguagePlugin::setIcons(){
    // setam imaginile specifice fiecarei actiuni in functie de tema curenta
    QString currentTheme = theme->getCurrentTheme();
    QString folder_name = "plugins/NaturalLanguageEdit/ThemeIcons";
    actionTrim->setIcon(QIcon(QPixmap(folder_name + "/" + currentTheme + "/"  + "/trim.png")));
    actionPadding->setIcon(QIcon(QPixmap(folder_name + "/" + currentTheme + "/" + "/padding.png")));
    actionCapitalize->setIcon(QIcon(QPixmap(folder_name + "/" + currentTheme + "/" + "/capitalize.jpeg")));
}

void NaturalLanguagePlugin::on_actionTrim_triggered(){

    modifyText(StringManipulator::trim);  // the actual function

}

void NaturalLanguagePlugin::on_actionPadding_triggered(){
    modifyText(StringManipulator::padding);
}

void NaturalLanguagePlugin::on_actionCapitalize_triggered(){
    modifyText(StringManipulator::capitalizeAll);
}

void NaturalLanguagePlugin::on_actiondot_little_endian_triggered()
{
    changeDatesInText(StringManipulator::dot_little_endian);
}

void NaturalLanguagePlugin::on_actionslash_little_endian_triggered()
{
    changeDatesInText(StringManipulator::slash_little_endian);
}

void NaturalLanguagePlugin::on_actionline_little_endian_triggered()
{
    changeDatesInText(StringManipulator::line_little_endian);
}

void NaturalLanguagePlugin::on_actiondot_big_endian_triggered()
{
    changeDatesInText(StringManipulator::dot_big_endian);
}

void NaturalLanguagePlugin::on_actionslash_big_endian_triggered()
{
    changeDatesInText(StringManipulator::slash_big_endian);
}

void NaturalLanguagePlugin::on_actionline_big_endian_triggered()
{
    changeDatesInText(StringManipulator::line_big_endian);
}

void NaturalLanguagePlugin::changeDatesInText(const StringManipulator::dateFormat format) {
    try
    {

        QTextCursor cursor = getCurrentTextEdit()->textCursor();
        if(!cursor.hasSelection()) // if there is no selected text, ask if the user wants to modify all the text
        {
            QMessageBox::StandardButton resBtn =
            QMessageBox::question( getCurrentTextEdit(),"TextEditor",tr("Do you want to apply this function for the entire text?\n"),
            QMessageBox::No | QMessageBox::Yes);
            if (resBtn == QMessageBox::Yes)
            {  // the user selected "Yes" -> select the whole text
                cursor.movePosition(QTextCursor::Start);
                cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
                cursor.select(QTextCursor::LineUnderCursor);
            }
            else if(resBtn == QMessageBox::No)
            {
                return;
            }
        }
        // extragem textul din editor
        std::string text = cursor.selectedText().toStdString();
        // initializam obiectul care va gasii meciurile pentru expresia regulata
        auto highlights = StringManipulator::find(regex.toStdString(), text, true);
        for(auto h : highlights){
            // se extrage data din text
            std::string date = text.substr(h.getPosition(), h.getPosition() + h.getLength());
            std::cout << h.print() << std::endl;
            // se modifica formatul datei
            StringManipulator::changeDateFormat(date, format);
            // se inlocuieste in text
            text.replace(h.getPosition(), h.getPosition() + h.getLength(), date);
        }
        cursor.beginEditBlock(); // put remove and insert operations in the same block to not affect the QUndoStack
        cursor.removeSelectedText();  // remove the previous text
        cursor.insertText(QString(text.c_str()));  // insert the modified text
        cursor.endEditBlock();  // end the block
    } catch(std::invalid_argument& e)
    {
        QMessageBox::warning(getCurrentTextEdit(), "Warning", QString(e.what()));
        return;
    }

}

QPlainTextEdit* NaturalLanguagePlugin::getCurrentTextEdit(){
    QPlainTextEdit* pTextEdit = NULL;
    QWidget* pWidget= tabWidget->currentWidget();
    pTextEdit = (QPlainTextEdit*)pWidget;
    return pTextEdit;
}

void NaturalLanguagePlugin::modifyText(int (*function)(std::string &text))
{
    try
    {

        QTextCursor cursor = getCurrentTextEdit()->textCursor();
        if(!cursor.hasSelection()) // daca nu exista text selectat, atunci se selecteaza tot textul
        {
            QMessageBox::StandardButton resBtn = QMessageBox::question( getCurrentTextEdit(),"TextEditor",
                                                                        tr("Do you want to apply this function for the entire text?\n"),
                                                                        QMessageBox::No | QMessageBox::Yes);
            if (resBtn == QMessageBox::Yes)
            {  // the user selected "Yes" -> select the whole text
                cursor.movePosition(QTextCursor::Start);
                cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
                cursor.select(QTextCursor::LineUnderCursor);
            }
            else if(resBtn == QMessageBox::No)
            {
                return;
            }
        }
        std::string text = cursor.selectedText().toStdString(); // get the text from QTextCursor
        function(text);  // modify the text with the given function
        cursor.beginEditBlock(); // put remove and insert operations in the same block to not affect the QUndoStack
        cursor.removeSelectedText();  // remove the previous text
        cursor.insertText(QString(text.c_str()));  // insert the modified text
        cursor.endEditBlock();
    } catch(std::invalid_argument& e)
    {
        QMessageBox::warning(getCurrentTextEdit(), "Warning", QString(e.what()));
        return;
    }
}
