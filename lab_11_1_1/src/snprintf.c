#include "../inc/snprintf.h"

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

static char *int_to_char(long num, int base)
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
        *(str + len++) = (num % base) + '0';
    } while (num /= base);
    
    str[len] = '\0';
    reverse_num(str, len);
    return str;
}

static int digit_copy(char *str, int str_index, size_t size, long number, int base)
{
    char *num_in_str = int_to_char(number, base);
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
                char *num_in_str = int_to_char(va_arg(args, unsigned), 8);
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
                char *num_in_str = int_to_char(va_arg(args, int), 10);
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
                char *num_in_str = int_to_char(va_arg(args, unsigned), 8);
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
                char *num_in_str = int_to_char(va_arg(args, int), 10);
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
