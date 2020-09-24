#include "main.h"

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

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    // int rc = ok;
    int count = 0, sum = 0;
    
    for (int i = 0; pb_src + i != pe_src; i++)
    {
        if (*pb_src + i > sum)
        {
            sum += *pb_src + i;
            count++;
        }
    }

    if (count)
    {
        *pb_dst = malloc(count * sizeof(int));
        if (pb_dst)
        {
            int j = 0;
            sum = *pb_src;
            for (int i = 0; pb_src + i != pe_src; i++)
            {
                if (*pb_src + i > sum)
                {
                    *((*pb_dst) + j++) = *(pb_src + i);
                }
            }
            *pe_dst = *pb_dst + count;
        }
        else
            return error;  
    }
    else
        return error;

    return ok;
}

void write_objs_in_file(FILE *file, const int *arr_lhs, const int *arr_rhs)
{
    for (; arr_lhs != arr_rhs; arr_lhs++)
        fprintf(file, "%d ", *arr_lhs);
}