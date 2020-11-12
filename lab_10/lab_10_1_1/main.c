#include "inc/main.h"

void print_elements(node_t *head)
{
    while (head)
    {
        printf("%s%d\n", head->data->product_name, head->data->price);
        head = head->next;
    }
}

int main(void)
{
    FILE *input_file = fopen("tests/data.txt", "r");
    int rc = ok;
    if (input_file)
    {
        node_t *head = NULL;
        node_t *temp = create_node(input_file);
        while (temp)
        {
            push_back(&head, temp);
            temp = create_node(input_file);
        }
        head = sort(head, compare_by_price);
        print_elements(head);
        free_elements(&head);
        fclose(input_file);
    }
    else
        rc = error;
    return rc;
}