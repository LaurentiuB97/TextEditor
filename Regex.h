#ifndef REGEX_H
#define REGEX_H
#include <string>
#include <vector>
#include "TextHighLight.h"
enum states {FAILED, //the current search has failed, the result is not satisfying
                    SUCCESS_BUT_UNFINISHED,  // the character is valid but it's still not enough to return a satisfying return
                    SUCCESS_AND_CAN_BE_FINISHED, //  can return a satisfying result in the current state, but it can continue to analize
                    SUCCES_AND_FINISHED, // the character is valid and is no need to continue the searching. The search for this token must be stopped
                    INVALID_REGEX // the regular expresion is not correctly defined
                    };
class Regex {
public:
    
    static bool verify_character(const char character,
                                   const std::string  &regex,
                                   const states current_state,
                                   bool insensitive = false);
    static std::vector<TextHighLight> filter(const std::string &expresion);
    static bool belongsToInterval(const char character,
                                  const std::string regex_interval,
                                  bool insensitive = false);
    

};

#endif // REGEX_H