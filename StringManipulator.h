#ifndef STRINGMANIPULATOR_H
#define STRINGMANIPULATOR_H
#include "TextHighLight.h"
#include <iostream>
#include <string>

enum dateFormat {big_endian, middle_endian, little_endian};

class StringManipulator {
 public:
    static TextHighLight* find(const std::string &pattern, const std::string &text, const bool isRegex); //still incomplete
    static TextHighLight replace(const std::string &replacement, const TextHighLight &foundText, std::string &text);//incomplete
    static int trim(std::string &text);//incomplete
    static int padding(std::string &text);//incomplete
    static int capitalizeAll(std::string &text);//incomplete
    static int capitalizeFirst(std::string &text);//incomplete
    static int capitalizeOffset(std::string &text, const TextHighLight highlight);//incomplete
    static int lowercaseAll(std::string &text);//incomplete
    static int lowercaseFirst(std::string &text);//incomplete
    static int lowercaseOffset(std::string &text, const TextHighLight highlight);//incomplete
    static int transformToASCII(string &text);//incomplete
    static int changeDateFormat(string &text, dateFormat format);//incomplete
 private:
    StringManipulator();//incomplete
}


#endif // STRINGMANIPULATOR_H