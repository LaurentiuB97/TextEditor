#ifndef NATURALLAUNGUAGEPLUGIN_H
#define NATURALLAUNGUAGEPLUGIN_H
#include <iostream>
#include <QObject>
#include <QtPlugin>
#include <QAction>
#include <QPlainTextEdit>
#include <QString>
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

    void disconnect() override;

    void generateActions();

    void setIcons();

    void on_actionTrim_triggered();

    void on_actionPadding_triggered();

    void on_actionCapitalize_triggered();

    void on_actionLowercase_triggered();

    void on_actiondot_little_endian_triggered();

    void on_actionslash_little_endian_triggered();

    void on_actionline_little_endian_triggered();

    void on_actiondot_big_endian_triggered();

    void on_actionslash_big_endian_triggered();

    void on_actionline_big_endian_triggered();

    void on_actionCapitalize_toggled(bool arg);

    void on_actionLowercase_toggled(bool arg);

    void on_actionPadding_toggled(bool arg);

    void on_actionTrim_toggled(bool arg);

    void changeDatesInText(const StringManipulator::dateFormat format);

    QPlainTextEdit* getCurrentTextEdit();

    void modifyText(int (*function)(QString &text));

    QAction *actionCapitalize;
    QAction *actionLowercase;
    QAction *actionTrim;
    QAction *actionPadding;
    QAction *actiondot_little_endian;
    QAction *actionslash_little_endian;
    QAction *actionline_little_endian;
    QAction *actiondot_big_endian;
    QAction *actionslash_big_endian;
    QAction *actionline_big_endian;
    QAction* Capitalize_checker;
    QAction* Lowercase_checker;
    QAction* Padding_checker;
    QAction* Trim_checker;

private:
    QMenu* wordEdit;
    QMenuBar* menuBar;
    QToolBar* toolBar;
    QTabWidget* tabWidget;
    Theme* theme;
    Availability* availability;
    QList<QAction*> actions;
};



#endif //NATURALLAUNGUAGEPLUGIN_H
