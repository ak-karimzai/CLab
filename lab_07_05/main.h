#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

#define INPUT_FILE 1
#define OUTPUT_FILE 2
#define KEY 3

enum error_type
{
    ok,
    error
};