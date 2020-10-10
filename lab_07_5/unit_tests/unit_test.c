#include <stdlib.h>
#include "../inc/unit_function.h"

int main()
{
    int rc = 0;
    rc += key_unit_tests();
    rc += mysort_sort_tests();

    return rc == EXIT_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE;
}