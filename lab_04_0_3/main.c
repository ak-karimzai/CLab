#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 256
#define TRUE 1
#define OK_COUNT 1
#define FALSE 0
#define MAX_WORD_LEN 16

enum error_type
{
    ok,
    word_size_err,
    no_words,
    empty_string,
    input_err,
    size_err
};

int read_string(char *arr)
{
    gets(arr);
    if (strlen(arr) > N)
        return word_size_err;
    if (strlen(arr) == 0)
        return empty_string;
    return ok;
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

int split(const char *const string, char matrix[][N], int *const count)
{
    int i = 0, k = 0;

    while (string[i + 1])
    {
        if (!punctions(string[i]))
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
            if (!punctions(string[i + 1]))
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
    if (!punctions(string[i]))
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
    char * p = buf, first = 0;
    while (*p) 
    {
        if ( isspace(*p) )
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

int main()
{
    char str[N] = { 0 };
    char str_1[N][N] = { 0 };  
    int len_str = 0;

    if (read_string(str))
    {
        printf("Error\n");
        return input_err;
    }
    
    if (split(str, str_1, &len_str))
    {
        return input_err;
    }

    for (int i = 0; i < len_str; i++)
    {
        main_algo(str_1[i]);
    }
    
    for (int i = len_str - 2; i >= 0; i--)
    {
        printf("%s ", str_1[i]);
    }

    return ok;
}