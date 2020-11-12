#include "../inc/free.h"

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

void free_prod(product *prod)
{
    if (prod)
    {
        if (prod->product_name)
            free(prod->product_name);
        free(prod);
    }
}

void free_node(node_t *node)
{
    free_prod(node->data);
    free(node);
}

void free_elements(node_t **head)
{
    node_t *temp = NULL;
    node_t *current = *head;
    while (current)
    {
        temp = current;
        current = current->next;
        free_node(temp);
    }
    *head = NULL;
}