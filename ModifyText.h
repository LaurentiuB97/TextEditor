#ifndef MODIFYTEXT_H
#define MODIFYTEXT_H
#include <QUndoCommand>
#include <QPlainTextEdit>
class ModifyText : public QUndoCommand
{
public:
    ModifyText(QPlainTextEdit* editor,const QString &oldText,
               const QString &newText, QUndoCommand* parent = nullptr);
    void undo() override;
    void redo() override;
private:
    QString m_oldText, m_newText;
    QPlainTextEdit* m_editor;
};

#endif  // MODIFYTEXT_H
