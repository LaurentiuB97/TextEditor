#include "TestTextEditor.h"
#include <TextHighLight.h>
#include <iostream>
#include <string>

void TestTextEditor::setUp(){}
void TestTextEditor::tearDown(){}
void TestTextEditor::find_simpleCase() {
    std::string pattern = "ra";
    std::string text = "ad astra per aspera";
    TextHighLight* highlights = find(pattern, text, false);
    CPPUNIT_ASSERT(highlights[0] == TextHighLight(7,2));
    CPPUNIT_ASSERT(highlights[1] == TextHighLight(17,2));
}
void find_textTextNotFound() {
    std::string pattern = "temp";
    std::string text = "sentence";
    TextHighLight* highlights = find(pattern, text, false);
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
    std::string text = "text";
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, text, false), std::invalid_argument);

}
void TestTextEditor::find_EmptyText() {
    std::string pattern = "pattern";
    std::string text = "";  //making the text empty
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, text, false), std::invalid_argument);
}
void TestTextEditor::find_PatternWithUnexpectedCharacters() {
    std::string pattern = "œžŸ¢¥";
    std::string text = "sentence";
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, text, false), std::invalid_argument);
}
void TestTextEditor::find_TextWithUnexpectedCharacters() {
    std::string pattern = "p";
    std::string text = "œžŸ¢¥";
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, text, false), std::invalid_argument);
}
void TestTextEditor::find_TextOutOfBound() {  // (homework)
}
void TestTextEditor::find_PatternLargerThanText() {
    std::string pattern = "pattern larger than text";
    std::string text = "text";
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, text, false), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::replace_simpleCase() {
    std::string text = "Good morning!";
    std::string replacement = "afternoon";
    TextHighLight highlight(5, 7);
    CPPUNIT_ASSERT(StringManipulator::replace(replacement, highlight, text) == 7);
    CPPUNIT_ASSERT(text == "Good afternoon!");
}
void TestTextEditor::replace_ReplacementWithUnexpectedCharacter() {
    std::string replacement = "œžŸ¢¥";
    std::string text = "sentence";
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
void TestTextEditor::replace_TextWithUnexpectedCharacter() {
    std::string replacement = "a";
    std::string text = "œžŸ¢¥";
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
void TestTextEditor::replace_EmptyText() {
    std::string replacement = "replacement";
    std::string text = "";
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
void TestTextEditor::replace_TextOutOfBound() {} // (homework)
void TestTextEditor::replace_NegativeHighLightPosition() {
    std::string replacement = "repl";
    std::string text = "sentence";
    TextHighLight highlight(-1,2);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
void TestTextEditor::replace_NegativeHighLightLength() {
    std::string replacement = "repl";
    std::string text = "sentence";
    TextHighLight highlight(2,-1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
void TestTextEditor::replace_PositionLargerThanMax() {
    std::string replacement = "repl";
    std::string text = "sentence";
    TextHighLight highlight(50,3);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
void TestTextEditor::replace_LengthLargerThanMax() {
    std::string replacement = "repl";
    std::string text = "sentence";
    TextHighLight highlight(3,50);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::trim_simpleCase() {
    std::string text = "Hello    world!";
    CPPUNIT_ASSERT(StringManipulator::trim(text) == 3);
    CPPUNIT_ASSERT(text == "Hello world!"); 
}
void TestTextEditor::trim_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::trim(text), std::invalid_argument);
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
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::padding(text), std::invalid_argument);
}
void TestTextEditor::padding_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::padding(text), std::invalid_argument);
}
void TestTextEditor::padding_TextOutOfBound() {}
//===========================================================================================================
void TestTextEditor::capitalizeAll_simpleCase() {
    std::string text = "Hello World!";
    CPPUNIT_ASSERT(StringManipulator::capitalizeAll(text) == 8);
    CPPUNIT_ASSERT(text == "HELLO WORLD!");
}
void TestTextEditor::capitalizeAll_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeAll(text), std::invalid_argument);
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
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeFirst(text), std::invalid_argument);
}
void TestTextEditor::capitalizeFirst_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeFirst(text), std::invalid_argument);
}
void TestTextEditor::capitalizeFirst_TextOutOfBound() {}// (homework)
//===========================================================================================================
void TestTextEditor::capitalizeOffset_simpleCase() {
    std::string text = "Hello world";
    TextHighLight highlight(0,7);
    CPPUNIT_ASSERT(StringManipulator::capitalizeOffset(text, highlight) == 5);
    CPPUNIT_ASSERT(text = "HELLO World");
}
void TestTextEditor::capitalizeOffset_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥";
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_EmptyText() {
    std::string text = "";
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_TextOutOfBound() {} //(homework)
void TestTextEditor::capitalizeOffset_NegativeHighPosition() {
    std::string text = "sentence";
    TextHighLight highlight(-1, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_NegativeHighLightLength() {
    std::string text = "sentence";
    TextHighLight highlight(0, -1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_PositionLargerThanMax() {
    std::string text = "sentence";
    TextHighLight highlight(32, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_LengthLargerThanMax() {
    std::string text = "sentence";
    TextHighLight highlight(7, 5);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::lowercaseAll_simpleCase() {
    std::string text = "Hello World!";
    CPPUNIT_ASSERT(StringManipulator::lowercaseAl(text) == 2);
    CPPUNIT_ASSERT(text = "hello world!");
}
void TestTextEditor::lowercaseAll_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseAll(text), std::invalid_argument);
}
void TestTextEditor::lowercaseAll_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseAll(text), std::invalid_argument);
}
void TestTextEditor::lowercaseAll_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::lowercaseFirst_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseFirst(text), std::invalid_argument);
}
void TestTextEditor::lowercaseFirst_EmptyText() {
    std::string text;
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseFirst(text), std::invalid_argument);
}
void TestTextEditor::lowercaseFirst_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::lowercaseOffset_EmptyText() {
    std::string text = "";
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text), std::invalid_argument);
}
void TestTextEditor::lowercaseOffset_TextOutOfBound() {} // (homework)
void TestTextEditor::lowercaseOffset_NegativeHighLightPosition() {
    std::string text = "sentence";
    TextHighLight highlight(-1, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text), std::invalid_argument);
}
void TestTextEditor::lowercaseOffset_NegativeHighLightLength() {
    std::string text = "sentence";
    TextHighLight highlight(0, -1);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text), std::invalid_argument);
}
void TestTextEditor::lowercaseOffset_PositionLargerThanMax() {
    std::string text = "sentence";
    TextHighLight highlight(32, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::lowercaseOffset_LengthLargerThanMax() {
    std::string text = "sentence";
    TextHighLight highlight(7, 5);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text, highlight), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::transformToASCII_EmptyText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::transformToASCII(text), std::invalid_argument);
}
void TestTextEditor::transformToASCII_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::changeDateFormat_EmptyText() {
    std::string text = "";
    dateFormat format = big_endian;
    CPPUNIT_ASSERT_THROW(StringManipulator::changeDateFormat(text, format), std::invalid_argument);
}
void TestTextEditor::changeDateFormat_TextOutOfBound() {} // (homework)
void TestTextEditor::changeDateFormat_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥";
    dateFormat format = big_endian;
    CPPUNIT_ASSERT_THROW(StringManipulator::changeDateFormat(text, format), std::invalid_argument);
}



