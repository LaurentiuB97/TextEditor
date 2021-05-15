#include "CppPlugin.h"
#include <QObject>
#include <QWidget>
#include <QDebug>
void CppPlugin::setProperties(QMenuBar* menuBar,QToolBar* toolBar,
                       TabWidget* tabWidget, Theme* theme){
    this->menuBar = menuBar;
    this->tabWidget = tabWidget;
    this->theme = theme;
    this->toolBar = toolBar;
}

void CppPlugin::setActions(){
        //load highlights
    highlighter.loadKeyWords();
    highlighter.loadTypes();
    
    connect(tabWidget, SIGNAL(newTabAdded(int)), this, SLOT(setNewConnection(int)));
    
}

void CppPlugin::setNewConnection(int index){
    auto editor = tabWidget->getEditor(index);
    connect(editor, &QPlainTextEdit::textChanged, this, &CppPlugin::highlightText);
}

void CppPlugin::highlightText(){
    auto edit = tabWidget->getCurrentTextEdit();
    QMap<QString, QList<TextHighLight>> map;
    QColor keywords_color(204,204,0);
    QColor types_color(51,51,255);
    QColor string_color(139,69,19);
    map.insert(keywords_color.name(), highlighter.findKeyWords(edit));
    map.insert(types_color.name(), highlighter.findTypes(edit));
    map.insert(string_color.name(), highlighter.findString(edit));
    highlighter.colorTargets(map, edit);
}
