#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H
#include "Theme.h"
#include <QMap>
#include <QString>
#include <QMenu>
class SettingsManager{
public:
    SettingsManager();
    ~SettingsManager();
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
