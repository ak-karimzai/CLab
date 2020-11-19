#include "../inc/polynome_value.h"

long int polynome_val(ll_polynome_t *polynome, int value)
{
    node_t *temp = polynome->head;
    long int res = 0;
    while (temp)
    {
        res += ((long int) pow(value, temp->pow) * temp->coeff);
        temp = temp->next;
    }
    return res;
}