#ifndef MS_STRLIB_PORTING_H
#define MS_STRLIB_PORTING_H

/**
 *  @file porting.h
 *  @author championsurfer3044
 *  @date 25 Dec 2018 
 *  @brief 
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
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Data Types
*----------------------------------------------------------------------
*/

#define __ATTRIBUTE__(x)

#if defined(__GNUC__)
#undef __ATTRIBUTE__
#define __ATTRIBUTE__(x)    __attribute__(x)
#endif

typedef unsigned long long 	UINT64;
typedef long long 			    INT64;
typedef unsigned int 		    UINT32;
typedef int 				        INT32;
typedef double 				      FLOAT64;
typedef float               FLOAT32;
typedef unsigned short 		  UINT16;
typedef short 				      INT16;
typedef unsigned char 		  UINT8;
typedef char 				        INT8;
typedef char 				        CHAR;
typedef char 				        BOOL;

#define _STATIC				      static
#define _CONST				      const
#define _EXTERN				      extern
#define _VOID				        void

#ifndef FALSE
#define FALSE				        (0)
#endif

#ifndef TRUE
#define TRUE				        (1)
#endif

typedef enum _ENDIAN
{
  __ENDIAN_LITTLE = 0,
  __ENDIAN_BIG,
  __ENDIAN_MAX
}_ENDIAN;

/*
*----------------------------------------------------------------------
*   Public Constants (const)
*----------------------------------------------------------------------
*/

#define BE_BIG_END				0
#define BE_LITTLE_END			1

#define LE_BIG_END				1
#define LE_LITTLE_END			0

#define CRC_HIGH_BYTE			0
#define CRC_LOW_BYTE			1


#ifndef NULL
#define NULL            ((void *)0)
#endif

#ifndef NULLVAL
#define NULLVAL         (0)
#endif

/*
*----------------------------------------------------------------------
*   Public Function Prototypes
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Externs
*----------------------------------------------------------------------
*/
#ifdef __cplusplus
}
#endif

#endif //MS_STRLIB_PORTING_H
