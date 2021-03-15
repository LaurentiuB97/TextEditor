#ifndef STRINGMANIPULATOR_H
#define STRINGMANIPULATOR_H
#include "TextHighLight.h"
#include <iostream>
#include <string>
#include <vector>



class StringManipulator {
 public:
    enum dateFormat {slash_big_endian, slash_little_endian, dot_big_endian, dot_little_endian, line_big_endian, line_little_endian};
    /// It returns a vector with the highlights of all search results in a text
    ///
    /// @param[in] pattern - it can be a normal sequance of text or a regular expresion
    /// @param[in] text - the text the function must search in
    /// @param[in] isRegex - it specifies if the pattern is a peace of text or a regular expresion
    ///
    /// @return a vector of TextHighLight objects which correspond to the positions of the matches
    static std::vector<TextHighLight> find(const std::string &pattern, const std::string &text, const bool isRegex);
    /// Replaces the portion of the string that is specified in the TextHighLight object
    ///
    /// @param[in] replacement - the string meant to be put on the highlighted text's place
    /// @param[in] highlight - specifies the position and the length of the sequance which is meant to be replaced
    /// @param[in] text - the string which the function will make the change in
    ///
    /// @return the highlight of the new sequance of text
    static TextHighLight replace(const std::string &replacement, const TextHighLight &highlight, std::string &text);
    /// Removes the unnecesary spaces (if there are two or more consecutive spaces, it will remove the aditional once and let just one to that positon
    ///
    /// @param[in][out] text - the string which is meant to be trimmed
    ///
    /// @return the number of changes in text
    static int trim(std::string &text);
    /// Puts spaces where there are missing (after punctuation signs must likely)
    ///
    /// @param[in][out] text - the string which is meant to be modified
    ///
    /// @return the number of changes in text
    static int padding(std::string &text);
    /// Capitalize all the letters from the given text
    ///
    /// @param[in][out] text - the string which is meant to be modified
    ///
    /// @return the number of changes in text
    static int capitalizeAll(std::string &text);
    /// Capitalize the first letter of every sentence when is the case
    ///
    /// @param[in][out] text - the string which is meant to be modified
    ///
    /// @return the number of changes in text
    static int capitalizeFirstLetter(std::string &text);
    ///Capitalize a certain potion of text specified by a highlight
    ///
    /// @param[in][out] text - the string which is meant to be modified
    /// @param[in] highlight - specifies the position and length of the sequance
    ///
    /// @return the number of changes in text
    static int capitalizeOffset(std::string &text, const TextHighLight highlight);
    /// Lowercase all of the letters from the text
    ///
    /// @param[in][out] text - the string which is meant to be modified
    ///
    /// @return the number of changes in text
    static int lowercaseAll(std::string &text);
    /// Lowercase the first letter of every sentence, where is the case
    /// ///
    /// @param[in][out] text - the string which is meant to be modified
    ///
    /// @return the number of changes in text
    static int lowercaseFirstLetter(std::string &text);
    /// Lowercase a certain sequance of text, specified by the highlight
    ///
    /// @param[in][out] text - the string which is meant to be modified
    /// @param[in] - it specifies the position and the length of the given sequance
    ///
    /// @return the number of changes in text
    static int lowercaseOffset(std::string &text, const TextHighLight highlight);
    /// Find all the non-ASCII characters and replace them with spaces
    ///
    /// @param[in][out] text - the string which is meant to be modified
    ///
    /// @return the number of changes in text
    static int transformToASCII(std::string &text);
    /// Convert the given date (which is actualy a string text) in a new format
    ///
    /// @param[in][out] text - the string which is meant to be modified ( the time date - it must respect the format)
    /// @param the desired format
    ///
    /// @return the number of changes in text
    static int changeDateFormat(std::string &text, dateFormat format);
    /// returns the first occurance of a non-ASCII character
    ///
    /// @param[in] the text meant to be analyzed
    ///
    /// @return the first occurance of a non-ASCII character
    static int findNonASCII(const std::string &text);
    /// it specifies if a given string respects the norms to be considered a time date
    ///
    /// @param[in] text - the text meant to be analyzed
    ///
    /// true if the text has date format and false if it doesn't
    static bool isADate(const std::string &text);
    /// it specifies if the given character is a capital letter or not
    ///
    /// @param[in] the character
    ///
    /// @return true if it is a capital letter and false if it is not
    static bool isACapitalLetter(const char character);
    /// it specifies if the given character is a lowercase letter or not
    ///
    /// @param[in] the character
    ///
    /// @return true if it is a lowercase letter and false if it is not
    static bool isALowercaseLetter(const char character);
    /// it specifies if the given character is a letter or not
    ///
    /// @param[in] the character
    ///
    /// @return true if it is a letter and false if it is not
    static bool isLetter(const char character);
    /// it specifies if the given character is a digit or not
    ///
    /// @param[in] the character
    ///
    /// @return true if it is a digit and false if it is not
    static bool isNumber(const char character);
    /// treats exception like "empty text" or  "forbiden character"
    ///
    /// @param[in] text - the text meant to be analyzed
    static void treatingExceptionsForText(const std::string &text);
    /// treats exception like "empty text" or  "forbiden character" or incorrect highlight
    ///
    /// @param[in] text - the text meant to be analyzed
    /// @param[in] highlight - the TextHighLight object meant to be analyzed
    static void treatingExceptionsForHighlight(const std::string &text, const TextHighLight &highlight);
 private:
    StringManipulator();//incomplete
};


#endif // STRINGMANIPULATOR_H
