#include "TestTextEditor.h"
#include <TextHighLight.h>
#include <iostream>
#include <string>

void TestTextEditor::setUp(){
    std::string forbidden_text = "œžŸ¢¥";
    std::string standard_example = "Hello world!";
    std::string standard_token = "world";
}
//void TestTextEditor::tearDown(){}
void TestTextEditor::find_simpleCase() {
    std::string pattern = "ra";
    std::string text = "ad astra per aspera";
    TextHighLight* highlights = find(pattern, text, false);
    CPPUNIT_ASSERT(highlights[0] == TextHighLight(7,2));
    CPPUNIT_ASSERT(highlights[1] == TextHighLight(17,2));
}
void find_textTextNotFound() {
    std::string pattern = "temp";
    TextHighLight* highlights = find(pattern, standard_example, false);
    CPPUNIT_ASSERT(highlights = nullptr);
}
void TestTextEditor::find_Regex() {
    std::string pattern = "/e+/g";
    std::string text = "meet, street, sleep";
    TextHighLight* highlights = find(pattern, text, true);
    CPPUNIT_ASSERT(highlights[0] == TextHighLight(1,2));
    CPPUNIT_ASSERT(highlights[1] == TextHighLight(9,2));
    CPPUNIT_ASSERT(highlights[2] == TextHighLight(16,2));
}
void TestTextEditor::find_EmptyPattern() {
    std::string pattern = "";  // making the pattern empty
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, standard_example, false), std::invalid_argument);
}
void TestTextEditor::find_EmptyText() {
    std::string text = "";  //making the text empty
    CPPUNIT_ASSERT_THROW(StringManipulator::find(standard_token, text, false), std::invalid_argument);
}
void TestTextEditor::find_PatternWithUnexpectedCharacters() {
    CPPUNIT_ASSERT_THROW(StringManipulator::find(forbidden_text, standard_example, false), std::invalid_argument);
}
void TestTextEditor::find_TextWithUnexpectedCharacters() {
    CPPUNIT_ASSERT_THROW(StringManipulator::find(standard_token, forbidden_text, false), std::invalid_argument);
}
void TestTextEditor::find_TextOutOfBound() {  // (homework)
}
void TestTextEditor::find_PatternLargerThanText() {
    std::string pattern = "pattern larger than text";
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, standard_example, false), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::replace_simpleCase() {
    std::string text = "Hello there";
    TextHighLight highlight(6, 5);
    CPPUNIT_ASSERT(StringManipulator::replace(standard_token, highlight, text) == 5);
    CPPUNIT_ASSERT(text == standard_example);
}
void TestTextEditor::replace_ReplacementWithUnexpectedCharacter() {
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(forbidden_text, highlight, standard_example), std::invalid_argument);
}
void TestTextEditor::replace_TextWithUnexpectedCharacter() {
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, forbidden_text), std::invalid_argument);
}
void TestTextEditor::replace_EmptyText() {
    std::string text = "";
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, text), std::invalid_argument);
}
void TestTextEditor::replace_TextOutOfBound() {} // (homework)
void TestTextEditor::replace_NegativeHighLightPosition() {
    TextHighLight highlight(-1,2);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, standard_example), std::invalid_argument);
}
void TestTextEditor::replace_NegativeHighLightLength() {
    TextHighLight highlight(2,-1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, standard_example), std::invalid_argument);
}
void TestTextEditor::replace_PositionLargerThanMax() {
    TextHighLight highlight(50,3);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, standard_example), std::invalid_argument);
}
void TestTextEditor::replace_LengthLargerThanMax() {
    TextHighLight highlight(3,50);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, standard_example), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::trim_simpleCase() {
    std::string text = "Hello    world!";
    CPPUNIT_ASSERT(StringManipulator::trim(text) == 3);
    CPPUNIT_ASSERT(text == standard_example); 
}
void TestTextEditor::trim_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::trim(forbidden_text), std::invalid_argument);
}
void TestTextEditor::trim_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::trim(text), std::invalid_argument);
}
void TestTextEditor::trim_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::padding_simpeCase() {
    text = "Hi there!How are you?"
    CPPUNIT_ASSERT(padding(text) == 1);
    CPPUNIT_ASSERT(text  == "Hi there! How are you?");
}
void TestTextEditor::padding_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::padding(forbidden_text), std::invalid_argument);
}
void TestTextEditor::padding_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::padding(text), std::invalid_argument);
}
void TestTextEditor::padding_TextOutOfBound() {}
//===========================================================================================================
void TestTextEditor::capitalizeAll_simpleCase() {
    CPPUNIT_ASSERT(StringManipulator::capitalizeAll(standard_example) == 8);
    CPPUNIT_ASSERT(standard_example == "HELLO WORLD!");
}
void TestTextEditor::capitalizeAll_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeAll(forbidden_text), std::invalid_argument);
}
void TestTextEditor::capitalizeAll_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeAll(text), std::invalid_argument);
}
void TestTextEditor::capitalizeAll_TextOutOfBound() {}// (homework)
//===========================================================================================================
void TestTextEditor::capitalizeFirst_simpleCase() {
    std::string text = "hi there! how are you?";
    CPPUNIT_ASSERT(capitalizeFirst(text) == 2);
    CPPUNIT_ASSERT(text = "Hi there! How are you?");
}
void TestTextEditor::capitalizeFirst_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeFirst(forbidden_text), std::invalid_argument);
}
void TestTextEditor::capitalizeFirst_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeFirst(text), std::invalid_argument);
}
void TestTextEditor::capitalizeFirst_TextOutOfBound() {}// (homework)
//===========================================================================================================
void TestTextEditor::capitalizeOffset_simpleCase() {
    TextHighLight highlight(0,7);
    CPPUNIT_ASSERT(StringManipulator::capitalizeOffset(standard_example, highlight) == 5);
    CPPUNIT_ASSERT(standard_example = "HELLO World!");
}
void TestTextEditor::capitalizeOffset_UnexpectedCharacter() {
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(forbidden_text, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_EmptyText() {
    std::string text = "";
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_TextOutOfBound() {} //(homework)
void TestTextEditor::capitalizeOffset_NegativeHighPosition() {
    TextHighLight highlight(-1, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(standard_example, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_NegativeHighLightLength() {
    TextHighLight highlight(0, -1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(standard_example, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_PositionLargerThanMax() {
    TextHighLight highlight(32, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(standard_example, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_LengthLargerThanMax() {
    TextHighLight highlight(7, 15);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(standard_example, highlight), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::lowercaseAll_simpleCase() {
    CPPUNIT_ASSERT(StringManipulator::lowercaseAl(standard_example) == 2);
    CPPUNIT_ASSERT(standard_example = "hello world!");
}
void TestTextEditor::lowercaseAll_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseAll(forbidden_text), std::invalid_argument);
}
void TestTextEditor::lowercaseAll_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseAll(text), std::invalid_argument);
}
void TestTextEditor::lowercaseAll_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::lowercaseFirst_simpleCase() {
    CPPUNIT_ASSERT(StringManipulator::lowercaseFirst(standard_example) == 1);
    CPPUNIT_ASSERT(standard_example == "hello world!");
} 
void TestTextEditor::lowercaseFirst_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseFirst(forbidden_text), std::invalid_argument);
}
void TestTextEditor::lowercaseFirst_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseFirst(text), std::invalid_argument);
}
void TestTextEditor::lowercaseFirst_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::lowercaseOffset_simpleCase() {
    std::string text = "HELlo World!";
    TextHighLight highlight(1,6);
    CPPUNIT_ASSERT(StringManipulator::lowercaseOffset(text, highlight) == 3);
    CPPUNIT_ASSERT(text == standard_example);
}
void TestTextEditor::lowercaseOffset_EmptyText() {
    std::string text = "";
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text), std::invalid_argument);
}
void TestTextEditor::lowercaseOffset_TextOutOfBound() {} // (homework)
void TestTextEditor::lowercaseOffset_NegativeHighLightPosition() {
    TextHighLight highlight(-1, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(standard_example), std::invalid_argument);
}
void TestTextEditor::lowercaseOffset_NegativeHighLightLength() {
    TextHighLight highlight(0, -1);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(standard_example), std::invalid_argument);
}
void TestTextEditor::lowercaseOffset_PositionLargerThanMax() {
    TextHighLight highlight(32, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(standard_example, highlight), std::invalid_argument);
}
void TestTextEditor::lowercaseOffset_LengthLargerThanMax() {
    TextHighLight highlight(7, 8);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(standard_example, highlight), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::transformToASCII_simpleCase() {
    std::string text = "Hiœžthere!";
    CPPUNIT_ASSERT(StringManipulator::transformToASCII(text) == 2);
    CPPUNIT_ASSERT( text == "Hi  there!");
}
void TestTextEditor::transformToASCII_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::transformToASCII(text), std::invalid_argument);
}
void TestTextEditor::transformToASCII_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::changeDateFormat_simpleCase() {
    std::string text = "2020/10/22";
    dateFormat format = little_endian;
    CPPUNIT_ASSERT(StringManipulator::changeDateFormat(text, format) == 1);
    CPPUNIT_ASSERT(text = 22/10/2020);
}
void TestTextEditor::changeDateFormat_EmptyText() {
    std::string text = "";
    dateFormat format = big_endian;
    CPPUNIT_ASSERT_THROW(StringManipulator::changeDateFormat(text, format), std::invalid_argument);
}
void TestTextEditor::changeDateFormat_TextOutOfBound() {} // (homework)
void TestTextEditor::changeDateFormat_UnexpectedCharacter() {
    dateFormat format = big_endian;
    CPPUNIT_ASSERT_THROW(StringManipulator::changeDateFormat(forbidden_text, format), std::invalid_argument);
}



