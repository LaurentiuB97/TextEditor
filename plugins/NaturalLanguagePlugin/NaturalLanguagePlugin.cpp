#include "NaturalLanguagePlugin.h"
#include "TextHighLight.h"
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QDir>
#include <QMainWindow>
#include <string>

// Expresia regulata care detecteaza formatul de tip data din text
QString regex = "((((0[1-9])|((1|2)\\d)|(3[0,1]))[\\/, \\-,\\.]((0[1-9])|(1[0-2]))[\\/, \\-,\\.]\\d\\d\\d\\d)|(\\d\\d\\d\\d[\\/, \\-,\\.]((0[1-9])|(1[0-2]))[\\/, \\-,\\.]((0[1-9])|((1|2)\\d)|(3[0,1]))))";
void NaturalLanguagePlugin::setProperties(QMenuBar* menuBar, QToolBar* toolBar, TabWidget* tabWidget,
                                          Theme* theme, Availability* availability) {
    this->menuBar = menuBar;
    this->tabWidget = tabWidget;
    this->theme = theme;
    this->toolBar = toolBar;
    this->availability = availability;

}

void NaturalLanguagePlugin::generateActions(){
    //crearea actiunilor
    //Capitalize
    actionCapitalize = new QAction("Majuscule");
    actions.append(actionCapitalize);

    // Lowercase
    actionLowercase = new QAction("Litere mici");
    actions.append(actionLowercase);

    //Padding
    actionPadding = new QAction("Completare spații");
    actions.append(actionPadding);

    //Trim
    actionTrim = new QAction("Trunchere");
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
    generateActions();
    //SETARE ACTIUNI
    // adaugare actiunile intr-un meniu
    wordEdit = new QMenu("Editare text", menuBar);
    wordEdit->addAction(actionCapitalize);
    wordEdit->addAction(actionLowercase);
    wordEdit->addAction(actionPadding);
    wordEdit->addAction(actionTrim);
    QMenu* changeDateFormat = new QMenu("Schimbare format dată", menuBar);
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

    // adaugare in toolBar
    toolBar->addAction(actionCapitalize);
    toolBar->addAction(actionLowercase);
    toolBar->addAction(actionPadding);
    toolBar->addAction(actionTrim);

    // inseram functionanilatile pentru fiecare actiune
    connect(actionCapitalize, &QAction::triggered, this, &NaturalLanguagePlugin::on_actionCapitalize_triggered);
    connect(actionLowercase, &QAction::triggered, this, &NaturalLanguagePlugin::on_actionLowercase_triggered);
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
    //conectam si semnalul de schimbare a temei cu schimabarea imaginilor
    connect(theme, &Theme::themeChanged, this, &NaturalLanguagePlugin::setIcons);

    //ADAUGARE CASUTE DE BIFARE
    Capitalize_checker = new QAction("Capitalize", this);
    Capitalize_checker->setCheckable(true);
    Capitalize_checker->setChecked(true);
    Lowercase_checker = new QAction("Lowercase",this);
    Lowercase_checker->setCheckable(true);
    Lowercase_checker->setChecked(true);
    Padding_checker = new QAction("Padding",this);
    Padding_checker->setCheckable(true);
    Padding_checker->setChecked(true);
    Trim_checker = new QAction("Trim",this);
    Trim_checker->setCheckable(true);
    Trim_checker->setChecked(true);
    // adaugare actiuni in meniu
    for(QMenu* submenu : list){
        if(submenu->objectName()== "menuVisible_actions"){
            submenu->addAction(Capitalize_checker);
            submenu->addAction(Lowercase_checker);
            submenu->addAction(Padding_checker);
            submenu->addAction(Trim_checker);
            connect(Capitalize_checker, &QAction::toggled, this,
                    &NaturalLanguagePlugin::on_actionCapitalize_toggled);
            connect(Lowercase_checker, &QAction::toggled, this,
                    &NaturalLanguagePlugin::on_actionLowercase_toggled);
            connect(Padding_checker, &QAction::toggled, this,
                    &NaturalLanguagePlugin::on_actionPadding_toggled);
            connect(Trim_checker, &QAction::toggled, this,
                    &NaturalLanguagePlugin::on_actionTrim_toggled);
        }
    }

}


void NaturalLanguagePlugin::disconnect(){
    wordEdit->deleteLater();
    actions.clear();
    actionCapitalize->deleteLater();
    actionLowercase->deleteLater();
    actionPadding->deleteLater();
    actionTrim->deleteLater();
    Capitalize_checker->deleteLater();
    Lowercase_checker->deleteLater();
    Padding_checker->deleteLater();
    Trim_checker->deleteLater();
}

