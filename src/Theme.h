#ifndef THEME_H
#define THEME_H
#include <QColor>
#include <QString>
#include <QObject>
class Theme : public QObject{
    Q_OBJECT
public:
    Theme(QObject* parent = nullptr);

    void setTheme(const QString mode);
    QString getCurrentTheme();
    QColor getBaseColor();
    QColor getTextColor();
    QColor getButtonColor();
    QColor getEditorColor();
    QColor getRegexButtonColor();
    QColor getTabBarColor();
    QColor getCurrentTabColor();
signals:
    void themeChanged();
private:
    QColor baseColor, textColor, buttonColor,editorColor, regexButtonColor, tabBarColor, currentTabColor;
    QString currentTheme;
};

#endif
