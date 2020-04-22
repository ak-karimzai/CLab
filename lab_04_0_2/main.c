#include <stdio.h>
#include <string.h>

#define STR_LEN 256
#define WORD_LEN 16
#define GOT_ARG 1

enum error_type
{
    ok,
    input_err,
    string_len_err,
    empty_string_err,
    word_len_err
};

int result = ok;

void string_input(char *const str)
{
    int i = 0;
    
    scanf("%c", &str[i]);
    while (str[i] != '\n' && i < STR_LEN)
    {
        i++;
        if (scanf("%c", &str[i]) != got_arg)
        {
            result = input_err;
            printf("input error\n");
        }
    }
    if (!i)
    {
        result = empty_string_err;
        printf("input error");
    }
    if (str[i] != '\n')
    {
        result = string_len_err;
        printf("input error");
    }
    str[i] = '\0';
    result = ok
}

int split(const char *const str, char matr[STR_LEN][WORD_LEN], const char *const puncts)
{
    int row = 0, col = 0, k = 0, j = 0;
    int punct = GOT_ARG;
    
    while (str[k])
    {
        while (puncts[j])
        {
            if (str[k] == puncts[j])
            {
                punct = GOT_ARG;
                break;
            }
            j++;
        }
        if (punct)
        {
            matr[row][col++] = str[k];
        }
        else
        {
            matrix[row++][col] = '\0';
            col = 0;
        }
        k++;
        j = 0;
        punct = GOT_ARG;
    }
    matr[row][col] = '\0';

    return ++row;
}

int check_s_matr(char matrix[STR_LEN][WORD_LEN], const int words_num)
{
    for (int i = 0; i < words_num; i++)
    {
        int k = 0;
        while (matrix[i][k])
            k++;
        if (matrix[i][k] != '\0' || k > WORD_LEN)
            return word_len_err;    
    }
    return ok;
}

int 
int main()
{
    char str[256], str_11[20][16];
    char spe[] = {",", ";", ":", "-", ".", "!", "?"}
    fgets (str, STR_LEN - 1, stdin);
    printf("Entered string is:\n %s", str);
}