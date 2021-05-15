#include "CursorGroup.h"
#include <QDebug>
//CursorGroup::CursorGroup(){}
CursorGroup::CursorGroup(QObject *parent, QTabWidget *tabs,
                         QLabel *line, QLabel *collumn) : tabs(tabs), line(line), collumn(collumn){
    this->setParent(parent);
    //conectare tab-nou : adaugare editor

}
CursorGroup::~CursorGroup(){}

QPlainTextEdit* CursorGroup::getCurrentTextEdit(){
    QPlainTextEdit* pTextEdit = NULL;
    QWidget* pWidget= tabs->currentWidget();
    pTextEdit = (QPlainTextEdit*)pWidget;
    return pTextEdit;
}

void CursorGroup::setLineAndCollumnForEditor(QPlainTextEdit* editor){
    QTextCursor cursor = editor->textCursor();
    line->setText("Ln: " + QString::number(cursor.blockNumber()));
    collumn->setText("Cl: " + QString::number(cursor.positionInBlock()));

}
void CursorGroup::setLineAndCollumn(){
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    line->setText("Ln: " + QString::number(cursor.blockNumber()));
    collumn->setText("Cl: " + QString::number(cursor.positionInBlock()));
}

void CursorGroup::connectCursor(QPlainTextEdit* editor){
    //QPlainTextEdit* editor = (QPlainTextEdit*)tabs->cornerWidget(Qt::TopRightCorner);
    connect(editor, &QPlainTextEdit::cursorPositionChanged, this, &CursorGroup::setLineAndCollumn);
}

