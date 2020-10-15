#ifndef STRINGMANIPULATOR_H
#define STRINGMANIPULATOR_H
#include "TextHighLight.h"
#include <iostream>
#include <string>

enum dateFormat {big_endian, middle_endian, little_endian};

class StringManipulator {
 public:
    static StringManipulator getInstance();
    static TextHighLight* find(const std::string &pattern, const std::string &text, const bool isRegex);
    static TextHighLight replace(const std::string &replacement, const TextHighLight &foundText, std::string &text);
    static int trim(std::string &text);
    static int padding(std::string &text);
    static int capitalizeAll(std::string &text);
    static int capitalizeFirst(std::string &text);
    static int capitalizeOffset(std::string &text, const TextHighLight highlight);
    static int lowercaseAll(std::string &text);
    static int lowercaseFirst(std::string &text);
    static int lowercaseOffset(std::string &text, const TextHighLight highlight);
    static int transformToASCII(string &text);
    static int changeDateFormat(string &text, dateFormat format);
 private:
    StringManipulator();
}


#endif // STRINGMANIPULATOR_H