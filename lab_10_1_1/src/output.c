#include "../inc/output.h"

void print_elements(node_t *head)
{
    while (head)
    {
        printf("%s%d\n", head->data->product_name, head->data->price);
        head = head->next;
    }
}