#ifndef _SN_PRINTF_H_
#define _SN_PRINTF_H_

#include <stdlib.h>
#include <stdarg.h>

#define DECIMAL 10
#define OCTAL 8
#define OCTAL_SYM 'o'
#define DECIMAL_SYM 'd'
#define LONG_SYM 'l'
#define SHORT_SYM 'h'
#define STRING_SYM 's'
#define CHAR_SYM 'c'

#define NUMBER_OF_DIGITS 32

int my_snprintf(char *str_s, size_t n, const char *str_format, ...);

#endif //_SN_PRINTF_H_