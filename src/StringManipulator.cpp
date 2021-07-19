// Copyright 2021 Bobocea Laurentiu
#include "StringManipulator.h"
#include "PunctuationMark.h"
#include "TextHighLight.h"
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <QRegExp>
#include <QStringList>
#include <QDebug>


int ENTER_CODE = 8233;

/// Cauta in textul dat secvente de text corespunzatoare sablonului pattern
/// @param[in] pattern - sablonul cautarii - poate fi o secventa simpla de text
/// sau o expresie regulata
/// @param[in] text - textul in care se cauta sablonul
/// @param[in] isRegex -flag ce indica daca sablonul este
///  o expresie regulata sau nu
///
/// @returns un vector cu pozitiile si lungimile rezultatelor cautarii
std::vector<TextHighLight> StringManipulator::find(const QString &pattern,
                                                   const QString &text,
                                                   const bool isRegex,
                                                   const QString flag) {
    // tratare cazuri speciale
    treatingExceptionsForText(text);
    treatingExceptionsForText(pattern);
    //o copie exacta a lui "pattern", neconstanta
    QString modified_pattern = pattern.left(pattern.count());
    if (!isRegex) {
        if (pattern.count() > text.count()) {
            throw std::invalid_argument("Pattern larger than text");
        }
        // anulam efectul operatorilor daca exista,
        //deoarece acest pattern nu este un regex
        repealOperators(modified_pattern);
    }
    std::vector<TextHighLight> highlights;
    // incardam expresia intre paranteze pentru
    //a evita highlight-urile de lungime 0
    modified_pattern = "(" + modified_pattern + ")";
    QRegExp rx(modified_pattern);
    int counter = 0;
    int pos = 0;
    // cat timp exista potriviri executa:
    //indexIn ia prima potrivire din text incepand de la pozitia pos
    while ((pos = rx.indexIn(text, pos)) != -1) {
        TextHighLight th(pos, rx.cap(1).count());
         highlights.push_back(th);
         // se ia doar primul highlight si iese din functie
         if (flag == "FIRST") {
            return highlights;
         }
         //std::cout <<  th.print() << std::endl;
         pos += rx.matchedLength();
         //qDebug() << "Counter" << counter++ << endl;
     }
     //qDebug() << "while finished" << endl;
     for (auto& th : highlights) {
        if (th.getLength() == 0) {
            throw std::invalid_argument("This pattern will produce"
                                        " some non-highlighted results");
            break;
        }
    }
    QString regex = "(abcd)+";
    repealOperators(regex);

    return highlights;
}

/// Inlocuieste secventa specificata de highlight cu textul replacement
///
/// @param[in] replacement - textul inlocuitor
/// @param[in] highlight -un obiect ce contine pozitia si
///  lungimea secventei de inlocuit
/// @param[in] text - textul in care se face inlocuirea
///
/// @returns highlight-ul noi secvente adaugate
TextHighLight StringManipulator::replace(const QString &replacement,
                                         const TextHighLight &highlight,
                                         QString &text) {
    //Tratarea exceptiilor
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    if(int i = findNonASCII(replacement) != -1) {
        throw std::invalid_argument("Replacement contains forbidden"
                                    " character - position: " +
                                    std::to_string(i));
        return TextHighLight(0,0);
    }
    // inlocuirea stringului
    text.replace(highlight.getPosition(),
                 highlight.getLength(),
                 replacement);
    TextHighLight highlight_result(highlight.getPosition(),
                                   replacement.length());
    return highlight_result;
}

/// Inlocuieste aparitiile secventei toReplace cu secventa replacement in text
///
/// @param[in] toReplace - textul de inlocuit
/// @param[in] replacement - textul inlocuitor
/// @param[in] text - textul in care se face inlocuirea
///
/// @returns numarul de inlocuiri din text
int StringManipulator::replaceAll(const QString &toReplace,
                                  const QString &replacement,
                                  QString &text){
    int counter = 0;
    text.replace(toReplace, replacement);
    return counter;
}

