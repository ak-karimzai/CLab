#include "main.h"
#include "function.h"

int main(int argc, char **argv)
{
    int rc = ok;
    FILE *input_file, *output_file;
    int *arr = NULL;
    int num_of_objs;
    if (argc == 3)
    {
        // puts(argv[INPUT_FILE]);
        input_file = fopen(argv[INPUT_FILE], "r");
        output_file = fopen(argv[OUTPUT_FILE], "w");
        if (input_file == NULL || output_file == NULL)
        {
            // puts("error");
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
                    mysort(arr, num_of_objs, sizeof(arr[0]), compare_int);
                    write_objs_in_file(output_file, arr, arr + num_of_objs);
                }
                else
                    rc = error;
            }
            else
                rc = error;
            fclose(output_file);
            fclose(input_file);
            free(arr);
        }
    }
    else if (argc == 4)
    {
        if (strcmp(argv[KEY], "f") == ok)
        {
            input_file = fopen(argv[INPUT_FILE], "r");
            output_file = fopen(argv[OUTPUT_FILE], "w");
            if (input_file == NULL || output_file == NULL)
            {
                // puts("error");
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
                        int *arr_lhs = NULL, *arr_rhs = NULL;
                        // printf("\n%d\n", 3344);
                        // printf("%d sdad\n", key(arr, arr + num_of_objs, &arr_lhs, &arr_rhs));
                        if (key(arr, arr + num_of_objs, &arr_lhs, &arr_rhs) != ok)
                        {
                            // puts("Hey i'm here");
                            rc = error;
                        }
                        else
                        {
                            mysort(arr_lhs, (arr_rhs - arr_lhs), sizeof(arr_rhs[0]), compare_int);
                            write_objs_in_file(output_file, arr_lhs, arr_rhs);
                        }
                        free(arr_lhs);
                        free(arr);
                    }
                    else
                        rc = error;
                }
                else
                    rc = error;
                fclose(output_file);
                fclose(input_file);
            }
        }
        else
            rc = error; 
    }
    else
    {
        rc = error;
    }
    
    return rc;
}