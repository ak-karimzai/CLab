#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

enum type_error
{
    ok,
    arg_err,
    file_err,
    empty_file,
    put_err,
    get_err,
    error
};

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
        return get_err;
    return ok;
}

int put_by_pos(FILE *f, int pos, int x)
{
    fseek(f, pos * sizeof(int) - sizeof(int), SEEK_SET);
    if (fwrite(&x, sizeof(int), 1, f) == 0)
        return put_err;
    return ok;
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
            return get_err;

        arr[i] = x; 
    }
    sort_array(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (put_by_pos(f, i + 1, arr[i]))
            return put_err;
    }
    return ok;
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

    if (argc < 3) 
        return arg_err;
    
    if (strcmp(argv[1], "c") == ok)
    {
        int n = atoi(argv[2]);
        if (n == 0)
            return get_err;
        
        in = fopen(argv[3], "wb");
        
        if (in == NULL)
            return file_err;

        add_to_array(in, n);

        fclose(in);
        return ok;
    }

    if (strcmp(argv[1], "p") == 0)
    {
        in = fopen(argv[2], "rb");
        
        if (in == NULL)
            return file_err;

        int n = file_size(in);
        
        if (n == 0)
            return empty_file;

        display(in, n);

        fclose(in);
        
        return ok;
    }
    
    if (strcmp(argv[1], "s") == 0)
    {
        in = fopen(argv[2], "rb+");
        
        int n = file_size(in);

        if (n == 0)
            return empty_file;
        
        if (sort_arr(in, n))
            return put_err;

        return ok;
    }
}