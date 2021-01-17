#ifndef _PHSH_H_
#define _PHSH_H_

#include <stdio.h>
#include <stdlib.h>
#include "data_struct.h"

void push_front(node_t **head, node_t *element);

void push_back(node_t **head, node_t *element);

node_t *find(node_t *head, const void *data, comparator cmp);

#endif //_PHSH_H_