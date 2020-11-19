#include "../inc/addition.h"

ll_polynome_t *polynome_addition(ll_polynome_t *lhs, ll_polynome_t *rhs)
{
    ll_polynome_t *sum = NULL;
    if (create_ll_node(&sum) == ok)
    {
        node_t *temp;
        while (lhs->head && rhs->head)
        {
            if (lhs->head->pow > rhs->head->pow)
            {
                temp = lhs->head;
                lhs->head = lhs->head->next;
                temp->next = NULL;
                push(sum, temp);
            }
            else if (lhs->head->pow < rhs->head->pow)
            {
                temp = rhs->head;
                rhs->head = rhs->head->next;
                temp->next = NULL;
                push(sum, temp);
            }
            else
            {
                temp = lhs->head;
                lhs->head->coeff += rhs->head->coeff;
                lhs->head = lhs->head->next;
                temp->next = NULL;
                push(sum, temp);
                temp = rhs->head;
                rhs->head = rhs->head->next;
                free(temp);
            }
        }
        if (lhs->head)
            sum->end = lhs->head;
        else if (rhs->head)
            sum->end = rhs->head;
    }
    return sum;
}