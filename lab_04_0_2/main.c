#include <stdio.h>
#include <string.h>
#include "my_functions.h"

int main()
{
    char str[N] = { 0 };
    int len_str1 = 0;
    int *pointer_len = &len_str1;

    char first_matr[N][N] = { 0 };
    
    if (read_string(str))
    {
        puts("incorrect input string");
        return input_err;
    }

    const int len_words_check1 = split(str, first_matr, pointer_len);

    if (len_words_check1)
    {
        puts("words length error.");
        return err_word_size;
    }
    if (0 == len_str1)
    {
        puts("one of strijngs have no words.");
        return no_words;
    }
    puts("Result:");
    lexem_repeat_search_search(first_matr, &len_str1);

    return ok;
}