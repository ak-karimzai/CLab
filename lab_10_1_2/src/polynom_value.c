#include "../inc/polynom_value.h"

long int get_polynom_val(poly_node *list, int val)
{
    long int sum = 0;
    node_t *temp = list->head;

    while (temp)
    {
        sum += (temp->data.m * (long int) pow(val, temp->data.n));
        temp = temp->next;
    }
    return sum;
}

int polynom_value(void)
{
    poly_node *list;
    init_list_node(&list);
    
    int rc = ok, val;
    if (list)
    {
        string_t *polynom_coeffs = get_line();
        if (polynom_coeffs)
        {
            rc = create_list_from_line(polynom_coeffs, list);
            if (rc == ok)
            {
                if (fscanf(stdin, "%d", &val) == 1)
                    printf("%ld\n", get_polynom_val(list, val));
                else
                    rc = error;
            }
            free_string(polynom_coeffs);
        }
        else
            rc = error;
        free_list(list);
    }
    else 
        rc = error;
    return rc;
}