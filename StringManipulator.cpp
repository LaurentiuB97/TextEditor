#include "StringManipulator.h"
#include "PunctuationMark.h"
#include "TextHighLight.h"
#include "Utils.h"
#include <string>
#include <iostream>
#include <vector>
#include <regex>

/// It returns a vector with the highlights of all search results in a text
///
/// @param[in] pattern - it can be a normal sequance of text or a regular expresion
/// @param[in] text - the text the function must search in
/// @param[in] isRegex - it specifies if the pattern is a peace of text or a regular expresion
///
/// @return a vector of TextHighLight objects which correspond to the positions of the matches
std::vector<TextHighLight> StringManipulator::find(const std::string &pattern, const std::string &text, const bool isRegex) {
    // treating special cases
    treatingExceptionsForText(text);
    treatingExceptionsForText(pattern);
    if(!isRegex) {
        if(pattern.length() > text.length()) {
            throw std::invalid_argument("Pattern larger than text");
        }
    }
    std::vector<TextHighLight> highlights;
    if(isRegex) {
        std::vector<std::string> tokens = Utils::split(pattern, "/");
        bool global_active = false;
        //bool icase_active = false;
        std::regex expression(tokens[0]); // expression with default flags
        // see if we have some flags
        if(tokens.size() == 2){
            if(tokens[1].find("i") != std::string::npos) {
            std::regex temp(tokens[0], std::regex_constants::icase);
            expression  = temp; // modify the expression's flags
            //icase_active = true;
            }
            if(tokens[1].find("g") != std::string::npos) {
                global_active = true;
            }
        }
        // aply searching algorithm
        std::string::const_iterator start, end;
        start = text.begin();
        end = text.end();
        std::match_results<std::string::const_iterator> what;
        int absolute_position = 0;
        int length = 0;
        while(regex_search(start, end, what, expression)) {
            if(highlights.size() > 0) {
                highlights.push_back(TextHighLight(what.position() +
                                                highlights.back().getPosition() +
                                                highlights.back().getLength(),
                                                std::string(what[0]).length()));
            } else {
                highlights.push_back(TextHighLight(what.position(), std::string(what[0]).length()));
            }
            if(global_active) {
                start = what[0].second;  // we have the global flag, so we search all results
            } else {
                break; // we don't have global flag, so we search just for the first
            }
        }

    } else {
        int iterator = 0;
        while(iterator < text.length())
        {
            if(text[iterator] == pattern[0])
            {   // there is a first character match
                if(text.substr(iterator, pattern.length()) == pattern)
                {  // there is a complete match -> store the highlight
                    highlights.push_back(TextHighLight(iterator, pattern.length()));
                    iterator += pattern.length();
                }
                else
                {   // even if the first characters are the same, it is not a match -> move to the next character
                    iterator++;
                }

            }
            else
            {   // there is no character match for this iteration -> move to the next character
                iterator++;
            }

        }
    }
    return highlights;
}

/// Replaces the portion of the string that is specified in the TextHighLight object
///
/// @param[in] replacement - the string meant to be put on the highlighted text's place
/// @param[in] highlight - specifies the position and the length of the sequance which is meant to be replaced
/// @param[in] text - the string which the function will make the change in
///
/// @return the highlight of the new sequance of text
TextHighLight StringManipulator::replace(const std::string &replacement, const TextHighLight &highlight, std::string &text) { // incomplete

    // treating exceptions
    treatingExceptionsForText(text);
    treatingExceptionsForHighlight(text, highlight);
    if(int i = findNonASCII(replacement) != -1) {
        throw std::invalid_argument("Replacement contains forbidden character - position: " + std::to_string(i));
        return TextHighLight(0,0);
    }
    // replacing the string
    text.replace(highlight.getPosition(), highlight.getLength(), replacement);
    TextHighLight highlight_result(highlight.getPosition(), replacement.length());
    return highlight_result; // (homework) - i don't know what the result must be :)))
}

/// Removes the unnecesary spaces (if there are two or more consecutive spaces, it will remove the aditional once and let just one to that positon
///
/// @param[in][out] text - the string which is meant to be trimmed
///
/// @return the number of changes in text
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

