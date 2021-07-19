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
    QString resourcesFolder = "plugins/CppPlugin/highlight_files";
    QString keywordsPath = resourcesFolder + "/keywords";
    QString typesPath = resourcesFolder + "/types.txt";
    QString directivesPath = resourcesFolder + "/directives";
    QStringList keywords,types, directives;

public:
    HighLighter();
    ~HighLighter();
    void colorTargets(const QList<QPair<QString, QList<TextHighLight>>> &list, QPlainTextEdit* edit);
    QList<TextHighLight> findKeyWords(QPlainTextEdit* edit);
    QList<TextHighLight> findDirectives(QPlainTextEdit* edit);
    QList<TextHighLight> findFunctions(QPlainTextEdit* edit);
    QList<TextHighLight> findTypes(QPlainTextEdit* edit);
    QList<TextHighLight> findString(QPlainTextEdit* edit);
    QList<TextHighLight> findComments(QPlainTextEdit* edit);
    QList<TextHighLight> findRegex(const QString &pattern, const QString &text);

    void loadKeyWords();
    void loadDirectives();
    void loadTypes();
};
