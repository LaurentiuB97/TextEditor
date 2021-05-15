#ifndef CURSORGROUP_H
#define CURSORGROUP_H
#include <QObject>
#include <QTabWidget>
#include <QPlainTextEdit>
#include <QLabel>
#include <QMap>
class CursorGroup : public QObject{
    Q_OBJECT
public:
    CursorGroup(QObject *parent, QTabWidget *tabs, QLabel *line, QLabel *collumn);
    QPlainTextEdit* getCurrentTextEdit();
    void setLineAndCollumn();
    void setLineAndCollumnForEditor(QPlainTextEdit* editor);
    void setActiveCursor();
    void connectCursor(QPlainTextEdit* editor);
private:
    ~CursorGroup();
    QTabWidget *tabs;
    QLabel *line;
    QLabel *collumn;

};


#endif //CURSORGROUP_H
