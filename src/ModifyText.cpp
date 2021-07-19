// Copyright 2021 Bobocea Laurentiu
#include "ModifyText.h"
#include <iostream>
ModifyText::ModifyText(QPlainTextEdit* editor,
                       const QString &oldText,
                       int old_cursor_position,
                       const QString &newText,
                       int new_cursor_position,
                       const QUndoCommand* previous,
                       QUndoCommand* parent)
    : m_editor(editor), m_oldText(oldText),
      old_cursor_position(old_cursor_position),
      m_newText(newText), new_cursor_position(new_cursor_position),
      QUndoCommand(parent) {
    setText(oldText);
}

void ModifyText::undo() {
    // setare text
    m_editor->setPlainText(m_oldText);
    // pune cursorul in pozitie
    QTextCursor cursor = m_editor->textCursor();
    cursor.setPosition(getOldCursorPosition());
    m_editor->setTextCursor(cursor);
}

void ModifyText::redo() {
    // setare text
    m_editor->setPlainText(m_newText);
    // pune cursorul in pozitie
    QTextCursor cursor = m_editor->textCursor();
    cursor.setPosition(getNewCursorPosition());
    m_editor->setTextCursor(cursor);
}

int ModifyText::getOldCursorPosition() {
    return old_cursor_position;
}

int ModifyText::getNewCursorPosition() {
    return new_cursor_position;
}
