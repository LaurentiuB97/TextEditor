#ifndef STRINGMANIPULATOR_H
#define STRINGMANIPULATOR_H
#include "TextHighLight.h"
#include <iostream>
#include <string>
#include <vector>



class StringManipulator {
 public:
    enum dateFormat {slash_big_endian, slash_little_endian, dot_big_endian, dot_little_endian, line_big_endian, line_little_endian};
    static std::vector<TextHighLight> find(const std::string &pattern, const std::string &text, const bool isRegex);
    static TextHighLight replace(const std::string &replacement, const TextHighLight &highlight, std::string &text);
    static int trim(std::string &text);
    static int padding(std::string &text);
    static int capitalizeAll(std::string &text);
    static int capitalizeFirstLetter(std::string &text);
    static int capitalizeOffset(std::string &text, const TextHighLight highlight);
    static int lowercaseAll(std::string &text);
    static int lowercaseFirstLetter(std::string &text);
    static int lowercaseOffset(std::string &text, const TextHighLight highlight);
    static int transformToASCII(std::string &text);
    static int changeDateFormat(std::string &text, dateFormat format);
    static int findNonASCII(const std::string &text);
    static bool isADate(const std::string &text);
    static bool isACapitalLetter(const char character);
    static bool isALowercaseLetter(const char character);
    static bool isLetter(const char character);
    static bool isNumber(const char character);
    static void treatingExceptionsForText(const std::string &text);
    static void treatingExceptionsForHighlight(const std::string &text, const TextHighLight &highlight);
 private:
    StringManipulator();//incomplete
};


#endif // STRINGMANIPULATOR_H
