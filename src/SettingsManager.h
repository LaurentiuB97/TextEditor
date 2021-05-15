#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H
#include "Theme.h"
#include <QObject>
#include <QMap>
#include <QString>
#include <QMenu>
class SettingsManager : public QObject{
    Q_OBJECT

public:
    SettingsManager(QObject* parent = nullptr);
    void LoadSettings();
    void setActions(QMenu* visibleMenu);
    void saveSettings(QMenu* visibleMenu);
    Theme* getTheme();
private:
    QString file = "config.json";
    Theme* theme;
    QMap<QString, bool> actions;
};
#endif //SETTINGS_MANAGER_H
