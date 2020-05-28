#include <stdio.h>
#include "function.h"

int main()
{
    int max;
    if (fscanf(stdin, "%d", &max) == 0 || feof(stdin))
    {
        printf("I/O Error\n");
        return error;
    }
    find_two_max(max);
    return ok;
}