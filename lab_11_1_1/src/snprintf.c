#include "../inc/snprintf.h"
#include <stdio.h>
#define NUMBER_OF_DIGITS 32

static void swap(char *lhs, char *rhs)
{
    char temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

static void reverse_num(char *s, size_t len)
{
    if (len)
    {
        for (size_t i = s[0] == '-' ? 1 : 0, j = len - 1; i < j; i++, j--)
            swap(s + i, s + j);
    }
}

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
    char *num_in_str = NULL;

    while (*str_format)
    {
        if (*str_format == '%')
        {
            if (*(str_format + 1) == 's')
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
            else if (*(str_format + 1) == 'o')
            {
                char *num_in_str = long_to_str(va_arg(args, unsigned), 8);
                int j = 0;
                while (*(num_in_str + j))
                {
                    if (str_s && n && str_index < n)
                        *(str_s + str_index) = *(num_in_str + j);
                    str_index++;
                    j++;
                }
                free(num_in_str);
            }
            else if (*(str_format + 1) == 'd')
            {
                char *num_in_str = long_to_str(va_arg(args, int), 10);
                int j = 0;
                while (*(num_in_str + j))
                {
                    if (str_s && n && str_index < n)
                        *(str_s + str_index) = *(num_in_str + j);
                    str_index++;
                    j++;
                }
                free(num_in_str);
            }
            else if (*(str_format + 1) == 'h' && *(str_format + 2) == 'o')
            {
                char *num_in_str = long_to_str(va_arg(args, unsigned), 8);
                int j = 0;
                while (*(num_in_str + j))
                {
                    if (str_s && n && str_index < n)
                        *(str_s + str_index) = *(num_in_str + j);
                    str_index++;
                    j++;
                }
                free(num_in_str);
                str_format++;
            }
            else if (*(str_format + 1) == 'l' && *(str_format + 2) == 'd')
            {
                char *num_in_str = long_to_str(va_arg(args, long), 10);
                int j = 0;
                while (*(num_in_str + j))
                {
                    if (str_s && n && str_index < n)
                        *(str_s + str_index) = *(num_in_str + j);
                    str_index++;
                    j++;
                }
                free(num_in_str);
                str_format++;
            }
            else if (*(str_format + 1) == 'h' && *(str_format + 2) == 'd')
            {
                char *num_in_str = long_to_str(va_arg(args, int), 10);
                int j = 0;
                while (*(num_in_str + j))
                {
                    if (str_s && n && str_index < n)
                        *(str_s + str_index) = *(num_in_str + j);
                    str_index++;
                    j++;
                }
                free(num_in_str);
                str_format++;
            }
            else if (*(str_format + 1) == 'c')
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
