#ifndef TRANSLATORPLUGIN_H
#define TRANSLATORPLUGIN_H
#include "EditorInterface.h"
#include "Theme.h"
#include "TabWidget.h"
#include <QObject>
#include <QProcess>
#include <QtPlugin>
#include <QWidget>
#include <QAction>
class TranslatorPlugin : public QObject, EditorInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Examples.EditorInterface" FILE "translatorplugin.json")
    Q_INTERFACES(EditorInterface)
public:
   void setActions() override;
   void setProperties(QMenuBar* menuBar = nullptr,QToolBar* toolBar = nullptr,
                      TabWidget* tabWidget = nullptr, Theme* theme = nullptr) override;
   void translateSelection(const QString &from,const QString &to);
   QString translate(const QString &text,const QString &from,const QString &to);
private slots:
   void fromEnToRo();
   void fromRoToEn();
   void fromRoToFr();
   void fromFrToRo();
private:
    QAction* actionRoToEn;
    QAction* actionEnToRo;
    QAction* actionRoToFr;
    QAction* actionFrToRo;
    QMenuBar* menuBar;
    QToolBar* toolBar;
    TabWidget* tabWidget;
    Theme* theme;
};

#endif //TRANSLATORPLUGIN_H
