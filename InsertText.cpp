#include "InsertText.h"
#include <iostream>
#include <QTextCursor>
InsertText::InsertText(QPlainTextEdit* editor, const QString &text,
                       const QString &delimiter, QUndoCommand *parent)
        : m_editor(editor), m_text(text), m_delimiter(delimiter), QUndoCommand(parent)
{

}
void InsertText::undo()
{
    for(int i = m_text.length()-2; i >= 0; --i)
    {
        if((i == 0) || (m_text[i] == " ") || (m_text[i] == ","))
        {
            oldText = m_text.left(i);
            break;
        }
    }
    m_editor->setPlainText(oldText);
    QTextCursor cursor = m_editor->textCursor();
    cursor.setPosition(oldText.length());
    m_editor->setTextCursor(cursor);
}
void InsertText::redo()
{
    m_editor->setPlainText(m_text + m_delimiter);
    QTextCursor cursor = m_editor->textCursor();
    cursor.setPosition(m_text.length() + 1);
    m_editor->setTextCursor(cursor);
}
