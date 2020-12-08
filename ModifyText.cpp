#include "ModifyText.h"

ModifyText::ModifyText(QPlainTextEdit* editor, const QString &oldText,
                       const QString &newText,QUndoCommand* parent)
    : m_editor(editor), m_oldText(oldText), m_newText(newText), QUndoCommand(parent){ setText("modify text");}
void ModifyText::undo()
{
    m_editor->setPlainText(m_oldText);
}
void ModifyText::redo()
{
    m_editor->setPlainText(m_newText);
}
