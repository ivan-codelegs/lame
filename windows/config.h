#ifndef CONFIGMS_H_INCLUDED
#define CONFIGMS_H_INCLUDED

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS

/* Define if you have the <errno.h> header file.  */
#define HAVE_ERRNO_H

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H

/* faster log implementation with less but enough precission */
#define USE_FAST_LOG 1

#define HAVE_STRCHR
#define HAVE_MEMCPY

typedef long double ieee854_float80_t;
typedef double      ieee754_float64_t;
typedef float       ieee754_float32_t;

#ifdef HAVE_MPGLIB
# define DECODE_ON_THE_FLY 1
#endif

#include <stdint.h>

#define LAME_LIBRARY_BUILD
#define HAVE_XMMINTRIN_H

#endif
