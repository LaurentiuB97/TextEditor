// Copyright 2021 Bobocea Laurentiu
#include "Theme.h"
#include <iostream>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

Theme::Theme(QObject* parent){
    this->setParent(parent);
}

QString Theme::getCurrentTheme(){return currentTheme;}
QColor Theme::getBaseColor() {return baseColor;}
QColor Theme::getTextColor(){return textColor;}
QColor Theme::getButtonColor(){return buttonColor;}
QColor Theme::getEditorColor(){return buttonColor;}
QColor Theme::getRegexButtonColor(){return regexButtonColor;}
QColor Theme::getTabBarColor(){return tabBarColor;}
QColor Theme::getCurrentTabColor(){return currentTabColor;}

void Theme::setTheme(const QString mode){
    // verificam daca directorul cu tema aleasa exista
    QDir director("Themes//" + mode);
    if(!director.exists()){ // in caz afirmativ, inchidem functia
        qDebug() << "Themes//" + mode << "doesn't exists" <<endl;
        return;
    }
    this->currentTheme = mode;
    emit themeChanged();
    QString file = "Themes//" + mode + "//palette.json";
    QFile loadFile(file);
    if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Nu s-a putut deschide fisierul");
            return;
    }
    auto data = QString::fromUtf8(loadFile.readAll());
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject rootObj = doc.object();
    loadFile.close();
    baseColor = QColor(rootObj["baseColor"].toString());
    textColor = QColor(rootObj["textColor"].toString());
    buttonColor = QColor(rootObj["buttonColor"].toString());
    editorColor = QColor(rootObj["editorColor"].toString());
    regexButtonColor = QColor(rootObj["regexButtonColor"].toString());
    tabBarColor = QColor(rootObj["tabBarColor"].toString());
    currentTabColor = QColor(rootObj["currentTabColor"].toString());
}
