#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

#define INPUT_FILE 1
#define OUTPUT_FILE 2

enum error_type
{
    ok,
    error
};

int file_count_objs(FILE *file)
{
    int count = 0, temp;
    
    while (fscanf(file, "%d", &temp) == 1)
        count++;
    
    if (feof(file) || temp == EOF)
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

void write_objs_in_file(FILE *file, const int *arr, const int num_of_objs)
{
    for (int i = 0; i < num_of_objs; i++)
        fprintf(file, "%d ", *(arr + i));
}

int main(int argc, char **argv)
{
    int rc = error;
    FILE *input_file, *output_file;
    int *arr;
    int num_of_objs;
    if (argc == 3)
    {
        puts(argv[INPUT_FILE]);
        input_file = fopen(argv[INPUT_FILE], "r");
        output_file = fopen(argv[OUTPUT_FILE], "w");
        if (!input_file || !output_file)
        {
            puts("error");
            rc = error;
        }
        else
        {
            num_of_objs = file_count_objs(input_file);
            if (num_of_objs)
            {
                arr = read_objs_from_file(input_file, num_of_objs);
                if (arr)
                {
                    mysort(arr, arr + num_of_objs, sizeof(arr[0]), compare_int);
                    write_objs_in_file(output_file, arr, num_of_objs);
                }
                else
                    rc = error;
            }
            else
                rc = error;
        }
        fclose(output_file);
        fclose(input_file);
        free(arr);
    }
    else
    {
        rc = error;
    }
    
    return rc;
}