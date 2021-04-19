#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TextHighLight.h"
#include "HighLighter.h"
#include "StringManipulator.h"
#include "SettingsManager.h"
#include "EditorInterface.h"
#include <vector>
//#include <bits/stdc++.h>  // for function as a parameter
#include <QMainWindow>
#include <QFile>
#include <QUndoGroup>
#include <QTextCursor>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QPlainTextEdit>
#include <QMap>
#include <QColor>
#include <QPluginLoader>
const int default_format = 0;
const int colored_format = 1;
const int do_not_delete_find_box_text = 0;
const int delete_find_box_text = 1;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum mode {default_mode, dark_mode};

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void setHighLight(const TextHighLight &highlight, const int requiredFormat = colored_format);

    void modifyText(int (*function)(std::string &text));

    void setAppearance(QString name_mode);

    void addToUndoStack();

    void manageChangedText();

    void highlightText();

    void StackOn();

    void StackOff();

    QPlainTextEdit* getCurrentTextEdit();

    QPlainTextEdit* getTextEditByName(const QString &name);


//    void writeOnLine();

//    void writeOnColumn();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_2_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionUnderline_triggered();

    void on_FindButton_clicked();

    void on_actionFind_triggered();

    void on_previous_clicked();

    void on_next_clicked();

    void on_exitFind_clicked();

    void on_FindRegexButton_clicked();

    void on_actionFind_regex_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionNew_2_toggled(bool arg1);

    void on_actionOpen_2_toggled(bool arg1);

    void on_actionSave_2_toggled(bool arg1);

    void on_actionCut_2_toggled(bool arg1);

    void on_actionCopy_2_toggled(bool arg1);

    void on_actionPaste_2_toggled(bool arg1);

    void on_actionUndo_2_toggled(bool arg1);

    void on_actionRedo_2_toggled(bool arg1);

    void on_actionDefault_toggled(bool arg1);

    void on_actionDarkMode_toggled(bool arg1);

    void on_tabWidget_currentChanged(int index);

    void closeEvent(QCloseEvent *event);

    void on_actionReplace_triggered();

    void on_actionIndent_forward_triggered();

    void on_actionIndent_backward_triggered();

    bool loadPlugin();



private:
    Ui::MainWindow *ui;
    QMap<QString, QFile*> filesList;
    QUndoGroup* undoGroup;
    QString currentFile = "";
    std::vector<TextHighLight> findResults;
    int indexFindResults;
    HighLighter highlighter;
    SettingsManager st;
    EditorInterface* editorInterface;
    //bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MAINWINDOW_H