/// Elimina spatiile suplimentare dintr-un text.
///  In locurile unde sunt doua sau mai multe
/// spatii consecutive va ramane doar un spatiu
///
/// @param[in][out] text - textul ce trebuie truncheat
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::trim(QString &text) {
    treatingExceptionsForText(text);
    int changes = 0;
    // cat timp exista doua spatii consecutive in text:
    while(text.contains("  ")) {
        for (int position = 0; position < text.count(); position++) {
            if (text[position] == ' ') {
                if (text[position + 1] == ' ') {
                    changes++;
                    text.remove(position + 1, 1);
                }
            }
        }
    }
    return changes;
}

/// Completeaza cu spatii in zonele unde ar trebui sa existe.
/// Zone tinta: Intre propozitii, dupa semnul de punctuatie sau
/// dupa fiecare virgula
///
/// @param[in][out] text - textul ce trebuie modificat
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::padding(QString &text) {
    //Tratarea exceptiilor
    treatingExceptionsForText(text);
    int changes = 0;
    std::vector<int> positions = PunctuationMark::findAllMarks(text);
    for (int i = 0; i < positions.size(); ++i) {
        if (text[positions[i] + 1].isUpper()) {
        // daca urmatorul caracter de dupa semul de punctuatie
        //este o litera mare:
            text.insert(positions[i] + 1, " ");
            changes++;
            for (int j = i; j < positions.size(); ++j) {
                positions[j]++;
            }
        }
        if (text[positions[i]] == ',' && text[positions[i]+1] != ' ') {
            // daca nu exista un spatiu dupa virgula:"
            text.insert(positions[i] + 1, " ");
            changes++;
            for (int j = i; j < positions.size(); ++j) {
                positions[j]++;
            }
        }
    }

    return changes;
 }

/// Transforma toate literele mici din text in majuscule
///
/// @param[in][out] text - textul ce trebuie modificat
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::capitalizeAll(QString &text) {
    // tratarea exceptiilor
    treatingExceptionsForText(text);
    int changes = 0;
    for (int position = 0; position < text.count(); position++) {
        if (text[position].isLower()) { // daca litera apartine a-z
            text.replace(position, 1, text[position].toUpper());
            changes++;
        }
    }
    return changes;
}
/// Transforma la i nmajuscula fiecare litera mica la inceputul unei propozitii
///
/// @param[in][out] text - textul ce trebuie modificat
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::capitalizeFirstLetter(QString &text) {
    //Tratarea exceptiilor
    treatingExceptionsForText(text);

    int changes = 0;
    std::vector<int> dot_marks_positions =
            PunctuationMark::searchFor('.', text);
    std::vector<int> question_marks_positions =
            PunctuationMark::searchFor('?', text);
    std::vector<int> exclamation_marks_positions =
            PunctuationMark::searchFor('!', text);
    // doing for the first letter from the text
    if (text[0].isLower()) {
        text.replace(0,1,text[0].toUpper());
        changes++;
    }
    // doing for dot case
    for (auto p : dot_marks_positions) {  // go through all the positions
        // if the dot have a space after it and also a lowercase letter
        if (text[p+1] == ' ' &&
           text[p+2].isLower()) {
            // make the letter uppercase
            text.replace(p+2,1,text[p+2].toUpper());
            changes++;
        }
    }
    // doing for question mark case
    for (auto p : question_marks_positions) {
      // if the question mark have a space after it and also a lowercase letter
        if (text[p+1] == ' ' &&
           text[p+2].isLower()) {
              // make the letter uppercase
               text.replace(p+2,1,text[p+2].toUpper());
               changes++;
           }
    }
    // doing for exclamation mark case
    for (auto p : exclamation_marks_positions) {
        // if the exclamation mark have a space
        //after it and also a lowercase letter
        if (text[p+1] == ' ' &&
           isALowercaseLetter(text[p+2])) {
            // make the letter uppercase
               text.replace(p+2,1,text[p+2].toUpper());
               changes++;
           }
    }
    return changes;
}

///Transforma in majuscule literele mici din secventa specificata de highlight
///
/// @param[in][out] text -  textul ce trebuie modificat
/// @param[in] highlight - highlight-ul secventei ce trebuie modificate
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::capitalizeOffset(QString &text,
                                        const TextHighLight highlight) {
    //Tratarea exceptiilor
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    int changes = 0;
    for (int position = highlight.getPosition();
        position < highlight.getPosition() + highlight.getLength();
        position++) {
        if (text[position].isLower()) {  // if letter is in a-z
            text.replace(position, 1, text[position].toUpper());
            changes++;
        }
    }
    return changes;
}

