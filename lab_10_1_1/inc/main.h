#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include "data_struct.h"
node_t* sort(node_t *head, comparator cmp);
void sorted_insert(node_t **head, node_t *element, comparator cmp);
int copy(node_t *head, node_t **new_head);
node_t* find(node_t *head, const void *data, comparator cmp);
void* pop_front(node_t **head);
void* pop_back(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);
void push_front(node_t **head, node_t *element);
void push_back(node_t **head, node_t *element);
node_t *create_node(FILE *input_file);
void free_prod(product *prod);
int compare_by_price(const void *first, const void *second);
void remove_duplicates(node_t **head, comparator cmp);

#endif //