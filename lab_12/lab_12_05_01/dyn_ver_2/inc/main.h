#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "input.h"
#include "output.h"

#define INPUT_FILE 1
#define OUTPUT_FILE 2
#define KEY 3

typedef int (*compare)(const void *lhs, const void *rhs);
typedef int (*key_p)(const int*, int, int*, int*);
typedef int (*sort_p)(void*, size_t, size_t, compare);

int compare_int(const void *lhs, const void *rhs);

#endif // MAIN_H