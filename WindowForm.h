#ifndef WINDOW_FORM_H
#define WINDOW_FORM_H
#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QToolBar>
#include <QString>
class WindowForm : public QWidget {
 public:
    WindowForm(QWidget *parent = 0);
    ~WindowForm();
 private:
   QVBoxLayout *parentLayout;
   QHBoxLayout *toolLayout;
   QHBoxLayout *fontLayout;
   QPlainTextEdit *textEdit;
   QToolBar *toolBar;
   QPushButton *bold, *italic, *underline; 
 
};

#endif