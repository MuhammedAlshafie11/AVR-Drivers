#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

/* Logic Levels */
#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

/* Null Pointer */
#define NULL_PTR    ((void*)0)

/* 8-bit Unsigned Integer */
typedef unsigned char uint8;          /* Range: 0 .. 255 */

/* 8-bit Signed Integer */
typedef signed char sint8;            /* Range: -128 .. +127 */

/* 16-bit Unsigned Integer */
typedef unsigned short uint16;        /* Range: 0 .. 65535 */

/* 16-bit Signed Integer */
typedef signed short sint16;          /* Range: -32768 .. +32767 */

/* 32-bit Unsigned Integer */
typedef unsigned long uint32;         /* Range: 0 .. 4294967295 */

/* 32-bit Signed Integer */
typedef signed long sint32;           /* Range: -2147483648 .. +2147483647 */

/* 64-bit Unsigned Integer */
typedef unsigned long long uint64;    /* Range: 0 .. 18446744073709551615 */

/* 64-bit Signed Integer */
typedef signed long long sint64;      /* Range: -9223372036854775808 .. 9223372036854775807 */

/* 32-bit Floating-Point Number (Single Precision) */
typedef float float32;

/* 64-bit Floating-Point Number (Double Precision) */
typedef double float64;

#endif /* STD_TYPES_H */
