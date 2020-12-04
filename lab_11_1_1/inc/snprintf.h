#ifndef _SN_PRINTF_H_
#define _SN_PRINTF_H_

#include <stdlib.h>
#include <inttypes.h>
#include <stdarg.h>

int my_snprintf(char *str_s, size_t n, const char *str_format, ...);

#endif //_SN_PRINTF_H_