/// Transforma in litere mici toate majusculele din text
///
/// @param[in][out] text - textul ce trebuie modificat
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::lowercaseAll(QString &text) {
    //Tratarea exceptiilor
    treatingExceptionsForText(text);
    int changes = 0;
    for (int position = 0; position < text.count(); position++) {
        if (text[position].isUpper()) { // if letter is in A-Z
            // lowercase = Uppercase + 32
            text.replace(position,1,text[position].toLower());
            changes++;
        }
    }
    return changes;
}

/// Functia opusa functiei capitalizeFirstLetter
/// ///
/// @param[in][out] text - textul ce trebuie modificat
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::lowercaseFirstLetter(QString &text) {
    //Tratarea exceptiilor
    treatingExceptionsForText(text);
    int changes = 0;
    std::vector<int> dot_marks_positions =
            PunctuationMark::searchFor('.', text);
    std::vector<int> question_marks_positions =
            PunctuationMark::searchFor('?', text);
    std::vector<int> exclamation_marks_positions =
            PunctuationMark::searchFor('!', text);
    // pentru prima litera din text
    if (text[0].isUpper()) {
        text.replace(0,1,text[0].toLower());
        changes++;
    }
    // pentru cazul cu punct
    for (auto p : dot_marks_positions) {  // go through all the positions
        // if the dot have a space after it and also a lowercase letter
        if (text[p+1] == ' ' &&
           text[p+2].isUpper()) {
            // make the letter uppercase
            text.replace(p+2, 1, text[p+2].toLower());
            changes++;
        }
    }
    // pentru cazul cu semnul intrebarii
    for (auto p : question_marks_positions) {
        // if the question mark have a
        // space after it and also a lowercase letter
        if (text[p+1] == ' ' &&
           text[p+2].isUpper()) {
               // make the letter uppercase
               text.replace(p+2, 1, text[p+2].toLower());
               changes++;
           }
    }
    // pentru cazul cu semnul exclamarii
    for (auto p : exclamation_marks_positions) {
        // if the exclamation mark have a space
        // after it and also a lowercase letter
        if(text[p+1] == ' ' &&
           text[p+2].isUpper()) {
               // make the letter uppercase
               text.replace(p+2, 1, text[p+2].toLower());
               changes++;
           }
    }

    return changes;
}

/// Transforma in litere mici toate majusculele din
///  text specificate de highlight
///
/// @param[in][out] text - textul ce trebuie modificat
///
/// @param[in] highlight - highlight-ul secventei ce trebuie modificate
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::lowercaseOffset(QString &text,
                                       const TextHighLight &highlight) {
    // Tratarea exceptiilor
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    int changes = 0;
    for (int position = highlight.getPosition();
        position < highlight.getPosition() + highlight.getLength();
        position++) {
        if (text[position].isUpper()) { // if letter is in A-Z
            text.replace(position, 1, text[position].toLower());
            changes++;
        }
    }
    return changes;
}

/// Inlocuieste cu spatii goale toate caracterele ce nu sunt din codul ASCII
///
/// @param[in][out] text - textul ce trebuie modificat
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::transformToASCII(QString &text) {
    if (text.isEmpty() || text.isNull()) {
        throw std::invalid_argument("Empty text!");
    }
    int poz;
    int changes = 0;
    do {
        poz = findNonASCII(text);
        if(poz != -1) {
            text.replace(poz, 1, " ");
            changes++;
        }
    } while (poz != -1);
    // trim(text);
    return changes;
}

