// Copyright 2021 Bobocea Laurentiu
#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include <QtCore>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


