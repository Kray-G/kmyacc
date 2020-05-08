/*
 * common definitions
 *
 * Copyright (C) 1993, 2005  MORI Koichiro
 */


typedef unsigned char uchar;
typedef int bool;

#define YES 1
#define NO 0
#define height(x) (sizeof(x) / sizeof((x)[0]))

#define global
#define private static

#if defined(_MSC_VER)
#define NORETURN_B __declspec(noreturn)
#define NORETURN_A
#elif defined(__GNUC__)
#define NORETURN_B
#define NORETURN_A __attribute__((__noreturn__))
#endif
