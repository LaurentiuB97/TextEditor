// Copyright 2021 Bobocea Laurentiu
#ifndef STRINGMANIPULATOR_H
#define STRINGMANIPULATOR_H
#include "TextHighLight.h"
#include <iostream>
#include <string>
#include <vector>
#include <QList>
#include <QString>
#include <QChar>


class StringManipulator {
 public:
    enum dateFormat {slash_big_endian, slash_little_endian, dot_big_endian, dot_little_endian,
                     line_big_endian, line_little_endian};
    /// Cauta in textul dat secvente de text corespunzatoare sablonului pattern
    /// @param[in] pattern - sablonul cautarii - poate fi o secventa simpla de text
    /// sau o expresie regulata
    /// @param[in] text - textul in care se cauta sablonul
    /// @param[in] isRegex -flag ce indica daca sablonul este o expresie regulata sau nu
    ///
    /// @returns un vector cu pozitiile si lungimile rezultatelor cautarii
    static std::vector<TextHighLight> find(const QString &pattern, const QString &text,
                                           const bool isRegex = false, const QString flag = "ALL");

    /// Inlocuieste secventa specificata de highlight cu textul replacement
    ///
    /// @param[in] replacement - textul inlocuitor
    /// @param[in] highlight -un obiect ce contine pozitia si lungimea secventei de inlocuit
    /// @param[in] text - textul in care se face inlocuirea
    ///
    /// @returns highlight-ul noi secvente adaugate
    static TextHighLight replace(const QString &replacement, const TextHighLight &highlight, QString &text);

    /// Inlocuieste aparitiile secventei toReplace cu secventa replacement in text
    ///
    /// @param[in] toReplace - textul de inlocuit
    /// @param[in] replacement - textul inlocuitor
    /// @param[in] text - textul in care se face inlocuirea
    ///
    /// @returns numarul de inlocuiri din text
    static int replaceAll(const QString &toReplace, const QString &replacement, QString &text);

    /// Elimina spatiile suplimentare dintr-un text. In locurile unde sunt doua sau mai multe
    /// spatii consecutive va ramane doar un spatiu
    ///
    /// @param[in][out] text - textul ce trebuie truncheat
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int trim(QString &text);

    /// Completeaza cu spatii in zonele unde ar trebui sa existe.
    /// Zone tinta: Intre propozitii, dupa semnul de punctuatie sau
    /// dupa fiecare virgula
    ///
    /// @param[in][out] text - textul ce trebuie modificat
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int padding(QString &text);

    /// Transforma toate literele mici din text in majuscule
    ///
    /// @param[in][out] text - textul ce trebuie modificat
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int capitalizeAll(QString &text);

    /// Transforma la i nmajuscula fiecare litera mica la inceputul unei propozitii
    ///
    /// @param[in][out] text - textul ce trebuie modificat
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int capitalizeFirstLetter(QString &text);

    ///Transforma in majuscule literele mici din secventa specificata de highlight
    ///
    /// @param[in][out] text -  textul ce trebuie modificat
    /// @param[in] highlight - highlight-ul secventei ce trebuie modificate
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int capitalizeOffset(QString &text, const TextHighLight highlight);

    /// Transforma in litere mici toate majusculele din text
    ///
    /// @param[in][out] text - textul ce trebuie modificat
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int lowercaseAll(QString &text);

    /// Functia opusa functiei capitalizeFirstLetter
    /// ///
    /// @param[in][out] text - textul ce trebuie modificat
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int lowercaseFirstLetter(QString &text);

    /// Transforma in litere mici toate majusculele din text specificate de highlight
    ///
    /// @param[in][out] text - textul ce trebuie modificat
    ///
    /// @param[in] highlight - highlight-ul secventei ce trebuie modificate
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int lowercaseOffset(QString &text, const TextHighLight &highlight);

    /// Inlocuieste cu spatii goale toate caracterele ce nu sunt din codul ASCII
    ///
    /// @param[in][out] text - textul ce trebuie modificat
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int transformToASCII(QString &text);

    /// Transforma formatul de data din textul dat in formatul dorit
    ///
    /// @param[in][out] text - textul ce trebuie modificat ( trebuie sa respecte formatul de data)
    ///
    /// @param[in] format - numele formatui dorit
    ///
    /// @returns numarul de schimbari din text dupa aplicarea functiei
    static int changeDateFormat(QString &text, dateFormat format);

    /// gaseste prima pozitie a unui caracter non-ASCII
    ///
    /// @param[in] text - textul ce trebuie verificat
    ///
    /// @returns prima pozitie a unui caracter non-ASCII
    static int findNonASCII(const QString &text);

    /// specifica daca textul dat este un format de data cunoscut
    ///
    /// @param[in] text - textul ce trebuie verificat
    ///
    /// @returns true daca este un format si false daca nu respecta nici un format
    static bool isADate(const QString &text);

    /// specifica daca caracterul dat este majuscula sau nu
    ///
    /// @param[in] character - caracterul de verificat
    ///
    /// @returns true daca e majuscula, false in caz contrar
    static bool isACapitalLetter(const QChar &character);

    /// specifica daca caracterul dat este litera mica sau nu
    ///
    /// @param[in] the character
    ///
    /// @returns true daca caracterul este litera mica, false in caz contrar
    static bool isALowercaseLetter(const QChar &character);

    /// specifica daca caracterul dat este o litera sau nu
    ///
    /// @param[in] character - caracterul ce trebuie verificat
    ///
    /// @return true daca caracterul este litera, false in caz contrar
    static bool isLetter(const QChar &character);

    /// specifica daca caracterul dat este o cifra sau nu
    ///
    /// @param[in] character - caracterul ce trebuie verificat
    ///
    /// @returns true daca este cifra, false in caz contrar
    static bool isNumber(const QChar &character);

    /// verifica daca caracterul primut ca intrare este un construct regex
    ///
    /// @param[in] character - caracterul care trebuie verificat
    ///
    /// @returns - true daca caracterul este un construct regex si false in caz contrar
    static bool isRegexOperator(const QChar &character);

    /// trateaza exceptiile de tip text gol si  caracter interzis
    /// Arunca o exceptie in cazul in care apare o astfel de exceptie
    ///
    /// @param[in] text - textul de analizat
    static void treatingExceptionsForText(const QString &text);

    /// trateaza exceptiile de tip text gol,  caracter interzis sau highlight incorect
    /// Arunca o exceptie in cazul in care apare o astfel de exceptie
    ///
    /// @param[in] text - textul de analizat
    /// @param[in] highlight - highlight-ul de analizat
    static void treatingExceptionsForHighlight(const QString &text, const TextHighLight &highlight);

    /// @returns o lista cu caractere ce reprezinta operatori regex
    static QList<QChar> regexSpecialCharacters();

    /// in cazul in care expresia ce trebuie gasita contine operatori de tip regex, se introduce caracterul "\" pentru a le anula efectul
    ///
    ///@param[in][out]  text - textul care trebuie modificat
    ///
    /// @returns - numarul de modificari inserate in text
    static int repealOperators(QString &text);



 private:
    StringManipulator();
    //static QList<QChar> regexSpecialCharacters;
};


#endif // STRINGMANIPULATOR_H
