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

int my_snprintf(char *restrict_s, size_t n, const char *restrict_format, ...)
{
    size_t len = my_strlen(restrict_format), k = 0, i = 0;
    va_list args;
    va_start(args, restrict_format);
    for (; i < len - 1 && k <= n - 1; i++)
    {
        if (restrict_format[i] == '%')
        {
            i++;
            if (restrict_format[i] == 's')
            {
                const char *s = va_arg(args, char *);
                while (*s)
                {
                    restrict_s[k++] = *s;
                    s++;
                }
            }
            else if (restrict_format[i] == 'd')
            {
                int temp_num = va_arg(args, int);
                char num_in_string[256];
                int_to_char(num_in_string, temp_num);
                char *p = num_in_string;
                while (*p)
                {
                    restrict_s[k++] = *p;
                    p++;
                }
            }
            else if (restrict_format[i] == 'c')
            {
                char temp_char = va_arg(args, int);
                restrict_s[k++] = temp_char;
            }
            // else if (restrict_format[i] == 'l' && restrict_format[i + 1] == d)
            // {
            //     long int temp_int = va_arg(args, long int);
            //     char num_in_string[256];
            //     int_to_char(num_in_string, temp_int);
            //     char *p = num_in_string;
            //     while (*p)
            //     {
            //         restrict_s[k++] = *p;
            //         p++;
            //     }
            // }
        }
        else
            restrict_s[k++] = restrict_format[i];
    }
    if (len && k < len - 1)
        restrict_s[k++] = restrict_format[i];
    restrict_s[k] = '\0';
    va_end(args);
    return k;
}

int main()
{
    char arr[20];
    printf("%d\n", my_snprintf(arr, sizeof(arr), "%c", 'A'));
    // puts(arr);
    return 0;
}