#include "../inc/copy_append.h"

void free_node_c(node_t *node)
{
    free(node->data);
    free(node);
}

void free_list(node_t *head)
{
    node_t *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free_node_c(temp);
    }
}

node_t *get_node(void *data)
{
    node_t *temp = malloc(sizeof(node_t));
    if (temp)
    {
        temp->data = data;
        temp->next = NULL;
    }
    return temp;
}

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

void swap_node(node_t *lhs, node_t *rhs)
{
    void *temp = lhs->data;
    lhs->data = rhs->data;
    rhs->data = temp;
}

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