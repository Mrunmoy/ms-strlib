/**
 * @file ms_strop.c
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

/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/
#include "ms_strop.h"

/*
*----------------------------------------------------------------------
*   Private Defines
*----------------------------------------------------------------------
*/
#if defined(MODULE_MS_STRLIB_ENABLED) && MODULE_MS_STRLIB_ENABLED > 0
/*
*----------------------------------------------------------------------
*   Private Macros
*----------------------------------------------------------------------
*/

#define MS_CLI_STRMOV(d,s) memmove(d,s,strlen(s)+1)

/*
*----------------------------------------------------------------------
*   Exported Functions
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
void ms_strlib_remove_backspaces(char * p_buffer, size_t max_len) {
  if (!p_buffer) return;

  UINT32 running_string_length = strlen(p_buffer);
  UINT32 i = 0;
  UINT32 j;
  UINT8 firstChar = 1;

  while ((p_buffer[i]) || (i < running_string_length)) {
    if(p_buffer[i] == STRLIB_ESC_BKSP) {
      if (firstChar) // if backspace was found at the first index
      {
        for (j = i; j < running_string_length; j++) { // shift up
          p_buffer[j] = p_buffer[j + 1];
        }
        running_string_length--;
      }
      else // the backspace is not in the first character
      {
        for (j = i; j < running_string_length; j++) {
          p_buffer[j - 1] = p_buffer[j + 1];
        }
        i--;
        running_string_length = running_string_length - 2;
      }
    } else {
      if (!i) {
        firstChar = 0;
      }
      i++;
    }
  }
}


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
ms_strlib_err_t ms_strlib_strtok(char ** pp_buffer, char const * p_delimeters, char ** pp_out_token) {
   UINT32  index;

   if (!pp_buffer || !*pp_buffer || !p_delimeters || !*p_delimeters || !pp_out_token) {
     return STRERR_INVALID_INPUT;
   }

   // empty string ? return "empty string"
   if (**pp_buffer == NULLVAL) {
     return STRERR_EMPTY_STRING;
   }

   // find first delimiter in string
   index = strcspn(*pp_buffer, p_delimeters);

   //  if delimiter is first char of string...
   //  replace token with null char
   //  set string ptr to next char
   //  return "missing token"
   if (index == 0) {
      **pp_buffer = NULLVAL;
      (*pp_buffer)++;
      return STRERR_MISSING_TOKEN;
   }

   // the next token starts at the string pointer
   *pp_out_token = *pp_buffer;

   // find the next delimiter which marks the end of this token
   // set the string pointer to this delimiter
   *pp_buffer += strcspn(*pp_out_token, p_delimeters);

   // replace the delimiter with a null char so the token string is null terminated
   // if we are at the end of the token, we leave the string pointer alone so that
   // the next call will return CLI_ERR_EMPTY_STRING
   if(**pp_buffer != NULLVAL) {
      // we are not at the end of the token yet
      // replace the delimiter
      **pp_buffer = NULLVAL;
      // set string pointer to the character after the delimiter
      (*pp_buffer)++;
   }

   return STRERR_NONE;
}


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
char *ms_strlib_strdelch(char * p_buffer, const char * p_remove_list) {
   char *str;

   // If the string pointer is null ptr, return null ptr
   // If the lose pointer is null ptr, return null ptr
   if (!p_buffer || !p_remove_list) {
     return NULL;
   }

   // If the string is empty, return the string, there is nothing to delete
   // If the lose string is empty, return the string, there is nothing to delete
   if ((*p_buffer == NULLVAL) || (*p_remove_list == NULLVAL)) {
     return p_buffer;
   }

   /* parse thru the string until nullchar */
   for (str = p_buffer; *str; ++str) {
      /* is the current char one we need to remove? */
      if (strchr(p_remove_list, *str)) {
         /* shift the string to the left one char to remove the unwanted char */
        MS_CLI_STRMOV(str, str + 1);

         /* move back a char so we can check to new char in the position we just checked */
         --str;
      }
   }

   return p_buffer;
}


/** \brief      ms_strlib_toupper.
 *              This function converts a string to uppercase string.
 *
 *  \param      p_buffer.
 *              This parameter is a pointer to a valid memory containing
 *              null terminated string that needs to be converted.
 *  \return     uppercased string.
 */
char * ms_strlib_toupper(char * p_buffer) {
   char *s;
   if (p_buffer) {
      for (s = p_buffer; *s; ++s) {
        *s = (char) toupper((UINT8) *s);
      }
   }
   return p_buffer;
}


/** \brief      ms_strlib_tolower.
 *              This function converts a string to lowercase string.
 *
 *  \param      p_buffer.
 *              This parameter is a pointer to a valid memory containing
 *              null terminated string that needs to be converted.
 *  \return     lowercased string.
 */
char *ms_strlib_tolower(char *p_buffer) {
   char *s;
   if (p_buffer) {
      for (s = p_buffer; *s; ++s) {
        *s = (char) tolower((UINT8) *s);
      }
   }
   return p_buffer;
}
#endif
