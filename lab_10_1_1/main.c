#include "inc/main.h"

void free_node(node_t *node)
{
    free_prod(node->data);
    free(node);
}

void print_elements(node_t *head)
{
    while (head)
    {
        printf("%s%d\n", head->data->product_name, head->data->price);
        head = head->next;
    }
}

void free_elements(node_t **head)
{
    node_t *temp = NULL;
    node_t *current = *head;
    while (current)
    {
        temp = current;
        current = current->next;
        free_node(temp);
    }
    *head = NULL;
}

int main(void)
{
    FILE *input_file = fopen("data.txt", "r");
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
        node_t *finded = find(head, head->next->next->next->next->data, compare_by_price);
        print_elements(finded);
        free_elements(&head);
        fclose(input_file);
    }
    else
        rc = error;
    return rc;
}