#include <stdio.h>

void write_objs_in_file(FILE *file, const int *arr_lhs, const int *arr_rhs)
{
    for (; arr_lhs != arr_rhs; arr_lhs++)
        fprintf(file, "%d ", *arr_lhs);
}