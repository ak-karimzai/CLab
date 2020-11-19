#ifndef _CREATE_FREE_H_
#define _CREATE_FREE_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_struct.h"

char *get_string(void);

void free_list(ll_polynome_t *polynome);

int valid_is_choice(const char *str);

#endif //_CREATE_FREE_H_