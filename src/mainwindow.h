#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TextHighLight.h"
#include "HighLighter.h"
#include "StringManipulator.h"
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

    void changeDatesInText(const StringManipulator::dateFormat format);

    void setAppearance(mode selected_mode);

    void addToUndoStack();

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

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionUnderline_triggered();

    void on_actionTrim_triggered();

    void on_actionPadding_triggered();

    void on_actionCapitalize_triggered();

    void on_FindButton_clicked();

    void on_actionFind_triggered();

    void on_previous_clicked();

    void on_next_clicked();

    void on_exitFind_clicked();

    void on_actiondot_little_endian_triggered();

    void on_actionslash_little_endian_triggered();

    void on_actionline_little_endian_triggered();

    void on_actiondot_big_endian_triggered();

    void on_actionslash_big_endian_triggered();

    void on_actionline_big_endian_triggered();

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

    void on_actionTrim_2_toggled(bool arg1);

    void on_actionPadding_2_toggled(bool arg1);

    void on_actionCapitalize_2_toggled(bool arg1);

    void on_actionDefault_toggled(bool arg1);

    void on_actionDark_Mode_toggled(bool arg1);

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QUndoGroup* undoGroup;
    QString currentFile = "";
    std::vector<TextHighLight> findResults;
    int indexFindResults;
    //bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MAINWINDOW_H
