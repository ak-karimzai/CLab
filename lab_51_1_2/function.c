#include <stdio.h>
#include <limits.h>

enum 
{
    error = -1,
    ok
};

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
    
    if (count < 2)
    {
        return error;
    }

    rewind(f);
    count = 0;
    while (fscanf(f, "%d", &num) != EOF)
    {
        if (num > avg)
            count++;
    }   
    
    printf("%d", count);
    return ok;
}