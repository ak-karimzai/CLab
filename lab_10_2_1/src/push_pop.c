#include "../inc/push_pop.h"

int push(poly_node *head, node_t *new_ele)
{
    int rc = ok;
    if (head && head->end && new_ele && new_ele->data.n > head->end->data.n)
    {
        free(new_ele);
        rc = error;
    }
    else if (new_ele)
    {
        if (head->head == NULL)
            head->head = head->end = new_ele;
        else
        {
            head->end->next = new_ele;
            head->end = new_ele;
        }
    }
    else
        rc = error;
    return rc;
}