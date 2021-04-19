#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Utils.h"
#include "ModifyText.h"
#include <string>
#include <cstring>
#include <vector>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCharFormat>
#include <QUndoStack>
#include <QMenu>
#include <QUndoView>
#include <QCloseEvent>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QCoreApplication>

QChar ENTER = QChar(8233);
QString tab = "        ";
bool canInsertToStack = true;
// command for find function
static int delete_text_command = 1;
// iterator for the "New" action
static int new_tab_index = 0;
// theme colors commands
QColor editorColor, color,textColor, buttonColor, regexButtonColor;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowTitle("TextEditor");
    //set the stacks group
    undoGroup = new QUndoGroup(this);
    ui->setupUi(this);
    ui->tabWidget->removeTab(0); // we have a default garbage tab, so it must be removed
    on_actionNew_triggered(); // add a fresh new tab
    undoGroup->setActiveStack(undoGroup->stacks()[0]); // set active the first stack in the group
    // Incarcam plug-inurile
    if(loadPlugin())
    {
        editorInterface->setProperties(ui->menuBar, ui->tabWidget, st.getTheme());
        editorInterface->setActions();
    }


    //load highlights
    highlighter.loadKeyWords();
    highlighter.loadTypes();
    // ASPECT
    st.LoadSettings();
    //Se seteaza tema din fisierul de configurare
    for(auto action : ui->menuTheme->actions())
    {
        if(action->text() == st.getTheme()->getCurrentTheme())
        {
            action->setChecked(true);
        }
    }
    // Se seteaza actiunile vizibile
    st.setActions(ui->menuVisible_actions);



}

MainWindow::~MainWindow()
{
    for(auto stack : undoGroup->stacks())
    {
        delete stack;
    }
    delete undoGroup;
    delete ui;
}

