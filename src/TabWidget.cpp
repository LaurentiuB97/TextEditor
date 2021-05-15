#include "TabWidget.h"
#include <QtGui>
#include <QtWidgets>
#include <QDebug>
TabWidget::TabWidget(QWidget* parent){
    this->setParent(parent);
    this->setTabsClosable(true);
    //this->setTabsMovable(true);
}

TabWidget::~TabWidget(){}

void TabWidget::tabInserted(int index){
    emit newTabAdded(index);
}
void TabWidget::tabRemoved(int index){}

QPlainTextEdit* TabWidget::getEditor(int index){
    QPlainTextEdit* pTextEdit = NULL;
    QWidget* pWidget= this->widget(index);
    pTextEdit = (QPlainTextEdit*)pWidget;
    return pTextEdit;
}

QPlainTextEdit* TabWidget::getCurrentTextEdit(){
    QPlainTextEdit* pTextEdit = NULL;
    QWidget* pWidget= this->currentWidget();
    pTextEdit = (QPlainTextEdit*)pWidget;
    return pTextEdit;
}
