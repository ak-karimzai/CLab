#include "main.h"

void free_array(int *arr)
{
    free(arr);
}

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

int get_num_of_elements(const int *arr_lhs, const int *arr_rhs, int *sum)
{
    int count = 0;
    *sum = 0;
    for (const int *p = arr_lhs; p != arr_rhs; p++)
    {
        *sum += *p;
    }

    if (*sum == 0)
        return count;

    int tmp_sum = *sum;
    for (const int *p = arr_lhs; p != arr_rhs - 1; p++)
    {
        tmp_sum -= *p;
        if (*p > tmp_sum)
            count++;
    }
    return count;
}

void add_elements_to_array(int *dst_arr, const int *src_arr_lhs, const int *src_arr_rhs, int sum)
{
    int i = 0;
    for (; src_arr_lhs != src_arr_rhs - 1; src_arr_lhs++)
    {
        sum -= *src_arr_lhs;
        if (*(src_arr_lhs) > sum)
            *(dst_arr + i++) = *src_arr_lhs;
    }
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    // int rc = ok;
    int count = 0, sum;
    if (!pb_src || pe_src - pb_src <= 0)
    {
        *pb_dst = *pe_dst = NULL;
        return error;
    }
    
    count = get_num_of_elements(pb_src, pe_src, &sum);
    // printf("%d\n", count);
    if (count == 0)
        return error;
    
    *pb_dst = malloc(count * sizeof(int));
    if (*pb_dst == NULL)
    {
        *pb_dst = *pe_dst = NULL;
        return error;
    }
    
    add_elements_to_array(*pb_dst, pb_src, pe_src, sum);
    // printf("%d\n", count);
    *pe_dst = *pb_dst + count;
    
    return ok;
}

void write_objs_in_file(FILE *file, const int *arr_lhs, const int *arr_rhs)
{
    for (; arr_lhs != arr_rhs; arr_lhs++)
        fprintf(file, "%d ", *arr_lhs);
}