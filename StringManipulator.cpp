#include "StringManipulator.h"
#include <string>
#include <iostream>


TextHighLight* StringManipulator::find(const std::string &pattern, const std::string &text, const bool isRegex) {
    
    // treating special cases
    if(pattern.empty()) {
        throw std::invalid_argument("Empty pattern!");
    }
    if(text.empty()) {
        throw std::invalid_argument("Empty text");
    }

    TextHighLight* highlight_list;
    if(isRegex) {
        // (homework)
    } else {
        std::string temp = text;
        int i = 0;
        while(int pos = temp.find(pattern) != std::string::npos) { // find the first occurance of the pattern in text (if it exists)
            TextHighLight highlight(pos, pattern.length());  // set the highlight
            highlight_list[i] = highlight;
            ++i;
            temp.erase(0, pos + pattern.length()) // erase the previous occurance to find another one
        }
        if(i == 0) {
            highlight_list = nullptr;
        }
    }
    
    return highlight_list;
}
TextHighLight StringManipulator::replace(const std::string &replacement, const TextHighLight &foundText, std::string &text) {}
int StringManipulator::trim(std::string &text) {}
int StringManipulator::padding(std::string &text) {}
int StringManipulator::capitalizeAll(std::string &text) {}
int StringManipulator::capitalizeFirst(std::string &text) {}
int StringManipulator::capitalizeOffset(std::string &text, const TextHighLight highlight) {}
int StringManipulator::lowercaseAll(std::string &text) {}
int StringManipulator::lowercaseFirst(std::string &text) {}
int StringManipulator::lowercaseOffset(std::string &text, const TextHighLight highlight) {}
int StringManipulator::transformToASCII(string &text) {}
int StringManipulator::changeDateFormat(string &text, dateFormat format) {}