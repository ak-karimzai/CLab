#include "main.h"
#include "unit_function.h"
#include <assert.h>
#include <check.h>
/*
void test_sort()
{
    START_TEST (mysort)
    {
        int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int after_sort[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        mysort(arr, 10, sizeof(int), compare_int);
        for (int i = 0; i < 10; i++)
        {
            ck_assert_int_eq(arr[i], after_sort[i])
            // c(arr[i] == after_sort[i]);
        }
    }
    END_TEST
    START_TEST (mysort)
    {
        int arr[] = {2, 7, 9, 8, 5, 1, 6, 2, 4, 0};
        int after_sort[] = {0, 1, 2, 2, 4, 5, 6, 7, 8, 9};
        mysort(arr, 10, sizeof(int), compare_int);
        for (int i = 0; i < 10; i++)
        {
            ck_assert_int_eq(arr[i], after_sort[i]);
            // assert(arr[i] == after_sort[i]);
        }
    }
    END_TEST
    START_TEST (mysort)
    {
        int arr[] = {25, 83, 32, 82, 73, 56, 63,  4, 38, 51};
        int after_sort[] = {4, 25, 32, 38, 51, 56, 63, 73, 82, 83};
        mysort(arr, 10, sizeof(int), compare_int);
        for (int i = 0; i < 10; i++)
        {
            ck_assert_int_eq(arr[i], after_sort[i])
            // assert(arr[i] == after_sort[i]);
        }
    }
    END_TEST
}*/
/*
void test_ker()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; arr + i != arr + 7; i++)
        printf("(%d, %d) ", arr[i], i);
}*/

// void test_key()
// {
//     int arr[] = {10, 20, 30, 40, 50, 60, 70};
//     int *dst, *e_dst;
//     int avg = 0;
//     int n = get_num_of_elements(arr, arr + 7, &avg);
//     int temp[7];
//     add_elements_to_array(temp, arr, arr + 7, avg);
//     for (int i = 0; i < n; i++)
//         fprintf(stdout, "%d ", temp[i]);
//     printf("%d\n", key(arr, arr + 7, &dst, &e_dst));
//     for (int i = 0; i < n; i++)
//         printf("%d ", dst[i]);
//     printf("%lu dasdd", (arr - (arr + 7)) / sizeof(int));
// }

void test_obj_count()
{
    FILE *f = fopen("neg_in_1.txt", "r");
    if (file_count_objs(f) == 4)
        puts("fayaz Khan");
    else
        puts("mumtaz khan");
    fclose(f);
}

int main()
{
    // test_ker();
    // test_key();
    test_obj_count();
    return 0;
}