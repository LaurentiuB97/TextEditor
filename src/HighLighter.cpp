#include "HighLighter.h"

HighLighter::HighLighter(){}
HighLighter::~HighLighter(){}

void HighLighter::colorTargets(const QMap<QString, QList<TextHighLight>> &map, QPlainTextEdit* edit){
    QTextCursor cursor(edit->document());
    QList<QTextEdit::ExtraSelection> extraSelections;
    QMapIterator<QString, QList<TextHighLight>> i(map);
    while (i.hasNext()) { // for each item from map:
        i.next();
        auto list = i.value(); // prepare list
        auto color = QColor(i.key()); // prepare color
        for(TextHighLight th : list){ // for each item from list:
            QTextEdit::ExtraSelection selection;
            //QTextCursor cursor(edit->document());
            cursor.setPosition(th.getPosition(), QTextCursor::MoveAnchor);
            cursor.setPosition(th.getPosition() + th.getLength(), QTextCursor::KeepAnchor);
            selection.cursor = cursor;
            // set text appearance
            selection.format.setForeground(color);
            // add to extra-selections
            extraSelections.append(selection);
        }
    }
    edit->setExtraSelections(extraSelections);
}

// return a list with highlights for every keyword
QList<TextHighLight> HighLighter::findKeyWords(QPlainTextEdit* edit) {
    QList<TextHighLight> highlights;
        auto text = edit->toPlainText();
        for(auto& word : keywords){
            QString pattern  = "(\\b" + word + "\\b)";
            //std::cout << pattern.toStdString() << std::endl;
            highlights.append(findRegex(pattern,text));
        }
    return highlights;
}

// return a list with highlights for every keyword
QList<TextHighLight> HighLighter::findTypes(QPlainTextEdit* edit) {
    QList<TextHighLight> highlights;
        auto text = edit->toPlainText();
        for(auto& word : types){
            QString pattern  = "(\\b" + word + "\\b)";
            //std::cout << pattern.toStdString() << std::endl;
            highlights.append(findRegex(pattern,text));
        }
    return highlights;
}

// load the keywords for the specific language
void HighLighter::loadKeyWords(){
    QFile file(this->keywordsPath);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) { // if something went wrong, show a message
        std::cout << "loading file error" << std::endl;
        return;
    }
    // put the content in a QString
    QTextStream in(&file);
    QString text = in.readAll();
    this->keywords = text.split(",");
}

QList<TextHighLight> HighLighter::findString(QPlainTextEdit* edit){
    QString pattern = "(\"(?:[^\"\\\\]|\\\\\"|\\\\)*\")|('(?:[^\\\\]|\\\\'|\\\\)*')";
    return findRegex(pattern, edit->toPlainText());
}

void HighLighter::loadTypes(){
    QFile file(this->typesPath);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) { // if something went wrong, show a message
        std::cout << "loading file error" << std::endl;
        return;
    }
    // put the content in a QString
    QTextStream in(&file);
    QString text = in.readAll();
    this->types = text.split(",");
}

// returns highlights for every match from text
QList<TextHighLight> HighLighter::findRegex(const QString &pattern,
                                            const QString &text){
    QList<TextHighLight> highlights;
    QRegExp rx(pattern);
    int pos = 0;
    while ((pos = rx.indexIn(text, pos)) != -1) {
        TextHighLight th(pos, rx.cap(1).count());
        //std::cout << rx.cap(1).toStdString();
        highlights.append(th);
        //std::cout <<  th.print() << std::endl;
        pos += rx.matchedLength();
    }
    for(auto& th : highlights){
        if(th.getLength() == 0)
        {
            throw std::invalid_argument("This pattern will produce some non-highlighted results");
            break;
        }
    }
    //std::cout << "Text:" << text.toStdString() << " pattern:" << pattern.toStdString()<< std::endl;
    //std::cout << "Au fost gasite " << highlights.count() << "rezultate:"<< std::endl;
//    for(auto& h : highlights)
//    {
//        std::cout << h.print() << std::endl;
//    }
    return highlights;
}


