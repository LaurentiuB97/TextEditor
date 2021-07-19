// Copyright 2021 Bobocea Laurentiu
#include "PluginManager.h"
#include <QDebug>
#include <QCoreApplication>



PluginManager::PluginManager() {}

void PluginManager::setMembers(SettingsManager* settings, QMenuBar* menuBar, QToolBar* toolBar,
                               TabWidget* tabWidget, Theme* theme) {
    this->menuBar = menuBar;
    this->toolBar = toolBar;
    this->tabWidget = tabWidget;
    this->theme = theme;
    this->availability = new Availability(this);
    availability->setAvailabilityStatus(true);
    this->settings = settings;
}
bool PluginManager::loadPlugin(const QString &fileName) {
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    qDebug() << "FileName : " << fileName << endl;
    QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));

    QObject *plugin = pluginLoader.instance();

    if (plugin) {
        editorInterface = qobject_cast<EditorInterface *>(plugin);
        if (editorInterface) {
            // facem "instalarea pluginului"
            editorInterface->setProperties(menuBar, toolBar, tabWidget,
                                           theme, availability);
            // adaugam obiectul in lista de plugin-uri
            plugins.insert(filterName(fileName), editorInterface);
            // adaugam numele plugin-ului in numele plugin-urilor active
            if(settings->isActive(filterName(fileName))) {
                editorInterface->setActions(); // doar in acest caz se instaleaza plugin-ul
                activatedPlugins.insert(filterName(fileName), true);
            } else {
                activatedPlugins.insert(filterName(fileName), false);
            }
            return true;
        }
        // pluginLoader.unload();
    }
    return false;
}

int  PluginManager::loadPlugins() {
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    const QStringList entries = pluginsDir.entryList(QDir::Files);
    int loaded = 0;
    for (const QString &fileName : entries) {
        if (loadPlugin(fileName)) {
            loaded++;
        }
    }
    return loaded;
}

int PluginManager::loadPlugins(const QStringList &list) {
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    int loaded = 0;
    const QStringList entries = pluginsDir.entryList(QDir::Files);
    for (const QString &name : list) {
        for (QString fullname : entries) {
            if (filterName(fullname).compare(name) == 0) {
                if (loadPlugin(fullname)) {
                    loaded++;
                }
            }
        }
    }
    return loaded;
}

QMap<QString, EditorInterface*> PluginManager::getPlugins() {
    return plugins;
}

QMap<QString, bool> PluginManager::getActivationStatus() {
    return activatedPlugins;
}

void PluginManager::setActivationStatus(const QMap<QString, bool> &map) {
    activatedPlugins = map;
    // salvare setari in clasa SettingsManager pentru salvare
    QList<QString> list;
    for(QString key : activatedPlugins.keys()) {
        // se extrag doar valorile active
        if(activatedPlugins[key] == true) {
            list.append(key);
        }
    }

    settings->setActivePlugins(list);
    qDebug() << "List " << settings->getActivePlugins().count() << endl;
}

QString PluginManager::filterName(const QString &fullName) {
    auto tokens = fullName.split("/");  // scapam de calea
    QString temp = tokens[tokens.count()-1];  // ultimul element
    temp.remove(0, 3);  // indepartam prefixul lib din nume
    temp.chop(3);  // indepartam extensia ".so"
    return temp;
}
