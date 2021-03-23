#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Utils.h"
#include "ModifyText.h"
#include <string>
#include <cstring>
#include <vector>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCharFormat>
#include <QUndoStack>
#include <QMenu>
#include <QUndoView>

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
    ui->actionDefault->setChecked(true);
    ui->tabWidget->removeTab(0); // we have a default garbage tab, so it must be removed
    on_actionNew_triggered(); // add a fresh new tab
    undoGroup->setActiveStack(undoGroup->stacks()[0]); // set active the first stack in the group
    // set icons for all the actions

    //ui->tabWidget->installEventFilter(this);
//    connect(ui->plainText, QTextCursor::cursorPositionChanged,this, writeOnLine);
//    connect(ui->plainText, QTextCursor::cursorPositionChanged,this, writeOnColumn);
    highlighter.loadKeyWords();
    highlighter.loadTypes();
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
        if(!cursor.hasSelection()) // if there is no selected text, ask if the user wants to modify all the text
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

void MainWindow::changeDatesInText(const StringManipulator::dateFormat format) {
    try
    {

        QTextCursor cursor = getCurrentTextEdit()->textCursor();
        if(!cursor.hasSelection()) // if there is no selected text, ask if the user wants to modify all the text
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
        // extract text from current tab
        std::string text = cursor.selectedText().toStdString(); // get the text from QTextCursor
        // find the dates
        StringManipulator::trim(text); // trim the text to not be some extra spaces in it
        auto words = Utils::split(text, " ");
        text = "";
        for(auto word : words)
        {
            if(StringManipulator::isADate(word)) {
                StringManipulator::changeDateFormat(word, format);
            }
            text +=word + " ";  // rebuilding the text with the new changes
        }
        cursor.beginEditBlock(); // put remove and insert operations in the same block to not affect the QUndoStack
        cursor.removeSelectedText();  // remove the previous text
        cursor.insertText(QString(text.c_str()));  // insert the modified text
        cursor.endEditBlock();  // end the block
    } catch(std::invalid_argument& e)
    {
        QMessageBox::warning(this, "Warning", QString(e.what()));
        return;
    }

}

