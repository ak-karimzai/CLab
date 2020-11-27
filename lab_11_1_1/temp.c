#include <stdio.h>
#include <stdlib.h>
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
        for (size_t i = s[0] == '-' ? 1 : 0, j = my_strlen(s) - 1; i < j; i++, j--)
            swap((s + i), (s + j));
}

char *int_to_char(char *str, int num)
{
    int last_digit;
    size_t len = 0;
    if (num < 0)
    {
        *(str + len++) = '-';
        num *= -1;
    }
    while (num)
    {
        last_digit = num % 10;
        num /= 10;
        *(str + len++) = last_digit + '0';
    }
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
            str_format++;
            if (*str_format == 's')
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
            else if (*str_format == 'd')
            {
                int temp_num = va_arg(args, int);
                char num_in_string[256];
                int_to_char(num_in_string, temp_num);
                char *p = num_in_string;
                while (*p)
                {
                    if (str_s && n && str_index < n)
                        *(str_s + str_index) = *p;
                    str_index++;
                    p++;
                }
            }
            else if (*str_format == 'c')
            {
                char temp_char = va_arg(args, int);
                if (str_s && n && str_index < n)
                    *(str_s + str_index) = temp_char;
                str_index++;
            }
            str_format++;
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
    if (str_index < n)
        *(str_s + str_index) = '\0';
    else
        *(str_s + (n - 1)) = '\0';
    va_end(args);
    return str_index;
}

int main()
{
    char arr[20];
    printf("%d\n", my_snprintf(arr, sizeof(arr), "%s%s%d", "A", "H", 990819));
    puts(arr);
    return 0;
}