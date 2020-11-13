#include "../inc/polynom_sum.h"

poly_node *sum_of_polys(poly_node *lhs, poly_node *rhs)
{
    poly_node *sum;
    init_list_node(&sum);
    if (sum)
    {
        node_t *temp;
        while (lhs->head && rhs->head)
        {
            if (lhs->head->data.n > rhs->head->data.n)
            {
                temp = lhs->head;
                lhs->head = lhs->head->next;
                temp->next = NULL;
                push(sum, temp);
            }
            else if (lhs->head->data.n < rhs->head->data.n)
            {
                temp = rhs->head;
                rhs->head = rhs->head->next;
                temp->next = NULL;
                push(sum, temp);
            }
            else
            {
                temp = rhs->head;
                temp->data.m += lhs->head->data.m;
                rhs->head = rhs->head->next;
                push(sum, temp);
                temp = lhs->head;
                free(temp);
                lhs->head = lhs->head->next;
            }
        }
        if (lhs->head)
            sum->end->next = lhs->head;
        if (rhs->head)
            sum->end->next = rhs->head;
    }
    return sum;
}

void print_sum_of_polys(poly_node *list)
{
    node_t *temp = list->head;
    while (temp)
    {
        printf("%d %d ", temp->data.m, temp->data.n);
        temp = temp->next;
    }
    printf("L\n");
}

int create_linked_list(string_t *first_poly, string_t *second_poly, poly_node *lhs, poly_node *rhs)
{
    int rc = error;
    if (create_list_from_line(first_poly, lhs) == ok)
        if (create_list_from_line(second_poly, rhs) == ok)
            rc = ok;
    return rc;
}

int polynom_sum(void)
{
    poly_node *list_rhs, *list_lhs;
    init_list_node(&list_rhs);
    init_list_node(&list_lhs);
    int rc = error;
    if (list_rhs && list_lhs)
    {
        string_t *first_poly = get_line();
        string_t *second_poly = get_line();
        if (first_poly && second_poly)
        {
            if (create_linked_list(first_poly, second_poly, list_lhs, list_rhs) == ok)
            {
                poly_node *sum = sum_of_polys(list_lhs, list_rhs);
                if (sum)
                {
                    print_sum_of_polys(sum);
                    free_list(sum);
                    rc = ok;
                }
                free_list(list_rhs);
                free_list(list_lhs); 
            }
            free_string(first_poly);
            free_string(second_poly);
        }
        else
        {
            free_string(first_poly);
            free_string(second_poly);
        }
    }
    else
    {
        free_list(list_lhs);
        free_list(list_rhs);
    }
    return rc;
}