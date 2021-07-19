#include "TranslatorPlugin.h"
#include <QMessageBox>
#include <QDebug>
void TranslatorPlugin::setProperties(QMenuBar* menuBar,QToolBar* toolBar,
                       TabWidget* tabWidget, Theme* theme,
                       Availability* availability){
    this->menuBar = menuBar;
    this->tabWidget = tabWidget;
    this->theme = theme;
    this->toolBar = toolBar;
    this->availability = availability;
}

void TranslatorPlugin::setActions(){
    translateMenu = new QMenu("Traducere", menuBar);
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

void TranslatorPlugin::disconnect(){
    translateMenu->deleteLater();
}

void TranslatorPlugin::fromEnToRo(){translateSelection("en", "ro");}
void TranslatorPlugin::fromRoToEn(){translateSelection("ro", "en");}
void TranslatorPlugin::fromRoToFr(){translateSelection("ro", "fr");}
void TranslatorPlugin::fromFrToRo(){translateSelection("fr", "ro");}
void TranslatorPlugin::translateSelection(const QString &from,const QString &to){
    availability->setAvailabilityStatus(false);// blocam alte plugin-uri, sa nu existe interferente
    auto editor = tabWidget->getCurrentTextEdit();
    QTextCursor cursor = editor->textCursor();
    if(!cursor.hasSelection()){ // daca nu exista text selectat, atunci se selecteaza tot textul

        QMessageBox::StandardButton resBtn = QMessageBox::question( editor,"TextEditor",
                                                                    tr("Doriți să aplicați această funcție pentru tot textul?\n"),
                                                                    QMessageBox::No | QMessageBox::Yes);
        if (resBtn == QMessageBox::Yes){  // utilizatorul a selectat "Yes" -> se selecteaz[ tot textul.
            editor->selectAll();
            cursor = editor->textCursor();
        }
        else if(resBtn == QMessageBox::No){
            return;
        }
    }
    QString text = cursor.selectedText();
    if(text.count() == 0){
        QMessageBox::warning(editor, "Warning", tr("Text nul!"));
        return;
    }
    cursor.beginEditBlock(); // punem tot procesul intr-un singur bloc pentru a creea doar o singura comanda de Refacere
    cursor.removeSelectedText();  // se sterge vechiul textul existent in zona de editare
    cursor.insertText(translate(text, from, to));  // se insereaza noul text
    cursor.endEditBlock(); // sfarsit bloc
    availability->setAvailabilityStatus(true); // permitem din nou celorlalte plugin-uri sa se defasoare fara restrictii
}
QString TranslatorPlugin::translate(const QString &text,const QString &from,const QString &to){
    QString filename = "plugins/TranslatorPlugin/translate.py";
    QString command = QString("python3 %1 \"%2\" %3 %4").arg(filename).arg(text).arg(from).arg(to);
    //qDebug() << "commnand:" << command << endl;
    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    process.start(command);
    process.waitForFinished(-1);
    QString output(process.readAllStandardOutput());
    output.chop(1); // ultimul caracter este mereu un '\n', lucru de care nu avem nevoie
    //qDebug() << output << endl;

    return output;
}
