// Copyright 2021 Bobocea Laurentiu
#ifndef SRC_EDITORINTERFACE_H_
#define SRC_EDITORINTERFACE_H_
#include <QMenuBar>
#include <QToolBar>
#include "TabWidget.h"
#include "Theme.h"
#include "Availability.h"

class EditorInterface{
 public:
    /// Constructorul standard al interfetei
    virtual ~EditorInterface()= default;
    /// adauga in clasa plugin-ului pointeri catre diferite obiecte
    ///  din fereastra principala
    /// ce urmeaza sa fie folosite de plugin in functionalitatile sale
    virtual void setProperties(QMenuBar* menuBar = nullptr,
                               QToolBar* toolBar = nullptr,
                               TabWidget* tabWidget = nullptr,
                               Theme* theme = nullptr,
                               Availability* availability = nullptr) = 0;
    /// seteaza functionalitatile plugin-ului in aplicatia gazda pe baza
    ///  proprietatilor asignate in SetProperties. Acestea pot fi actiuni
    ///  adaugate in toolBar sau meniuBar
    /// sau conexiuni semnal-slot in tabWidget
    virtual void setActions() = 0;
    /// elimina efectele functiei setActions.
    virtual void disconnect() = 0;
};
QT_BEGIN_NAMESPACE
#define EditorInterface_iid "org.qt-project.Qt.Examples.EditorInterface"
Q_DECLARE_INTERFACE(EditorInterface, EditorInterface_iid)
QT_END_NAMESPACE

#endif  // SRC_EDITORINTERFACE_H_
