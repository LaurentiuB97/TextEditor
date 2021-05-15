#include "TranslatorPlugin.h"
#include <QMessageBox>
#include <QDebug>
void TranslatorPlugin::setProperties(QMenuBar* menuBar,QToolBar* toolBar,
                       TabWidget* tabWidget, Theme* theme){
    this->menuBar = menuBar;
    this->tabWidget = tabWidget;
    this->theme = theme;
    this->toolBar = toolBar;
}

void TranslatorPlugin::setActions(){
    qDebug() << "Setting actions:" <<endl;
    QMenu* translateMenu = new QMenu("Translate", menuBar);
    // creem actiunile
    actionEnToRo = new QAction("EN -> RO");
    actionRoToEn = new QAction("RO -> EN");
    actionFrToRo = new QAction("FR -> RO");
    actionRoToFr = new QAction("RO -> FR");
    // adaugam actiunile in meniu
    translateMenu->addAction(actionEnToRo);
    translateMenu->addAction(actionRoToEn);
    translateMenu->addAction(actionFrToRo);
    translateMenu->addAction(actionRoToFr);
    // adaugam meniul in bara de submeniul "Plugins"
    auto list = menuBar->findChildren<QMenu*>();
    for(QMenu* submenu : list){
        if(submenu->objectName()== "menuPlugins"){
            submenu->addMenu(translateMenu);

        }
    }
    //conectam actiunile la functiile aferente
    connect(actionEnToRo, SIGNAL(triggered()), this, SLOT(fromEnToRo()));
    connect(actionRoToEn, SIGNAL(triggered()), this, SLOT(fromRoToEn()));
    connect(actionFrToRo, SIGNAL(triggered()), this, SLOT(fromFrToRo()));
    connect(actionRoToFr, SIGNAL(triggered()), this, SLOT(fromRoToFr()));

}

void TranslatorPlugin::fromEnToRo(){translateSelection("en", "ro");}
void TranslatorPlugin::fromRoToEn(){translateSelection("ro", "en");}
void TranslatorPlugin::fromRoToFr(){translateSelection("ro", "fr");}
void TranslatorPlugin::fromFrToRo(){translateSelection("fr", "ro");}
void TranslatorPlugin::translateSelection(const QString &from,const QString &to){
    auto editor = tabWidget->getCurrentTextEdit();
    QTextCursor cursor = editor->textCursor();
    if(!cursor.hasSelection()){ // daca nu exista text selectat, atunci se selecteaza tot textul

        QMessageBox::StandardButton resBtn = QMessageBox::question( editor,"TextEditor",
                                                                    tr("Do you want to apply this function for the entire text?\n"),
                                                                    QMessageBox::No | QMessageBox::Yes);
        if (resBtn == QMessageBox::Yes){  // the user selected "Yes" -> select the whole text
            cursor.movePosition(QTextCursor::Start);
            cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
            cursor.select(QTextCursor::LineUnderCursor);
        }
        else if(resBtn == QMessageBox::No){
            return;
        }
    }
    QString text = tabWidget->getCurrentTextEdit()->toPlainText();
    cursor.beginEditBlock(); // put remove and insert operations in the same block to not affect the QUndoStack
    cursor.removeSelectedText();  // remove the previous text
    cursor.insertText(translate(text, from, to));  // insert the modified text
    cursor.endEditBlock();
}
QString TranslatorPlugin::translate(const QString &text,const QString &from,const QString &to){
    QString filename = "plugins/TranslatorPlugin/translate.py";
    QString command = QString("python3 %1 %2 %3 %4").arg(filename).arg(text).arg(from).arg(to);
    qDebug() << "commnand:" << command << endl;
    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    process.start(command);
    process.waitForFinished(-1);
    QString output(process.readAllStandardOutput());
    output.chop(1); // ultimul caracter este mereu un '\n', lucru de care nu avem nevoie
    qDebug() << output << endl;

    return output;
}
