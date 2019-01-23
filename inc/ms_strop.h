#ifndef MS_STROP_H
#define MS_STROP_H
/**
 * @file ms_strop.h
 * @author championsurfer3044
 * @date 23 Jan 2019
 * @brief
 *
 *  LICENSE:-
 *  The MIT License (MIT)
 *  Copyright (c) 2018 Mrunmoy Samal
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
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#if defined(MODULE_MS_STRLIB_ENABLED) && MODULE_MS_STRLIB_ENABLED > 0
/*
 *----------------------------------------------------------------------
 *   Include Files
 *----------------------------------------------------------------------
 */
#include "platform/common.h"
#include "platform/porting.h"
#include "ms_strop_error_codes.h"

/*
*----------------------------------------------------------------------
*   Private Defines
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Macros
*----------------------------------------------------------------------
*/

#define ASCII_0_9(ASCII) (((ASCII >= 0x30) && (ASCII <= 0x39))?TRUE:FALSE)
#define ASCII_1_8(ASCII) (((ASCII >= 0x31) && (ASCII <= 0x38))?TRUE:FALSE)
#define ASCII_a_f(ASCII) (((ASCII >= 0x41) && (ASCII <= 0x46))?TRUE:FALSE)
#define ASCII_A_F(ASCII) (((ASCII >= 0x61) && (ASCII <= 0x66))?TRUE:FALSE)
#define ASCII_a_g(ASCII) (((ASCII >= 0x41) && (ASCII <= 0x47))?TRUE:FALSE)

/*
*----------------------------------------------------------------------
*   Private Data Types
*----------------------------------------------------------------------
*/
typedef enum strlib_escape_chars_t {
  STRLIB_ESC_NULL  = '\0',
  STRLIB_ESC_BELL  = '\a',
  STRLIB_ESC_BKSP  = '\b',
  STRLIB_ESC_HZTB  = '\t',
  STRLIB_ESC_LNFD  = '\n',
  STRLIB_ESC_VRTB  = '\v',
  STRLIB_ESC_FMFD  = '\f',
  STRLIB_ESC_CGRN  = '\r',
  STRLIB_ESC_SPACE = ' ',
  STRLIB_ESC_DOT   = 0x2E
} strlib_escape_chars_t;

/*
*----------------------------------------------------------------------
*   Public Variables
*----------------------------------------------------------------------
*/

/*
 *----------------------------------------------------------------------
 *   Public Function Prototypes (extern)
 *----------------------------------------------------------------------
 */
/** \brief      ms_strlib_remove_backspaces.
 *              This function breaks string into tokens.
 *              Will not remove NULLVAL from a string.
 *  \param      p_buffer.
 *              This parameter is a pointer to a valid memory containing
 *              null terminated string that needs to be processed.
 *  \param      max_len.
 *              maximum characters in the string excluding null character.
 *  \return     error code ms_strlib_err_t.
 */
void ms_strlib_remove_backspaces(char * p_buffer, size_t max_len);


/** \brief      ms_strlib_strtok.
 *              This function breaks string into tokens.
 *              Will not remove NULLVAL from a string.
 *  \param      pp_buffer.
 *              This parameter is a pointer to pointer to a valid memory containing
 *              null terminated string that needs to be processed.
 *  \param      p_delimeters.
 *              pointer to null term string of delimiters.
 *  \param      pp_out_token.
 *              pointer to next token in *pp_out_token.
 *  \return     error code ms_strlib_err_t.
 */
ms_strlib_err_t ms_strlib_strtok(char ** pp_buffer, char const * p_delimeters, char ** pp_out_token);


/** \brief      ms_strlib_strdelch.
 *              This function removes specified characters from a string.
 *              Will not remove NULLVAL from a string.
 *  \param      p_buffer.
 *              This parameter is a pointer to a valid memory containing
 *              null terminated string that needs to be processed.
 *  \param      p_remove_list.
 *              pointer to null terminated string of characters to remove
 *  \return     processed string.
 */
char *ms_strlib_strdelch(char * p_buffer, const char * p_remove_list);


/** \brief      ms_strlib_toupper.
 *              This function converts a string to uppercase string.
 *
 *  \param      p_buffer.
 *              This parameter is a pointer to a valid memory containing
 *              null terminated string that needs to be converted.
 *  \return     uppercased string.
 */
char * ms_strlib_toupper(char * p_buffer);


/** \brief      ms_strlib_tolower.
 *              This function converts a string to lowercase string.
 *
 *  \param      p_buffer.
 *              This parameter is a pointer to a valid memory containing
 *              null terminated string that needs to be converted.
 *  \return     lowercased string.
 */
char *ms_strlib_tolower(char *p_buffer);


#endif // MODULE_MS_STRLIB_ENABLED

#ifdef __cplusplus
}
#endif


#endif //MS_STROP_H
