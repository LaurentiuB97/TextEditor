#ifndef TESTTEXTEDITOR_H
#define TESTTEXTEDITOR_H
#include "StringManipulator.h"
#include "textHighLight.h"
#include <cppunit/TestFixture.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class TestTextEditor : public Cppunit::TextFixture {
    CPPUNIT_TEST_SUITE(TestTextEditor);
    CPPUNIT_TEST();
    CPPUNIT_TEST_SUITE_END();
 public:
    void setUp();
    void tearDown();
    void find_NullPattern();
    void find_NullText();
    void find_PatternWithUnexpectedCharacters();
    void find_TextWithUnexpectedCharacters();
    void find_TextOutOfBound();
    void find_PatternLargerThenText();
    //===========================================================================================================
    void replace_ReplacementWithUnexpectedCharacter();
    void replace_TextWithUnexpectedCharacter();
    void replace_NullText();
    void replace__TextOutOfBound();
    void replace_NegativeHighLightPosition();
    void replace_NegativeHighLightLength();
    void replace_PositionLargerThenMax();
    void replace_LengthLargerThenMax();
    //===========================================================================================================
    void trim_UnexpectedCharacter();
    void trim_NullText();
    void trim_TextOutOfBound();
    //===========================================================================================================
    void padding_UnexpectedCharacter();
    void padding_NullText();
    void padding_TextOutOfBound();
    //===========================================================================================================
    void capitalizeAll_UnexpectedCharacter();
    void capitalizeAll_NullText();
    void capitalizeAll_TextOutOfBound();
    //===========================================================================================================
    void capitalizeFirst_UnexpectedCharacter();
    void capitalizeFirst_NullText();
    void capitalizeFirst_TextOutOfBound();
    //===========================================================================================================
    void capitalizeOffset_UnexpectedCharacter();
    void capitalizeOffset_NullText();
    void capitalizeOffset_TextOutOfBound();
    void capitalizeOffset_NegativeHighLightPosition();
    void capitalizeOffset_NegativeHighLightLength();
    void capitalizeOffset_PositionLargerThenMax();
    void capitalizeOffset_LengthLargerThenMax();
    //===========================================================================================================
    void lowercaseAll_UnexpectedCharacter();
    void lowercaseAll_NullText();
    void lowercaseAll_TextOutOfBound();
    //===========================================================================================================
    void lowercaseFirst_UnexpectedCharacter();
    void lowercaseFirst_NullText();
    void lowercaseFirst_TextOutOfBound();
    //===========================================================================================================
    void lowercaseOffset_UnexpectedCharacter();
    void lowercaseOffset_NullText();
    void lowercaseOffset_TextOutOfBound();
    void lowercaseOffset_NegativeHighLightPosition();
    void lowercaseOffset_NegativeHighLightLength();
    void lowercaseOffset_PositionLargerThenMax();
    void lowercaseOffset_LengthLargerThenMax();
    //===========================================================================================================
    void transformToASCII_NullText();
    void transformToASCII_TextOutOfBound();
    //===========================================================================================================
    void changeDateFormat_NullText();
    void changeDateFormat_TextOutOfBound();
    void changeDateFormat_UnexpectedCharacter();
    void changeDateFormat_UnepectedDateFormat();
    //===========================================================================================================
}
#endif  // TESTTEXTEDITOR_H