void MainWindow::setAppearance(mode selected_mode)
{
    QString name_mode = (selected_mode == default_mode)? "DefaultMode" : "DarkMode";
    // setting icons for buttons
    QString folder_name = "Themes";
    QString subfolder_name = "icons";//
    ui->actionNew->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "//new.png")));
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
    ui->actionTrim->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/trim.png")));
    ui->actionPadding->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/padding.png")));
    ui->actionCapitalize->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/capitalize.jpeg")));
    ui->FindButton->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/find.png")));
    ui->FindRegexButton->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" + subfolder_name + "/find_regex.png")));
    // setting colors

    if(selected_mode == default_mode)
    {
         // Define colors
        color = QColor(248,248,248);
        textColor = QColor(Qt::black);
        buttonColor = QColor(Qt::white);
        editorColor = Qt::white;
        regexButtonColor= QColor(Qt::black);
    }
    else if(selected_mode == dark_mode)
    {
        // Define colors
        color = QColor(50,50,50);
        textColor = QColor(Qt::white);
        buttonColor = QColor(40,40,40);
        editorColor = QColor(80,80,80);
        regexButtonColor= QColor(Qt::white);
    }
        //BACKGROUND
        QPalette palette = this->palette();

        palette.setColor(QPalette::Window, color);
        palette.setColor(QPalette::WindowText, textColor);
        this->setPalette(palette);
        // MENIU BAR
        palette = ui->menuBar->palette();
        palette.setColor(QPalette::ButtonText, textColor);
        ui->menuBar->setPalette(palette);
        auto list = ui->menuBar->findChildren<QMenu*>();
        int i;
        palette = list[0]->palette();
        palette.setColor(QPalette::Base, color);
        palette.setColor(QPalette::Text, textColor);
        for(i = 0; i < list.count(); ++i)
        {
            list[i]->setPalette(palette);
        }
        // TOOLBAR
        palette = ui->mainToolBar->palette();
        palette.setColor(QPalette::Window, color);
        palette.setColor(QPalette::Button, color);
        ui->mainToolBar->setPalette(palette);
        //TABWIDGET
        palette = ui->tabWidget->palette();
        palette.setColor(QPalette::Base, color);
        palette.setColor(QPalette::Window, color);
        palette.setColor(QPalette::Text, textColor);
        ui->tabWidget->setPalette(palette);
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
        if(stack->index() != 0)
        {
            // get the new text state
            QString newText = getCurrentTextEdit()->toPlainText();
            // get the text from previous state
            //stack->undo();
            stack->redo();
            QString oldText = getCurrentTextEdit()->toPlainText();
            int old_position = getCurrentTextEdit()->textCursor().position();
            getCurrentTextEdit()->setPlainText(newText);
            // insert comand to undo stack
            stack->push(new ModifyText(getCurrentTextEdit(), oldText,old_position, newText, new_position));
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
    ui->tabWidget->addTab(editor, name);
    QUndoStack* stack = new QUndoStack(); //(homework) fa asta si la openAction
    stack->setObjectName(name);
    undoGroup->addStack(stack);
    //editor->installEventFilter(this);
    connect(editor, &QPlainTextEdit::textChanged, this, &MainWindow::manageChangedText);
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open the file"));
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) { // if something went wrong, show a message
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    // put the content in a QString
    QTextStream in(&file);
    QString text = in.readAll();
    // CREATE THE NEW TAB
    // split the filename apart to get the name
    std::vector<std::string> tokens = Utils::split(filename.toStdString(), "/");
    // converting the last element (the actual tabName) to char array,then to QString
    QString tabName = QString(tokens[tokens.size()-1].c_str());
    QPlainTextEdit* editor = new QPlainTextEdit();
    editor->setPlainText(text);
    ui->tabWidget->addTab(editor, tabName);
    // create stack for this tab
    QUndoStack* stack = new QUndoStack();
    stack->setObjectName(tabName);
    undoGroup->addStack(stack);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)) { // if something went wrong, show a message
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
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
    QApplication::quit();
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

void MainWindow::on_actionTrim_triggered()
{
    // we must save the old and new versions of text for undo/redo commands
//    QString oldText, newText;
//    oldText = getCurrentTextEdit()->toPlainText();
    modifyText(StringManipulator::trim);  // the actual function
//    newText = getCurrentTextEdit()->toPlainText();
//    // add command to stack
//    QUndoStack* stack = undoGroup->activeStack(); // get the active stack
//    stack->push(new ModifyText(getCurrentTextEdit(), oldText, newText));
}

void MainWindow::on_actionPadding_triggered()
{
//    QString oldText, newText;
//    oldText = getCurrentTextEdit()->toPlainText();
    modifyText(StringManipulator::padding);  // the actual function
//    newText = getCurrentTextEdit()->toPlainText();
//    // add command to stack
//    QUndoStack* stack = undoGroup->activeStack(); // get the active stack
//    stack->push(new ModifyText(getCurrentTextEdit(), oldText, newText));
}

void MainWindow::on_actionCapitalize_triggered()
{
//    QString oldText, newText;
//    oldText = getCurrentTextEdit()->toPlainText();
    modifyText(StringManipulator::capitalizeAll);  // the actual function
//    newText = getCurrentTextEdit()->toPlainText();
//    // add command to stack
//    QUndoStack* stack = undoGroup->activeStack(); // get the active stack
//    stack->push(new ModifyText(getCurrentTextEdit(), oldText, newText));
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

void MainWindow::on_actiondot_little_endian_triggered()
{
    changeDatesInText(StringManipulator::dot_little_endian);
}

void MainWindow::on_actionslash_little_endian_triggered()
{
    changeDatesInText(StringManipulator::slash_little_endian);
}

void MainWindow::on_actionline_little_endian_triggered()
{
    changeDatesInText(StringManipulator::line_little_endian);
}

void MainWindow::on_actiondot_big_endian_triggered()
{
    changeDatesInText(StringManipulator::dot_big_endian);
}

void MainWindow::on_actionslash_big_endian_triggered()
{
    changeDatesInText(StringManipulator::slash_big_endian);
}

void MainWindow::on_actionline_big_endian_triggered()
{
    changeDatesInText(StringManipulator::line_big_endian);
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

    // find the stack associated with the tab
    QString name = ui->tabWidget->tabText(index);
    QUndoStack* stack;
    for(auto st : undoGroup->stacks()) // verify every stack from undoGroup
    {
        if(st->objectName() == name)
        {
            stack = st;
        }
    }
    // removing the stack
    undoGroup->removeStack(stack);
    delete stack;
    // removing the tab
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

void MainWindow::on_actionTrim_2_toggled(bool arg1)
{
    ui->actionTrim->setVisible(arg1);
}

void MainWindow::on_actionPadding_2_toggled(bool arg1)
{
    ui->actionPadding->setVisible(arg1);
}

void MainWindow::on_actionCapitalize_2_toggled(bool arg1)
{
    ui->actionCapitalize->setVisible(arg1);
}

void MainWindow::on_actionDefault_toggled(bool arg1)
{
    if(arg1)
    {
        setAppearance(default_mode);
        ui->actionDark_Mode->setChecked(false);
    }
}

void MainWindow::on_actionDark_Mode_toggled(bool arg1)
{
    if(arg1)
    {
        setAppearance(dark_mode);
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

