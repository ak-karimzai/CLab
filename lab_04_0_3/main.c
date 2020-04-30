#include <stdio.h>
#include <string.h>
#include "my_functions.h"

int main()
{
    char str[N] = { 0 };
    char str_1[N][N] = { 0 }; 
    int len_str = 0, flag = 0;

    if (read_string(str))
    {
        return input_err;
    }
    
    if (split(str, str_1, &len_str))
    {
        return input_err;
    }
    if (len_str == 1)
    {
        return input_err;
    }
    set_string(str_1, len_str);
    for (int i = 1; i < len_str; i++)
    {
        if (strcmp(str_1[1], str_1[i]) != 0)
            flag = 1;
    }
    if (!flag)
    {
        return input_err;
    }
    set_string_1(str_1, &len_str);
    printf("Result: ");
    for (int i = len_str - 2; i >= 0; i--)
    {
        printf("%s ", str_1[i]);
    }

    return ok;
}