#ifndef EDITORINTERFACE_H
#define EDITORINTERFACE_H
#include <QMenuBar>
#include <QTabWidget>
#include "Theme.h"

class EditorInterface{
public:
    virtual ~EditorInterface()= default;
    virtual void setProperties(QMenuBar* menuBar, QTabWidget* tabWidget, Theme* theme) = 0;
    virtual void setActions() = 0;
};


QT_BEGIN_NAMESPACE

#define EditorInterface_iid "org.qt-project.Qt.Examples.EditorInterface"

Q_DECLARE_INTERFACE(EditorInterface, EditorInterface_iid)

QT_END_NAMESPACE

#endif //PLUGININTEDITORINTERFACE_HERFACE_H
