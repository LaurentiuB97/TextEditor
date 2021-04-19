#ifndef THEME_H
#define THEME_H
#include <QColor>
#include <QString>
class Theme{
public:
    Theme();
    ~Theme();
    void loadColors(const QString mode);
    QString getCurrentTheme();
    QColor getBaseColor();
    QColor getTextColor();
    QColor getButtonColor();
    QColor getEditorColor();
    QColor getRegexButtonColor();
private:
    QColor baseColor, textColor, buttonColor,editorColor, regexButtonColor;
    QString currentTheme;
};

#endif
