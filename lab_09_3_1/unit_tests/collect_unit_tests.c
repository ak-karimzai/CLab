#include <check.h>
#include <stdlib.h>
#include "../inc/unit_test_headers/collect_unit_tests.h"

int read_tests(void)
{
    int no_failed = 0;
    SUITE *s;
    SRUNNER *runner;

    s = check_read_fun();

    runner = srunner_create(s);

    srunner_run_all(runner, CKVER);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);
    return no_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}