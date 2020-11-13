#include "../inc/polynom_derivative.h"

void dirvative_of_poly(poly_node *list)
{
    node_t *temp = list->head;
    while (temp)
    {
        temp->data.m *= temp->data.n--;
        temp = temp->next; 
    }    
}

void print_list(poly_node *list)
{
    node_t *temp = list->head;
    while (temp)
    {
        if (temp->data.n != -1)
            printf("%d %d ", temp->data.m, temp->data.n);
        temp = temp->next;
    }
    printf("L\n");
}