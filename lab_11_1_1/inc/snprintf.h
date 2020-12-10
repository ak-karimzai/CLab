#ifndef _SN_PRINTF_H_
#define _SN_PRINTF_H_

#include <stdlib.h>
#include <stdarg.h>

#define NUMBER_OF_DIGITS 32

int my_snprintf(char *str_s, size_t n, const char *str_format, ...);

#endif //_SN_PRINTF_H_