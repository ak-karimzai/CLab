#include "../inc/comparator.h"

int compare_by_price(const void *first, const void *second)
{
    product *lhs = (product *) first, *rhs = (product *) second;
    int res = EQUAL;
    if (lhs->price > rhs->price)
        res = BIGGER;
    else if (lhs->price < rhs->price)
        res = LESS_THAN;
    return res;
}