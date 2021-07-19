#include "TestTextEditor.h"
#include "TextHighLight.h"
#include "StringManipulator.h"
#include <QString>
#include <iostream>
#include <string>

QString forbidden_text = "œžŸ¢¥";
QString standard_example = "Hello world!";
QString standard_token = "world";

/// setUp the repetitive values
void TestTextEditor::setUp() {
    QString forbidden_text = "œžŸ¢¥";
    QString standard_example = "Hello world!";
    QString standard_token = "world";
}
void TestTextEditor::tearDown(){} 

/// it verifies the find function in a simple case, with no errors
void TestTextEditor::find_simpleCase() {
    QString pattern = "ra";
    QString text = "ad astra per aspera";
    std::vector<TextHighLight> highlights = StringManipulator::find(pattern, text, false);
    CPPUNIT_ASSERT(highlights[0].equals(TextHighLight(6,2)));
    CPPUNIT_ASSERT(highlights[1].equals(TextHighLight(17,2)));
}
/// it verifies the find function when the pattern is not found in the main text
void TestTextEditor::find_TextNotFound() {
    QString pattern = "temp";
    std::vector<TextHighLight> highlights = StringManipulator::find(pattern, standard_example, false);
    CPPUNIT_ASSERT(highlights.size() == 0);
}

/// it verifies the find function giving a simple regex for searching
void TestTextEditor::find_Regex() {
    QString pattern = "(e+)";
    QString text = "meet, street, sleep";
    std::vector<TextHighLight> highlights = StringManipulator::find(pattern, text, true);
    CPPUNIT_ASSERT(highlights[0].equals(TextHighLight(1,2)));
    CPPUNIT_ASSERT(highlights[1].equals(TextHighLight(9,2)));
    CPPUNIT_ASSERT(highlights[2].equals(TextHighLight(16,2)));
}

/// it verifies if the find functions throws an exception message when the pattern is empty
void TestTextEditor::find_EmptyPattern() {
    QString pattern = "";  // making the pattern empty
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, standard_example, false), std::invalid_argument);
}

/// it verifies if the find function throws an exception message when the main text is empty
void TestTextEditor::find_EmptyText() {
    QString text = "";  //making the text empty
    CPPUNIT_ASSERT_THROW(StringManipulator::find(standard_token, text, false), std::invalid_argument);
}

/// it verifies if the find function throws an exception message when the pattern contains some forbidden characters
void TestTextEditor::find_PatternWithUnexpectedCharacters() {
    CPPUNIT_ASSERT_THROW(StringManipulator::find(forbidden_text, standard_example, false), std::invalid_argument);
}
/// it verifies if the find function throws an exception message when the main text contais some forbidden characters;
void TestTextEditor::find_TextWithUnexpectedCharacters() {
    CPPUNIT_ASSERT_THROW(StringManipulator::find(standard_token, forbidden_text, false), std::invalid_argument);
}


/// it verifies if the find function throws an exception message when the pattern to find is larger than the main text (logic error)
void TestTextEditor::find_PatternLargerThanText() {
    QString pattern = "pattern larger than text";
    CPPUNIT_ASSERT_THROW(StringManipulator::find(pattern, standard_example, false), std::invalid_argument);
}

//===========================================================================================================
/// it verifies the replace function in a non-exceptional case.
/// The main task here is to replace "there" ffrom "Hello there!" with "world". The result will be "Hello world!" (the standard example)
void TestTextEditor::replace_simpleCase() {
    QString text = "Hello there!";
    TextHighLight highlight(6, 5);
    CPPUNIT_ASSERT(StringManipulator::replace(standard_token, highlight, text).equals(TextHighLight(6,5)));
    CPPUNIT_ASSERT(text == standard_example);
}

/// it verifies if the replace function throws an exception message when the replacement contains forbidden characters
void TestTextEditor::replace_ReplacementWithUnexpectedCharacter() {
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(forbidden_text, highlight, standard_example), std::invalid_argument);
}

