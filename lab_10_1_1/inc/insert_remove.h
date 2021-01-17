#ifndef _INSERT_REMOVE_H_
#define _INSERT_REMOVE_H_

#include <stdlib.h>
#include "data_struct.h"

void remove_duplicates(node_t **head, comparator cmp);

void insert(node_t **head, node_t *elem, node_t *before);

#endif //_INSERT_REMOVE_H_