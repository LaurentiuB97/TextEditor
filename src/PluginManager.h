// Copyright 2021 Bobocea Laurentiu
#ifndef SRC_PLUGINMANAGER_H_
#define SRC_PLUGINMANAGER_H_
#include "EditorInterface.h"
#include "Availability.h"
#include "Theme.h"
#include "TabWidget.h"
#include <QPluginLoader>
#include <QDir>
#include <QObject>
#include <QMap>
#include <QMenuBar>
#include <QToolBar>
#include "SettingsManager.h"

class PluginManager : public QObject {
    Q_OBJECT
 public:
    PluginManager();
    void setMembers(SettingsManager* settings, QMenuBar* menuBar = nullptr,
                    QToolBar* toolBar = nullptr,TabWidget* tabWidget = nullptr,
                    Theme* theme = nullptr);
    bool loadPlugin(const QString &fileName);
    int loadPlugins();
    int loadPlugins(const QStringList &list);
    void makeSetup();
    QMap<QString, EditorInterface*> getPlugins();
    QMap<QString, bool> getActivationStatus();
    void setActivationStatus(const QMap<QString, bool> &map);
    QString filterName(const QString &fullName);
 private:
    QMap<QString, EditorInterface*> plugins;
    QMap<QString, bool> activatedPlugins;
    SettingsManager* settings;
    EditorInterface* editorInterface;
    QMenuBar* menuBar;
    QToolBar* toolBar;
    TabWidget* tabWidget;
    Theme* theme;
    Availability* availability;
};

#endif  // SRC_PLUGINMANAGER_H_
