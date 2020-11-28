#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdarg.h>


size_t my_strlen(const char *str)
{
    size_t len = 0;
    for (; *str; str++)
        len++;
    return len;
}

void swap(char *lhs, char *rhs)
{
    char temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

void reverse_string(char *s)
{
    if (my_strlen(s))
    {
        for (size_t i = s[0] == '-' ? 1 : 0, j = my_strlen(s) - 1; i < j; i++, j--)
            swap(s + i, s + j);
    }
}

char *int_to_char(int32_t num)
{
    char *str = calloc(256, sizeof(char));
    size_t len = 0;

    if (num < 0)
    {
        *(str + len++) = '-';
        num = -num;
    }
    do
    {
        *(str + len++) = num % 10 + '0';
    } while (num /= 10);
    
    str[len] = '\0';
    reverse_string(str);
    return str;
}

char *int64_to_char(int64_t num)
{
    char *str = calloc(256, sizeof(char));
    size_t len = 0;

    if (num < 0)
    {
        *(str + len++) = '-';
        num = -num;
    }
    do
    {
        *(str + len++) = num % 10 + '0';
    } while (num /= 10);
    
    str[len] = '\0';
    reverse_string(str);
    return str;
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
            else if (*(str_format + 1) == 'd')
            {
                char *num_in_str = int_to_char(va_arg(args, int32_t));
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
            else if (*(str_format + 1) == 'l' && *(str_format + 2) == 'd')
            {
                char *num_in_str = int64_to_char(va_arg(args, int64_t));
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
            else if (*(str_format + 1) == 'l' && *(str_format + 2) == 'l' && *(str_format + 3) == 'd')
            {
                char *num_in_str = int64_to_char(va_arg(args, int64_t));
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