/// it verifies if the replace function throws an exception message when main text contains forbidden characters
void TestTextEditor::replace_TextWithUnexpectedCharacter() {
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, forbidden_text), std::invalid_argument);
}

/// it verifies if the replace function throws an exception message when the main text is empty
void TestTextEditor::replace_EmptyText() {
    QString text = "";
    TextHighLight highlight(0,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, text), std::invalid_argument);
}

/// it verifies if the replace function throws an exception message when the highlight position is negative (the position of a string is always positive)
void TestTextEditor::replace_NegativeHighLightPosition() {
    TextHighLight highlight(-1,2);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, standard_example), std::invalid_argument);
}

/// it verifies if the replace function throws an exception message when the highlight length is negative (the length must always be positive)
void TestTextEditor::replace_NegativeHighLightLength() {
    TextHighLight highlight(2,-1);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, standard_example), std::invalid_argument);
}

/// it verifies if the replace function throws an exception message when the highlight position is larger than the length of the string (out-of-bound parameter)
void TestTextEditor::replace_PositionLargerThanMax() {
    TextHighLight highlight(50,3);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, standard_example), std::invalid_argument);
}

/// it verifies if the replace function throws an exception message when the length of the highlight length is larger than main_text.length() - highlight_position.
/// which means that the highlight goes beyond string terminator (out-of-bound parameter)
void TestTextEditor::replace_LengthLargerThanMax() {
    TextHighLight highlight(3,50);
    CPPUNIT_ASSERT_THROW(StringManipulator::replace(standard_token, highlight, standard_example), std::invalid_argument);
}
//===========================================================================================================

/// it verifies the trim function gives the right results in a non-exceptional case. It must remove the unnecessary spaces between two words
/// and return the number o changes that have occured
void TestTextEditor::trim_simpleCase() {
    QString text = "Hello    world!";
    CPPUNIT_ASSERT(StringManipulator::trim(text) == 3);
    CPPUNIT_ASSERT(text == standard_example); 
}

/// it verifies if the trim function throws an exception message when the text contains forbidden characters
void TestTextEditor::trim_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::trim(forbidden_text), std::invalid_argument);
}

/// it verifies if the trim function throws an exception message when the text is empty
void TestTextEditor::trim_EmptyText() {
    QString text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::trim(text), std::invalid_argument);
}
//===========================================================================================================

/// it verifies the padding function to give the right results. It must put a space after the first sentance and return the number of changes (one change)
void TestTextEditor::padding_simpeCase() {
    QString text = "Hi there!How are you?";
    CPPUNIT_ASSERT(StringManipulator::padding(text) == 1);
    CPPUNIT_ASSERT(text  == "Hi there! How are you?");
}

/// it verifies if the padding function throws an exception message when the text contains forbidden characters
void TestTextEditor::padding_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::padding(forbidden_text), std::invalid_argument);
}

/// it verifies if the padding function throws an exception message when the text is empty
void TestTextEditor::padding_EmptyText() {
    QString text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::padding(text), std::invalid_argument);
}
//===========================================================================================================

/// it verifies the capitalizeAll function to set uppercase for all characters from the given text and also return the number of changes
void TestTextEditor::capitalizeAll_simpleCase() {
    QString text = standard_example;
    CPPUNIT_ASSERT(StringManipulator::capitalizeAll(text) == 9);
    CPPUNIT_ASSERT(text == "HELLO WORLD!");
}

/// it verifies if the capitalizeAll function throws an exception message when the text contains forbidden characters
void TestTextEditor::capitalizeAll_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeAll(forbidden_text), std::invalid_argument);
}

/// it verifies if the capitalizeAll function throws an exception message when the text is empty
void TestTextEditor::capitalizeAll_EmptyText() {
    QString text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeAll(text), std::invalid_argument);
}
//===========================================================================================================

/// it verifies the capitalizeFirst function to set lowercase for all characters from the given text and also to return the number of changes
void TestTextEditor::capitalizeFirst_simpleCase() {
    QString text = "hi there! how are you?";
    CPPUNIT_ASSERT(StringManipulator::capitalizeFirstLetter(text) == 2);
    CPPUNIT_ASSERT(text == "Hi there! How are you?");
}

