#include <stdio.h>

#define N 100

typedef struct array
{
    int a[100];
    int n;
} arr;

void add_to_array(arr *a)
{
    int x;
    scanf("%d", &a->n);
    for (int i = 0; i < a->n; i++)
    {
        scanf("%d", &x);
        a->a[i] = x;
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

int main()
{
    arr in_arr, out_arr;
    FILE *in, *out;
    
    in = fopen("p_file.bin", "wb");
    if (in == NULL)
    {
        return 1;
    }
    add_to_array(&in_arr);
    size_t element = fwrite(&in_arr, sizeof(arr), 1, in);
    fclose(in);
    if (element == 0)
    {
        return 2;
    }
    out = fopen("p_file.bin", "rb");

    element = fread(&out_arr, sizeof(arr), 1, out);
    fclose(out);
    if (element == 0)
    {
        return 3;
    }
    for (int i = 0; i < out_arr.n; i++)
    {
        printf("%d ", out_arr.a[i]);
    }
    sort_arr(&out_arr);
    in = fopen("p_file.bin", "wb");
    if (in == NULL)
        return 1;
    element = fwrite(&out_arr, sizeof(arr), 1, in);
    fclose(in);
    if (element == 0)
    {
        return 3;
    }
    return 0;
}