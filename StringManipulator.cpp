#include "StringManipulator.h"
#include <string>
#include <iostream>


//StringManipulator::StringManiputator() {}

TextHighLight* StringManipulator::find(const std::string &pattern, const std::string &text, const bool isRegex) {
    // treating special cases
    if(pattern.empty()) {
        throw std::invalid_argument("Empty pattern!");
    }
    if(int i = findNonASCII(pattern) != -1) {
        throw std::invalid_argument("Pattern contains forbidden character - position: " +  std::to_string(i));
    }
    if(pattern.length() > text.length()) {
        throw std::invalid_argument("Pattern larger than text");
    }
    TextHighLight* highlight_list;
    if(isRegex) {
        // (homework)
    } else {
        std::string temp = text;
        int i = 0;
        while(temp.find(pattern) != std::string::npos) { // find the first occurance of the pattern in text (if it exists)
            int pos = temp.find(pattern);
            TextHighLight highlight(pos, pattern.length());  // set the highlight
            highlight_list[i] = highlight; // add highlight to the list
            ++i;
            temp.erase(0, pos + pattern.length()); // erase the previous occurance to find another one
        }
        if(i == 0) {  // if the pattern was not found
            highlight_list = nullptr;
        }
    }
    return highlight_list;
}


TextHighLight StringManipulator::replace(const std::string &replacement, const TextHighLight &highlight, std::string &text) { // incomplete
    TextHighLight highlight_result;
    // treating exceptions
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    if(int i = findNonASCII(replacement) != -1) {
        throw std::invalid_argument("Replacement contains forbidden character - position: " + std::to_string(i));
    }
    // replacing the string
    text.replace(highlight.getPosition(), highlight.getLength(), replacement);
    return highlight_result; // (homework) - i don't know what the result must be :)))
}
int StringManipulator::trim(std::string &text) {
    treatingExceptionsForText(text);
    char space = ' ';
    int changes = 0;
    for(int position = 0; position < text.length(); position++){
        if(text[position] == space) {
            if(text[position + 1] == space) {
                changes++;
                text.erase(position + 1, 1);
            }
        }
    }
    return changes;
}
// int StringManipulator::padding(std::string &text) {}
int StringManipulator::capitalizeAll(std::string &text) {
    // treating exceptions
    treatingExceptionsForText(text);

    int changes = 0;
    for(int position = 0; position < text.length(); position++) {
        if(text[position] >= 97 && text[position] <= 122) { // if letter is in a-z
            text[position] -= 32; // Uppercase = lowercase -32
            changes++;
        }
    }
    return changes;
}
int StringManipulator::capitalizeFirst(std::string &text) {
    // treating exceptions
    treatingExceptionsForText(text);
    
    int changes = 0;
    if(text[0] >= 97 && text[0] <= 122) { // if letter is in a-z
        text[0] -= 32; // Uppercase = lowercase -32
        changes++;
    }
    return changes;
}
int StringManipulator::capitalizeOffset(std::string &text, const TextHighLight highlight) {
    // treating exceptions
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    int changes = 0;
    for(int position = highlight.getPosition(); position < highlight.getLength(); position++) {
        if(text[position] >= 97 && text[position] <= 122) { // if letter is in a-z
            text[position] -= 32; // Uppercase = lowercase -32
            changes++;
        }
    }
    return changes;
}
int StringManipulator::lowercaseAll(std::string &text) {
    // treating exceptions
    treatingExceptionsForText(text);
    
    int changes = 0;
    for(int position = 0; position < text.length(); position++) {
        if(text[position] >= 65 && text[position] <= 90) { // if letter is in A-Z
            text[position] += 32; // lowercase = Uppercase + 32
            changes++;
        }
    }
    return changes;
}
int StringManipulator::lowercaseFirst(std::string &text) {
    treatingExceptionsForText(text);
    int changes = 0;
    if(text[0] >= 65 && text[0] <= 90) { // if letter is in A-Z
            text[0] += 32; // lowercase = Uppercase + 32
            changes++;
    }
    return changes;
}
int StringManipulator::lowercaseOffset(std::string &text, const TextHighLight highlight) {
    // treating exceptions
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    int changes = 0;
    for(int position = highlight.getPosition(); position < highlight.getLength(); position++) {
        if(text[position] >= 65 && text[position] <= 90) { // if letter is in A-Z
            text[position] += 32; // lowercase = Uppercase + 32
            changes++;
        }
    }
    return changes;
}
int StringManipulator::transformToASCII(std::string &text) {
    if(text.empty()) {
        throw std::invalid_argument("Empty text!");
    }
    int poz;
    int changes = 0;
    do {
        poz = findNonASCII(text);
        if(poz != -1) {
            text[poz] = ' ';
            changes++;
        }
    } while(poz != -1);
    return changes;
}
// int StringManipulator::changeDateFormat(string &text, dateFormat format) {}

/// returns the first occurance of a non-ASCII character and 
int StringManipulator::findNonASCII(const std::string &text) {
    if(text.empty()){
        throw std::invalid_argument("Empty text");
    }
    const char *buf = text.c_str();
    for(int i = 0; i < text.length(); ++i) {
        if((buf[i] < 32) || (buf[i] > 126)) {
            return i;
        }
    }
    return -1;
}

void StringManipulator::treatingExceptionsForText(const std::string &text) {
    if(text.empty()) {
        throw std::invalid_argument("Empty text");
    }
    if(int i = findNonASCII(text) != -1) {
        throw std::invalid_argument("Text contains forbidden character - position: " +  std::to_string(i));
    }
}
void StringManipulator::treatingExceptionsForHighlight(const std::string &text, const TextHighLight &highlight) {
    if(highlight.getPosition() < 0) {
        throw std::invalid_argument("Negative position");
    }
    if(highlight.getLength() < 0) {
        throw std::invalid_argument("Negative length");
    }
    if(highlight.getPosition() >= text.length()) {
        throw std::invalid_argument("Position larger than the text's length - text.length() = " +
                                    std::to_string(text.length()) +
                                    ", position = " +
                                    std::to_string(highlight.getPosition()));
    }
    if((highlight.getPosition() + highlight.getLength()) > text.length()) {
        throw std::invalid_argument("Length to large! text.length() =  " +
                                    std::to_string(text.length()) + ", position + length = " +
                                    std::to_string(highlight.getPosition() + highlight.getLength()));
    }
}