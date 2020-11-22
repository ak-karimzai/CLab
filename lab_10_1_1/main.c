#include "inc/main.h"

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