#include "../inc/create_free.h"

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

int valid_is_choice(const char *str)
{
    int rc = error;
    if (strcmp(str, POLYNOM_VALUE) == ok)
        rc = ok;
    else if (strcmp(str, POLYNOM_ADDITION) == ok)
        rc = ok;
    else if (strcmp(str, POLYNOM_DERIVATIVE) == ok)
        rc = ok;
    else if (strcmp(str, POLYNOM_DIVISION) == ok)
        rc = ok;
    return rc;
}

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