#include "../inc/sort.h"

void sorted_insert(node_t **head, node_t *element, comparator cmp)
{
    int cmp_res;
    node_t *current = *head;
    
    if (*head == NULL || cmp((*head)->data, element->data) >= EQUAL)
    {
        element->next = *head;
        *head = element;
    }
    else
    {
        while (current->next && cmp(current->next->data, element->data) < EQUAL)
            current = current->next;
        element->next = current->next;
        current->next = element;
    }
}

void swap_node(node_t *lhs, node_t *rhs)
{
    void *temp = lhs->data;
    lhs->data = rhs->data;
    rhs->data = temp;
}

node_t *sort(node_t *head, comparator cmp)
{
    node_t *new_head = NULL;
    node_t *temp = NULL;
    while (head)
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        sorted_insert(&new_head, temp, cmp);
    }
    return new_head;
}