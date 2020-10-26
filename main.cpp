#include "StringManipulator.h"
#include "TextHighLight.h"
#include <iostream>
#include <string>

int main(){
    std::string text = "HELLOžžžžŸ¢WORLD!";
    std::cout << StringManipulator::transformToASCII(text) << std::endl;
    std::cout << text << std::endl;
    return 0;
}