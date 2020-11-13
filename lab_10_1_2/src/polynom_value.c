#include "../inc/polynom_value.h"

long int get_polynom_val(poly_node *list, int val)
{
    long int sum = 0;
    node_t *temp = list->head;

    while (temp)
    {
        sum += (temp->data.m * (long int) pow(val, temp->data.n));
        temp = temp->next;
    }
    return sum;
}