void MainWindow::modifyText(int (*function)(std::string &text))
{
    try
    {

        QTextCursor cursor = getCurrentTextEdit()->textCursor();
        if(!cursor.hasSelection()) // daca nu exista text selectat, atunci se selecteaza tot textul
        {
            QMessageBox::StandardButton resBtn =
            QMessageBox::question( this,"TextEditor",tr("Do you want to apply this function for the entire text?\n"),
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
        QMessageBox::warning(this, "Warning", QString(e.what()));
        return;
    }
}



void MainWindow::setAppearance(QString name_mode)
{
    st.getTheme()->loadColors(name_mode);
    // setting icons for buttons
    QString folder_name = "Themes";
    QString subfolder_name = "icons";
    ui->actionNew->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/new.png")));
    ui->actionOpen->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/open.png")));
    ui->actionSave->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/save.png")));
    ui->actionCut->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/cut.png")));
    ui->actionCopy->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/copy.png")));
    ui->actionPaste->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/paste.png")));
    ui->actionUndo->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/undo.png")));
    ui->actionRedo->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/redo.png")));
    ui->actionBold->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/bold.png")));
    ui->actionItalic->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/italic.png")));
    ui->actionUnderline->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/underline.png")));


    ui->FindButton->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/find.png")));
    ui->FindRegexButton->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/find_regex.png")));
    // setting colors
        QPalette palette = this->palette();
        QColor color = st.getTheme()->getBaseColor();
        QColor textColor = st.getTheme()->getTextColor();
        QColor editorColor = st.getTheme()->getEditorColor();
        QColor buttonColor = st.getTheme()->getButtonColor();
        QColor regexButtonColor = st.getTheme()->getRegexButtonColor();

        this->setStyleSheet("background : " + color.name() + "; color : " + textColor.name());
        // SEARCH BAR
        palette = ui->findTextBox->palette();
        palette.setColor(QPalette::Base, editorColor);
        palette.setColor(QPalette::Text, textColor);
        ui->findTextBox->setPalette(palette);
        // FIND BUTTON
        palette = ui->FindButton->palette();
        palette.setColor(QPalette::Button, buttonColor);
        palette.setColor(QPalette::ButtonText, textColor);
        ui->FindButton->setPalette(palette);
        // FIND REGEX BUTTON
        palette = ui->FindRegexButton->palette();
        palette.setColor(QPalette::Button, regexButtonColor);
        ui->FindRegexButton->setPalette(palette);
        // "PREVIOUS" BUTTON
        palette = ui->previous->palette();
        palette.setColor(QPalette::Button, buttonColor);
        palette.setColor(QPalette::ButtonText, textColor);
        ui->previous->setPalette(palette);
        // "NEXT" BUTTON
        palette = ui->next->palette();
        palette.setColor(QPalette::Button, buttonColor);
        palette.setColor(QPalette::ButtonText, textColor);
        ui->next->setPalette(palette);
        // "EXIT FIND" BUTTON
        palette = ui->exitFind->palette();
        palette.setColor(QPalette::Button, buttonColor);
        palette.setColor(QPalette::ButtonText, textColor);
        ui->exitFind->setPalette(palette);
}

// Make adding commands to undo stack available
void MainWindow::StackOn(){ canInsertToStack = true; }

// Make adding commands to undo stack unavailable
void MainWindow::StackOff(){ canInsertToStack = false;}

void MainWindow::addToUndoStack()
{
    // memorize the position of the cursor
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    int new_position = cursor.position();
    // get the active stack
    QUndoStack* stack = undoGroup->activeStack();
    if(canInsertToStack == true)
    {
        //block stack insertion for the next operations
        StackOff();
        auto previous = stack->command(stack->index());
        //qDebug() << previous->text() << endl;
        if(stack->index() != 0)
        {
            // get the new text state
            QString newText = getCurrentTextEdit()->toPlainText();
            // get the text from previous state
            stack->undo();
            stack->redo();
            QString oldText = getCurrentTextEdit()->toPlainText();
            int old_position = getCurrentTextEdit()->textCursor().position();
            getCurrentTextEdit()->setPlainText(newText);
            // insert comand to undo stack
            stack->push(new ModifyText(getCurrentTextEdit(), oldText,old_position, newText, new_position,previous));
        }
        else
        {
            stack->push(new ModifyText(getCurrentTextEdit(), "",0,
                                       getCurrentTextEdit()->toPlainText(),new_position));
        }
        // make stack insertion available
        StackOn();
    }
}

void MainWindow::manageChangedText(){
    addToUndoStack();
    highlightText();
}

void MainWindow::highlightText(){
    auto edit = getCurrentTextEdit();
    QMap<QString, QList<TextHighLight>> map;
    QColor keywords_color(204,204,0);
    QColor types_color(51,51,255);
    QColor string_color(139,69,19);
    map.insert(keywords_color.name(), highlighter.findKeyWords(edit));
    map.insert(types_color.name(), highlighter.findTypes(edit));
    map.insert(string_color.name(), highlighter.findString(edit));
    highlighter.colorTargets(map, edit);
    // deletig pointers
    //delete keywords_color, types_color;
}

QPlainTextEdit* MainWindow::getCurrentTextEdit(){
    QPlainTextEdit* pTextEdit = NULL;
    QWidget* pWidget= ui->tabWidget->currentWidget();
    pTextEdit = (QPlainTextEdit*)pWidget;
    return pTextEdit;
}

QPlainTextEdit* MainWindow::getTextEditByName(const QString &name){
    QPlainTextEdit* pTextEdit = nullptr;
    for(int i = 0; i < ui->tabWidget->count(); i++ )
    {
        if(ui->tabWidget->tabText(i) == name)
        {
            QWidget* pWidget = ui->tabWidget->widget(i);
            pTextEdit = (QPlainTextEdit*)pWidget;
        }
        break;
    }

    return pTextEdit;
}
void MainWindow::on_actionNew_triggered()
{
    // clearing the current file name
    currentFile.clear();
    // create plainTextEdit and add it to a new tb
    QString name = "New " + QString::number(++new_tab_index);
    QPlainTextEdit *editor = new QPlainTextEdit(ui->tabWidget);
    editor->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    ui->tabWidget->addTab(editor, name);
    QUndoStack* stack = new QUndoStack(); //(homework) fa asta si la openAction
    stack->setObjectName(name);
    undoGroup->addStack(stack);
    //editor->installEventFilter(this);
    connect(editor, &QPlainTextEdit::textChanged, this, &MainWindow::manageChangedText);
//    QUndoView* view = new QUndoView(stack, editor);
//    view->setGeometry(300,0, 300, 600);
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open the file"));
    QFile* file = new QFile(filename);
    currentFile = filename;
    if(!file->open(QIODevice::ReadWrite | QFile::Text)) { // if something went wrong, show a message
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file->errorString());
        return;
    }
    // put the content in a QString
    QTextStream in(file);
    QString text = in.readAll();
    // CREAREA NOULUI TAB
    // extragem numele fisierului din calea absoluta
    qDebug() << "Path : " << filename << endl;
    auto tokens = filename.split("/");
    // ultimul token este numele fisierului iar restul tokenilor sunt numele directoarelor din calea absoluta
    QString tabName = tokens[tokens.count()-1];
    QPlainTextEdit* editor = new QPlainTextEdit();
    editor->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    editor->setPlainText(text);
    ui->tabWidget->addTab(editor, tabName);
    // crearea unei stive pentru noul tab
    QUndoStack* stack = new QUndoStack();
    stack->setObjectName(tabName);
    undoGroup->addStack(stack);
    // adaugam fisierul in dictionar impreuna cu numele tabului
    filesList.insert(tabName, file);
}

void MainWindow::on_actionSave_triggered()
{   // se verifica daca text-ul curent este asociat unui tab nou creat sau unui fisier deschis
    if(filesList.contains(ui->tabWidget->tabText(ui->tabWidget->currentIndex()))){
        qDebug() << "Contine fisierul" << endl;
    } else{ // fisierul nu a fost gasit, deci se creaza unul cu ajutorul metodei "Save as"
        qDebug() << "Nu contine fisierul" << endl;
        on_actionSave_as_2_triggered();
    }

}

void MainWindow::on_actionSave_as_2_triggered(){
    // se deschide un dialog de unde putem lua numele noului fisier
    QString filename = QFileDialog::getSaveFileName(this, "Save as");
    // se deschide fisierul
    QFile file(filename);
    if(!file.open(QFile::ReadWrite | QFile::Text)) { // if something went wrong, show a message
        //QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = getCurrentTextEdit()->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionCopy_triggered()
{
    getCurrentTextEdit()->copy();
}

void MainWindow::on_actionPaste_triggered()
{   // we must save the old and new versions of text for undo/redo commands
    getCurrentTextEdit()->paste();  // the actual function
}

void MainWindow::on_actionCut_triggered()
{
    // we must save the old and new versions of text for undo/redo commands
    getCurrentTextEdit()->cut();  // the actual function
}

void MainWindow::on_actionUndo_triggered()
{
    if(canInsertToStack == true)
    {
        // block stack insertion
        StackOff();
        undoGroup->activeStack()->undo();
        // make stack insertion available
        StackOn();
    }
}

void MainWindow::on_actionRedo_triggered()
{
    if(canInsertToStack == true)
    {
        // block stack insertion
        StackOff();
        undoGroup->activeStack()->redo();
        // make stack insertion available
        StackOn();
    }
}

void MainWindow::on_actionBold_triggered()
{
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    if(!cursor.hasSelection())  // if there is no selected text, select the word under QTextCursor
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    QTextCharFormat format;
    format.setFontWeight(cursor.charFormat().font().bold()? QFont::Normal : QFont::Bold);  // set the fomat to bold, if it is not already
    cursor.mergeCharFormat(format); // apply the format to the selected text
}

void MainWindow::on_actionItalic_triggered()
{
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    if(!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    QTextCharFormat format;
    if(!cursor.charFormat().font().italic())
    {
        format.setFontItalic(true);
    }
    else
    {
        format.setFontItalic(false);
    }
    cursor.mergeCharFormat(format);
}

void MainWindow::on_actionUnderline_triggered()
{
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    if(!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    QTextCharFormat format;
    if(!cursor.charFormat().font().underline())
    {
        format.setFontUnderline(true);
    }
    else
    {
        format.setFontUnderline(false);
    }
    cursor.mergeCharFormat(format);
}


void MainWindow::on_FindButton_clicked()
{
    on_actionFind_triggered();
}

void MainWindow::on_actionFind_triggered()
{
    if(findResults.size() > 0) // if there is a find action in progress, abort it
    {
        delete_text_command = do_not_delete_find_box_text; // tell the on_exitFind_clicked function to not delete the text in findTextBox
        on_exitFind_clicked();
        delete_text_command = delete_find_box_text;  // put the global variable to its original status;
    }
    // take text from findTextBox
    std::string pattern = ui->findTextBox->text().toStdString();
    std::string text = getCurrentTextEdit()->toPlainText().toStdString();
    // make a list with resulted highlights
    try
    {
        findResults = StringManipulator::find(pattern, text, false);
    }
    catch(std::invalid_argument& e)
    {
        QMessageBox::warning(this, "Warning", QString(e.what()));
        return;
    }
    //set first highlight
    if(findResults.size() > 0) // if there is at least one match index = first position
    {
        indexFindResults = 0;
    }
    else  // if there are no matches, send a warning message
    {
        QMessageBox::warning(this, "Warning", "Cannot find the pattern");
        return;
    }
    //cursor.beginEditBlock();
    setHighLight(findResults[indexFindResults]);
    ui->findResultsLabel->setText(QString::number(indexFindResults + 1) +
                                  " from " + QString::number(findResults.size()) +
                                  " results");
}

void MainWindow::setHighLight(const TextHighLight &highlight,const int requiredFormat)
{
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    cursor.setPosition(highlight.getPosition());
    cursor.setPosition(highlight.getPosition() + highlight.getLength(), QTextCursor::KeepAnchor);
    getCurrentTextEdit()->ensureCursorVisible();
    getCurrentTextEdit()->setTextCursor(cursor);
}

void MainWindow::on_previous_clicked()
{
    if(findResults.size() != 0)
    {
        // clear the previous highlight
        setHighLight(findResults[indexFindResults], default_format);
        // increment index
        if(indexFindResults > 0)
        {
            indexFindResults--;
        }
        else
        {
            indexFindResults = findResults.size() - 1;
        }
        // set highlight
        setHighLight(findResults[indexFindResults]);
        ui->findResultsLabel->setText(QString::number(indexFindResults + 1) +
                                      " from " + QString::number(findResults.size()) +
                                      " results");
    }
}

void MainWindow::on_next_clicked()
{ if(findResults.size() != 0)
    {
        // clear the previous highlight
        setHighLight(findResults[indexFindResults], default_format);
        // increment index
        if(indexFindResults < findResults.size() - 1)
        {
            indexFindResults++;
        }
        else
        {
            indexFindResults = 0;
        }
        // set highlight
        setHighLight(findResults[indexFindResults]);
        ui->findResultsLabel->setText(QString::number(indexFindResults + 1) +
                                      " from " + QString::number(findResults.size()) +
                                      " results");
    }

}

void MainWindow::on_exitFind_clicked()
{

    if(findResults.size() > 0)
    {
        // if there is some garbage text in findTextBox (delete_text_command will tell to delete it), then clear the findTextBox
        if(delete_text_command == delete_find_box_text)
        {
            ui->findTextBox->setText(QString(""));
        }
        findResults.clear(); // clear the results vector
        indexFindResults = 0; // add the index to its default value
        //QTextCursor cursor = getCurrentTextEdit()->textCursor();
        ui->findResultsLabel->clear();
        //cursor.endEditBlock();
    }
}


void MainWindow::on_FindRegexButton_clicked()
{
  on_actionFind_regex_triggered();
}

void MainWindow::on_actionFind_regex_triggered()
{
    if(findResults.size() > 0) // if there is a find action in progress, abort it
    {
        delete_text_command = do_not_delete_find_box_text;
        on_exitFind_clicked();
        delete_text_command = delete_find_box_text;
    }
    // take text from findTextBox
    std::string pattern = ui->findTextBox->text().toStdString();
    std::string text = getCurrentTextEdit()->toPlainText().toStdString();
    // make a list with resulted highlights
    try
    {
        findResults = StringManipulator::find(pattern, text, true);
    }
    catch(std::invalid_argument& e)
    {
        QMessageBox::warning(this, "Warning", QString(e.what()));
        return;
    }
    //set first highlight
    if(findResults.size() > 0) // if there is at least one match index = first position
    {
        indexFindResults = 0;
    }
    else  // if there are no matches, send a warning message
    {
        QMessageBox::warning(this, "Warning", "Cannot find the pattern");
        return;
    }
    //cursor.beginEditBlock();
    setHighLight(findResults[indexFindResults]);
    ui->findResultsLabel->setText(QString::number(indexFindResults + 1) +
                                  " from " + QString::number(findResults.size()) +
                                  " results");
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(ui->tabWidget->count()==1)
    {
        on_actionNew_triggered();
    }

    // se cauta stiva asociata tabului
    QString name = ui->tabWidget->tabText(index);
    QUndoStack* stack;
    for(auto st : undoGroup->stacks()) // verify every stack from undoGroup
    {
        if(st->objectName() == name)
        {
            stack = st;
        }
    }
    // se sterge stiva
    undoGroup->removeStack(stack);
    delete stack;
    // se sterge pointerul catre fisierul asociat
    delete filesList[name];
    // se elimina perechea nume - fisier din dictionarul filesList
    filesList.remove(name);
    // se sterge tabul
    ui->tabWidget->removeTab(index);

}


void MainWindow::on_actionNew_2_toggled(bool arg1)
{
    ui->actionNew->setVisible(arg1);

}

void MainWindow::on_actionOpen_2_toggled(bool arg1)
{
    ui->actionOpen->setVisible(arg1);
}

void MainWindow::on_actionSave_2_toggled(bool arg1)
{
    ui->actionSave->setVisible(arg1);
}

void MainWindow::on_actionCut_2_toggled(bool arg1)
{
    ui->actionCut->setVisible(arg1);
}

void MainWindow::on_actionCopy_2_toggled(bool arg1)
{
    ui->actionCopy->setVisible(arg1);
}

void MainWindow::on_actionPaste_2_toggled(bool arg1)
{
    ui->actionPaste->setVisible(arg1);
}

void MainWindow::on_actionUndo_2_toggled(bool arg1)
{
    ui->actionUndo->setVisible(arg1);
}

void MainWindow::on_actionRedo_2_toggled(bool arg1)
{
    ui->actionRedo->setVisible(arg1);
}


void MainWindow::on_actionDefault_toggled(bool arg1)
{
    if(arg1)
    {
        setAppearance("Default");
        ui->actionDarkMode->setChecked(false);
    }
}

void MainWindow::on_actionDarkMode_toggled(bool arg1)
{
    if(arg1)
    {
        setAppearance("DarkMode");
        ui->actionDefault->setChecked(false);
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(undoGroup->stacks().count() > 0)
    {
        for(auto stack : undoGroup->stacks())
        {
            if(stack->objectName() == ui->tabWidget->tabText(index))
            {
                undoGroup->setActiveStack(stack);
            }
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    event->ignore();
     if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Do you want to exit?", QMessageBox::Yes | QMessageBox::No))
     {
        st.saveSettings(ui->menuVisible_actions);
        event->accept();
     }
}


void MainWindow::on_actionReplace_triggered(){
    // Construim fereastra
    QDialog dialog(this);
    QFormLayout form(&dialog);
    // Adaugam intrarile
    QLineEdit *findInput = new QLineEdit(&dialog);
    QString findLabel = "Find:";
    form.addRow(findLabel, findInput);
    QLineEdit *replaceInput = new QLineEdit(&dialog);
    QString replaceLabel = "Replace with:";
    form.addRow(replaceLabel, replaceInput);
    //Construim butoanele de confirmare
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox); // adaugam butoanele in fereastra
    // construim triggerele pentru executie in functie de optiunea aleasa
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    if (dialog.exec() == QDialog::Accepted){ // in cazul in care se doreste executia functiei:
        std::string toReplace = findInput->text().toStdString();
        std::string text = getCurrentTextEdit()->toPlainText().toStdString();
        try{// luam in considerare faptul ca la fiecare schimbare, pozitiile tuturor cuvintelor se poate schimba
            // se afla numarul de cuvinte ce trebuie modificate
            std::vector<TextHighLight> highlights = StringManipulator::find(toReplace, text);
            int nr_of_changes = highlights.size();
            QTextCursor cursor = getCurrentTextEdit()->textCursor();
            // se face detectarea si modifcarea fiecarui cuvant
            for(int i = 0; i < nr_of_changes;++i){
                text = getCurrentTextEdit()->toPlainText().toStdString();
                highlights = StringManipulator::find(toReplace, text, false, "FIRST");
                auto h = highlights[0];
                cursor.setPosition(h.getPosition());
                cursor.setPosition(h.getPosition() + h.getLength(), QTextCursor::KeepAnchor);
                //cursor.deleteChar(); // stergem textul selectat
                cursor.insertText(replaceInput->text());

            }

        } catch(std::invalid_argument& e)
        {
            QMessageBox::warning(this, "Warning", QString(e.what()));
            return;
        }
    }
}

void MainWindow::on_actionIndent_forward_triggered(){
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    QString text = cursor.selectedText();

    if(cursor.hasSelection()){
        int anchor;
        if(cursor.anchor() >= cursor.position()){ // daca selectia a fost facuta de la dreapta la stanga
            anchor = cursor.position();
        } else { // daca selectia a fost de la dreapta la stanga
            anchor = cursor.anchor();
        }
        if(text[0] != ENTER)
        {
            text = tab + text;
        }
        int i = 0;
        while(i != text.count()-1){
            if(text[i] == ENTER){
                text.insert(i+1, tab);
                i += 4;
            } else {
                i++;
            }
        }
        cursor.insertText(text);
        cursor.setPosition(anchor);
        cursor.setPosition(anchor + text.count(), QTextCursor::KeepAnchor);
        getCurrentTextEdit()->ensureCursorVisible();
        getCurrentTextEdit()->setTextCursor(cursor);
    }
}


void MainWindow::on_actionIndent_backward_triggered(){
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    QString text = cursor.selectedText();
    if(cursor.hasSelection()){
        int anchor;
        if(cursor.anchor() >= cursor.position()){ // daca selectia a fost facuta de la dreapta la stanga
            anchor = cursor.position();
        } else { // daca selectia a fost de la dreapta la stanga
            anchor = cursor.anchor();
        }
        auto list = text.split(ENTER);
        QString temp;
        // separare pe randuri
        for(int i = 0; i < list.count(); i++){
            //inlaturarea tabului cel mai din stanga daca exista
            if(list[i].left(tab.count()) == tab){
                list[i].remove(0,tab.count());
            }
            // reconstruirea stringului
            if(i != list.count()-1){
                temp = temp + list[i] + ENTER;
            } else{ // nu punem enter la finalul stringului
                temp = temp + list[i];
            }
        }
        cursor.insertText(temp);
        cursor.setPosition(anchor);
        cursor.setPosition(anchor + temp.count(), QTextCursor::KeepAnchor);
        getCurrentTextEdit()->ensureCursorVisible();
        getCurrentTextEdit()->setTextCursor(cursor);
    }
}

bool MainWindow::loadPlugin(){
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    const QStringList entries = pluginsDir.entryList(QDir::Files);
        for (const QString &fileName : entries) {
            QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
            QObject *plugin = pluginLoader.instance();
            if (plugin) {
                editorInterface = qobject_cast<EditorInterface *>(plugin);
                if (editorInterface)
                    return true;
                pluginLoader.unload();
            }
        }

        return false;
}




