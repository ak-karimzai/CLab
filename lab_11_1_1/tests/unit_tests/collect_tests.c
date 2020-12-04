#include "../../inc/unit_test_h/collect_tests.h"

int main()
{
    return collect_all_tests();
}

int collect_all_tests(void)
{
    int no_failed = 0, all_faileds = 0;
    SUITE *s;
    SRUNNER *runner;

    s = int_tests();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CKVER);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    all_faileds += no_failed;

    s = char_tests();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CKVER);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    all_faileds += no_failed;

    s = str_tests();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CKVER);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    all_faileds += no_failed;

    return all_faileds;
}