#include "WindowForm.h"
#include "StringManipulator.h"
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextStream>
#include <QTime>
#include <QFont>
#include <QPlainTextEdit>
#include <iostream>

WindowForm::WindowForm(QWidget *parent) : QWidget(parent) {
    parentLayout = new QVBoxLayout(this);
    toolLayout = new QHBoxLayout();
    textEdit = new QPlainTextEdit();
    // making the toolbar
    toolBar = new QToolBar();
    toolBar->addAction("File");
    toolBar->addAction("Edit");
    toolBar->addAction("About");
    // include the font layout into tool layout
    toolLayout->addWidget(toolBar,0, Qt::AlignLeft | Qt::AlignTop);
    // making font buttons
    fontLayout = new QHBoxLayout();
    // create and edit bold button
    bold = new QPushButton("B");
    bold->setFixedSize(20,20);
    bold->setContentsMargins(5,5,5,5);
    //create and edit italic button
    italic = new QPushButton("I");
    italic->setContentsMargins(5,5,5,5);
    italic->setFixedSize(20,20);
    //create and edit underline button
    underline = new QPushButton("U");
    underline->setFixedSize(20,20);
    underline->setContentsMargins(5,5,5,5);
    //adding the buttons to font layout
    toolLayout->addWidget(bold);
    toolLayout->addWidget(italic);
    toolLayout->addWidget(underline, 0, Qt::AlignLeft);
    
    //toolLayout->addLayout(fontLayout);
    // include the tool layout to the parent layout
    parentLayout->addLayout(toolLayout);
    parentLayout->addWidget(textEdit, 0, Qt::AlignBottom | Qt::AlignCenter);
    textEdit->setFixedSize(1200,1000);

}

WindowForm::~WindowForm() {
    delete parentLayout;
    delete textEdit;
    delete toolBar;
    delete toolLayout;
    delete fontLayout;
    delete bold;
    delete italic;
    delete underline;
}