/// Transforma formatul de data din textul dat in formatul dorit
///
/// @param[in][out] text - textul ce trebuie modificat
/// ( trebuie sa respecte formatul de data)
///
/// @param[in] format - numele formatui dorit
///
/// @returns numarul de schimbari din text dupa aplicarea functiei
int StringManipulator::changeDateFormat(QString &text, dateFormat format) {
    treatingExceptionsForText(text);
    if (isADate(text)) {
        QString day, month, year;
        QString delimiter;
        for (auto p : text) {  // find the delimiter
            // find the non-letter character (which is the delimiter)
            if (!p.isNumber()) {
                delimiter += p;
                break;
            }
        }
        // the delimiter must pe one of ".", "/" or "-", else quit function
        if (delimiter != "." && delimiter != "/" && delimiter != "-") {
            return -1;
        }
        auto tokens = text.split(delimiter);
        if (tokens[0].count() != 4) {  // the year is not first
            if (tokens[2].count() == 4) {  // the year is the last
                day = tokens[0];
                month = tokens[1];
                year = tokens[2];
            } else {  // imposible conversion
                return -1;
            }
        } else { // the year is first
            year = tokens[0];
            month = tokens[1];
            day = tokens[2];
        }
        switch(format) {
            case slash_big_endian:
                text = year + "/" + month + "/" + day;
                return 1;
            case slash_little_endian:
                text = day + "/" + month + "/" + year;
                return 1;
            case dot_big_endian:
                text = year + "." + month + "." + day;
                return 1;
            case dot_little_endian:
                text = day + "." + month + "." + year;
                return 1;
            case line_big_endian:
                text = year + "-" + month + "-" + day;
                return 1;
            case line_little_endian:
                text = day + "-" + month + "-" + year;
                return 1;
        }
    }
        return 0;
}

/// gaseste prima pozitie a unui caracter non-ASCII
///
/// @param[in] text - textul ce trebuie verificat
///
/// @returns prima pozitie a unui caracter non-ASCII
int StringManipulator::findNonASCII(const QString &text) {
    if (text.isEmpty() || text.isNull()){
        throw std::invalid_argument("Empty text");
    }
    for (int i = 0; i < text.count(); i++) {
        int code = text[i].unicode();
        if (((code < 8) || (code > 127)) && (code != ENTER_CODE) ) {
            return i;
        }
    }
    return -1;
}

/// specifica daca textul dat este un format de data cunoscut
///
/// @param[in] text - textul ce trebuie verificat
///
/// @returns true daca este un format si false daca nu respecta nici un format
bool StringManipulator::isADate(const QString &text) {
    QString delimiter, day, month, year;
    bool result;
    treatingExceptionsForText(text);
    // find the delimiter (it could be '.', '/' or '-')
    if (find(".", text,false).size() == 2) {
        delimiter = ".";
    } else if(find("/", text,false).size() == 2) {
        delimiter = "/";
    } else if(find("-", text,false).size() == 2) {
        delimiter = "-";
    }
    // split the date to verify the component parts
    auto tokens = text.split(delimiter);
    // verify if the components are just numbers
    for (auto& token : tokens) {
        for (auto character : token) {
            if (!character.isNumber()) {
                // the component contains a non-number
                // character, so the text is not a date
                return false;
            }
        }
    }
    // verify the lenght of the components
    // (to see where is the day, month and year
    if (tokens[0].count() != 4) { // the year is not first
        // verify the day
        if (tokens[0].count() == 2) {
            day = tokens[0];
        } else {
            return false;
        }
        // verify the month
        if (tokens[1].count() == 2) {
            month = tokens[1];
        } else {
            return false;
        }
        // verify the year
        if (tokens[2].count() == 4) {
            year = tokens[2];
        } else {
            return false;
        }
    } else { // the year is first
        // verify the year
        if (tokens[0].count() == 4) {
            year = tokens[0];
        } else {
            return false;
        }
        // verify the month
        if (tokens[1].count() == 2) {
            month = tokens[1];
        } else {
            return false;
        }
        // verify the day
        if (tokens[2].count() == 2) {
            day = tokens[2];
        } else {
            return false;
        }
    }
    // verify the components ranges:
    if (day[0] == '0') {  // treating cases where we have days < 10
        if(day[1] == '0') {  // the day can't be 0
            return false;
        }
    } else if (day.toInt() > 31) {
        return false;
    }
    if (month[0] == '0') { // treating cases where we have months < 10
        if(month[1] == '0') { // the month can't be 0
            return false;
        }
    } else if (month.toInt() > 12) {
        return false;
    }
    if (year.toInt() < 1000){
        return false;
    }
    return true;

}

