  // Copyright 2021 Bobocea Laurentiu
#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QCheckBox>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QCoreApplication>

QChar ENTER = QChar(8233);
QString tab = "        ";
bool canInsertToStack = true;
// variabila ce comanda functia de cautare
static int delete_text_command = 1;
// iterator pentru functia "New"
static int new_tab_index = 0;
// varaibile pentru culorile ferestrei
QColor editorColor, color, textColor, buttonColor, regexButtonColor;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) { ui->setupUi(this);
    // setare taburi
    tabWidget = new TabWidget(this);
    // stergem tabWidget-ul formal care pastreaza
    // geometria pentru tabWidget-ul din clasa derivata
    ui->verticalLayout->replaceWidget(ui->tabWidget, tabWidget);
    ui->tabWidget->deleteLater();
    // semnalul de inchidere al unui dab
    connect(tabWidget, &TabWidget::tabCloseRequested,
            this, &MainWindow::tabWidget_tabCloseRequested);
    connect(tabWidget, &TabWidget::currentChanged, this,
            &MainWindow::on_tabWidget_currentChanged);
    this->setWindowTitle("TextEditor");
    // se seteaza grupul de stive
    undoGroup = new QUndoGroup(this);
    // setare grup cursoare pentru determinarea liniei si coloanei
    cursorGroup = new CursorGroup(this, tabWidget, ui->line, ui->collumn);
    ui->horizontalLayout->setSpacing(1);
    st = new SettingsManager(this);
    // ASPECT
    st->LoadSettings();
    // Se seteaza tema din fisierul de configurare
    for (auto action : ui->menuTheme->actions()) {
        if (action->text() == st->getTheme()->getCurrentTheme()) {
            action->setChecked(true);
        }
    }
    // Se seteaza actiunile vizibile
    st->setActions(ui->menuVisible_actions);
    // Incarcam plug-inurile
    pluginManager.setMembers(st, ui->menuBar, ui->mainToolBar,
                             tabWidget, st->getTheme());
    pluginManager.loadPlugins();
    // adaugare tab nou
    on_actionNew_triggered();
    // se seteaza activa prima stiva din grup
    undoGroup->setActiveStack(undoGroup->stacks()[0]);
}

MainWindow::~MainWindow() {
    for (auto stack : undoGroup->stacks()) {
        delete stack;
    }
    delete undoGroup;
    delete ui;
}

void MainWindow::modifyText(int (*function)(std::string &text)) {
    try {
        QTextCursor cursor = getCurrentTextEdit()->textCursor();
        // daca nu exista text selectat,
        // atunci se selecteaza tot textul
        if (!cursor.hasSelection()) {
            QMessageBox::StandardButton resBtn =
            QMessageBox::question(this, "TextEditor",
            tr("Nu s-a găsit nici o selectare de text."
               " Doriți să aplicați funcția pentru tot textul?\n"),
            QMessageBox::No | QMessageBox::Yes);
            // userul a selectat "Yes" -> se selecteaza tot textul
            if (resBtn == QMessageBox::Yes) {
                cursor.movePosition(QTextCursor::Start);
                cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
                cursor.select(QTextCursor::LineUnderCursor);
            } else if (resBtn == QMessageBox::No) {
                return;
            }
        }
        // primeste textul de la QTextCursor
        std::string text = cursor.selectedText().toStdString();
        // se modifica textul cu functia data ca parametru
        function(text);
        // inceput bloc modificare -> o singura comanda adaugata in stiva
        cursor.beginEditBlock();
        // stergere text vechi
        cursor.removeSelectedText();
        // inserare text nou
        cursor.insertText(QString(text.c_str()));
        cursor.endEditBlock();
    } catch(std::invalid_argument& e) {
        QMessageBox::warning(this, "Warning", QString(e.what()));
        return;
    }
}

