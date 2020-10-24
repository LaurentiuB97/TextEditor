#ifndef TESTTEXTEDITOR_H
#define TESTTEXTEDITOR_H
#include "StringManipulator.h"
#include "TextHighLight.h"
#include <cppunit/TestFixture.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class TestTextEditor : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestTextEditor);
    CPPUNIT_TEST(find_simpleCase);
    CPPUNIT_TEST(find_TextNotFound);
    CPPUNIT_TEST_SUITE_END();
 public:
    void find_simpleCase();
    void find_Regex();
    void find_TextNotFound();
    void find_EmptyPattern();
    void find_EmptyText();
    void find_PatternWithUnexpectedCharacters();
    void find_TextWithUnexpectedCharacters();
    void find_TextOutOfBound();
    void find_PatternLargerThanText();
    //===========================================================================================================
    void replace_simpleCase();
    void replace_ReplacementWithUnexpectedCharacter();
    void replace_TextWithUnexpectedCharacter();
    void replace_EmptyText();
    void replace_TextOutOfBound();
    void replace_NegativeHighLightPosition();
    void replace_NegativeHighLightLength();
    void replace_PositionLargerThanMax();
    void replace_LengthLargerThanMax();
    //===========================================================================================================
    void trim_simpleCase();
    void trim_UnexpectedCharacter();
    void trim_EmptyText();
    void trim_TextOutOfBound();
    //===========================================================================================================
    void padding_simpeCase();
    void padding_UnexpectedCharacter();
    void padding_EmptyText();
    void padding_TextOutOfBound();
    //===========================================================================================================
    void capitalizeAll_simpleCase();
    void capitalizeAll_UnexpectedCharacter();
    void capitalizeAll_EmptyText();
    void capitalizeAll_TextOutOfBound();
    //===========================================================================================================
    void capitalizeFirst_simpleCase();
    void capitalizeFirst_UnexpectedCharacter();
    void capitalizeFirst_EmptyText();
    void capitalizeFirst_TextOutOfBound();
    //===========================================================================================================
    void capitalizeOffset_simpleCase();
    void capitalizeOffset_UnexpectedCharacter();
    void capitalizeOffset_EmptyText();
    void capitalizeOffset_TextOutOfBound();
    void capitalizeOffset_NegativeHighLightPosition();
    void capitalizeOffset_NegativeHighLightLength();
    void capitalizeOffset_PositionLargerThanMax();
    void capitalizeOffset_LengthLargerThanMax();
    //===========================================================================================================
    
    void lowercaseAll_simpleCase();
    void lowercaseAll_UnexpectedCharacter();
    void lowercaseAll_EmptyText();
    void lowercaseAll_TextOutOfBound();
    //===========================================================================================================
    void lowercaseFirst_simpleCase();
    void lowercaseFirst_UnexpectedCharacter();
    void lowercaseFirst_EmptyText();
    void lowercaseFirst_TextOutOfBound();
    //===========================================================================================================
    void lowercaseOffset_simpleCase();
    void lowercaseOffset_UnexpectedCharacter();
    void lowercaseOffset_EmptyText();
    void lowercaseOffset_TextOutOfBound();
    void lowercaseOffset_NegativeHighLightPosition();
    void lowercaseOffset_NegativeHighLightLength();
    void lowercaseOffset_PositionLargerThanMax();
    void lowercaseOffset_LengthLargerThanMax();
    //===========================================================================================================
    void transformToASCII_simpleCase();
    void transformToASCII_EmptyText();
    void transformToASCII_TextOutOfBound();
    //===========================================================================================================
    void changeDateFormat_EmptyText();
    void changeDateFormat_TextOutOfBound();
    void changeDateFormat_UnexpectedCharacter();
    //===========================================================================================================
};

CPPUNIT_TEST_SUITE_REGISTRATION( TestTextEditor );
#endif  // TESTTEXTEDITOR_H