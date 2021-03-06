#ifndef NATURALLAUNGUAGEPLUGIN_H
#define NATURALLAUNGUAGEPLUGIN_H
#include <iostream>
#include <QObject>
#include <QtPlugin>
#include <QAction>
#include <QPlainTextEdit>
#include "EditorInterface.h"
#include "StringManipulator.h"
#include "Theme.h"
#include "TabWidget.h"
#include "Availability.h"

class NaturalLanguagePlugin : public QObject, EditorInterface{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Examples.EditorInterface" FILE "naturallanguageplugin.json")
    Q_INTERFACES(EditorInterface)

public:
    void setActions() override;

    void setProperties(QMenuBar* menuBar = nullptr,QToolBar* toolBar = nullptr,
                       TabWidget* tabWidget = nullptr, Theme* theme = nullptr,
                       Availability* availability = nullptr) override;

    void setIcons();

    void on_actionTrim_triggered();

    void on_actionPadding_triggered();

    void on_actionCapitalize_triggered();

    void on_actiondot_little_endian_triggered();

    void on_actionslash_little_endian_triggered();

    void on_actionline_little_endian_triggered();

    void on_actiondot_big_endian_triggered();

    void on_actionslash_big_endian_triggered();

    void on_actionline_big_endian_triggered();

    void changeDatesInText(const StringManipulator::dateFormat format);

    QPlainTextEdit* getCurrentTextEdit();

    void modifyText(int (*function)(std::string &text));

    QAction *actionCapitalize;
    QAction *actionTrim;
    QAction *actionPadding;
    QAction *actiondot_little_endian;
    QAction *actionslash_little_endian;
    QAction *actionline_little_endian;
    QAction *actiondot_big_endian;
    QAction *actionslash_big_endian;
    QAction *actionline_big_endian;
private:
    QMenuBar* menuBar;
    QToolBar* toolBar;
    QTabWidget* tabWidget;
    Theme* theme;
    Availability* availability;
    QList<QAction*> actions;
};



#endif //NATURALLAUNGUAGEPLUGIN_H
