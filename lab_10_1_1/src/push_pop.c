#include "../inc/push_pop.h"

node_t *find(node_t *head, const void *data, comparator cmp)
{
    node_t *temp = NULL;
    node_t *current = head;
    if (head)
    {
        while (current && cmp(current->data, data) != ok)
            current = current->next;
        if (current)
            temp = current;
    }
    return temp;
}

void* pop_front(node_t **head)
{
    void *data = NULL;
    node_t *temp;
    if (*head)
    {
        data = ((void *)(*head)->data);
        temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
    return data;
}

void* pop_back(node_t **head)
{
    node_t *current = *head;
    node_t *before_end = NULL;
    void *data = NULL;

    if (*head)
    {
        if ((*head)->next == NULL)
        {
            data = (void *)(*head)->data;
            free(*head);
            *head = NULL;
        }
        else
        {
            while (current->next)
            {
                before_end = current;
                current = current->next;
            }
            data = (void *) current->data;
            before_end->next = NULL;
            free(current);
        }
    }
    return data;
}

void insert(node_t **head, node_t *elem, node_t *before)
{
    node_t *to_before = NULL;
    node_t *current = *head;

    if (*head == before)
    {
        elem->next = (*head)->next;
        (*head)->next = elem;
    }
    else
    {
        while (current != before)
        {
            to_before = current;
            current = current->next;
        }
        if (to_before)
        {
            elem->next = to_before->next;
            to_before->next = elem;
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