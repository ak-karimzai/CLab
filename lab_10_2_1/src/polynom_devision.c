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

int polynom_devision(void)
{
    poly_node *list;
    poly_node *odd_nodes;
    poly_node *even_nodes;
    init_list_node(&list);
    init_list_node(&odd_nodes);
    init_list_node(&even_nodes);
    
    int rc = error;
    if (list && odd_nodes && even_nodes)
    {
        string_t *polynom_coeffs = get_line();
        if (polynom_coeffs)
        {
            rc = create_list_from_line(polynom_coeffs, list);
            if (rc == ok)
            {
                create_even_odd_nodes(list, odd_nodes, even_nodes);
                print_nodes(even_nodes);
                print_nodes(odd_nodes);
            }
            free_string(polynom_coeffs);
        }
        free_list(even_nodes);
        free_list(odd_nodes);
        free_list(list);
    }
    else
    {
        free_list(list);
        free_list(odd_nodes);
        free_list(even_nodes);
    }
    return rc;
}