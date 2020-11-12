#include "../inc/comparator.h"

int compare_by_price(const void *first, const void *second)
{
    product *lhs = (product *) first, *rhs = (product *) second;
    if (lhs->price == rhs->price)
        return EQUAL;
    else if (lhs->price > rhs->price)
        return BIGGER;
    else if (lhs->price < rhs->price)
        return LESS_THAN;
}