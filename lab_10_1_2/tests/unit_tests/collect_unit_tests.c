#include "../../inc/unit_h/collect_unit_tests.h"

int main()
{
    return collect_all_tests();
}

int collect_all_tests(void)
{
    int no_failed = 0, all_faileds = 0;
    SUITE *s;
    SRUNNER *runner;

    s = addtion_function_tests();

    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    all_faileds += no_failed;

    s = devide_function_tests();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    all_faileds += no_failed;
    
    s = derivative_function_tests();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    all_faileds += no_failed;

    s = value_function_tests();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    all_faileds += no_failed;

    return all_faileds ? error : ok;
}