/// specifica daca caracterul dat este majuscula sau nu
///
/// @param[in] character - caracterul de verificat
///
/// @returns true daca e majuscula, false in caz contrar
bool StringManipulator::isACapitalLetter(const QChar &character) {
    return character.isUpper();
}

/// specifica daca caracterul dat este litera mica sau nu
///
/// @param[in] the character
///
/// @returns true daca caracterul este litera mica, false in caz contrar
bool StringManipulator::isALowercaseLetter(const QChar &character) {
    return character.isLower();
}

/// specifica daca caracterul dat este o litera sau nu
///
/// @param[in] character - caracterul ce trebuie verificat
///
/// @return true daca caracterul este litera, false in caz contrar
bool StringManipulator::isLetter(const QChar &character) {
    return character.isLetter();
}

/// specifica daca caracterul dat este o cifra sau nu
///
/// @param[in] character - caracterul ce trebuie verificat
///
/// @returns true daca este cifra, false in caz contrar
bool StringManipulator::isNumber(const QChar &character) {
    return character.isNumber();  // is in 0-9 in ASCII code or not
}

/// verifica daca caracterul primut ca intrare este un construct regex
///
/// @param[in] character - caracterul care trebuie verificat
///
/// @returns - true daca caracterul este un construct regex si false in caz contrar
bool StringManipulator::isRegexOperator(const QChar &character) {
    for (QChar &c : StringManipulator::regexSpecialCharacters()) {
        if (c == character) {
            return true;
        }
    }
    return false;
}

/// trateaza exceptiile de tip text gol si  caracter interzis
/// Arunca o exceptie in cazul in care apare o astfel de exceptie
///
/// @param[in] text - textul de analizat
void StringManipulator::treatingExceptionsForText(const QString &text) {
    if (text.isEmpty() || text.isNull()) {
        throw std::invalid_argument("Text gol");
    }
    if (int i = findNonASCII(text) != -1) {
        throw std::invalid_argument("Textul conține caractere interzise!");
    }
}

/// trateaza exceptiile de tip text gol,
///   caracter interzis sau highlight incorect
/// Arunca o exceptie in cazul in care apare o astfel de exceptie
///
/// @param[in] text - textul de analizat
/// @param[in] highlight - highlight-ul de analizat
void StringManipulator::treatingExceptionsForHighlight(const QString &text,
                                                       const TextHighLight &highlight){
    if (highlight.getPosition() < 0) {
        throw std::invalid_argument("Negative position");
    }
    if (highlight.getLength() < 0) {
        throw std::invalid_argument("Negative length");
    }
    if (highlight.getPosition() >= text.count()) {
        throw std::invalid_argument("Position larger than"
                                    " the text's length - text.length() = " +
                                    std::to_string(text.count()) +
                                    ", position = " +
                                    std::to_string(highlight.getPosition()));
    }
    if((highlight.getPosition() + highlight.getLength()) > text.count()) {
        throw std::invalid_argument("Length to large! text.count() =  " +
                                    std::to_string(text.count()) +
                                    ", position + length = " +
                                    std::to_string(highlight.getPosition() +
                                                   highlight.getLength()));
    }
}

/// @returns o lista cu caractere ce reprezinta operatori regex
QList<QChar> StringManipulator::regexSpecialCharacters(){
    QList<QChar> list = {'+', '-', '/', '\\', '*', '(', ')', '$', '^',
                         '*', '(', ')', '[', ']', '{', '}', '?', '.', '|'};
    return list;
}

/// in cazul in care expresia ce trebuie gasita contine operatori de tip regex,
///  se introduce caracterul "\" pentru a le anula efectul
///
///@param[in][out]  text - textul care trebuie modificat
///
/// @returns - numarul de modificari inserate in text
int StringManipulator::repealOperators(QString &text){
        int counter = 0;
        int changes = 0;
        while (counter < text.count()){
            if (isRegexOperator(text[counter])) { // s-a gasit un operator
                //se insereaza "\" pentru a-i anula efectul
                text.insert(counter, QChar('\\'));
                counter += 2; // se trece acum peste
                changes++;
            } else {
                counter++;
            }
        }
    }
