#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H
#include "EditorInterface.h"
#include "Theme.h"
#include "TabWidget.h"
#include <QPluginLoader>
#include <QDir>
#include <QObject>
#include <QMap>
#include <QMenuBar>
#include <QToolBar>

class PluginManager : public QObject{
    Q_OBJECT
public:
    PluginManager();
    void setMembers(QMenuBar* menuBar = nullptr,QToolBar* toolBar = nullptr,
                    TabWidget* tabWidget = nullptr, Theme* theme = nullptr);
    bool loadPlugin(const QString &fileName);
    int loadPlugins();
    int loadPlugins(const QStringList &list);
    void makeSetup();
    QString filterName(const QString &fullName);
private:
    QMap<QString, EditorInterface*> plugins;
    EditorInterface* editorInterface;
    QMenuBar* menuBar;
    QToolBar* toolBar;
    TabWidget* tabWidget;
    Theme* theme;
};

#endif //PLUGINMANAGER_H
