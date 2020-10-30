#include "StringManipulator.h"
#include "TextHighLight.h"
#include "PunctuationMark.h"
#include "Utils.h"
#include <iostream>
#include <string>

int main(){
    std::string text = "2020/01/11";
    std::cout << StringManipulator::changeDateFormat(text, StringManipulator::line_little_endian) << std::endl;
    std::cout << text << std::endl;
    return 0;
}