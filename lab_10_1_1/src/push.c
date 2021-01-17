#include "../inc/push.h"

void push_front(node_t **head, node_t *element)
{
    if (*head == NULL)
    {
        *head = element;
    }
    else if (element)
    {
        element->next = *head;
        (*head) = element;
    }
}

void push_back(node_t **head, node_t *element)
{
    node_t *temp = *head;
    if (*head == NULL)
    {
        *head = element;
    }
    else
    {
        while (temp->next)
            temp = temp->next;
        temp->next = element;
    }
}

node_t *find(node_t *head, const void *data, comparator cmp)
{
    node_t *temp = NULL;
    node_t *current = head;
    if (head)
    {
        while (current && cmp(current->data, data) != ok)
            current = current->next;
        temp = current;
    }
    return temp;
}