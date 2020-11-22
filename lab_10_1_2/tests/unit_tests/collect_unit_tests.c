#include "../../inc/unit_h/collect_unit_tests.h"

int main()
{
    return collect_all_tests();
}

int collect_all_tests(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = addtion_function_tests();

    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed != 0)
        return error;

    s = devide_function_tests();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed != 0)
        return error;
    
    s = derivative_function_tests();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed != 0)
        return error;

    s = value_function_tests();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed != 0)
        return error;
    return ok;
}