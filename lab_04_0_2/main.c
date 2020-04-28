#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define GOT_ARG 1
#define MAX_STRING_LENGTH 256
#define MAX_WORD_LENGTH 16

enum type_error
{
    ok,
    input_err,
    string_len_err,
    empty_string_err,
    word_len_err
};

int result = ok;

void input_string(char *const str)
{
    int i = 0;

    scanf("%c", &str[i]);
    while (str[i] != '\n' && i < MAX_STRING_LENGTH)
    {
        i++;
        if (scanf("%c", &str[i]) != GOT_ARG)
        {
            result = input_err;
            printf("input err");
        }
    }
    if (!i)
    {
        result = empty_string_err;
        printf("input err");
    }
    if (str[i] != '\n')
    {
        result = string_len_err;
        printf("input err");
    }
    str[i] = '\0';
}

int split(const char *const str, char matr[MAX_STRING_LENGTH][MAX_WORD_LENGTH], const char *const puncts)
{
    int row = 0, col = 0, k = 0, j = 0;
    int punct_found = TRUE;
    while (str[k])
    {
        while (puncts[j])
        {
            if (str[k] == puncts[j])
            {
                punct_found = FALSE;
                break;
            }
            j++;
        }
        if (punct_found)
            matr[row][col++] = str[k];
        else
        {
            matr[row++][col] = '\0';
            col = 0;    
        }
        k++;
        j = 0;
        punct_found = TRUE;
    }
    matr[row][col] = '\0';

    return ++row;
}

void delete(char f_str_words_matrix[][MAX_WORD_LENGTH], int *f_str_words_count, int i)
{
    for (; i < *f_str_words_count - 1; i++)
    {
        strcpy(f_str_words_matrix[i], f_str_words_matrix[i + 1]);
        //printf("%s %d\n", f_str_words_matrix[i], array[i]);
    }
    *f_str_words_count = *f_str_words_count - 1;
}

void check_if_rep(char matr[][MAX_WORD_LENGTH], char matr_1[][MAX_WORD_LENGTH], int m, int *n, int *array)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            if (strcmp(matr[i], matr_1[j]) == 0)
            {
                //printf("N%s\n", matr_1[j]);
                delete(matr_1, n, j);
                array[i]++;
                j--;
            }
        }
    }
}

void number_of_word(char str_matrix[][MAX_WORD_LENGTH], int *array, int *n)
{
    for (int i = 0; i < *n - 1; i++)
    {   
        for (int j = i + 1; j < *n; j++)
        {
            if (strcmp(str_matrix[i], str_matrix[j]) == 0)
            {
                //printf("All%s", str_matrix[j]);
                delete(str_matrix, n, j);
                array[i]++;
                j--;
            }
        }
    }
}

int check_num_of_word(char matrix[MAX_STRING_LENGTH][MAX_WORD_LENGTH], const int words_numb)
{
    for (int i = 0; i < words_numb; i++)
    {
        int k = 0;
        while (matrix[i][k])
            k++;

        if (matrix[i][k] != '\0' || k > MAX_WORD_LENGTH)
            return word_len_err;
    }
    return ok;
}

void number_of_word_in_2nd(char str_matrix[][MAX_WORD_LENGTH], char str_matrix_1[][MAX_WORD_LENGTH], int *array, int m, int *n)
{
    for (int i = 0; i < m; i++)
    {   
        for (int j = 0; j < *n; j++)
        {
            if (strcmp(str_matrix[i], str_matrix_1[j]) == 0)
            {
                //printf("All%s", str_matrix[j]);
                delete(str_matrix_1, n, j);
                array[i]++;
                j--;
            }
        }
    }
}

int main()
{
    char f_str[MAX_STRING_LENGTH] = { 0 }, s_str[MAX_STRING_LENGTH] = { 0 };
    char f_str_words_matrix[MAX_STRING_LENGTH][MAX_WORD_LENGTH] = { 0 };
    char s_str_words_matrix[MAX_STRING_LENGTH][MAX_WORD_LENGTH] = { 0 };
    int array[MAX_WORD_LENGTH] = { 0 }, array_1[MAX_WORD_LENGTH] = { 0 };

    char puncts[] = " ,;:-.!?";

    int f_str_words_count = 0, s_str_words_count = 0;

    input_string(f_str);
    input_string(s_str);
    if (result)
    {
        printf("job faild!\n");
        return result;
    }

    f_str_words_count = split(f_str, f_str_words_matrix, puncts);
    s_str_words_count = split(s_str, s_str_words_matrix, puncts);

    number_of_word(f_str_words_matrix, array, &f_str_words_count);
    number_of_word_in_2nd(f_str_words_matrix, s_str_words_matrix, array, f_str_words_count, &s_str_words_count);
    number_of_word(s_str_words_matrix, array_1, &s_str_words_count);

    //check_if_rep(f_str_words_matrix, s_str_words_matrix, f_str_words_count, &s_str_words_count, array);

    if (check_num_of_word(f_str_words_matrix, f_str_words_count) != ok || check_num_of_word(s_str_words_matrix, s_str_words_count) != ok)
    {
        printf("word len err\n");
        return word_len_err;
    }

    printf("Result:\n");
    //delete(f_str_words_matrix, &f_str_words_count);
    //printf("F%d\n", f_str_words_count);
    for (int i = 0; i < f_str_words_count; i++)
    {
        //strcpy (f_str_words_matrix[i], f_str_words_matrix[i + 1]);
        printf("%s %d\n", f_str_words_matrix[i], array[i] + 1);
    }
    //printf("F%d\n", s_str_words_count);
    for (int i = 0; i < s_str_words_count; i++)
    {
        //strcpy (f_str_words_matrix[i], f_str_words_matrix[i + 1]);
        printf("%s %d\n", s_str_words_matrix[i], array_1[i] + 1);
    }

    return result;
}