#ifndef _POLYNOM_DEVISION_H_
#define _POLYNOM_DEVISION_H_

#include <stdio.h>
#include <stdlib.h>

#include "data_struct.h"
#include "free.h"
#include "create.h"

void print_nodes(poly_node *list);

void create_even_odd_nodes(poly_node *main, poly_node *odd, poly_node *even);

#endif //_POLYNOM_DEVISION_H_