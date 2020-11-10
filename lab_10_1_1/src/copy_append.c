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

node_t* sort(node_t *head, comparator cmp)
{
    node_t *current = head, *temp;
    node_t *k;
    while (current)
    {
        temp = current->next;
        k = current;
        while (temp)
        {
            if (cmp(current->data, temp->data) == 1)
                k = temp;
            temp = temp->next;
        }
        swap_node(current, k);
        current = current->next;
    }
    return head;
}

void sorted_insert(node_t **head, node_t *element, comparator cmp)
{
    int cmp_res;
    node_t *current = *head;
    node_t *before_point = NULL;
    if (*head)
    {
        *head = sort(*head, cmp);
        cmp_res = cmp(current->data, element->data);
        if (cmp_res > 0 || cmp_res == 0)
        {
            element->next = *head;
            *head = element;
        }
        else if (cmp_res < 0)
        {
            current = current->next;
            while (current && cmp(current->data, element->data) == -1)
            {
                before_point = current;
                current = current->next;
            }
            if (before_point)
            {
                element->next = before_point->next;
                before_point->next = element;
            }
        }
    }
}