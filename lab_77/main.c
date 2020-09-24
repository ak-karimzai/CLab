#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

enum error_type
{
    ok,
    error
};

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // char arr_char[] = {'z', 'y', 'x', 'w', 'v', 'u', 'p'};
    mysort(arr, arr + 10, sizeof(arr[0]), compare_int);
    // mysort(arr_char, arr_char + 7, sizeof(char), compare_char);
    for (int i = 0; i < 10; i++)
        fprintf(stdout, "%d ", arr[i]);
    puts("\nfinished");
    // for (int i = 0; i < 7; i++)
    //     fprintf(stdout, "%c ", arr_char[i]);
    return 0;
}