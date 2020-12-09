#include "../../inc/unit_test_h/collect_tests.h"

int main()
{
    return collect_all_tests();
}

int test_runner(SUITE *(*suite)(void))
{
    int no_failed = 0;
    SUITE *s;
    SRUNNER *runner;

    s = suite();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CKVER);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);
    return no_failed;
}

int collect_all_tests(void)
{
    int all_faileds = 0;
    

    all_faileds += test_runner(oct_tests);
    all_faileds += test_runner(long_tests);
    all_faileds += test_runner(int_tests);
    all_faileds += test_runner(char_tests);
    all_faileds += test_runner(str_tests);

    return all_faileds;
}