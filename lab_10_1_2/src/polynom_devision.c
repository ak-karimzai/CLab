#include "../inc/polynom_devision.h"

void create_even_odd_nodes(poly_node *main, poly_node *odd, poly_node *even)
{
    node_t *temp;
    while (main->head)
    {
        if (main->head->data.n % 2 == 0)
        {
            temp = main->head;
            main->head = main->head->next;
            temp->next = NULL;
            push(even, temp);
        }
        else
        {
            temp = main->head;
            main->head = main->head->next;
            temp->next = NULL;
            push(odd, temp);

        }
    }
}

void print_nodes(poly_node *list)
{
    node_t *temp = list->head;
    while (temp)
    {
        printf("%d %d ", temp->data.m, temp->data.n);
        temp = temp->next;
    }
    printf("L\n");
}