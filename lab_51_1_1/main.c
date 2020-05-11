#include <stdio.h>


void find_two_max(int max)
{
    int max_1, max_2;
    while (fscanf(stdin, "%d", &max_1) == 1)
    {
        max_2 = max;
        if (max_1 > max)
            max = max_1;
    }
    printf("%d\n%d", max_1, max_2);
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