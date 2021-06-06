#include <QObject>
#include <QWidget>
#include <QtPlugin>
#include "EditorInterface.h"
#include "HighLighter.h"
#include "Theme.h"
#include "TabWidget.h"
#include "Availability.h"

class CppPlugin : public QObject, EditorInterface{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Examples.EditorInterface" FILE "cppplugin.json")
    Q_INTERFACES(EditorInterface)

 public:
    void setActions() override;
    void setProperties(QMenuBar* menuBar = nullptr,QToolBar* toolBar = nullptr,
                       TabWidget* tabWidget = nullptr, Theme* theme = nullptr,
                       Availability* availability = nullptr) override;
    void highlightText();
 protected slots:
    void setNewConnection(int index);
 private:
    QMenuBar* menuBar;
    QToolBar* toolBar;
    TabWidget* tabWidget;
    Theme* theme;
    Availability* availability;
    HighLighter highlighter;
};
