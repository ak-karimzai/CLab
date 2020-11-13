#include "../inc/create.h"

void init_list_node(poly_node **list)
{
    *list = malloc(sizeof(poly_node));
    if (*list)
        (*list)->head = (*list)->end = NULL;
}

node_t *create_node(int m, int n)
{
    node_t *temp = malloc(sizeof(node_t));
    if (temp)
    {
        temp->data.m = m;
        temp->data.n = n;
    }
    return temp;
}

string_t *get_line(void)
{
    int rc = error;
    string_t *temp = calloc(1, sizeof(string_t));
    if (temp)
    {
        char *buf = NULL;
        size_t len = 0;
        ssize_t read;
        if ((read = getline(&buf, &len, stdin)) > 0)
        {
            buf[read - 1] = '\0';
            temp->string = buf;
            temp->len = read;
            rc = ok;
        }
    }
    if (rc == error)
    {
        free(temp);
        temp = NULL;
    }
    return temp;
}

int myatoi(char *s, int *x)
{
    int rc = ok;
    for (size_t i = 0; i < strlen(s); i++)
        if (s[i] < '0' && s[i] > '9')
            rc = error;
    *x = rc == ok ? atoi(s) : 0;
    return rc; 
}

int create_list_from_line(string_t *str, poly_node *list)
{
    int m, n, rc = error;
    char *delim = strtok(str->string, " ");
    while (delim)
    {
        if (myatoi(delim, &m) == ok && (delim = strtok(NULL, " ")) && (myatoi(delim, &n) == ok))
        {
            if (push(list, create_node(m, n)) == ok)
                rc = ok;
            else
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
        delim = strtok(NULL, " ");
    }
    return rc;
}