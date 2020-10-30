#include "StringManipulator.h"
#include "PunctuationMark.h"
#include "Utils.h"
#include <string>
#include <iostream>
#include <vector>

//StringManipulator::StringManiputator() {}

std::vector<TextHighLight> StringManipulator::find(const std::string &pattern, const std::string &text, const bool isRegex) {
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
    std::vector<TextHighLight> highlight_list;
    if(isRegex) {
        // (homework)
    } else {
        std::string temp = text;
        while(temp.find(pattern) != std::string::npos) { // find the first occurance of the pattern in text (if it exists)
            int pos = temp.find(pattern);
            TextHighLight highlight(pos, pattern.length());  // set the highlight
            highlight_list.push_back(highlight); // add highlight to the list
            temp.erase(0, pos + pattern.length()); // erase the previous occurance to find another one
        }
    }
    return highlight_list;
}


TextHighLight StringManipulator::replace(const std::string &replacement, const TextHighLight &highlight, std::string &text) { // incomplete
    
    // treating exceptions
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    if(int i = findNonASCII(replacement) != -1) {
        throw std::invalid_argument("Replacement contains forbidden character - position: " + std::to_string(i));
    }
    // replacing the string
    text.replace(highlight.getPosition(), highlight.getLength(), replacement);
    TextHighLight highlight_result(highlight.getPosition(), replacement.length());
    return highlight_result; // (homework) - i don't know what the result must be :)))
}
int StringManipulator::trim(std::string &text) {
    treatingExceptionsForText(text);
    int changes = 0;
    while(text.find("  ") != std::string::npos){ // while there are two consecutive spaces in the text
        for(int position = 0; position < text.length(); position++) {
            if(text[position] == ' ') {
                if(text[position + 1] == ' ') {
                    changes++;
                    text.erase(position + 1, 1);
                }
            }
        }
    }
    return changes;
}
int StringManipulator::padding(std::string &text) {
    // treating exceptions
    treatingExceptionsForText(text);
    int changes = 0;
    std::vector<int> positions = PunctuationMark::findAllMarks(text);

    for(int i = 0; i < positions.size(); ++i) {
        if(isACapitalLetter(text[positions[i] + 1])) { // if the next character after the punctuation mark is a capital letter then:
            text.insert(positions[i] + 1, " ");
            changes++;
            for(int j = i; j < positions.size(); ++j) {
                positions[j]++;
            }
        }
    }
    
    return changes;
 }
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
int StringManipulator::capitalizeFirstLetter(std::string &text) { // incomplete
    // treating exceptions
    treatingExceptionsForText(text);
    
    int changes = 0;
    std::vector<int> dot_marks_positions = PunctuationMark::searchFor('.', text);
    std::vector<int> question_marks_positions = PunctuationMark::searchFor('?', text);
    std::vector<int> exclamation_marks_positions = PunctuationMark::searchFor('!', text);
    // doing for dot case
    for(auto p : dot_marks_positions) {  // go through all the positions
        if(text[p+1] == ' ' &&   // if the dot have a space after it and also a lowercase letter
           isALowercaseLetter(text[p+2])) {
            text[p+2] -= 32; // make the letter uppercase
            changes++;
        }
    }
    // doing for question mark case
    for(auto p : question_marks_positions) {
        if(text[p+1] == ' ' &&  // if the question mark have a space after it and also a lowercase letter
           isALowercaseLetter(text[p+2])) {
               text[p+2] -= 32;  // make the letter uppercase
               changes++;
           }
    }
    // doing for exclamation mark case
    for(auto p : exclamation_marks_positions) {
        if(text[p+1] == ' ' &&  // if the exclamation mark have a space after it and also a lowercase letter
           isALowercaseLetter(text[p+2])) {
               text[p+2] -= 32;  // make the letter uppercase
               changes++;
           }
    }

    return changes;
}
int StringManipulator::capitalizeOffset(std::string &text, const TextHighLight highlight) {
    // treating exceptions
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    int changes = 0;
    for(int position = highlight.getPosition(); position < highlight.getPosition() + highlight.getLength(); position++) {
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
int StringManipulator::lowercaseFirstLetter(std::string &text) {
    // treating exceptions
    treatingExceptionsForText(text);
    
    int changes = 0;
    std::vector<int> dot_marks_positions = PunctuationMark::searchFor('.', text);
    std::vector<int> question_marks_positions = PunctuationMark::searchFor('?', text);
    std::vector<int> exclamation_marks_positions = PunctuationMark::searchFor('!', text);
    // doing for dot case
    for(auto p : dot_marks_positions) {  // go through all the positions
        if(text[p+1] == ' ' &&   // if the dot have a space after it and also a lowercase letter
           isACapitalLetter(text[p+2])) {
            text[p+2] += 32; // make the letter uppercase
            changes++;
        }
    }
    // doing for question mark case
    for(auto p : question_marks_positions) {
        if(text[p+1] == ' ' &&  // if the question mark have a space after it and also a lowercase letter
           isACapitalLetter(text[p+2])) {
               text[p+2] += 32;  // make the letter uppercase
               changes++;
           }
    }
    // doing for exclamation mark case
    for(auto p : exclamation_marks_positions) {
        if(text[p+1] == ' ' &&  // if the exclamation mark have a space after it and also a lowercase letter
           isACapitalLetter(text[p+2])) {
               text[p+2] += 32;  // make the letter uppercase
               changes++;
           }
    }

    return changes;
}
int StringManipulator::lowercaseOffset(std::string &text, const TextHighLight highlight) {
    // treating exceptions
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    int changes = 0;
    for(int position = highlight.getPosition(); position < highlight.getPosition() + highlight.getLength(); position++) {
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
            text.replace(poz, 1, " ");
            changes++;
        }
    } while(poz != -1);
    trim(text);
    return changes/2;
}
int StringManipulator::changeDateFormat(std::string &text, dateFormat format) {
    treatingExceptionsForText(text);
    std::string day, month, year;
    std::string delimiter;
    for(auto p : text) { // find the delimiter
        if(!isNumber(p)) { // find the non-letter character (which is the delimiter)
            delimiter += p;
            break;
        }
    }
    
    std::vector<std::string> tokens = Utils::split(text, delimiter);
    if(tokens[0].size() != 4) { // the year is not first
        if(tokens[2].size() == 4) { // the year is the last
            day = tokens[0];
            month = tokens[1];
            year = tokens[2];
        } else { // imposible conversion
            return -1;
        }
    } else { // the year is first
        year = tokens[0];
        day = tokens[1];
        month = tokens[2];
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
    return 0;
}

/// returns the first occurance of a non-ASCII character
int StringManipulator::findNonASCII(const std::string &text) {
    if(text.empty()){
        throw std::invalid_argument("Empty text");
    }
    const char *buf = text.c_str();
    for(int i = 0; i < text.length(); ++i) {
        if((buf[i] < 8) || (buf[i] > 126)) {
            return i;
        }
    }
    return -1;
}

bool StringManipulator::isACapitalLetter(const char character) {
    return character >= 65 && character <= 90;
}
bool StringManipulator::isALowercaseLetter(const char character) {
    return character >= 97 && character <= 122;
}

bool StringManipulator::isLetter(const char character) {
    return (character >= 65 && character <= 90) || (character >= 97 && character <= 122);
}

bool StringManipulator::isNumber(const char character) {
    return character >= 48 && character <= 57; // is in 0-9 in ASCII code or not
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