/// it verifies if the capitalizeFirst function throws an exception message when the text contains forbidden characters
void TestTextEditor::capitalizeFirst_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeFirstLetter(forbidden_text), std::invalid_argument);
}

/// it verifies if the capitalizeFirst function throws an exception message when the text is empty
void TestTextEditor::capitalizeFirst_EmptyText() {
    QString text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeFirstLetter(text), std::invalid_argument);
}

//===========================================================================================================
/// it verifies the capitalizeOffset function to capitalize the demanded characters and to return the number of changes
void TestTextEditor::capitalizeOffset_simpleCase() {
    TextHighLight highlight(0,7);
    QString text = standard_example;
    CPPUNIT_ASSERT(StringManipulator::capitalizeOffset(text, highlight) == 5);
    CPPUNIT_ASSERT(text == "HELLO World!");
}

/// it verifies if the capitalizeOffset function throws an exception message when the text contains forbidden characters
void TestTextEditor::capitalizeOffset_UnexpectedCharacter() {
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(forbidden_text, highlight), std::invalid_argument);
}

/// it verifies if the capitalizeOffset function throws an exception message when the text is empty
void TestTextEditor::capitalizeOffset_EmptyText() {
    QString text = "";
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(text, highlight), std::invalid_argument);
}

/// it verifies if the capitalizeOffset function throws an exception message when the highlight position is negative (a string position must always be positive or zero)
void TestTextEditor::capitalizeOffset_NegativeHighLightPosition() {
    TextHighLight highlight(-1, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(standard_example, highlight), std::invalid_argument);
}

/// it verifies if the capitalizeOffset function throws an exception message when the highlight length is negative (length must always be positive or zero)
void TestTextEditor::capitalizeOffset_NegativeHighLightLength() {
    TextHighLight highlight(0, -1);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(standard_example, highlight), std::invalid_argument);
}

/// it verifies if the capitalizeOffset function throws an exception message when the highlight position is larger then the text length (out-of-bound parameter)
void TestTextEditor::capitalizeOffset_PositionLargerThanMax() {
    TextHighLight highlight(32, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(standard_example, highlight), std::invalid_argument);
}

/// it verifies if the capitalizeOffset function throws an exception message when the length of the highlight length is larger than text.length() - highlight_position.
/// which means that the highlight goes beyond string terminator (out-of-bound parameter)
void TestTextEditor::capitalizeOffset_LengthLargerThanMax() {
    TextHighLight highlight(7, 15);
    CPPUNIT_ASSERT_THROW(StringManipulator::capitalizeOffset(standard_example, highlight), std::invalid_argument);
}
//===========================================================================================================

/// it verifies if the lowercaseAll function sets lowercase for all characters from the given text and also returns the number of changes
void TestTextEditor::lowercaseAll_simpleCase() {
    QString text  = standard_example;
    CPPUNIT_ASSERT(StringManipulator::lowercaseAll(text) == 1);
    CPPUNIT_ASSERT(text == "hello world!");
}

/// it verifies the lowercaseAll function to throw an exception message when the text contains forbidden characters
void TestTextEditor::lowercaseAll_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseAll(forbidden_text), std::invalid_argument);
}

/// it verifies the lowercaseAll function to throw an exception message when the text is empty
void TestTextEditor::lowercaseAll_EmptyText() {
    QString text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseAll(text), std::invalid_argument);
}

//===========================================================================================================

/// it verifies the lowercaseFirst function to set lowercase for the first letter from the text and also to return the number of chanes (one change)
void TestTextEditor::lowercaseFirst_simpleCase() {
    QString text = standard_example;
    CPPUNIT_ASSERT(StringManipulator::lowercaseFirstLetter(text) == 1);
    CPPUNIT_ASSERT(text == "hello world!");
}

/// it verifies if the lowercaseFirst function throws an exception message when the text contains forbidden characters
void TestTextEditor::lowercaseFirst_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseFirstLetter(forbidden_text), std::invalid_argument);
}

