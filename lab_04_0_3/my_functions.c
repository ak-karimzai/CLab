#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 257
#define TRUE 1
#define FALSE 0
#define MAX_WORD_LEN 17

enum error_type
{
    ok,
    word_size_err,
    no_words,
    empty_string,
    input_err,
    size_err
};

int read_string(char *array)
{
    int i = 0;
    puts("Enter string: ");

    do
    {
        if (scanf("%c", &array[i]) != TRUE)
        {
            return input_err;
        }
        ++i;
    } while (array[i - 1] != '\n' && i <= N);
    
    if (array[i - 1] != '\n')
    {
        return size_err;
    }

    if (i == 1)
    {
        return empty_string;
    }
    array[i - 1] = '\0';

    return ok;
}

int punctuation(const char symbol)
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

int split(const char *const string, char matrix[][N], int *const count)
{
    int i = 0, k = 0;

    while (string[i + 1])
    {
        if (!punctuation(string[i]))
        {
            if (k >= MAX_WORD_LEN)
            {
                return word_size_err;
            }
            matrix[*count][k] = string[i];
            k++;
        }
        else
        {
            if (!punctuation(string[i + 1]))
            {
                if (k != 0)
                {
                    ++(*count);
                    matrix[*count][k + 1] = '\0';
                }
                k = 0;
            }
        }
        ++i;
    }
    if (!punctuation(string[i]))
    {
        matrix[*count][k] = string[i];
        matrix[*count][++k] = '\0';
        if (k > MAX_WORD_LEN)
        {
            return word_size_err;
        }
    }
    if (*count != 0 || k > 0)
    {
        ++(*count);
    }

    return ok;
}

void main_algo(char *buf)
{
    char *p = buf, first = 0;
    while (*p) 
    {
        if (isspace(*p))
            first = 0;
        else
        {
            if (!first) 
                first = toupper(*p);
            else if (toupper(*p) == first)
            {
                memmove(p, p + 1, strlen(p));
                continue;
            }
        }
        ++p;
    }
}

void delete(char matrix[][N], int *count, int i)
{
    for (; i < *count - 1; i++)
    {
        strcpy(matrix[i], matrix[i + 1]);
    }
    *count = *count - 1;
}

void set_string(char matrix[][N], int count)
{
    for (int i = 0; i < count; i++)
    {
        main_algo(matrix[i]);
    }
}

void set_string_1(char matrix[][N], int *count)
{
    for (int i = 0; i < *count - 1; i++)
    {
        if (strcmp(matrix[*count - 1], matrix[i]) == 0)
        {
            delete(matrix, count, i);
        }
    }
}