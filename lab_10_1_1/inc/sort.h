#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include "data_struct.h"

void sorted_insert(node_t **head, node_t *element, comparator cmp);

void swap_node(node_t *lhs, node_t *rhs);

node_t *sort(node_t *head, comparator cmp);

#endif //_SORT_H_