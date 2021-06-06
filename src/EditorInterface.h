#ifndef EDITORINTERFACE_H
#define EDITORINTERFACE_H
#include <QMenuBar>
#include <QToolBar>
#include "TabWidget.h"
#include "Theme.h"
#include "Availability.h"

class EditorInterface{
public:
    virtual ~EditorInterface()= default;
    virtual void setProperties(QMenuBar* menuBar = nullptr,QToolBar* toolBar = nullptr,
                               TabWidget* tabWidget = nullptr, Theme* theme = nullptr,
                               Availability* availability = nullptr) = 0;
    virtual void setActions() = 0;
};


QT_BEGIN_NAMESPACE

#define EditorInterface_iid "org.qt-project.Qt.Examples.EditorInterface"

Q_DECLARE_INTERFACE(EditorInterface, EditorInterface_iid)

QT_END_NAMESPACE

#endif //PLUGININTEDITORINTERFACE_HERFACE_H