/// it verifies if the lowercaseFirst function throws an exception message when the text is empty
void TestTextEditor::lowercaseFirst_EmptyText() {
    QString text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseFirstLetter(text), std::invalid_argument);
}

//===========================================================================================================

/// it verifies if the lowercaseOffset function lowercase the specified characters and returns the number of changes
void TestTextEditor::lowercaseOffset_simpleCase() {
    QString text = "HELlo World!";
    TextHighLight highlight(1,6);
    CPPUNIT_ASSERT(StringManipulator::lowercaseOffset(text, highlight) == 3);
    CPPUNIT_ASSERT(text == standard_example);
}

/// it verifies if the lowercaseOffset function throws an exception message when the text is empty
void TestTextEditor::lowercaseOffset_EmptyText() {
    QString text = "";
    TextHighLight highlight(1,1);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text, highlight), std::invalid_argument);
}

/// it verifies if the lowercaseOffset function throws an exception message when the highlight position is negative (a string position must always be positive or zero)
void TestTextEditor::lowercaseOffset_NegativeHighLightPosition() {
    QString text = standard_example;
    TextHighLight highlight(-1, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text, highlight), std::invalid_argument);
}

/// it verifies if the lowercaseOffset function throws an exception message when the highlight length is negative (length must always be positive or zero)
void TestTextEditor::lowercaseOffset_NegativeHighLightLength() {
    QString text = standard_example;
    TextHighLight highlight(0, -1);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text, highlight), std::invalid_argument);
}

/// it verifies if the lowercaseOffset function throws an exception message when the highlight position is larger then the text length (out-of-bound parameter)
void TestTextEditor::lowercaseOffset_PositionLargerThanMax() {
    QString text = standard_example;
    TextHighLight highlight(32, 2);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text, highlight), std::invalid_argument);
}

/// it verifies if the lowercaseOffset function throws an exception message when the length of the highlight length is larger than text.length() - highlight_position.
/// which means that the highlight goes beyond string terminator (out-of-bound parameter)
void TestTextEditor::lowercaseOffset_LengthLargerThanMax() {
    QString text = standard_example;
    TextHighLight highlight(7, 8);
    CPPUNIT_ASSERT_THROW(StringManipulator::lowercaseOffset(text, highlight), std::invalid_argument);
}
//===========================================================================================================

/// it verifies if the transformToASCII function replace the forbidden characters with blank spaces
void TestTextEditor::transformToASCII_simpleCase() {
    QString text = "Hiœžthere!";
    CPPUNIT_ASSERT(StringManipulator::transformToASCII(text) == 2);
    CPPUNIT_ASSERT( text == "Hi  there!");
}

/// it verifies if the transformToASCII function throws an exception message when the text is empty
void TestTextEditor::transformToASCII_EmptyText() {
    QString text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::transformToASCII(text), std::invalid_argument);
}

//===========================================================================================================

/// it verifies if the changeDateFormat function if the given date is properly changed in the specified format and also returns the number of changes 
void TestTextEditor::changeDateFormat_simpleCase() {
    QString text = "2020/10/22";
    CPPUNIT_ASSERT(StringManipulator::changeDateFormat(text, StringManipulator::slash_little_endian) == 1);
    CPPUNIT_ASSERT(text == "22/10/2020");
}

/// it verifies if the changeDateFormat function throws an exception message when the text is empty
void TestTextEditor::changeDateFormat_EmptyText() {
    QString text = "";
    CPPUNIT_ASSERT_THROW(StringManipulator::changeDateFormat(text, StringManipulator::line_little_endian), std::invalid_argument);
}

/// it verifies if the changeDateFormat function throws an exception message when the text contains forbidden characters
void TestTextEditor::changeDateFormat_UnexpectedCharacter() {
    CPPUNIT_ASSERT_THROW(StringManipulator::changeDateFormat(forbidden_text, StringManipulator::line_little_endian), std::invalid_argument);
}



