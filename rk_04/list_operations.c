#include "list_operations.h"

node_t *create_ll_node(char *name, int age, node_t *marks)
{
    node_t *temp = calloc(1, sizeof(node_t));
    char *name_temp = NULL;
    if (temp)
    {
        if ((name_temp = strdup(name)) != NULL)
        {
            temp->name = name_temp;
            temp->age = age;
            temp->mark = marks;
        }
        else
        {
            free(temp);
        }
    }
    return temp;
}

linked_list *create_ll(void)
{
    linked_list* temp = calloc(1, sizeof(linked_list));
    return temp;
}

int push_back(linked_list *list, node_t *new_node)
{
    if (new_node)
    {
        if (list->head == NULL)
        {
            list->head = list->end = new_node;
        }
        else
        {
            list->end->next = new_node;
            list->end = new_node;
        }
        return ok;
    }
    return error;
}

void pop_back(linked_list *list)
{
    node_t *temp, *n_temp = NULL;
    temp = list->head;
    while (temp->next)
    {
        n_temp = temp;
        temp = temp->next;
    }
    if (n_temp)
    {
        n_temp->next = NULL;
        if (temp->mark)
        {
            free(temp->name);
        }
        free(temp);
    }
    else
    {
        if (temp->mark)
        {
            free(temp->name);
        }
        free(temp);
        list->head = NULL;
    }
}

void display(linked_list *list)
{
    node_t *temp = list->head;
    node_t *marks = NULL;
    while (temp)
    {
        printf("name: %s  age: %d marks: ", temp->name, temp->age);
        marks = temp->mark;
        while (marks)
        {
            printf("subject: %s Numbers: %d ", marks->name, marks->age);
            marks = marks->next;
        }
        printf("\n");
        temp = temp->next;
    }
}

void free_ll(linked_list *list)
{
    node_t *temp;
    while (list->head)
    {
        temp = list->head;
        list->head = list->head->next;
        if (temp->mark)
        {
            free(temp->mark->name);
            free(temp->mark);
        }
        free(temp);
    }
    free(list);
}