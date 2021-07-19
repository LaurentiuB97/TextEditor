// Copyright 2021 Bobocea Laurentiu
#ifndef SRC_SETTINGSMANAGER_H_
#define SRC_SETTINGSMANAGER_H_
#include "Theme.h"
#include <QObject>
#include <QMap>
#include <QString>
#include <QMenu>
class SettingsManager : public QObject {
    Q_OBJECT

 public:
    explicit SettingsManager(QObject* parent = nullptr);
    void LoadSettings();
    void setActions(QMenu* visibleMenu);
    void saveSettings(QMenu* visibleMenu);
    void setActivePlugins(const QList<QString> &list);
    bool isActive(const QString &plugin);
    QList<QString> getActivePlugins();
    Theme* getTheme();
 private:
    QString file = "config.json";
    Theme* theme;
    QMap<QString, bool> actions;
    QList<QString> active_plugins;
};
#endif  // SRC_SETTINGSMANAGER_H_
