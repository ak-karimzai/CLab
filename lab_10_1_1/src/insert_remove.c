#include "../inc/insert_remove.h"

void remove_duplicates(node_t **head, comparator cmp)
{
    node_t *first = *head;
    node_t *second, *temp, *third;
    
    while (first && first->next)
    {
        temp = first;
        second = first->next;
        while (second)
        {
            if (cmp(first->data, second->data) == ok)
            {
                temp->next = second->next;
                third = second;
                second = second->next;
                free(third);
            }
            else
            {
                temp = second;
                second = second->next;
            }
        }
        first = first->next;
    }
}

void insert(node_t **head, node_t *elem, node_t *before)
{
    node_t *current = *head;

    if ((*head) == before)
    {
        elem->next = (*head);
        (*head) = elem;
    }
    else
    {
        while (current && current->next)
        {
            if (current->next == before)
            {
                elem->next = current->next;
                current->next = elem;
                break;
            }
            current = current->next;
        }
    }
}