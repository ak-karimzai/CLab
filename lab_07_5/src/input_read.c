#include <stdio.h>
#include "../inc/input.h"

int file_count_objs(FILE *file)
{
    int count = 0, temp;
    
    while (fscanf(file, "%d", &temp) == 1)
        count++;
    
    if (feof(file) || fgetc(file) == EOF)
    {
        rewind(file);
        return count;
    }
    return 0;
}

int *read_objs_from_file(FILE *file, const int num_of_objs)
{
    int rc = ok;
    int *arr = malloc(num_of_objs * sizeof(int));
    if (arr)
    {
        for (size_t i = 0; i < num_of_objs; i++)
        {
            if (fscanf(file, "%d", (arr + i)) != 1)
            {
                rc = error;
            }
        }
    }
    else
        rc = error;
    return rc == ok ? arr : NULL;
}

int *procees_data_from_file(FILE *input_file, int *num_of_objs)
{
    int *arr = NULL;
    *num_of_objs = file_count_objs(input_file);
    if (*num_of_objs)
    {
        arr = read_objs_from_file(input_file, num_of_objs);
    }
    return arr;
}