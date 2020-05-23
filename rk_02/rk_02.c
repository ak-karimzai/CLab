#include <stdio.h>
#include <string.h>

#define N 1300
#define MAX_CITY_NAME 101

typedef struct 
{
    char city[MAX_CITY_NAME];
    int year;
    long long pop;
} city_r;

enum type_error
{
    ok,
    error
};

void swap_struct(city_r *x, city_r *y)
{
    city_r temp = *x;
    *x = *y;
    *y = temp;
}

void sort_struct(city_r *arr, int n)
{
   int i, j; 
   for (i = 0; i < n - 1; i++)
       for (j = 0; j < n - i - 1; j++)  
           if (arr[j].pop < arr[j+1].pop) 
              swap_struct(&arr[j], &arr[j+1]);
}

int process(FILE *in, FILE *out)
{
    city_r arr[N];
    int n = 0;
    
    while (1)
    {
        if (feof(in))
            break;

        fgets(arr[n].city, 101, in);
        
        for (int i = 0; i < 101; i++)
        {
            if (arr[n].city[i] == '\n')
                arr[n].city[i] = '\0';
        }
        
        fscanf(in, "\n%I64d \n%d\n", &arr[n].pop, &arr[n].year);
        n++;
    }
    sort_struct(arr, n);
    //fprintf(out, "Name of five city with Max Population:\n\n");
    for (int i = 0; i < 5; i++)
    {
        fprintf(out, "%s\n", arr[i].city);
    }
    //printf("%d", n);
    return n;
}

int main()
{
    FILE *in, *out;
    in = fopen("in.txt", "r");
    if (!in)
        return error;

    if (feof(in))
        return error;

    out = fopen("out.txt", "w");
    
    if (!out)
        return error;
    
    int len = process(in, out);

    if (len == 0)
        return error;

    fclose(in);
    
    fclose(out);
    
    return ok;    
}