#include <check.h>
#include <stdlib.h>
#include "../inc/unit_test_headers/collect_unit_tests.h"


int mysort_sort_tests(void)
{
    int no_failed = 0;
    SUITE *s;
    SRUNNER *runner;

    s = mysort_unit_tests_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CKVER);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);
    return no_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

int key_unit_tests(void)
{
    int no_failed = 0;
    SUITE *s;
    SRUNNER *runner;

    s = check_key_fun();
    runner = srunner_create(s);

    srunner_run_all(runner, CKVER);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return no_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}