#include "unit_function.h"
#include <check.h>
#include <stdlib.h>


int main()
{
    if (key_tests_final_result() == EXIT_FAILURE)
        return EXIT_FAILURE;
    
    if (calc_sort_test() == EXIT_FAILURE)
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}