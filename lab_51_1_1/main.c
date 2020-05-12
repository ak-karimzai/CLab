#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void find_two_max(int max)
{
    int max_1, max_2;

    fscanf(stdin, "%d", &max_1);
    if (max_1 > max)
        swap(&max, &max_1);
    
    while (fscanf(stdin, "%d", &max_2) == 1)
    {
        if (max_2 > max_1)
            swap(&max_1, &max_2);
        if (max_1 > max)
            swap(&max_1, &max);
    }
    printf("%d %d", max, max_1);
}

int main()
{
    int max;
    if (fscanf(stdin, "%d", &max) == 0 || feof(stdin))
    {
        printf("I/O Error\n");
        return -1;
    }
    find_two_max(max);
    return 0;
}