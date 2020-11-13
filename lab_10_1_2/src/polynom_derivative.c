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


int polynom_derivative(void)
{
    poly_node *list;
    init_list_node(&list);
    int rc = error;
    if (list)
    {
        string_t *polynom_coeffs = get_line();
        if (polynom_coeffs)
        {
            rc = create_list_from_line(polynom_coeffs, list);
            if (rc == ok)
            {
                dirvative_of_poly(list);
                print_list(list);
            }
            free_string(polynom_coeffs);
        }
        free_list(list);
    }
    return rc;
}