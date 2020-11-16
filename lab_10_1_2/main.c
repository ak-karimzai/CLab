#include "./inc/main.h"

int main()
{    
    int rc = error;
    string_t *choice;
    choice = get_line();
    if (choice)
    {
        if (strcmp(choice->string, POLYNOM_VALUE) == ok)
        {
            poly_node *list;
            init_list_node(&list);
            
            int val;
            if (list)
            {
                string_t *polynom_coeffs = get_line();
                if (polynom_coeffs)
                {
                    rc = create_list_from_line(polynom_coeffs, list);
                    if (rc == ok)
                    {
                        if (fscanf(stdin, "%d", &val) == 1)
                        {
                            printf("%ld\n", get_polynom_val(list, val));
                            free_list(list);
                        }
                        else
                            rc = error;
                    }
                    free_string(polynom_coeffs);
                }
            }
        }
        else if (strcmp(choice->string, POLYNOM_DERIVATIVE) == ok)
        {
            poly_node *list;
            init_list_node(&list);
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
        }
        else if (strcmp(choice->string, POLYNOM_ADDITION) == ok)
        {
            poly_node *list_rhs, *list_lhs;
            init_list_node(&list_rhs);
            init_list_node(&list_lhs);
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
        }
        else if (strcmp(choice->string, POLYNOM_DIVISION) == ok)
        {
            poly_node *list;
            poly_node *odd_nodes;
            poly_node *even_nodes;
            init_list_node(&list);
            init_list_node(&odd_nodes);
            init_list_node(&even_nodes);
            
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
        }
        free_string(choice);
    }
    return rc;
}