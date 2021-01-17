#include "../inc/derivative_devide.h"

void derivative_of_polynome(ll_polynome_t *polynome)
{
    node_t *temp = polynome->head;
    while (temp)
    {
        temp->coeff *= temp->pow;
        temp->pow -= 1;
        temp = temp->next;
    }
}

void devide_pol_to_odd_even(ll_polynome_t *polynome, ll_polynome_t *odd_nodes, ll_polynome_t *even_nodes)
{
    node_t *temp;
    while (polynome->head)
    {
        temp = polynome->head;
        polynome->head = polynome->head->next;
        temp->next = NULL;
        if (temp->pow % 2 == 0)
            push(even_nodes, temp);
        else
            push(odd_nodes, temp);
    }
}