void MainWindow::setAppearance(QString name_mode) {
    st->getTheme()->setTheme(name_mode);
    // setare pictograme pentru butoane
    QString folder_name = "Themes";
    QString subfolder_name = "icons";
    ui->actionNew->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" +
                                         subfolder_name + "/new.png")));
    ui->actionOpen->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" +
                                          subfolder_name + "/open.png")));
    ui->actionSave->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" +
                                          subfolder_name + "/save.png")));
    ui->actionCut->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" +
                                         subfolder_name + "/cut.png")));
    ui->actionCopy->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" +
                                          subfolder_name + "/copy.png")));
    ui->actionPaste->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/"
                                           + subfolder_name + "/paste.png")));
    ui->actionUndo->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" +
                                          subfolder_name + "/undo.png")));
    ui->actionRedo->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" +
                                          subfolder_name + "/redo.png")));

    ui->FindButton->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode + "/" +
                                          subfolder_name + "/find.png")));
    ui->FindRegexButton->setIcon(QIcon(QPixmap(folder_name + "/" + name_mode +
                                               "/" + subfolder_name +
                                               "/find_regex.png")));
    // setare culori
        QPalette palette = this->palette();
        QColor color = st->getTheme()->getBaseColor();
        QColor textColor = st->getTheme()->getTextColor();
        QColor editorColor = st->getTheme()->getEditorColor();
        QColor buttonColor = st->getTheme()->getButtonColor();
        QColor regexButtonColor = st->getTheme()->getRegexButtonColor();
        QColor tabBarColor = st->getTheme()->getTabBarColor();
        QColor currentTabColor = st->getTheme()->getCurrentTabColor();

        // CULOAREA DE FUNDAL
        this->setStyleSheet("background : " + color.name() +
                            "; color : " + textColor.name());
        // CULORILE TABURILOR
        tabWidget->setStyleSheet("QTabBar::tab{background : " +
                                 tabBarColor.name() +
                                 "; border: 1px solid gray;" +
                                 "border-top-left-radius: 4px;" +
                                 "border-top-right-radius: 4px;" +
                                  "padding-left: 3px}" +
                                     "QTabBar::tab:selected{background :" +
                                 currentTabColor.name() +
                                 ";border: 1px solid gray}");
        tabWidget->setTabShape(QTabWidget::Triangular);
        // SEARCH BAR
        palette = ui->findTextBox->palette();
        palette.setColor(QPalette::Base, editorColor);
        palette.setColor(QPalette::Text, textColor);
        ui->findTextBox->setPalette(palette);
        // FIND BUTTON

        ui->FindButton->setStyleSheet("background : " + buttonColor.name());
        // FIND REGEX BUTTON
        ui->FindRegexButton->setStyleSheet("background : " +
                                           regexButtonColor.name());
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

// daca un fisier sufera modificari, acesta va fi marcat
void MainWindow::markChangedFile() {
    auto name = tabWidget->tabText(tabWidget->currentIndex());
    // daca numele tabului nu are formatul tabName* atunci:
    if (name.right(1) != "*") {
        QTextStream in(filesList[name]->getFile());
        QString text = in.readAll();
        if (getCurrentTextEdit()->toPlainText() != text) {
            // marcam schimbarea
            filesList[name]->setChangeStatus(true);
            // adaugam * in numele tabului
            name.push_back("*");
            tabWidget->setTabText(tabWidget->currentIndex(), name);
        }
    }
}

// Se accepta introducerea de noi comenzi in stiva activa
void MainWindow::StackOn() { canInsertToStack = true; }

// introducerea de noi comenzi in stiva activa este indisponibila
void MainWindow::StackOff() { canInsertToStack = false;}

void MainWindow::save(const int index) {
    QString name = tabWidget->tabText(index);
    auto editor = getTextEditByName(name);
    if (name.right(1) == "*") {
        name.remove("*");
    }
    if (filesList.contains(name)) {
        if (filesList[name]->hasChanges()) {
            auto file = filesList[name]->getFile();
            // scriem in fisier
            file->seek(0);
            file->write(editor->toPlainText().toUtf8());
            tabWidget->setTabText(index, name);
            filesList[name]->setChangeStatus(false);
        }
    } else {
        // fisierul nu a fost gasit, deci se creaza
        // unul cu ajutorul metodei "Save as"
        saveAs(index);
    }
}

