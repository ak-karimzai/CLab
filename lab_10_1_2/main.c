#include "main.h"

void free_list(ll_polynome_t *polynome)
{
    if (polynome)
    {
        node_t *temp;
        while (polynome->head)
        {
            temp = polynome->head;
            polynome->head = polynome->head->next;
            free(temp);
        }
        free(polynome);
    }
}

char *get_string(void)
{
    char *line = NULL;
    size_t len;
    ssize_t read;
    read = getline(&line, &len, stdin);
    if (read > 0)
        line[read - 1] = '\0';
    return read > 0 ? line : NULL;
}

int myatoi(char *s, int *x)
{
    int rc = ok;
    size_t len = strlen(s);
    if (len > 0)
    {
        if (s[0] == '+' || s[0] == '-')
        {
            for (size_t i = 1; i < len; i++)
                if (s[i] < '0' || s[i] > '9')
                    rc = error;
        }
        else
        {
            for (size_t i = 0; i < len; i++)
                if (s[i] < '0' || s[i] > '9')
                    rc = error;
        }
    }
    *x = rc == ok ? atoi(s) : 0;
    return rc; 
}

node_t *create_node(int coeff, int pow)
{
    node_t *temp = malloc(sizeof(node_t));
    if (temp)
    {
        temp->coeff = coeff;
        temp->pow = pow;
        temp->next = NULL;
    }
    return temp;
}

int push(ll_polynome_t *polynome, node_t *node)
{
    int rc = ok;
    if (node)
    {
        if (polynome->head == NULL)
            polynome->head = polynome->end = node;
        else if (polynome->end->pow >= node->pow)
        {
            polynome->end->next = node;
            polynome->end = node;
        }
        else
        {
            rc = error;
            free(node);
        }
    }
    else
        rc = error;
    return rc;
}

int create_list_from_line(char *str, ll_polynome_t *polynome)
{
    int rc = ok, coeff, pow;
    char *num = strtok(str, " ");
    if (num == NULL)
        rc = error;
    while (num)
    {
        if (myatoi(num, &coeff) == ok && (num = strtok(NULL, " ")) && myatoi(num, &pow) == ok)
        {
            if (push(polynome, create_node(coeff, pow)) == error)
            {
                rc = error;
                break;
            }
        }
        else
        {
            rc = error;
            break;
        }
        num = strtok(NULL, " ");
    }
    return rc;
}

int create_ll_node(ll_polynome_t **res_trict)
{
    int rc = error;
    *res_trict = malloc(sizeof(ll_polynome_t));
    if (*res_trict)
    {
        (*res_trict)->head = (*res_trict)->end = NULL;
        rc = ok;
    }
    return rc;
}

long int polynome_val(ll_polynome_t *polynome, int value)
{
    node_t *temp = polynome->head;
    long int res = 0;
    while (temp)
    {
        res += ((long int) pow(value, temp->pow) * temp->coeff);
        temp = temp->next;
    }
    return res;
}

void print_list(ll_polynome_t *polynome, int flag)
{
    node_t *temp = polynome->head;
    if (flag == derivative)
    {
        while (temp)
        {
            if (temp->pow != -1)
                printf("%d %d ", temp->coeff, temp->pow);
            temp = temp->next;
        }
        printf("L\n");
    }
    else if (flag == just_print)
    {
        while (temp)
        {
            printf("%d %d ", temp->coeff, temp->pow);
            temp = temp->next;
        }
        printf("L\n");
    }
    else if (flag == sum_print)
    {
        while (temp)
        {
            if (temp->coeff != 0)
                printf("%d %d ", temp->coeff, temp->pow);
            temp = temp->next;
        }
        printf("L\n");
    }
}

void derivative_if_polynome(ll_polynome_t *polynome)
{
    node_t *temp = polynome->head;
    while (temp)
    {
        temp->coeff *= temp->pow;
        temp->pow -= 1;
        temp = temp->next;
    }
}

void devide_pol_to_odd_even(ll_polynome_t *polynome, ll_polynome_t *odd_nodes, ll_polynome_t *even_nodes)
{
    node_t *temp;
    while (polynome->head)
    {
        temp = polynome->head;
        polynome->head = polynome->head->next;
        temp->next = NULL;
        if (temp->pow % 2 == 0)
            push(even_nodes, temp);
        else
            push(odd_nodes, temp);
    }
}

ll_polynome_t *polynome_addition(ll_polynome_t *lhs, ll_polynome_t *rhs)
{
    ll_polynome_t *sum = NULL;
    if (create_ll_node(&sum) == ok)
    {
        node_t *temp;
        while (lhs->head && rhs->head)
        {
            if (lhs->head->pow > rhs->head->pow)
            {
                temp = lhs->head;
                lhs->head = lhs->head->next;
                temp->next = NULL;
                push(sum, temp);
            }
            else if (lhs->head->pow < rhs->head->pow)
            {
                temp = rhs->head;
                rhs->head = rhs->head->next;
                temp->next = NULL;
                push(sum, temp);
            }
            else
            {
                temp = lhs->head;
                lhs->head->coeff += rhs->head->coeff;
                lhs->head = lhs->head->next;
                temp->next = NULL;
                push(sum, temp);
                temp = rhs->head;
                rhs->head = rhs->head->next;
                free(temp);
            }
        }
        if (lhs->head)
            sum->end = lhs->head;
        else if (rhs->head)
            sum->end = rhs->head;
    }
    return sum;
}

int main()
{
    char *choice = get_string();
    int rc = ok;
    if (choice)
    {
        if (strcmp(choice, "val") == ok || strcmp(choice, "ddx") == ok || strcmp(choice, "dvd") == ok || strcmp(choice, "sum") == ok)
        {
            ll_polynome_t *polynome;
            char *poly_coeff_pow = get_string();
            if (poly_coeff_pow && create_ll_node(&polynome) == ok)
            {
                if (create_list_from_line(poly_coeff_pow, polynome) == error)
                    rc = error;
                else
                {
                    if (strcmp(choice, "val") == ok)
                    {
                        int x_value;
                        if (fscanf(stdin, "%d", &x_value) == 1)
                            printf("%ld\n", polynome_val(polynome, x_value));
                        else
                            rc = error;
                    }
                    else if (strcmp(choice, "dvd") == ok)
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
                    else if (strcmp(choice, "sum") == ok)
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
        }
        else
            rc = error;
        free(choice);
    }
    return rc;
}