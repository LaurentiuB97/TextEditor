#include "Regex.h"
#include "Utils.h"
#include "PunctuationMark.h"
#include <iostream>

// INCOMPLETE         
bool Regex::verify_character(const char character,
                               const std::string  &regex,
                               const states current_state,
                               bool insensitive) { // the regex must be well defined
    int pos1 = regex.find("[");
    int pos2 = regex.find("]");
    if(pos1 != std::string::npos && pos2 != std::string::npos) {  // the character must be contained in a definet interval
        bool resp = belongsToInterval(character, regex.substr(pos1+1, pos2-pos1-1), sensitive);
        std::cout << "Interval " << regex.substr(pos1+1, pos2-pos1-1) << std::endl;
        std::cout << "Resp: " << resp << std::endl;
        return resp;    
    }
    return false;
}

std::vector<TextHighLight> Regex::filter(const std::string &expresion) {
    std::vector<TextHighLight> results;
    std::vector<std::string> tokens = Utils::split(expresion, "/");
    std::string regex = tokens[0];
    std::string flags;
    bool insensitive = false;
    bool global = false;
    // ANALIZE
    if(tokens.size() == 2) {
        flags = tokens[1];
    }
    // ANALIZE THE FLAGS
    // treat special cases
    // (homework)
    // see which flags do we have
    if(flags.find("i") != std::string::npos) {
        insensitive = true;
    }
    if(flags.find("g")) {
        global = true;
    }
    // ANALIZE THE QUANTIFIERS
    // treat special cases
    // (homework)
    // see which quantifiers do we have


    
    
    
}

bool Regex::belongsToInterval(const char character, const std::string regex_interval, bool insensitive) {
    if(regex_interval.size() == 3 && regex_interval[1] == '-') {  // if in the middle is a line
        const char left_bond = regex_interval[0];
        const char right_bond = regex_interval[2];
        if(left_bond <= right_bond) {  // verifying the range
            if(character >= left_bond && character <= right_bond) {  // if the character belongs to this range of values
                return true;  // the character belong to the range
            } else {
                return false;  // the character does not belong to the range
            }
        } else {
            throw std::invalid_argument("Reversed range of values");
        }
    } else {
            throw std::invalid_argument("Inappropriate range syntax");
    }
    return false;
}