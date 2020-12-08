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
    CPPUNIT_TEST(find_Regex);
    CPPUNIT_TEST(find_EmptyPattern);
    CPPUNIT_TEST(find_PatternWithUnexpectedCharacters);
    CPPUNIT_TEST(find_TextWithUnexpectedCharacters);
    CPPUNIT_TEST(find_PatternLargerThanText);
    CPPUNIT_TEST(replace_simpleCase);
    CPPUNIT_TEST(replace_ReplacementWithUnexpectedCharacter);
    CPPUNIT_TEST(replace_TextWithUnexpectedCharacter);
    CPPUNIT_TEST(replace_EmptyText);
    CPPUNIT_TEST(replace_NegativeHighLightPosition);
    CPPUNIT_TEST(replace_NegativeHighLightLength);
    CPPUNIT_TEST(replace_PositionLargerThanMax);
    CPPUNIT_TEST(replace_LengthLargerThanMax);
    CPPUNIT_TEST(trim_simpleCase);
    CPPUNIT_TEST(trim_UnexpectedCharacter);
    CPPUNIT_TEST(trim_EmptyText);
    CPPUNIT_TEST(padding_simpeCase);
    CPPUNIT_TEST(padding_UnexpectedCharacter);
    CPPUNIT_TEST(padding_EmptyText);
    CPPUNIT_TEST(capitalizeAll_simpleCase);
    CPPUNIT_TEST(capitalizeAll_UnexpectedCharacter);
    CPPUNIT_TEST(capitalizeAll_EmptyText);
    CPPUNIT_TEST(capitalizeFirst_simpleCase);
    CPPUNIT_TEST(capitalizeFirst_UnexpectedCharacter);
    CPPUNIT_TEST(capitalizeFirst_EmptyText);
    CPPUNIT_TEST(capitalizeOffset_simpleCase);
    CPPUNIT_TEST(capitalizeOffset_UnexpectedCharacter);
    CPPUNIT_TEST(capitalizeOffset_EmptyText);
    CPPUNIT_TEST(capitalizeOffset_NegativeHighLightPosition);
    CPPUNIT_TEST(capitalizeOffset_NegativeHighLightLength);
    CPPUNIT_TEST(capitalizeOffset_PositionLargerThanMax);
    CPPUNIT_TEST(capitalizeOffset_LengthLargerThanMax);
    CPPUNIT_TEST(lowercaseAll_simpleCase);
    CPPUNIT_TEST(lowercaseAll_UnexpectedCharacter);
    CPPUNIT_TEST(lowercaseAll_EmptyText);
    CPPUNIT_TEST(lowercaseFirst_simpleCase);
    CPPUNIT_TEST(lowercaseFirst_UnexpectedCharacter);
    CPPUNIT_TEST(lowercaseFirst_EmptyText);
    CPPUNIT_TEST(lowercaseOffset_simpleCase);
    CPPUNIT_TEST(lowercaseOffset_EmptyText);
    CPPUNIT_TEST(lowercaseOffset_NegativeHighLightPosition);
    CPPUNIT_TEST(lowercaseOffset_NegativeHighLightLength);
    CPPUNIT_TEST(lowercaseOffset_PositionLargerThanMax);
    CPPUNIT_TEST(transformToASCII_simpleCase);
    CPPUNIT_TEST(transformToASCII_EmptyText);
    CPPUNIT_TEST(changeDateFormat_simpleCase);
    CPPUNIT_TEST(changeDateFormat_EmptyText);
    CPPUNIT_TEST(changeDateFormat_UnexpectedCharacter);
    CPPUNIT_TEST_SUITE_END();
 public:
    void setUp() override;
    void tearDown() override;
    void find_simpleCase();
    void find_Regex();
    void find_TextNotFound();
    void find_EmptyPattern();
    void find_EmptyText();
    void find_PatternWithUnexpectedCharacters();
    void find_TextWithUnexpectedCharacters();
    void find_PatternLargerThanText();
    //===========================================================================================================
    void replace_simpleCase();
    void replace_ReplacementWithUnexpectedCharacter();
    void replace_TextWithUnexpectedCharacter();
    void replace_EmptyText();
    void replace_NegativeHighLightPosition();
    void replace_NegativeHighLightLength();
    void replace_PositionLargerThanMax();
    void replace_LengthLargerThanMax();
    //===========================================================================================================
    void trim_simpleCase();
    void trim_UnexpectedCharacter();
    void trim_EmptyText();
    //===========================================================================================================
    void padding_simpeCase();
    void padding_UnexpectedCharacter();
    void padding_EmptyText();
    //===========================================================================================================
    void capitalizeAll_simpleCase();
    void capitalizeAll_UnexpectedCharacter();
    void capitalizeAll_EmptyText();
    //===========================================================================================================
    void capitalizeFirst_simpleCase();
    void capitalizeFirst_UnexpectedCharacter();
    void capitalizeFirst_EmptyText();
    //===========================================================================================================
    void capitalizeOffset_simpleCase();
    void capitalizeOffset_UnexpectedCharacter();
    void capitalizeOffset_EmptyText();
    void capitalizeOffset_NegativeHighLightPosition();
    void capitalizeOffset_NegativeHighLightLength();
    void capitalizeOffset_PositionLargerThanMax();
    void capitalizeOffset_LengthLargerThanMax();
    //===========================================================================================================
    
    void lowercaseAll_simpleCase();
    void lowercaseAll_UnexpectedCharacter();
    void lowercaseAll_EmptyText();
    //===========================================================================================================
    void lowercaseFirst_simpleCase();
    void lowercaseFirst_UnexpectedCharacter();
    void lowercaseFirst_EmptyText();
    //===========================================================================================================
    void lowercaseOffset_simpleCase();
    void lowercaseOffset_UnexpectedCharacter();
    void lowercaseOffset_EmptyText();
    void lowercaseOffset_NegativeHighLightPosition();
    void lowercaseOffset_NegativeHighLightLength();
    void lowercaseOffset_PositionLargerThanMax();
    void lowercaseOffset_LengthLargerThanMax();
    //===========================================================================================================
    void transformToASCII_simpleCase();
    void transformToASCII_EmptyText();
    //===========================================================================================================
    void changeDateFormat_simpleCase();
    void changeDateFormat_EmptyText();
    void changeDateFormat_UnexpectedCharacter();
    //===========================================================================================================
};

CPPUNIT_TEST_SUITE_REGISTRATION( TestTextEditor );
#endif  // TESTTEXTEDITOR_H