void MainWindow::saveAs(const int index) {
    QString name = tabWidget->tabText(index);
    auto editor = getTextEditByName(name);
    // se deschide un dialog de unde putem lua numele noului fisier
    QString filename = QFileDialog::getSaveFileName(this, "Save as");
    // se deschide fisierul
    QFile *file = new QFile(filename, editor);
    if (!file->open(QFile::ReadWrite | QFile::Text)) {
        // daca s-a intamplat ceva rau, inchide functia
        return;
    }
    // adaugam textul in fisier
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream out(file);
    QString text = editor->toPlainText();
    out << text;
    // adaugam fisierul in lista de fisiere deschise
    QString tabName = filename.split("/").last();
    QSharedPointer<FileStatus>  fileStatus =
            QSharedPointer<FileStatus>(new FileStatus, &QObject::deleteLater);
    fileStatus->setFile(file);
    filesList.insert(tabName, fileStatus);
    // schimbam numele tabului din "New ..." in numele fisierului
    tabWidget->setTabText(index, tabName);
}

void MainWindow::addToUndoStack() {
    // se memoreaza pozitia cursorului
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    int new_position = cursor.position();
    // obtinere stiva activa
    QUndoStack* stack = undoGroup->activeStack();
    if (canInsertToStack == true) {
        // blocare insertii noi
        StackOff();
        auto previous = stack->command(stack->index());
        if (stack->index() != 0) {
            // obtinere starea actualizata a textului
            QString newText = getCurrentTextEdit()->toPlainText();
            // obtine starea anterioara a textului
            stack->undo();
            stack->redo();
            QString oldText = getCurrentTextEdit()->toPlainText();
            int old_position = getCurrentTextEdit()->textCursor().position();
            getCurrentTextEdit()->setPlainText(newText);
            // inserare comanda noua in stiva activa
            stack->push(new ModifyText(getCurrentTextEdit(),
                                       oldText,old_position,
                                       newText, new_position,
                                       previous));
        } else {
            stack->push(new ModifyText(getCurrentTextEdit(),
                                       firstText[stack->objectName()],0,
                                       getCurrentTextEdit()->toPlainText(),
                                       new_position));
        }
        // inserti stiva disponibile din nou:
        StackOn();
    }
}

void MainWindow::manageChangedText() {
    // adaugam schimbarea in stiva
    addToUndoStack();
    if (filesList.contains(tabWidget->tabText(tabWidget->currentIndex()))) {
        markChangedFile();
    }
}



QPlainTextEdit* MainWindow::getCurrentTextEdit() {
    QPlainTextEdit* pTextEdit = NULL;
    QWidget* pWidget = tabWidget->currentWidget();
    pTextEdit = (QPlainTextEdit*)pWidget;
    return pTextEdit;
}

QPlainTextEdit* MainWindow::getTextEditByName(const QString &name) {
    QPlainTextEdit* pTextEdit = nullptr;
    for (int i = 0; i < tabWidget->count(); i++) {
        if (tabWidget->tabText(i) == name) {
            QWidget* pWidget = tabWidget->widget(i);
            pTextEdit = (QPlainTextEdit*)pWidget;
            break;
        }
    }

    return pTextEdit;
}

void MainWindow::on_actionNew_triggered() {
    // stergere nume fisier curent
    currentFile.clear();
    // creaza plainTextEdit si adaugare in noul tab
    QString name = "New " + QString::number(++new_tab_index);
    QPlainTextEdit *editor = new QPlainTextEdit(tabWidget);
    tabWidget->addTab(editor, name);
    QUndoStack* stack = new QUndoStack();
    stack->setObjectName(name);
    undoGroup->addStack(stack);
    firstText.insert(stack->objectName(), editor->toPlainText());
    connect(editor, &QPlainTextEdit::textChanged,
            this, &MainWindow::manageChangedText);
    // QUndoView* view = new QUndoView(stack, editor);
    // view->setGeometry(300,0, 300, 600);
    tabWidget->setCurrentWidget(editor);
    // adaugare setari cursor
    cursorGroup->connectCursor(editor);
}


