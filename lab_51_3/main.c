#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct
{
    int a[N];
    int n;
} arr;

void add_to_array(arr *a)
{
    //printf("%d", a->n);
    for (int i = 0; i < a->n; i++)
    {
        a->a[i] = rand();
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort_arr(arr *a)
{
    for (int i = 0; i < a->n; i++)
    {
        for (int j = i; j < a->n - 1; j++)
        {
            if (a->a[j] > a->a[j + 1])
                swap(&a->a[j], &a->a[j + 1]);
        }
    }
}

void display(arr array)
{
    for (int i = 0; i < array.n; i++)
    {
        printf("%d ", array.a[i]);
    }
}

int main(int argc, char **argv)
{
    arr in_arr, out_arr;
    FILE *in;
    if (argc < 2) return -1;
    if (strcmp(argv[1], "c") == 0)
    {
        in_arr.n = atoi(argv[2]);
        //printf("%d", in_arr.n);
        in = fopen(argv[3], "wb");
        if (in == NULL)
            return -1;
        add_to_array(&in_arr);
        size_t element = fwrite(&in_arr, sizeof(arr), 1, in);
        if (element == 0)
            return 1;
        //display(in_arr);
        fclose(in);
        return 0;
    }
    if (strcmp(argv[1], "p") == 0)
    {
        in = fopen(argv[2], "rb");
        fseek(in, 0, SEEK_SET);
        size_t element = fread(&out_arr, sizeof(arr), 1, in);
        if (element == 0) 
            return -1;
        display(out_arr);
        fclose(in);
        return 0;
    }
    if (strcmp(argv[1], "s") == 0)
    {
        in = fopen(argv[2], "rb+");
        fseek(in, 0, SEEK_SET);
        if (fread(&out_arr, sizeof(arr), 1, in) == 0)
            return -1;
        //display(out_arr);
        sort_arr(&out_arr);
        fseek(in, 0, SEEK_SET);
        if (fwrite(&out_arr, sizeof(arr), 1, in) == 0)
            return -1;
        //display(out_arr);
        //fseek(in, 0, SEEK_SET);
        //fread(&out_arr, sizeof(arr), 1, in);
        //display(out_arr);
        return 0;
    }
}