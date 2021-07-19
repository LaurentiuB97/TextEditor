// Copyright 2021 Bobocea Laurentiu
#ifndef SRC_MODIFYTEXT_H_
#define SRC_MODIFYTEXT_H_
#include <QUndoCommand>
#include <QPlainTextEdit>
class ModifyText : public QUndoCommand {
 public:
    ModifyText(QPlainTextEdit* editor,
               const QString &oldText,
               int old_cursor_position,
               const QString &newText,
               int new_cursor_position,
               const QUndoCommand* previous = nullptr,
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

#endif  // SRC_MODIFYTEXT_H_