void MainWindow::on_actionOpen_triggered() {
    // se creaza dialogul prin care se alege fisierul ce trebuie deschis
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Deschide fisierul"));
    // CREAREA NOULUI TAB
    // extragem numele fisierului din calea
    // absoluta (pentru a construi numele tabului)
    auto tokens = filename.split("/");
    // ultimul token este numele fisierului iar restul tokenilor sunt
    // numele directoarelor din calea absoluta
    QString tabName = tokens[tokens.count()-1];
    // creare editor
    QPlainTextEdit* editor = new QPlainTextEdit();
    editor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // deschidere fisier
    QFile* file = new QFile(filename, editor);
    if (!file->open(QIODevice::ReadWrite | QFile::Text)) {
        // if something went wrong, show a message
        QMessageBox::warning(this, "Warning", "Cannot open file: " +
                             file->errorString());
        return;
    }
    // adaugare editor ca tab
    tabWidget->addTab(editor, tabName);
    tabWidget->setCurrentWidget(editor);
    // se extrage testul din fisier
    QTextStream in(file);
    QString text = in.readAll();
    // inserare text
    editor->setPlainText(text);
    // crearea unei stive pentru noul tab
    QUndoStack* stack = new QUndoStack();
    stack->setObjectName(tabName);
    undoGroup->addStack(stack);
    // adaugam fisierul in dictionar impreuna cu numele tabului
    QSharedPointer<FileStatus>  fileStatus =
            QSharedPointer<FileStatus>(new FileStatus, &QObject::deleteLater);
    fileStatus->setFile(file);
    filesList.insert(tabName, fileStatus);
    firstText.insert(stack->objectName(), editor->toPlainText());
    connect(editor, &QPlainTextEdit::textChanged,
            this, &MainWindow::manageChangedText);
    // adaugare setari cursor
    cursorGroup->connectCursor(editor);
    // QUndoView* view = new QUndoView(stack, editor);
    // view->setGeometry(0,0, 300, 600);
}

void MainWindow::on_actionSave_triggered() { save(tabWidget->currentIndex());}

void MainWindow::on_actionSave_as_2_triggered() {
    saveAs(tabWidget->currentIndex());
}

void MainWindow::on_actionExit_triggered() {
    this->close();
}

void MainWindow::on_actionCopy_triggered() {
    getCurrentTextEdit()->copy();
}

void MainWindow::on_actionPaste_triggered() {
    getCurrentTextEdit()->paste();
}

void MainWindow::on_actionCut_triggered() {
    getCurrentTextEdit()->cut();
}

void MainWindow::on_actionUndo_triggered() {
    if (canInsertToStack == true) {
        // blocare insertie stiva
        StackOff();
        undoGroup->activeStack()->undo();
        // deblocare insertie stiva
        StackOn();
    }
}

void MainWindow::on_actionRedo_triggered() {
    if (canInsertToStack == true) {
        // blocare insertie stiva
        StackOff();
        undoGroup->activeStack()->redo();
        // deblocare insertie stiva
        StackOn();
    }
}

void MainWindow::on_FindButton_clicked() {
    on_actionFind_triggered();
}

