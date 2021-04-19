#ifndef MODIFYTEXT_H
#define MODIFYTEXT_H
#include <QUndoCommand>
#include <QPlainTextEdit>
class ModifyText : public QUndoCommand
{
public:
    ModifyText(QPlainTextEdit* editor,const QString &oldText, int old_cursor_position,
               const QString &newText,int new_cursor_position, const QUndoCommand* previous = nullptr,
               QUndoCommand* parent = nullptr);
    void undo() override;
    void redo() override;
    int getOldCursorPosition();
    int getNewCursorPosition();
private:
    QString m_oldText, m_newText;
    int old_cursor_position, new_cursor_position;
    QPlainTextEdit* m_editor;
    QUndoCommand* previous;
};

#endif  // MODIFYTEXT_H
