#include "HighLighter.h"

HighLighter::HighLighter(){}
//HighLighter::~HighLighter(){}

// return a list with highlights for every keyword
QList<TextHighLight> HighLighter::findKeyWords(QPlainTextEdit* edit) {
    QList<TextHighLight> highlights;
    auto text = edit->toPlainText();
    for(auto& word : keywords){
        QString pattern  = "(\b" + word + "\b)";
        highlights.append(findRegex(pattern,text));
    }
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

// returns highlights for every match from text
QList<TextHighLight> HighLighter::findRegex(const QString &pattern,
                                            const QString &text){
    QList<TextHighLight> highlights;
    QRegxExp rx(pattern);
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
    return highlights;
}

