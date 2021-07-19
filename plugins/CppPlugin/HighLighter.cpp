#include "HighLighter.h"
#include <QDebug>
HighLighter::HighLighter(){}
HighLighter::~HighLighter(){}

void HighLighter::colorTargets(const QList<QPair<QString, QList<TextHighLight>>> &list, QPlainTextEdit* edit){
    QTextCursor cursor(edit->document());
    QList<QTextEdit::ExtraSelection> extraSelections;

    for(auto& i : list) { // pentru fiecare item din lista
        auto list2 = i.second; // pregatire lista
        auto color = QColor(i.first); // pregatire culoare
        for(TextHighLight th : list2){ // pentru fiecare item din lista
            QTextEdit::ExtraSelection selection;
            cursor.setPosition(th.getPosition(), QTextCursor::MoveAnchor);
            cursor.setPosition(th.getPosition() + th.getLength(), QTextCursor::KeepAnchor);

            selection.cursor = cursor;
            // setare aspect text
            selection.format.setForeground(color);
            // adaugare la extra-selections
            extraSelections.append(selection);
        }
    }
    edit->setExtraSelections(extraSelections);
}

// returneaza o lista cu  highlight-uri pentru fiecare cuvant cheie
QList<TextHighLight> HighLighter::findKeyWords(QPlainTextEdit* edit) {
    QList<TextHighLight> highlights;
        auto text = edit->toPlainText();
        for(auto& word : keywords){
            QString pattern  = "\\b" + word + "\\b";
            highlights.append(findRegex(pattern,text));
        }
    return highlights;
}

QList<TextHighLight> HighLighter::findDirectives(QPlainTextEdit* edit){
    QList<TextHighLight> highlights;
        auto text = edit->toPlainText();
        for(auto& word : directives){
            QString pattern  = "#\\b" + word + "\\b";
            highlights.append(findRegex(pattern,text));
        }
    return highlights;
}

QList<TextHighLight> HighLighter::findFunctions(QPlainTextEdit* edit){
    QString pattern = "\\b[a-zA-Z]\\w+(?=[\\(])";
    return findRegex(pattern, edit->toPlainText());
}

// returneaza o lista cu  highlight-uri pentru fiecare cuvant ce reprez. un tip de data
QList<TextHighLight> HighLighter::findTypes(QPlainTextEdit* edit) {
    QList<TextHighLight> highlights;
        auto text = edit->toPlainText();
        for(auto& word : types){
            QString pattern = "\\b" + word + "\\b";
            highlights.append(findRegex(pattern,text));
        }
    return highlights;
}

// incarca cuvintele cheie specifice limbajului
void HighLighter::loadKeyWords(){
    QFile file(this->keywordsPath);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        std::cout << "loading file error" << std::endl;
        return;
    }
    // punem continutul intr-un QString
    QTextStream in(&file);
    QString text = in.readAll();
    this->keywords = text.split(",");
}

// incarcare directive de preprocesare
void HighLighter::loadDirectives(){
    QFile file(this->directivesPath);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) { // if something went wrong, show a message
        std::cout << "loading file error" << std::endl;
        return;
    }
    // punem continutul intr-un QString
    QTextStream in(&file);
    QString text = in.readAll();
    this->directives = text.split(",");
}

QList<TextHighLight> HighLighter::findString(QPlainTextEdit* edit){
    QString pattern = "(\"(.([^\"\n])*)\")|(\'(.([^\'\n])*)\')";
    return findRegex(pattern, edit->toPlainText());
}

QList<TextHighLight> HighLighter::findComments(QPlainTextEdit* edit){
    QString pattern =   "((\\/\*)(.[^\\*\\/]*)(\\*\\/))|(\/\/([^\n]*))";
    return findRegex(pattern, edit->toPlainText());
}

void HighLighter::loadTypes(){
    QFile file(this->typesPath);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        std::cout << "loading file error" << std::endl;
        return;
    }
    // punem continutul intr-un QString
    QTextStream in(&file);
    QString text = in.readAll();
    this->types = text.split(",");
}

// returneaza highlight-urile potrivirilor in raport cu sablonul pattern
QList<TextHighLight> HighLighter::findRegex(const QString &pattern,
                                            const QString &text){
    QList<TextHighLight> highlights;
    QRegExp rx("(" + pattern + ")");
    int pos = 0;
    while ((pos = rx.indexIn(text, pos)) != -1) {
        TextHighLight th(pos, rx.cap(1).count());
        highlights.append(th);
        pos += rx.matchedLength();
    }
    for(auto& th : highlights){
        if(th.getLength() == 0)
        {
            throw std::invalid_argument("Acest patern contine rezultate nule");
            break;
        }
    }

    return highlights;
}


