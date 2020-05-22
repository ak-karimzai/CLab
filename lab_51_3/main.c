#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void add_to_array(FILE *f, int n)
{
    fseek(f, 0, SEEK_SET);
    while (n > 0)
    {
        int x = rand();
        fwrite(&x, sizeof(int), 1, f);
        n--;
    }
}

int file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    int size = ftell(f) / sizeof(int);
    fseek(f, 0, SEEK_SET);

    return size;
}

int get_by_pos(FILE *f, int pos, int *x)
{
    fseek(f, pos * sizeof(int) - sizeof(int), SEEK_SET);
    if (fread(x, sizeof(int), 1, f) == 0)
        return -1;
    return 0;
}

int put_by_pos(FILE *f, int pos, int x)
{
    fseek(f, pos * sizeof(int) - sizeof(int), SEEK_SET);
    if (fwrite(&x, sizeof(int), 1, f) == 0)
        return -1;
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort_array(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int sort_arr(FILE *f, int n)
{
    int x;
    int arr[N];
    for (int i = 0; i < n; i++)
    {
        if (get_by_pos(f, i + 1, &x))
            return -1;

        arr[i] = x; 
    }
    sort_array(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (put_by_pos(f, i + 1, arr[i]))
            return -1;
    }
    return 0;
}

void display(FILE *f, int n)
{
    int i = 0;
    while (i < n)
    {
        int x;
        get_by_pos(f, i + 1, &x);
        printf("%d ", x);
        i++;
    }
}

int main(int argc, char **argv)
{
    FILE *in;

    if (argc < 2) 
        return -1;
    
    if (strcmp(argv[1], "c") == 0)
    {
        int n = atoi(argv[2]);
        
        in = fopen(argv[3], "wb");
        
        if (in == NULL)
            return -1;

        add_to_array(in, n);

        fclose(in);
        return 0;
    }

    if (strcmp(argv[1], "p") == 0)
    {
        in = fopen(argv[2], "rb");
        
        if (in == NULL)
            return -1;

        int n = file_size(in);

        display(in, n);
        fclose(in);
        return 0;
    }
    
    if (strcmp(argv[1], "s") == 0)
    {
        in = fopen(argv[2], "rb+");
        
        int n = file_size(in);
        
        if (sort_arr(in, n))
            return -1;

        return 0;
    }
}