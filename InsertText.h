#ifndef INSERTTEXT_H
#define INSERTTEXT_H
#include <QUndoCommand>
#include <QUndoStack>
#include <QPlainTextEdit>
#include <QString>

class InsertText : public QUndoCommand
{
public:
    InsertText(QPlainTextEdit* editor, const QString &text,
               const QString &delimiter, QUndoCommand *parent = nullptr);
    void undo() override;
    void redo() override;
    QString getCurrentText();
private:
        QPlainTextEdit *m_editor;
        QString m_text, m_delimiter, oldText;
};

#endif  //INSERTTEXT_H
