#include "StringManipulator.h"
#include "TextHighLight.h"
#include "PunctuationMark.h"
#include "Utils.h"
#include "Regex.h"
#include <iostream>
#include <string>

int main(){
    if(Regex::verify_character('z', "[a-f]", SUCCESS_AND_CAN_BE_FINISHED)) {
        std::cout << "apartine" << std::endl;
    } else {
        std::cout << "nu apartine" << std::endl;
    }
    return 0;
}