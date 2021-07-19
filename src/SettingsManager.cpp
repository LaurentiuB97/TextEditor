// Copyright 2021 Bobocea Laurentiu
#include "SettingsManager.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QString>
#include <QDebug>

SettingsManager::SettingsManager(QObject* parent) {
    theme = new Theme(this);
    this->setParent(parent);
}

void SettingsManager::LoadSettings() {
    // Incarcare setari
    QFile loadFile(file);
    if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Nu s-a putut deschide fisierul");
            return;
    }
    auto saveData = loadFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(saveData, &errorPtr);
    QJsonObject rootObj = doc.object();
    foreach(const QString& key, rootObj.keys()) {
        if (rootObj[key].isBool()) {
            actions.insert(key, rootObj[key].toBool());
        }
    }
    loadFile.close();
    // setare setari descarcate
    theme->setTheme(rootObj["Theme"].toString());
    // setare plugin-uri active
    auto array = rootObj["Active_Plugins"].toArray();
    for(auto item : array) {
        active_plugins.append(item.toString());
    }
}

void SettingsManager::setActions(QMenu* visibleMenu) {
    for (auto a : visibleMenu->actions()) {
        if (a->text().count() > 0) {
            for (auto& action : actions.keys()) {
                if (a->text() == action) {
                    a->setChecked(actions[action]);
                }
            }
        }
    }
}

void SettingsManager::saveSettings(QMenu* visibleMenu) {
    QJsonObject object;
    // Se preiau datele curente ce trebuie salvate
    object.insert("Theme", QJsonValue(theme->getCurrentTheme()));
    for (auto action : visibleMenu->actions()) {
        if (action->text().count() > 0) {
            object.insert(action->text(), QJsonValue(action->isChecked()));
        }
    }
    // salvare plugin-uri active
    QJsonArray array;
    qDebug() << "getActivePlugins:" << getActivePlugins().count() << endl;
    for(auto item : getActivePlugins()) {
        array.push_back(QJsonValue(item));
    }
    object.insert("Active_Plugins", QJsonValue(array));
    // se salveaza datele
    QJsonDocument doc;
    doc.setObject(object);
    QFile saveFile(file);
    saveFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    saveFile.write(doc.toJson());
    saveFile.close();
}

void SettingsManager::setActivePlugins(const QList<QString> &list) {
    active_plugins = list;
}

bool SettingsManager::isActive(const QString &plugin) {

    for(auto item : active_plugins){
        qDebug() << "Active Plugin: " << plugin << endl;
        if(item.compare(plugin) == 0){

            return true;
        }

    }
    return false;
}

QList<QString> SettingsManager::getActivePlugins() {
    return active_plugins;
}

Theme* SettingsManager::getTheme() {return theme;}
