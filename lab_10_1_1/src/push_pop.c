#include "../inc/push_pop.h"

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

void insert(node_t **head, node_t *elem, node_t *before)
{
    node_t *current = *head;

    if ((*head) == before)
    {
        elem->next = (*head);
        *head = elem;
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
    node_t *temp = NULL;
    if (*head == NULL)
    {
        *head = element;
    }
    else
    {
        temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = element;
    }
}