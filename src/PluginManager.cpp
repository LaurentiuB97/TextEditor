#include "PluginManager.h"
#include <QDebug>
#include <QCoreApplication>



PluginManager::PluginManager(){}

void PluginManager::setMembers(QMenuBar* menuBar,QToolBar* toolBar,
                               TabWidget* tabWidget, Theme* theme){
    this->menuBar = menuBar;
    this->toolBar = toolBar;
    this->tabWidget = tabWidget;
    this->theme = theme;
}
bool PluginManager::loadPlugin(const QString &fileName){
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    qDebug() << "FileName : " << fileName << endl;
    QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));

    QObject *plugin = pluginLoader.instance();

    if (plugin) {
        editorInterface = qobject_cast<EditorInterface *>(plugin);
        if (editorInterface){
            // facem "instalarea pluginului"
            editorInterface->setProperties(menuBar,toolBar, tabWidget, theme);
            editorInterface->setActions();
            // adaugam obiectul in
            plugins.insert(filterName(fileName), editorInterface);

            return true;
        }

        //pluginLoader.unload();
    }
    return false;
}

int  PluginManager::loadPlugins(){
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    const QStringList entries = pluginsDir.entryList(QDir::Files);
    int loaded = 0;
    for(const QString &fileName : entries) {
        if(loadPlugin(fileName)){
            loaded++;
        }
    }
    return loaded;
}

int PluginManager::loadPlugins(const QStringList &list){
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    int loaded = 0;
    const QStringList entries = pluginsDir.entryList(QDir::Files);
    for(const QString &name : list){
        for(QString fullname : entries){
            if(filterName(fullname).compare(name) == 0){
                if(loadPlugin(fullname)){
                    loaded++;
                }
            }
        }
    }
    return loaded;
}


QString PluginManager::filterName(const QString &fullName){
    auto tokens = fullName.split("/");// scapam de calea
    QString temp = tokens[tokens.count()-1]; // ultimul element
    temp.remove(0,3); // indepartam prefixul lib din nume
    temp.chop(3); // indepartam extensia ".so"
    return temp;
}
