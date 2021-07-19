// Copyright 2021 Bobocea Laurentiu
#include "CursorGroup.h"
#include <QDebug>
CursorGroup::CursorGroup(QObject *parent, QTabWidget *tabs,
                         QLabel *line, QLabel *collumn) : tabs(tabs),
                         line(line), collumn(collumn) {
    this->setParent(parent);
}
CursorGroup::~CursorGroup() {}

/// return pointerul catre aria de editare din tabul curent
QPlainTextEdit* CursorGroup::getCurrentTextEdit() {
    QPlainTextEdit* pTextEdit = NULL;
    // se ia pointerul catre obiectul curent de tip QPlainTextEdit
    QWidget* pWidget = tabs->currentWidget();
    // se converteste pointerul la QPlainTextEdit
    pTextEdit = (QPlainTextEdit*)pWidget;
    return pTextEdit;
}

/// pune in etichetele Line si Column coordonatele cursorului din editor
void CursorGroup::setLineAndCollumnForEditor(QPlainTextEdit* editor) {
    QTextCursor cursor = editor->textCursor();
    line->setText("Ln: " + QString::number(cursor.blockNumber()+1));
    collumn->setText("Cl: " + QString::number(cursor.positionInBlock()+1));
}
/// pune in etichetele Line si Column coordonatele cursorului din zona
/// de editare din tabul curent
void CursorGroup::setLineAndCollumn() {
    QTextCursor cursor = getCurrentTextEdit()->textCursor();
    line->setText("Ln: " + QString::number(cursor.blockNumber()+1));
    collumn->setText("Cl: " + QString::number(cursor.positionInBlock()+1));
}
/// realizeaza conexiunea intre aceasta clasa si obiectul editor
/// La fiecare schimbare a positiei cursorului, se va apela
///  metoda setLineAndCollumn
void CursorGroup::connectCursor(QPlainTextEdit* editor) {
    connect(editor, &QPlainTextEdit::cursorPositionChanged,
            this, &CursorGroup::setLineAndCollumn);
}