void NaturalLanguagePlugin::setIcons(){
    // setam imaginile specifice fiecarei actiuni in functie de tema curenta
    QString currentTheme = this->theme->getCurrentTheme();
    QString folder_name = "plugins/NaturalLanguagePlugin/ThemeIcons";
    QString path1 = folder_name + "/" + currentTheme +  "/trim.png";
    actionTrim->setIcon(QIcon(path1));
    actionPadding->setIcon(QIcon(QPixmap(folder_name + "/" + currentTheme + "/padding.png")));
    actionCapitalize->setIcon(QIcon(QPixmap(folder_name + "/" + currentTheme + "/capitalize.png")));
    actionLowercase->setIcon(QIcon(QPixmap(folder_name + "/" + currentTheme + "/lowercase.png")));
    // setam visibilitate
    actionTrim->setIconVisibleInMenu(true);
    actionPadding->setIconVisibleInMenu(true);
    actionCapitalize->setIconVisibleInMenu(true);
    actionLowercase->setIconVisibleInMenu(true);
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

void NaturalLanguagePlugin::on_actionLowercase_triggered(){
    modifyText(StringManipulator::lowercaseAll);
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

void NaturalLanguagePlugin::on_actionCapitalize_toggled(bool arg) {
    actionCapitalize->setVisible(arg);
}

void NaturalLanguagePlugin::on_actionLowercase_toggled(bool arg) {
    actionLowercase->setVisible(arg);
}

void NaturalLanguagePlugin::on_actionPadding_toggled(bool arg) {
    actionPadding->setVisible(arg);
}

void NaturalLanguagePlugin::on_actionTrim_toggled(bool arg) {
    actionTrim->setVisible(arg);
}

void NaturalLanguagePlugin::changeDatesInText(const StringManipulator::dateFormat format) {
    try
    {

        QTextCursor cursor = getCurrentTextEdit()->textCursor();
        if(!cursor.hasSelection()) // daca nu s-a selectat textul, intreaba userul daca modificarea se face pe tot textul
        {
            QMessageBox::StandardButton resBtn =
            QMessageBox::question( getCurrentTextEdit(),"TextEditor",tr("Nu s-a găsit nici o selectare de text. Doriți să aplicați funcția pentru tot textul?\n"),
            QMessageBox::No | QMessageBox::Yes);
            if (resBtn == QMessageBox::Yes)
            {  // userul a selectat "Yes" -> selectare text intreg
                getCurrentTextEdit()->selectAll();
                cursor = getCurrentTextEdit()->textCursor();

            }
            else if(resBtn == QMessageBox::No)
            {
                return;
            }
        }
        // extragem textul din editor
        QString text = cursor.selectedText();
        // initializam obiectul care va gasii meciurile pentru expresia regulata
        auto highlights = StringManipulator::find(regex, text, true);
        for(auto h : highlights){
            // se extrage data din text
            QString date = text.mid(h.getPosition(), h.getPosition() + h.getLength());
            std::cout << h.print() << std::endl;
            // se modifica formatul datei
            auto temp = date; // artificiu temportar!!!!!
            StringManipulator::changeDateFormat(temp, format);
            date = temp;
            // se inlocuieste in text
            text.replace(h.getPosition(), h.getPosition() + h.getLength(), date);
        }
        cursor.beginEditBlock(); // incepere bloc -> doar o singura comanda introdusa in stiva si nu doua
        cursor.removeSelectedText();  // stergere text
        cursor.insertText(text);  // inserare text nou
        cursor.endEditBlock();  // esf. bloc
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

void NaturalLanguagePlugin::modifyText(int (*function)(QString &text))
{
    try
    {

        QTextCursor cursor = getCurrentTextEdit()->textCursor();
        if(!cursor.hasSelection()) // daca nu exista text selectat, atunci se selecteaza tot textul
        {
            QMessageBox::StandardButton resBtn = QMessageBox::question( getCurrentTextEdit(),"TextEditor",
                                                                        tr("Nu s-a găsit nici o selectare de text. Doriți să aplicați funcția pentru tot textul?\n"),
                                                                        QMessageBox::No | QMessageBox::Yes);
            if (resBtn == QMessageBox::Yes)
            {  // userul a selectat "Yes" -> selectare text intreg
                cursor.movePosition(QTextCursor::Start);
                cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
                cursor.select(QTextCursor::LineUnderCursor);
            }
            else if(resBtn == QMessageBox::No)
            {
                return;
            }
        }
        QString text = cursor.selectedText(); // preluare text din QTextCursor
        function(text);  // modificare text cu functia primita
        cursor.beginEditBlock(); // incepere bloc -> doar o singura comanda introdusa in stiva si nu doua
        cursor.removeSelectedText();  // stergere text vechi
        cursor.insertText(text);  // inserare text nou
        cursor.endEditBlock();
    } catch(std::invalid_argument& e)
    {
        QMessageBox::warning(getCurrentTextEdit(), "Warning", QString(e.what()));
        return;
    }
}
