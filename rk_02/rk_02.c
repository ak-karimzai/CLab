#include <stdio.h>
#include <string.h>
#define N 1300

typedef struct 
{
    char city[101];
    int year;
    int pop;
} city_r;

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
void process(FILE *in, FILE *out)
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
        fscanf(in, "%d %d\n", &arr[n].pop, &arr[n].year);
        n++;
    }
    sort_struct(arr, n);
    fprintf(out, "Name of five city Max Population:\n\n");
    for (int i = 0; i < 5; i++)
    {
        fprintf(out, "city № %d: %s\n", i + 1, arr[i].city);
    }
}

int main()
{
    FILE *in, *out;
    in = fopen("in.txt", "r");
    if (!in)
        return -1;

    if (feof(in))
        return -1;

    out = fopen("out.txt", "w");
    
    if (!out)
        return -1;
    
    process(in, out);

    fclose(in);
    
    fclose(out);
    
    return 0;    
}