/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionRedo;
    QAction *actionUndo;
    QAction *actionFind;
    QAction *actionFind_regex;
    QAction *actionBold;
    QAction *actionItalic;
    QAction *actionUnderline;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionNew_2;
    QAction *actionOpen_2;
    QAction *actionSave_2;
    QAction *actionCut_2;
    QAction *actionCopy_2;
    QAction *actionPaste_2;
    QAction *actionUndo_2;
    QAction *actionRedo_2;
    QAction *actionDefault;
    QAction *actionDarkMode;
    QAction *actionReplace;
    QAction *actionIndent_forward;
    QAction *actionIndent_backward;
    QAction *actionCapitalize;
    QAction *actionPadding;
    QAction *actionTrim;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QPushButton *FindButton;
    QPushButton *FindRegexButton;
    QLineEdit *findTextBox;
    QPushButton *previous;
    QPushButton *next;
    QPushButton *exitFind;
    QLabel *findResultsLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuFind;
    QMenu *menuHelp;
    QMenu *menuPreferences;
    QMenu *menuVisible_actions;
    QMenu *menuTheme;
    QMenu *menuPlugins;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1178, 659);
        MainWindow->setMinimumSize(QSize(1001, 512));
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        MainWindow->setPalette(palette);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon3);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon4);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon5);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon6);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon7);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QStringLiteral("actionFind"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/icons/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon8);
        actionFind_regex = new QAction(MainWindow);
        actionFind_regex->setObjectName(QStringLiteral("actionFind_regex"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/icons/find_regex.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind_regex->setIcon(icon9);
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QStringLiteral("actionBold"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/icons/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon10);
        actionItalic = new QAction(MainWindow);
        actionItalic->setObjectName(QStringLiteral("actionItalic"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/icons/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon11);
        actionUnderline = new QAction(MainWindow);
        actionUnderline->setObjectName(QStringLiteral("actionUnderline"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/icons/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderline->setIcon(icon12);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icons/icons/exit.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon13);
        actionNew_2 = new QAction(MainWindow);
        actionNew_2->setObjectName(QStringLiteral("actionNew_2"));
        actionNew_2->setCheckable(true);
        actionNew_2->setChecked(true);
        actionOpen_2 = new QAction(MainWindow);
        actionOpen_2->setObjectName(QStringLiteral("actionOpen_2"));
        actionOpen_2->setCheckable(true);
        actionOpen_2->setChecked(true);
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QStringLiteral("actionSave_2"));
        actionSave_2->setCheckable(true);
        actionSave_2->setChecked(true);
        actionCut_2 = new QAction(MainWindow);
        actionCut_2->setObjectName(QStringLiteral("actionCut_2"));
        actionCut_2->setCheckable(true);
        actionCut_2->setChecked(true);
        actionCopy_2 = new QAction(MainWindow);
        actionCopy_2->setObjectName(QStringLiteral("actionCopy_2"));
        actionCopy_2->setCheckable(true);
        actionCopy_2->setChecked(true);
        actionPaste_2 = new QAction(MainWindow);
        actionPaste_2->setObjectName(QStringLiteral("actionPaste_2"));
        actionPaste_2->setCheckable(true);
        actionPaste_2->setChecked(true);
        actionUndo_2 = new QAction(MainWindow);
        actionUndo_2->setObjectName(QStringLiteral("actionUndo_2"));
        actionUndo_2->setCheckable(true);
        actionUndo_2->setChecked(true);
        actionRedo_2 = new QAction(MainWindow);
        actionRedo_2->setObjectName(QStringLiteral("actionRedo_2"));
        actionRedo_2->setCheckable(true);
        actionRedo_2->setChecked(true);
        actionDefault = new QAction(MainWindow);
        actionDefault->setObjectName(QStringLiteral("actionDefault"));
        actionDefault->setCheckable(true);
        actionDarkMode = new QAction(MainWindow);
        actionDarkMode->setObjectName(QStringLiteral("actionDarkMode"));
        actionDarkMode->setCheckable(true);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QStringLiteral("actionReplace"));
        actionIndent_forward = new QAction(MainWindow);
        actionIndent_forward->setObjectName(QStringLiteral("actionIndent_forward"));
        actionIndent_backward = new QAction(MainWindow);
        actionIndent_backward->setObjectName(QStringLiteral("actionIndent_backward"));
        actionCapitalize = new QAction(MainWindow);
        actionCapitalize->setObjectName(QStringLiteral("actionCapitalize"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/icons/icons/capitalizeAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCapitalize->setIcon(icon14);
        actionPadding = new QAction(MainWindow);
        actionPadding->setObjectName(QStringLiteral("actionPadding"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/icons/icons/padding.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPadding->setIcon(icon15);
        actionTrim = new QAction(MainWindow);
        actionTrim->setObjectName(QStringLiteral("actionTrim"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/icons/icons/trim.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTrim->setIcon(icon16);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(32, 16));
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        FindButton = new QPushButton(centralWidget);
        FindButton->setObjectName(QStringLiteral("FindButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(FindButton->sizePolicy().hasHeightForWidth());
        FindButton->setSizePolicy(sizePolicy1);
        FindButton->setIcon(icon8);

        horizontalLayout->addWidget(FindButton);

        FindRegexButton = new QPushButton(centralWidget);
        FindRegexButton->setObjectName(QStringLiteral("FindRegexButton"));
        sizePolicy1.setHeightForWidth(FindRegexButton->sizePolicy().hasHeightForWidth());
        FindRegexButton->setSizePolicy(sizePolicy1);
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        FindRegexButton->setPalette(palette1);
        FindRegexButton->setIcon(icon9);

        horizontalLayout->addWidget(FindRegexButton);

        findTextBox = new QLineEdit(centralWidget);
        findTextBox->setObjectName(QStringLiteral("findTextBox"));
        findTextBox->setEnabled(true);
        sizePolicy1.setHeightForWidth(findTextBox->sizePolicy().hasHeightForWidth());
        findTextBox->setSizePolicy(sizePolicy1);
        findTextBox->setInputMask(QStringLiteral(""));
        findTextBox->setFrame(true);

        horizontalLayout->addWidget(findTextBox);

        previous = new QPushButton(centralWidget);
        previous->setObjectName(QStringLiteral("previous"));
        sizePolicy1.setHeightForWidth(previous->sizePolicy().hasHeightForWidth());
        previous->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(previous);

        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        sizePolicy1.setHeightForWidth(next->sizePolicy().hasHeightForWidth());
        next->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(next);

        exitFind = new QPushButton(centralWidget);
        exitFind->setObjectName(QStringLiteral("exitFind"));
        sizePolicy1.setHeightForWidth(exitFind->sizePolicy().hasHeightForWidth());
        exitFind->setSizePolicy(sizePolicy1);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        exitFind->setPalette(palette2);

        horizontalLayout->addWidget(exitFind);

        findResultsLabel = new QLabel(centralWidget);
        findResultsLabel->setObjectName(QStringLiteral("findResultsLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(findResultsLabel->sizePolicy().hasHeightForWidth());
        findResultsLabel->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(findResultsLabel);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1178, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuFind = new QMenu(menuBar);
        menuFind->setObjectName(QStringLiteral("menuFind"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuPreferences = new QMenu(menuBar);
        menuPreferences->setObjectName(QStringLiteral("menuPreferences"));
        menuVisible_actions = new QMenu(menuPreferences);
        menuVisible_actions->setObjectName(QStringLiteral("menuVisible_actions"));
        menuTheme = new QMenu(menuPreferences);
        menuTheme->setObjectName(QStringLiteral("menuTheme"));
        menuPlugins = new QMenu(menuBar);
        menuPlugins->setObjectName(QStringLiteral("menuPlugins"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuFind->menuAction());
        menuBar->addAction(menuPreferences->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuPlugins->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionTrim);
        menuEdit->addAction(actionPadding);
        menuEdit->addAction(actionCapitalize);
        menuEdit->addAction(actionIndent_forward);
        menuEdit->addAction(actionIndent_backward);
        menuFind->addAction(actionFind);
        menuFind->addAction(actionFind_regex);
        menuFind->addAction(actionReplace);
        menuPreferences->addAction(menuVisible_actions->menuAction());
        menuPreferences->addAction(menuTheme->menuAction());
        menuVisible_actions->addAction(actionNew_2);
        menuVisible_actions->addAction(actionOpen_2);
        menuVisible_actions->addAction(actionSave_2);
        menuVisible_actions->addSeparator();
        menuVisible_actions->addAction(actionCut_2);
        menuVisible_actions->addAction(actionCopy_2);
        menuVisible_actions->addAction(actionPaste_2);
        menuVisible_actions->addSeparator();
        menuVisible_actions->addAction(actionUndo_2);
        menuVisible_actions->addAction(actionRedo_2);
        menuVisible_actions->addSeparator();
        menuTheme->addAction(actionDefault);
        menuTheme->addAction(actionDarkMode);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionTrim);
        mainToolBar->addAction(actionPadding);
        mainToolBar->addAction(actionCapitalize);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "Cut", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionFind->setText(QApplication::translate("MainWindow", "Find...", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionFind_regex->setText(QApplication::translate("MainWindow", "Find regex", Q_NULLPTR));
        actionBold->setText(QApplication::translate("MainWindow", "Bold", Q_NULLPTR));
        actionItalic->setText(QApplication::translate("MainWindow", "Italic", Q_NULLPTR));
        actionUnderline->setText(QApplication::translate("MainWindow", "Underline", Q_NULLPTR));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionNew_2->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
        actionOpen_2->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionSave_2->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionCut_2->setText(QApplication::translate("MainWindow", "Cut", Q_NULLPTR));
        actionCopy_2->setText(QApplication::translate("MainWindow", "Copy", Q_NULLPTR));
        actionPaste_2->setText(QApplication::translate("MainWindow", "Paste", Q_NULLPTR));
        actionUndo_2->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        actionRedo_2->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        actionDefault->setText(QApplication::translate("MainWindow", "Default", Q_NULLPTR));
        actionDarkMode->setText(QApplication::translate("MainWindow", "DarkMode", Q_NULLPTR));
        actionReplace->setText(QApplication::translate("MainWindow", "Replace...", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionReplace->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionIndent_forward->setText(QApplication::translate("MainWindow", "Indent forward", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionIndent_forward->setShortcut(QApplication::translate("MainWindow", "Ctrl+[", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionIndent_backward->setText(QApplication::translate("MainWindow", "Indent backward", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionIndent_backward->setShortcut(QApplication::translate("MainWindow", "Ctrl+]", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCapitalize->setText(QApplication::translate("MainWindow", "Capitalize", Q_NULLPTR));
        actionPadding->setText(QApplication::translate("MainWindow", "Padding", Q_NULLPTR));
        actionTrim->setText(QApplication::translate("MainWindow", "Trim", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
#ifndef QT_NO_TOOLTIP
        FindButton->setToolTip(QApplication::translate("MainWindow", "Find", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        FindButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        FindRegexButton->setToolTip(QApplication::translate("MainWindow", "Find regex", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        FindRegexButton->setText(QString());
        previous->setText(QApplication::translate("MainWindow", "<", Q_NULLPTR));
        next->setText(QApplication::translate("MainWindow", ">", Q_NULLPTR));
        exitFind->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        findResultsLabel->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuFind->setTitle(QApplication::translate("MainWindow", "Find", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menuPreferences->setTitle(QApplication::translate("MainWindow", "Preferences", Q_NULLPTR));
        menuVisible_actions->setTitle(QApplication::translate("MainWindow", "Visible actions", Q_NULLPTR));
        menuTheme->setTitle(QApplication::translate("MainWindow", "Theme", Q_NULLPTR));
        menuPlugins->setTitle(QApplication::translate("MainWindow", "Plugins", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
