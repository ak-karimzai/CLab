#include <stdio.h>
#include <limits.h>

void find_num(FILE *f)
{
    int num, avg;
    int max = INT_MIN, min = INT_MAX, count = 0;
    while (fscanf(f, "%d", &num) != EOF)
    {
        if (num > max)
            max = num;

        if (num < min)
            min = num;
    }
    avg = (max + min) / 2;
    
    rewind(f);
    
    while (fscanf(f, "%d", &num) != EOF)
    {
        if (num > avg)
            count++;
    }   
    
    printf("%d", count);
}
int main(int argc, char **argv)
{
    FILE *f;
    int x;

    f = fopen(argv[1], "r");
    if (f == NULL || feof(f) || fscanf(f, "%d", &x) != 1)
        return -1;

    find_num(f);
    fclose(f);
    return 0;
}