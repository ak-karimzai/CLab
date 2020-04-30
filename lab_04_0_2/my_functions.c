#include <stdio.h>
#include <string.h>

enum error_type
{
    ok,
    input_err,
    size_err,
    no_words,
    empty_string,
    err_word_size
};

#define TRUE 1
#define FALSE 0
#define OK_COUNT 1
#define MAX_WORD_LEN 16
#define N 256

int my_strcmp(const char *const str_1, const char *const str_2)
{
    int i = 0;

    while (str_1[i])
    {
        if (str_1[i] != str_2[i])
        {
            return FALSE;
        }
        ++i;
    }

    if (str_2[i] != '\0')
    {
        return FALSE;
    }

    return TRUE;
}

void delete(char matrix[][N], int *n, int i)
{
    for (; i < *n - 1; i++)
    {
        strcpy(matrix[i], matrix[i + 1]);
    }
    *n = *n - 1;
}


void lexem_repeat_search_search(char matr_1[][N], int *len_matr1)
{
    puts("Result: ");

    for (int i = 0; i < *len_matr1; i++)
    {
        //if (check_dublicate(matr_1, len_matr1, matr_1[i], i))
        int j = i + 1;
        int line_entry = FALSE;
        while (j < *len_matr1)
        {
            if (my_strcmp(matr_1[i], matr_1[j]))
            {
                delete(matr_1, len_matr1, j);
                line_entry++;
                j--;
            }
            ++j;
        }

        if (line_entry)
        {
            printf("%s %d\n", matr_1[i], ++line_entry);
        }
        else
        {
            printf("%s %d\n", matr_1[i], ++line_entry);
        }
    }
}

int punctions(const char symbol)
{
    char separators[8] = { ' ', ',', ';', ':', '.', '-', '!', '?' };
    for (int i = 0; i < 8; i++)
    {
        if (symbol == separators[i])
        {
            return TRUE;
        }
    }

    return FALSE;
}

int split(const char *const str, char matrix_split[][N], int *const count_lexem)
{
    int i = 0, k = 0;

    while (str[i + 1])
    {
        if (!punctions(str[i]))
        {
            if (k >= MAX_WORD_LEN)
            {
                return err_word_size;
            }
            matrix_split[*count_lexem][k] = str[i];
            k++;
        }
        else
        {
            if (!punctions(str[i + 1]))
            {
                if (k != 0)
                {
                    ++(*count_lexem);
                    matrix_split[*count_lexem][k + 1] = '\0';
                }
                k = 0;
            }
        }
        ++i;
    }

    if (!punctions(str[i]))
    {
        matrix_split[*count_lexem][k] = str[i];
        matrix_split[*count_lexem][++k] = '\0';
        if (k > MAX_WORD_LEN)
        {
            return err_word_size;
        }
    }

    if (*count_lexem != 0 || k > 0)
    {
        ++(*count_lexem);
    }

    return ok;
}

int read_string(char *const arr)
{
    int ch, i = 0;
    puts("Enter string: ");

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i < N - 1)
        {
            arr[i++] = ch;
        }
    }
    arr[i] = '\0';

    return ok;
}