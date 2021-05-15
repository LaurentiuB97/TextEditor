#ifndef TABWIDGET_H
#define TABWIDGET_H
#include <QTabWidget>
#include <QPlainTextEdit>
class TabWidget : public QTabWidget{
    Q_OBJECT
signals:
    void newTabAdded(int index);
public:
    TabWidget(QWidget* parent = nullptr);
    void tabInserted(int index);
    void tabRemoved(int index);
    QPlainTextEdit* getEditor(int index);
    QPlainTextEdit* getCurrentTextEdit();
private:
    ~TabWidget();
};

#endif //TABWIDGET_H
