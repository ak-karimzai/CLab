#include <stdio.h>
#include <stdlib.h>

#define N 100

enum type_error
{
    ok,
    put_err,
    get_err
};

void add_to_file(FILE *f, int n)
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

int sort_file(FILE *f, int n)
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