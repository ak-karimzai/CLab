#ifndef _LIST_OPERATIONS_H_
#define _LIST_OPERATIONS_H_

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "data_struct.h"

node_t *create_ll_node(char *name, int age, node_t *marks);
linked_list *create_ll(void);
int push_back(linked_list *list, node_t *new_node);
void pop_back(linked_list *list);
void display(linked_list *list);
void free_ll(linked_list *list);

#endif //_LIST_OPERATIONS_H_