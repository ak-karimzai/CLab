#include <stdio.h>
#include "../inc/sort.h"

void swap(product *lhs, product *rhs)
{
    product temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int sort_by_price(product *products, const int num_of_elements, const float given_price)
{
    int k = 0, count = 0;
    for (int i = 0; i < num_of_elements; i++)
    {
        if (products[i].price < given_price)
        {
            swap((products + k++), (products + i));
            count++;
        }
    }
    return count;
}