#include <stdlib.h>
#include <stdio.h>
#include "../inc/unit_test_headers/unit_function.h"

int main()
{
    int rc = EXIT_SUCCESS;

    rc += addition_tests();
    rc += multipli_unit_tests();
    rc += gauss_unit_tests();

    return rc;
}