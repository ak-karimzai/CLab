#include <stdio.h>
#include "function.h"

int main(int argc, char **argv)
{
    FILE *f;
    int x;

    f = fopen(argv[1], "r");
    if (fscanf(f, "%d", &x) == 0 || feof(f))
        return -1;

    if (find_num(f))
        return error;

    fclose(f);
    return ok;
}