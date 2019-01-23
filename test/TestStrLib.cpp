/**
 *  @file TestStrLib.cpp
 *  @author championsurfer3044
 *  @date 23 Jan 2019 
 *  @brief 
 *
 *  LICENSE:-
 *  The MIT License (MIT)
 *  Copyright (c) 2019 Mrunmoy Samal
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom
 *  the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall
 *  be included in all copies or substantial portions of the
 *  Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 *  OR OTHER DEALINGS IN THE SOFTWARE.
 */


/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/
#include "CppUTest/TestHarness.h"
#include "ms_strop.h"

/******************************************************************************
* ms_strlib_remove_backspaces Test Cases
******************************************************************************/
TEST_GROUP(StrLibTestGroup_RemoveBackspace)
{
};

TEST(StrLibTestGroup_RemoveBackspace, TestRemoveFirstBackspace)
{
  char test_string[] = "\bThis is a sample string with one backspace";
  ms_strlib_remove_backspaces(test_string, strlen(test_string)+1);
  STRCMP_EQUAL(test_string, "This is a sample string with one backspace");
}

TEST(StrLibTestGroup_RemoveBackspace, TestRemoveLastBackspace)
{
  char test_string[] = "This is a sample string with one backspace.\b";
  ms_strlib_remove_backspaces(test_string, strlen(test_string)+1);
  STRCMP_EQUAL(test_string, "This is a sample string with one backspace");
}

TEST(StrLibTestGroup_RemoveBackspace, TestRemoveMiddleBackspace)
{
  char test_string[] = "This is a sample string with one backsp \bace";
  ms_strlib_remove_backspaces(test_string, strlen(test_string)+1);
  STRCMP_EQUAL(test_string, "This is a sample string with one backspace");
}

TEST(StrLibTestGroup_RemoveBackspace, TestRemoveMultipleBackspaces)
{
  char test_string[] = "This\bs is a s\b\b sample string with one backsp \bace";
  ms_strlib_remove_backspaces(test_string, strlen(test_string)+1);
  STRCMP_EQUAL(test_string, "This is a sample string with one backspace");
}

TEST(StrLibTestGroup_RemoveBackspace, NullStringRemoveBackspace)
{
  char test_string[5] = "";
  ms_strlib_remove_backspaces(test_string, strlen(test_string)+1);
  STRCMP_EQUAL(test_string, "");
}

TEST(StrLibTestGroup_RemoveBackspace, NullRemoveBackspace)
{
  ms_strlib_remove_backspaces(NULL, 0);
}

/******************************************************************************
* ms_strlib_strtok Test Cases
******************************************************************************/
TEST_GROUP(StrLibTestGroup_StringTokenize)
{
};

TEST(StrLibTestGroup_StringTokenize, TestTokenize)
{
  char *writableString;
  char test_string[] = "This is a sample string to tokenize";
  char delimiter[] = " ";
  char buffer[2 * strlen(test_string)] = {0};
  char **token_pointer = (char **) calloc(10, 256);

  writableString = buffer;
  strcpy(writableString, test_string);

  CHECK_EQUAL(STRERR_NONE, ms_strlib_strtok(&writableString, delimiter, token_pointer));
  //printf("token: %s\n", *token_pointer);

  CHECK_EQUAL(STRERR_NONE, ms_strlib_strtok(&writableString, delimiter, token_pointer));
  //printf("token: %s\n", *token_pointer);

  CHECK_EQUAL(STRERR_NONE, ms_strlib_strtok(&writableString, delimiter, token_pointer));
  //printf("token: %s\n", *token_pointer);

  CHECK_EQUAL(STRERR_NONE, ms_strlib_strtok(&writableString, delimiter, token_pointer));
  //printf("token: %s\n", *token_pointer);

  CHECK_EQUAL(STRERR_NONE, ms_strlib_strtok(&writableString, delimiter, token_pointer));
  //printf("token: %s\n", *token_pointer);

  CHECK_EQUAL(STRERR_NONE, ms_strlib_strtok(&writableString, delimiter, token_pointer));
  //printf("token: %s\n", *token_pointer);

  CHECK_EQUAL(STRERR_NONE, ms_strlib_strtok(&writableString, delimiter, token_pointer));
  //printf("token: %s\n", *token_pointer);

  free(token_pointer);
}

TEST(StrLibTestGroup_StringTokenize, TestTokenize_NullDelimiter)
{
  char *writableString;
  char test_string[] = "This is a sample string to tokenize";
  char buffer[2 * strlen(test_string)] = {0};
  char **token_pointer = (char **) calloc(10, 256);

  writableString = buffer;
  strcpy(writableString, test_string);

  CHECK_EQUAL(STRERR_INVALID_INPUT, ms_strlib_strtok(&writableString, NULL, token_pointer));

  free(token_pointer);
}

TEST(StrLibTestGroup_StringTokenize, TestTokenize_NullString)
{
  char *writableString;
  char test_string[] = "";
  char delimiter[] = " ";
  char buffer[2 * strlen(test_string)] = {0};
  char **token_pointer = (char **) calloc(10, 256);

  writableString = buffer;
  strcpy(writableString, test_string);

  CHECK_EQUAL(STRERR_EMPTY_STRING, ms_strlib_strtok(&writableString, delimiter, token_pointer));

  free(token_pointer);
}

/******************************************************************************
* ms_strlib_strdelch Test Cases
******************************************************************************/
TEST_GROUP(StrLibTestGroup_StringDelch)
{
};

TEST(StrLibTestGroup_StringDelch, RemoveWhiteSpace)
{
  char test_string[] = "This is a sample string with one backspace";
  char remove_list[] = " ";
  ms_strlib_strdelch(test_string, remove_list);
  STRCMP_EQUAL(test_string, "Thisisasamplestringwithonebackspace");
}

TEST(StrLibTestGroup_StringDelch, RemoveChars_NullString)
{
  char remove_list[] = " ";
  STRCMP_EQUAL(NULL, ms_strlib_strdelch(NULL, remove_list));
}

TEST(StrLibTestGroup_StringDelch, RemoveChars_NullDelimeter)
{
  char test_string[] = "This is a sample string with one backspace";
  STRCMP_EQUAL(NULL, ms_strlib_strdelch(test_string, NULL));
}


/******************************************************************************
* ms_strlib_toupper Test Cases
******************************************************************************/
TEST_GROUP(StrLibTestGroup_StringToUpper)
{
};

TEST(StrLibTestGroup_StringToUpper, ValidString)
{
  char test_string[] = "Sample";
  STRCMP_EQUAL("SAMPLE", ms_strlib_toupper(test_string));
}

TEST(StrLibTestGroup_StringToUpper, NULLString)
{
  STRCMP_EQUAL(NULL, ms_strlib_toupper(NULL));
}

/******************************************************************************
* ms_strlib_tolower Test Cases
******************************************************************************/
TEST_GROUP(StrLibTestGroup_StringToLower)
{
};

TEST(StrLibTestGroup_StringToLower, ValidString)
{
  char test_string[] = "Sample";
  STRCMP_EQUAL("sample", ms_strlib_tolower(test_string));
}

TEST(StrLibTestGroup_StringToLower, NULLString)
{
  STRCMP_EQUAL(NULL, ms_strlib_tolower(NULL));
}