void MainWindow::on_actionFind_triggered() {
    // daca exista vreo functie de gasire in proces, inchide-o
    if (findResults.size() > 0) {
        // precizeaza on_exitFind_clicked  sa nu stearga textul in findTextBox
        delete_text_command = do_not_delete_find_box_text;
        on_exitFind_clicked();
         // pune variabila globala in starea originala
        delete_text_command = delete_find_box_text;
    }
    try {
      findResults = StringManipulator::find(ui->findTextBox->text(),
                                           getCurrentTextEdit()->toPlainText(),
                                            false);
    }
    catch(std::invalid_argument& e) {
        QMessageBox::warning(this, "Warning", QString(e.what()));
        return;
    }
    // setarea primului highlight
    // daca exista cel putin un index = first position
    if (findResults.size() > 0) {
        indexFindResults = 0;
    } else {  // daca nu sunt potriviri, afisare mesaj de avertizare
        QMessageBox::warning(this, "Warning", "Nu se poate gasi paternul");
        return;
    }
    setHighLight(findResults[indexFindResults]);
    ui->findResultsLabel->setText(QString::number(indexFindResults + 1) +
                                  " din " +
                                  QString::number(findResults.size())+
                                  " rezultate");
}

void MainWindow::setHighLight(const TextHighLight &highlight,
                              const int requiredFormat) {
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    cursor.setPosition(highlight.getPosition());
    cursor.setPosition(highlight.getPosition() + highlight.getLength(),
                       QTextCursor::KeepAnchor);
    getCurrentTextEdit()->ensureCursorVisible();
    getCurrentTextEdit()->setTextCursor(cursor);
}

void MainWindow::on_previous_clicked() {
    if (findResults.size() != 0) {
        // curatare  highlight anterior
        setHighLight(findResults[indexFindResults], default_format);
        // incrementare index
        if (indexFindResults > 0) {
            indexFindResults--;
        } else {
            indexFindResults = findResults.size() - 1;
        }
        // setare highlight
        setHighLight(findResults[indexFindResults]);
        ui->findResultsLabel->setText(QString::number(indexFindResults + 1) +
                                      " din " +
                                      QString::number(findResults.size()) +
                                      " rezultate");
    }
}

void MainWindow::on_next_clicked() {
    if (findResults.size() != 0) {
        // curatare  highlight anterior
        setHighLight(findResults[indexFindResults], default_format);
        // incrementare index
        if (indexFindResults < findResults.size() - 1) {
            indexFindResults++;
        } else {
            indexFindResults = 0;
        }
        // setare highlight
        setHighLight(findResults[indexFindResults]);
        ui->findResultsLabel->setText(QString::number(indexFindResults + 1) +
                                      " din " +
                                      QString::number(findResults.size()) +
                                      " rezultate");
    }
}

void MainWindow::on_exitFind_clicked() {
    if (findResults.size() > 0) {
        // daca exista text inutil in  findTextBox
        // (delete_text_command va notifica stergerea), curatare findTextBox
        if (delete_text_command == delete_find_box_text) {
            ui->findTextBox->setText(QString(""));
        }
        findResults.clear();  // curatare vector
        indexFindResults = 0;  // adaugare index la valoarea de baza
        ui->findResultsLabel->clear();
    }
}

void MainWindow::on_FindRegexButton_clicked() {
  on_actionFind_regex_triggered();
}

void MainWindow::on_actionFind_regex_triggered() {
    // daca exista vreo functie de cautare activa, inchide-o
    if (findResults.size() > 0) {
        delete_text_command = do_not_delete_find_box_text;
        on_exitFind_clicked();
        delete_text_command = delete_find_box_text;
    }
    try {
      findResults = StringManipulator::find(ui->findTextBox->text(),
                                           getCurrentTextEdit()->toPlainText(),
                                            true);
    } catch(std::invalid_argument& e) {
        QMessageBox::warning(this, "Warning", QString(e.what()));
        return;
    }
    // setare primul highlight
    // daca exista cel putin un index = first position
    if (findResults.size() > 0) {
        indexFindResults = 0;
    } else  {
    // daca nu sunt potriviri, trimite mesaj de avertizare
        QMessageBox::warning(this, "Warning", "Nu se poate gasi paternul");
        return;
    }
    setHighLight(findResults[indexFindResults]);
    ui->findResultsLabel->setText(QString::number(indexFindResults + 1) +
                                  " din " +
                                  QString::number(findResults.size()) +
                                  " rezultate");
}

