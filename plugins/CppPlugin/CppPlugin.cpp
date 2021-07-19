#include "CppPlugin.h"
#include <QObject>
#include <QWidget>
#include <QDebug>
void CppPlugin::setProperties(QMenuBar* menuBar,QToolBar* toolBar,
                       TabWidget* tabWidget, Theme* theme,
                       Availability* availability){
    this->menuBar = menuBar;
    this->tabWidget = tabWidget;
    this->theme = theme;
    this->toolBar = toolBar;
    this->availability = availability;
}

void CppPlugin::setActions(){
    //incarcare culori din fisiere
    highlighter.loadKeyWords();
    highlighter.loadTypes();
    highlighter.loadDirectives();
    //conectare taburi existente
    for(int i = 0; i < tabWidget->count();i++){
        QPlainTextEdit* editor = tabWidget->getEditor(i);
        connect(editor, &QPlainTextEdit::textChanged, this, &CppPlugin::highlightText);
    }
    // conectare taburi viitoare
    connect(tabWidget, SIGNAL(newTabAdded(int)), this, SLOT(setNewConnection(int)));
    
}

void CppPlugin::setNewConnection(int index){
    auto editor = tabWidget->getEditor(index);
    connect(editor, &QPlainTextEdit::textChanged, this, &CppPlugin::highlightText);
}

void CppPlugin::disconnect(){
    // deconectam tabWidget pentru a nu mai face conexiuni la taburile viitoare
    QObject::disconnect(tabWidget, SIGNAL(newTabAdded(int)), this, SLOT(setNewConnection(int)));
    // deconectam taburile deja existente
    for(int i = 0; i < tabWidget->count();i++){
        QPlainTextEdit* editor = tabWidget->getEditor(i);
        QObject::disconnect(editor, &QPlainTextEdit::textChanged, this, &CppPlugin::highlightText);
    }

}

void CppPlugin::highlightText(){
    if(availability->getAvailabilityStatus()){
        auto edit = tabWidget->getCurrentTextEdit();
        QList<QPair<QString, QList<TextHighLight>>> list;
        QColor keywords_color(204,0,204);
        QColor types_color(0,255,255);
        QColor string_color(128,96,77);
        QColor comments_color(246,195,36);
        QColor function_color(50,205,50);

        list.append(qMakePair(comments_color.name(), highlighter.findComments(edit)));
        list.append(qMakePair(string_color.name(), highlighter.findString(edit)));
        list.append(qMakePair(function_color.name(), highlighter.findFunctions(edit)));
        list.append(qMakePair(keywords_color.name(), highlighter.findDirectives(edit)));
        list.append(qMakePair(keywords_color.name(), highlighter.findKeyWords(edit)));
        list.append(qMakePair(types_color.name(), highlighter.findTypes(edit)));

        highlighter.colorTargets(list, edit);
    }
}