/// Puts spaces where there are missing (after punctuation signs must likely)
///
/// @param[in][out] text - the string which is meant to be modified
///
/// @return the number of changes in text
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
        if(text[positions[i]] == ',' && text[positions[i]+1] != ' ') // if there is a comma and the next character is not a space do"
        {
            text.insert(positions[i] + 1, " ");
            changes++;
            for(int j = i; j < positions.size(); ++j) {
                positions[j]++;
            }
        }
    }

    return changes;
 }

/// Capitalize all the letters from the given text
///
/// @param[in][out] text - the string which is meant to be modified
///
/// @return the number of changes in text
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
/// Capitalize the first letter of every sentence when is the case
///
/// @param[in][out] text - the string which is meant to be modified
///
/// @return the number of changes in text
int StringManipulator::capitalizeFirstLetter(std::string &text) { // incomplete
    // treating exceptions
    treatingExceptionsForText(text);

    int changes = 0;
    std::vector<int> dot_marks_positions = PunctuationMark::searchFor('.', text);
    std::vector<int> question_marks_positions = PunctuationMark::searchFor('?', text);
    std::vector<int> exclamation_marks_positions = PunctuationMark::searchFor('!', text);
    // doing for the first letter from the text
    if(isALowercaseLetter(text[0]))
    {
        text[0] -= 32;
        changes++;
    }
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

///Capitalize a certain potion of text specified by a highlight
///
/// @param[in][out] text - the string which is meant to be modified
/// @param[in] highlight - specifies the position and length of the sequance
///
/// @return the number of changes in text
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
/// Lowercase all of the letters from the text
///
/// @param[in][out] text - the string which is meant to be modified
///
/// @return the number of changes in text
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

/// Lowercase the first letter of every sentence, where is the case
/// ///
/// @param[in][out] text - the string which is meant to be modified
///
/// @return the number of changes in text
int StringManipulator::lowercaseFirstLetter(std::string &text) {
    // treating exceptions
    treatingExceptionsForText(text);

    int changes = 0;
    std::vector<int> dot_marks_positions = PunctuationMark::searchFor('.', text);
    std::vector<int> question_marks_positions = PunctuationMark::searchFor('?', text);
    std::vector<int> exclamation_marks_positions = PunctuationMark::searchFor('!', text);
    //doing it for the first letter from the text
    if(isACapitalLetter(text[0]))
    {
        text[0] += 32;
        changes++;
    }
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
/// Lowercase a certain sequance of text, specified by the highlight
///
/// @param[in][out] text - the string which is meant to be modified
/// @param[in] - it specifies the position and the length of the given sequance
///
/// @return the number of changes in text
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
/// Find all the non-ASCII characters and replace them with spaces
///
/// @param[in][out] text - the string which is meant to be modified
///
/// @return the number of changes in text
int StringManipulator::transformToASCII(std::string &text) {
    if(text.empty()) {
        throw std::invalid_argument("Empty text!");
    }
    int poz;
    int changes = 0;
    do {
        poz = findNonASCII(text);
        if(poz != -1) {
            text.replace(poz, 2, " ");
            changes++;
        }
    } while(poz != -1);
    //trim(text);
    return changes;
}
/// Convert the given date (which is actualy a string text) in a new format
///
/// @param[in][out] text - the string which is meant to be modified ( the time date - it must respect the format)
/// @param the desired format
///
/// @return the number of changes in text
int StringManipulator::changeDateFormat(std::string &text, dateFormat format) {
    treatingExceptionsForText(text);
    if(isADate(text)) {
        std::string day, month, year;
        std::string delimiter;
        for(auto p : text) { // find the delimiter
            if(!isNumber(p)) { // find the non-letter character (which is the delimiter)
                delimiter += p;
                break;
            }
        }
        if(delimiter != "." && delimiter != "/" && delimiter != "-") // the delimiter must pe one of ".", "/" or "-", else quit function
        {
            return -1;
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

/// returns the first occurance of a non-ASCII character
///
/// @param[in] the text meant to be analyzed
///
/// @return the first occurance of a non-ASCII character
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

/// it specifies if a given string respects the norms to be considered a time date
///
/// @param[in] text - the text meant to be analyzed
///
/// true if the text has date format and false if it doesn't
bool StringManipulator::isADate(const std::string &text) {
    std::string delimiter, day, month, year;
    bool result;
    treatingExceptionsForText(text);
    // find the delimiter (it could be '.', '/' or '-')
    if(find(".", text,false).size() == 2) {
        delimiter = ".";
    } else if(find("/", text,false).size() == 2) {
        delimiter = "/";
    } else if(find("-", text,false).size() == 2) {
        delimiter = "-";
    }
    // split the date to verify the component parts
    auto tokens = Utils::split(text, delimiter);
    // verify if the components are just numbers
    for(auto& token : tokens) {
        for(auto character : token) {
            if(!isNumber(character)) {
                return false; // the component contains a non-number character, so the text is not a date
            }
        }
    }
    // verify the lenght of the components (to see where is the day, month and year
    if(tokens[0].size() != 4) { // the year is not first
        // verify the day
        if(tokens[0].size() == 2) {
            day = tokens[0];
        } else {
            return false;
        }
        // verify the month
        if(tokens[1].size() == 2) {
            month = tokens[1];
        } else {
            return false;
        }
        // verify the year
        if(tokens[2].size() == 4) {
            year = tokens[2];
        } else {
            return false;
        }
    } else { // the year is first
        // verify the year
        if(tokens[0].size() == 4) {
            year = tokens[0];
        } else {
            return false;
        }
        // verify the month
        if(tokens[1].size() == 2) {
            month = tokens[1];
        } else {
            return false;
        }
        // verify the day
        if(tokens[2].size() == 2) {
            day = tokens[2];
        } else {
            return false;
        }
    }
    // verify the components ranges:
    if(day[0] == '0') {  // treating cases where we have days < 10
        if(day[1] == '0') { // the day can't be 0
            return false;
        }
    } else if(std::stoi(day) > 31) {
        return false;
    }
    if(month[0] == '0') { // treating cases where we have months < 10
        if(month[1] == '0') { // the month can't be 0
            return false;
        }
    } else if(std::stoi(month) > 12) {
        return false;
    }
    if(std::stoi(year) < 1000){
        return false;
    }
    return true;

}

/// it specifies if the given character is a capital letter or not
///
/// @param[in] the character
///
/// @return true if it is a capital letter and false if it is not
bool StringManipulator::isACapitalLetter(const char character) {
    return character >= 65 && character <= 90;
}

/// it specifies if the given character is a lowercase letter or not
///
/// @param[in] the character
///
/// @return true if it is a lowercase letter and false if it is not
bool StringManipulator::isALowercaseLetter(const char character) {
    return character >= 97 && character <= 122;
}

/// it specifies if the given character is a letter or not
///
/// @param[in] the character
///
/// @return true if it is a letter and false if it is not
bool StringManipulator::isLetter(const char character) {
    return (character >= 65 && character <= 90) || (character >= 97 && character <= 122);
}

/// it specifies if the given character is a digit or not
///
/// @param[in] the character
///
/// @return true if it is a digit and false if it is not
bool StringManipulator::isNumber(const char character) {
    return character >= 48 && character <= 57; // is in 0-9 in ASCII code or not
}

/// treats exception like "empty text" or  "forbiden character"
///
/// @param[in] text - the text meant to be analyzed
void StringManipulator::treatingExceptionsForText(const std::string &text) {
    if(text.empty()) {
        throw std::invalid_argument("Empty text");
    }
    if(int i = findNonASCII(text) != -1) {
        throw std::invalid_argument("Text contains forbidden character - position: " +  std::to_string(i));
    }
}

/// treats exception like "empty text" or  "forbiden character" or incorrect highlight
///
/// @param[in] text - the text meant to be analyzed
/// @param[in] highlight - the TextHighLight object meant to be analyzed
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