void MainWindow::tabWidget_tabCloseRequested(int index) {
    QString name = tabWidget->tabText(index);
    auto editor = getTextEditByName(name);
    if (name.right(1) == "*") {
        name.remove("*");
    }
    if ((filesList.contains(name) && filesList[name]->hasChanges()) ||
       (!filesList.contains(name)) && editor->toPlainText().count() != 0) {
        QMessageBox::StandardButton resBtn =
        QMessageBox::question(this, "TextEditor",
                              tr("Doriti sa salvati schimbarile?\n"),
        QMessageBox::No | QMessageBox::Yes | QMessageBox::Cancel);
        if (resBtn == QMessageBox::Yes) {
            save(index);
        } else if (resBtn ==QMessageBox::No) {
           // nu fa nimic si continua
        } else if (resBtn ==QMessageBox::Cancel) {
            return;
        }
    }
    if (tabWidget->count() == 1) {
        on_actionNew_triggered();
    }
    // se cauta stiva asociata tabului
    QUndoStack* stack;
    // verifica fiecare stiva din undoGroup
    for (auto st : undoGroup->stacks()) {
        if (st->objectName() == name) {
            stack = st;
        }
    }
    // se sterge stiva
    undoGroup->removeStack(stack);
    delete stack;
    // se elimina perechea nume - fisier din dictionarul filesList
    filesList.remove(name);
    // se sterge tabul
    tabWidget->removeTab(index);
}

void MainWindow::on_actionNew_2_toggled(bool arg1) {
    ui->actionNew->setVisible(arg1);
}

void MainWindow::on_actionOpen_2_toggled(bool arg1) {
    ui->actionOpen->setVisible(arg1);
}

void MainWindow::on_actionSave_2_toggled(bool arg1) {
    ui->actionSave->setVisible(arg1);
}

void MainWindow::on_actionCut_2_toggled(bool arg1) {
    ui->actionCut->setVisible(arg1);
}

void MainWindow::on_actionCopy_2_toggled(bool arg1) {
    ui->actionCopy->setVisible(arg1);
}

void MainWindow::on_actionPaste_2_toggled(bool arg1) {
    ui->actionPaste->setVisible(arg1);
}

void MainWindow::on_actionUndo_2_toggled(bool arg1) {
    ui->actionUndo->setVisible(arg1);
}

void MainWindow::on_actionRedo_2_toggled(bool arg1) {
    ui->actionRedo->setVisible(arg1);
}

void MainWindow::on_actionDefault_toggled(bool arg1) {
    if (arg1) {
        setAppearance("Default");
        ui->actionDarkMode->setChecked(false);
    }
}

void MainWindow::on_actionDarkMode_toggled(bool arg1) {
    if (arg1) {
        setAppearance("DarkMode");
        ui->actionDefault->setChecked(false);
    }
}

void MainWindow::on_tabWidget_currentChanged(int index) {
    if (undoGroup->stacks().count() > 0) {
        for (auto stack : undoGroup->stacks()) {
            auto text = tabWidget->tabText(index);
            text.remove("*");
            if (stack->objectName() == text) {
                undoGroup->setActiveStack(stack);
            }
        }
    }
    if (tabWidget->count() != 0) {
       QPlainTextEdit* editor = getTextEditByName(tabWidget->tabText(index));
       cursorGroup->setLineAndCollumnForEditor(editor);
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    event->ignore();
     if (QMessageBox::Yes == QMessageBox::question(this,
                                         "Close Confirmation",
                                         "Doriti sa iesiti din aplicatie?",
                                         QMessageBox::Yes | QMessageBox::No)) {
        st->saveSettings(ui->menuVisible_actions);
        event->accept();
     }
}

void MainWindow::on_actionReplace_triggered() {
    // Construim fereastra
    QDialog dialog(this);
    QFormLayout form(&dialog);
    // Adaugam intrarile
    QLineEdit *findInput = new QLineEdit(&dialog);
    QString findLabel = "Caută:";
    form.addRow(findLabel, findInput);
    QLineEdit *replaceInput = new QLineEdit(&dialog);
    QString replaceLabel = "Înlocuire cu:";
    form.addRow(replaceLabel, replaceInput);
    // Construim butoanele de confirmare
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);  // adaugam butoanele in fereastra
    // construim triggerele pentru executie in functie de optiunea aleasa
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    // in cazul in care se doreste executia functiei:
    if (dialog.exec() == QDialog::Accepted) {
        QString toReplace = findInput->text();
        QString replacement = replaceInput->text();
        QString text = getCurrentTextEdit()->toPlainText();
        try {
                StringManipulator::replaceAll(toReplace, replacement, text);
                getCurrentTextEdit()->setPlainText(text);
        } catch(std::invalid_argument& e) {
            QMessageBox::warning(this, "Warning", QString(e.what()));
            return;
        }
    }
}

