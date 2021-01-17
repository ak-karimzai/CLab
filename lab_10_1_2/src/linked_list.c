#include "../inc/linked_list.h"

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

int myatoi(char *s, int *x)
{
    int rc = ok;
    size_t len = strlen(s);
    if (len > 0)
    {
        size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        for (; i < len; i++)
            if (s[i] < '0' || s[i] > '9')
                rc = error;
    }
    *x = atoi(s);
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