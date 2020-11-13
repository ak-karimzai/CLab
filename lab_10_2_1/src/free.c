#include "../inc/free.h"

void free_list(poly_node *list)
{
    if (list)
    {
        node_t *temp;
        while (list && list->head)
        {
            temp = list->head;
            list->head = list->head->next;
            free(temp);
        }
        free(list);
    }
}

void free_string(string_t *string)
{
    if (string)
    {
        free(string->string);
        free(string);
    }
}