void MainWindow::on_actionIndent_forward_triggered() {
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    QString text = cursor.selectedText();
    if (cursor.hasSelection()) {
        int anchor;
        // daca selectia a fost facuta de la dreapta la stanga
        if (cursor.anchor() >= cursor.position()) {
            anchor = cursor.position();
        } else {  // daca selectia a fost de la dreapta la stanga
            anchor = cursor.anchor();
        }
        if (text[0] != ENTER) {
            text = tab + text;
        }
        int i = 0;
        while (i != text.count()-1) {
            if (text[i] == ENTER) {
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

void MainWindow::on_actionIndent_backward_triggered() {
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    QString text = cursor.selectedText();
    if (cursor.hasSelection()) {
        int anchor;
        // daca selectia a fost facuta de la dreapta la stanga
        if (cursor.anchor() >= cursor.position()) {
            anchor = cursor.position();
        } else {  // daca selectia a fost de la dreapta la stanga
            anchor = cursor.anchor();
        }
        auto list = text.split(ENTER);
        QString temp;
        // separare pe randuri
        for (int i = 0; i < list.count(); i++) {
            // inlaturarea tabului cel mai din stanga daca exista
            if (list[i].left(tab.count()) == tab) {
                list[i].remove(0, tab.count());
            }
            // reconstruirea stringului
            if (i != list.count()-1) {
                temp = temp + list[i] + ENTER;
            } else {  // nu punem enter la finalul stringului
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


void MainWindow::on_actionPlugin_uri_active_triggered() {
    QMap<QString, QCheckBox*> map;
    // Construim fereastra
    QDialog dialog(this);
    QFormLayout form(&dialog);
    auto activations = pluginManager.getActivationStatus();
    for (QString &key : activations.keys()) {
        QCheckBox* checkbox = new QCheckBox( &dialog);
        QLabel* label = new QLabel(key, &dialog);
        form.addRow(checkbox, label);
        map.insert(key, checkbox);
        if (activations[key]) {
            checkbox->setCheckState(Qt::Checked);
        }
    }
    // Construim butoanele de confirmare
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);  // adaugam butoanele in fereastra
    // construim triggerele pentru executie in functie de optiunea aleasa
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    if (dialog.exec() == QDialog::Accepted) {
        // verificam care casute sunt bifate si care nu
        for (auto k : map.keys()) {
            bool temp;
            if (map[k]->checkState() == Qt::Checked) {
                temp = true;
            } else {
                temp = false;
            }
            if (temp != activations[k]) {  // se verifica daca exista schimbari
                // se verifica daca casuta a fost bifata
                // daca a fost bifata, se activeaza plugin-ul
                if (temp == true) {
                    pluginManager.getPlugins()[k]->setActions();
                    qDebug() << "reactivate plugin" << endl;
                } else {
                    pluginManager.getPlugins()[k]->disconnect();
                }
                activations[k]=  temp;
            }
        }
        // se actualizeaza statusurile
        pluginManager.setActivationStatus(activations);
    }
}
