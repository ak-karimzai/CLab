#include <stdlib.h>
#include "../inc/unit_test_headers/unit_function.h"

int main()
{
    int rc = 0;
    
    rc += addition_tests();
    rc += multipli_unit_tests();
    rc += gauss_unit_tests();

    return rc;
}