#include "../inc/snprintf.h"

static void unsigned_long_to_str(unsigned long num, int base, char *str)
{
    unsigned char index;
    char buff[NUMBER_OF_DIGITS];
    index = NUMBER_OF_DIGITS;
    do
    {
        buff[--index] = '0' + (num % base);
        num /= base;
    } while (num);

    do
    {
        *str++ = buff[index++];
    } while (index < NUMBER_OF_DIGITS);

    *str = '\0';
}

static char *long_to_str(long num, int base)
{
    char *str = calloc(NUMBER_OF_DIGITS, sizeof(char));
    size_t len = 0;

    if (num < 0 && base == 10)
    {
        len++;
        *str = '-';
        unsigned_long_to_str(-num, base, str + 1);
    }
    else
        unsigned_long_to_str(num, base, str);
    return str;
}

static int digit_copy(char *str, int str_index, size_t size, long number, int base)
{
    char *num_in_str = long_to_str(number, base);
    int j = 0;
    while (*(num_in_str + j))
    {
        if (str && size && str_index < size)
            *(str + str_index) = *(num_in_str + j);
        str_index++;
        j++;
    }
    free(num_in_str);
    return str_index; 
}

int my_snprintf(char *str_s, size_t n, const char *str_format, ...)
{
    va_list args;
    va_start(args, str_format);
    size_t str_index = 0;

    while (*str_format)
    {
        if (*str_format == '%')
        {
            if (*(str_format + 1) == STRING_SYM)
            {
                const char *s = va_arg(args, char *);
                while (*s)
                {
                    if (str_s && n && str_index < n)
                        *(str_s + str_index) = *s;
                    str_index++;
                    s++;
                }
            }
            else if (*(str_format + 1) == OCTAL_SYM)
            {
                str_index = digit_copy(str_s, str_index, n, va_arg(args, unsigned), OCTAL);
            }
            else if (*(str_format + 1) == DECIMAL_SYM)
            {
                str_index = digit_copy(str_s, str_index, n, va_arg(args, int), DECIMAL);
            }
            else if (*(str_format + 1) == SHORT_SYM && *(str_format + 2) == OCTAL_SYM)
            {
                str_index = digit_copy(str_s, str_index, n, va_arg(args, unsigned), OCTAL);
                str_format++;
            }
            else if (*(str_format + 1) == LONG_SYM && *(str_format + 2) == DECIMAL_SYM)
            {
                str_index = digit_copy(str_s, str_index, n, va_arg(args, long), DECIMAL);
                str_format++;
            }
            else if (*(str_format + 1) == LONG_SYM && *(str_format + 2) == LONG_SYM && *(str_format + 3) == DECIMAL_SYM)
            {
                str_index = digit_copy(str_s, str_index, n, va_arg(args, long), DECIMAL);
                str_format = str_format + 2;
            }
            else if (*(str_format + 1) == SHORT_SYM && *(str_format + 2) == DECIMAL_SYM)
            {
                str_index = digit_copy(str_s, str_index, n, va_arg(args, int), DECIMAL);
                str_format++;
            }
            else if (*(str_format + 1) == CHAR_SYM)
            {
                char temp_char = va_arg(args, int);
                if (str_s && n && str_index < n)
                    *(str_s + str_index) = temp_char;
                str_index++;
            }
            str_format = str_format + 2;
        }
        else
        {
            if (str_s && n && str_index < n)
                *(str_s + str_index) = *str_format++;
            else
                str_format++;
            str_index++;
        }
    }
    if (str_s != NULL && n != 0)
    {
        if (str_index < n)
            *(str_s + str_index) = '\0';
        else
            *(str_s + (n - 1)) = '\0';
    }
    va_end(args);
    return str_index;
}
