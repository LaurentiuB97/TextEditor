#include "SettingsManager.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QString>
#include <QDebug>

SettingsManager::SettingsManager(QObject* parent){
    theme = new Theme(this);
    this->setParent(parent);
}

void SettingsManager::LoadSettings(){

    // Load settings
    QFile loadFile(file);
    if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
            return;
    }
    auto saveData = loadFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(saveData, &errorPtr);
    QJsonObject rootObj = doc.object();
    foreach(const QString& key, rootObj.keys()){
        if(rootObj[key].isBool()) {
            actions.insert(key, rootObj[key].toBool());
        }
    }
    loadFile.close();
    // set the loaded settings
    theme->setTheme(rootObj["Theme"].toString());
}

void SettingsManager::setActions(QMenu* visibleMenu){
    for(auto a : visibleMenu->actions())
    {
        if(a->text().count() > 0){
            for(auto& action : actions.keys()){
                if(a->text() == action){
                    a->setChecked(actions[action]);
                }

            }
        }
    }
}

void SettingsManager::saveSettings(QMenu* visibleMenu){
    QJsonObject object;
    // Se preiau datele curente ce trebuie salvate
    object.insert("Theme", QJsonValue(theme->getCurrentTheme()));
    for(auto action : visibleMenu->actions()){
        if(action->text().count() > 0){
            object.insert(action->text(), QJsonValue(action->isChecked()));
        }
    }
    // se salveaza datele
    QJsonDocument doc;
    doc.setObject(object);
    QFile saveFile(file);
    saveFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    saveFile.write(doc.toJson());
    saveFile.close();

}

Theme* SettingsManager::getTheme(){return theme;}
