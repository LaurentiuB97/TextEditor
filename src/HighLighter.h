#include <QPlainTextEdit>
#include <QStringList>
#include "TextHighLight.h"
#include <iostream>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
class HighLighter {
private:
    QString resourcesFolder = "highlight_files";
    QString keywordsPath = resourcesFolder + "/keywords";
    QStringList keywords;

public:
    HighLighter();
    ~HighLighter();
    void colorTargets(const QList<TextHighLight> &list, QPlainTextEdit* edit, const QColor &color);
    QList<TextHighLight> findKeyWords(QPlainTextEdit* edit);
    QList<TextHighLight> findRegex(const QString &pattern, const QString &text);
    void loadKeyWords();
};
