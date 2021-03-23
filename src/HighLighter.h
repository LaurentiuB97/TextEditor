#include <QPlainTextEdit>
#include <QStringList>
#include "TextHighLight.h"
#include <iostream>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QMap>
class HighLighter {
private:
    QString resourcesFolder = "highlight_files";
    QString keywordsPath = resourcesFolder + "/keywords";
    QString typesPath = resourcesFolder + "/types.txt";
    QStringList keywords,types;

public:
    HighLighter();
    ~HighLighter();
    void colorTargets(const QMap<QString, QList<TextHighLight>> &map, QPlainTextEdit* edit);
    QList<TextHighLight> findKeyWords(QPlainTextEdit* edit);
    QList<TextHighLight> findTypes(QPlainTextEdit* edit);
    QList<TextHighLight> findString(QPlainTextEdit* edit);
    QList<TextHighLight> findRegex(const QString &pattern, const QString &text);
    void loadKeyWords();
    void loadTypes();
};
