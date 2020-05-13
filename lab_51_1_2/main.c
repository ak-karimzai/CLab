#include <stdio.h>
#include <limits.h>

int find_num(FILE *f)
{
    int num, avg;
    int max = INT_MIN, min = INT_MAX, count = 0;

    rewind(f);
    while (fscanf(f, "%d", &num) != EOF)
    {
        if (num > max)
            max = num;

        if (num < min)
            min = num;
        count++;
    }
    avg = (max + min) / 2;
    
    if (count > 1)
    {
        return -1;
    }

    rewind(f);
    count = 0;
    while (fscanf(f, "%d", &num) != EOF)
    {
        if (num > avg)
            count++;
    }   
    
    printf("%d", count);
    return 0;
}
int main(int argc, char **argv)
{
    FILE *f;
    int x;

    f = fopen(argv[1], "r");
    if (fscanf(f, "%d", &x) == 0 || feof(f))
        return -1;

    if (find_num(f))
        return -1;

    fclose(f);
    return 0;
}