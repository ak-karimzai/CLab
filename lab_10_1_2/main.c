#include "./inc/main.h"

int main()
{
    char *choice = get_string();
    int rc = ok;
    if (choice && valid_is_choice(choice) == ok)
    {
        ll_polynome_t *polynome;
        char *poly_coeff_pow = get_string();
        if (poly_coeff_pow && create_ll_node(&polynome) == ok)
        {
            if (create_list_from_line(poly_coeff_pow, polynome) == error)
                rc = error;
            else
            {
                if (strcmp(choice, POLYNOM_VALUE) == ok)
                {
                    int x_value;
                    if (fscanf(stdin, "%d", &x_value) == 1)
                        printf("%ld\n", polynome_val(polynome, x_value));
                    else
                        rc = error;
                }
                else if (strcmp(choice, POLYNOM_DIVISION) == ok)
                {
                    ll_polynome_t *odd_nodes, *even_nodes;
                    odd_nodes = even_nodes = NULL;
                    if (create_ll_node(&odd_nodes) == ok && create_ll_node(&even_nodes) == ok)
                    {
                        devide_pol_to_odd_even(polynome, odd_nodes, even_nodes);
                        if (even_nodes->head)
                            print_list(even_nodes, just_print);
                        if (odd_nodes->head)
                            print_list(odd_nodes, just_print);
                        free_list(odd_nodes);
                        free_list(even_nodes);
                    }
                    else
                    {
                        rc = error;
                        free_list(odd_nodes);
                        free_list(even_nodes);
                    }
                }
                else if (strcmp(choice, POLYNOM_ADDITION) == ok)
                {
                    char *sec_poly_coeff_pow = get_string();
                    ll_polynome_t *second_polynome;
                    if (sec_poly_coeff_pow && create_ll_node(&second_polynome) == ok)
                    {
                        if (create_list_from_line(sec_poly_coeff_pow, second_polynome) == error)
                            rc = error;
                        else
                        {
                            ll_polynome_t *sum = polynome_addition(polynome, second_polynome);
                            print_list(sum, sum_print);
                            free_list(sum);
                        }
                        free_list(second_polynome);
                        free(sec_poly_coeff_pow);
                    }
                    else
                        free(sec_poly_coeff_pow);
                }
                else
                {
                    derivative_if_polynome(polynome);
                    print_list(polynome, derivative);
                }
            }
            free(poly_coeff_pow);
            free_list(polynome);
        }
        else
        {
            free(poly_coeff_pow);
            rc = error;
        }
        free(choice);
    }
    else
    {
        free(choice);
        rc = error;
    } 
    return rc;
}