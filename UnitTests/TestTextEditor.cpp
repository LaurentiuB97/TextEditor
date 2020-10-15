#include "TestTextEditor.h"
#include <TextHighLight.h>
#include <iostream>
#include <string>

void TestTextEditor::setUp(){}
void TestTextEditor::tearDown(){}
void TestTextEditor::find_NullPattern() {
    std::string pattern = "";  // making the pattern null
    std::string text = "text";
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, text, false), std::invalid_argument);

}
void TestTextEditor::find_NullText() {
    std::string pattern = "pattern";
    std::string text = "";  //making the text null
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
void TestTextEditor::find_PatternLargerThenText() {
    std::string pattern = "pattern larger then text";
    std::string text = "text";
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, text, false), std::invalid_argument);
}
//===========================================================================================================
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
void TestTextEditor::replace_NullText() {
    std::string replacement = "replacement";
    std::string replacement = "";
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
void TestTextEditor::replace__TextOutOfBound() {} // (homework)
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
void TestTextEditor::replace_PositionLargerThenMax() {
    std::string replacement = "repl";
    std::string text = "sentence";
    TextHighLight highlight(50,3);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
void TestTextEditor::replace_LengthLargerThenMax() {
    std::string replacement = "repl";
    std::string text = "sentence";
    TextHighLight highlight(3,50);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(replacement, highlight, text), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::trim_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::trim(text), std::invalid_argument);
}
void TestTextEditor::trim_NullText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::trim(text), std::invalid_argument);
}
void TestTextEditor::trim_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::padding_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::padding(text), std::invalid_argument);
}
void TestTextEditor::padding_NullText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::padding(text), std::invalid_argument);
}
void TestTextEditor::padding_TextOutOfBound() {}
//===========================================================================================================
void TestTextEditor::capitalizeAll_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeAll(text), std::invalid_argument);
}
void TestTextEditor::capitalizeAll_NullText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeAll(text), std::invalid_argument);
}
void TestTextEditor::capitalizeAll_TextOutOfBound() {}// (homework)
//===========================================================================================================
void TestTextEditor::capitalizeFirst_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeFirst(text), std::invalid_argument);
}
void TestTextEditor::capitalizeFirst_NullText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeFirst(text), std::invalid_argument);
}
void TestTextEditor::capitalizeFirst_TextOutOfBound() {}// (homework)
//===========================================================================================================
void TestTextEditor::capitalizeOffset_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥";
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_NullText() {
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
void TestTextEditor::capitalizeOffset_PositionLargerThenMax() {
    std::string text = "sentence";
    TextHighLight highlight(32, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::capitalizeOffset_LengthLargerThenMax() {
    std::string text = "sentence";
    TextHighLight highlight(7, 5);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::lowercaseAll_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥  ";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseAll(text), std::invalid_argument);
}
void TestTextEditor::lowercaseAll_NullText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseAll(text), std::invalid_argument);
}
void TestTextEditor::lowercaseAll_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::lowercaseFirst_UnexpectedCharacter() {
    std::string text = "œžŸ¢¥";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseFirst(text), std::invalid_argument);
}
void TestTextEditor::lowercaseFirst_NullText() {
    std::string text;
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseFirst(text), std::invalid_argument);
}
void TestTextEditor::lowercaseFirst_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::lowercaseOffset_NullText() {
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
void TestTextEditor::lowercaseOffset_PositionLargerThenMax() {
    std::string text = "sentence";
    TextHighLight highlight(32, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text, highlight), std::invalid_argument);
}
void TestTextEditor::lowercaseOffset_LengthLargerThenMax() {
    std::string text = "sentence";
    TextHighLight highlight(7, 5);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text, highlight), std::invalid_argument);
}
//===========================================================================================================
void TestTextEditor::transformToASCII_NullText() {
    std::string text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::transformToASCII(text), std::invalid_argument);
}
void TestTextEditor::transformToASCII_TextOutOfBound() {} // (homework)
//===========================================================================================================
void TestTextEditor::changeDateFormat_NullText() {
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
void TestTextEditor::changeDateFormat_UnepectedDateFormat() {
    std::string text = "12/03/2020";
    CPPUNIT_ASSERT_THROW(StringManipulator::changeDateFormat(text, anything_but_not_date_format), std::invalid_argument);
}


