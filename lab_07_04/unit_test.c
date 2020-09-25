#include "main.h"
#include "function.h"
#include <assert.h>

void test_sort()
{
    {
        int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int after_sort[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        mysort(arr, 10, sizeof(int), compare_int);
        for (int i = 0; i < 10; i++)
        {
            assert(arr[i] == after_sort[i]);
        }
    }
    {
        int arr[] = {2, 7, 9, 8, 5, 1, 6, 2, 4, 0};
        int after_sort[] = {0, 1, 2, 2, 4, 5, 6, 7, 8, 9};
        mysort(arr, 10, sizeof(int), compare_int);
        for (int i = 0; i < 10; i++)
        {
            assert(arr[i] == after_sort[i]);
        }
    }
    {
        int arr[] = {2, 7, 9, 8, 5, 1, 6, 2, 4, 0};
        int after_sort[] = {0, 1, 2, 2, 4, 5, 6, 7, 8, 9};
        mysort(arr, 10, sizeof(int), compare_int);
        for (int i = 0; i < 10; i++)
        {
            assert(arr[i] == after_sort[i]);
        }
    }   
}

int main()
{
    test_sort();
    return 0;
}