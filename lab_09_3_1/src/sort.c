#include "../inc/sort.h"

void swap(product *lhs, product *rhs)
{
    product temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int sort_by_price(product *products, const size_t num_of_elements, const unsigned int given_price)
{
    int k = 0, count = 0;
    for (size_t i = 0; i < num_of_elements; i++)
    {
        if (products[i].price < given_price)
        {
            swap((products + k++), (products + i));
            count++;
        }
    }
    return count;
}