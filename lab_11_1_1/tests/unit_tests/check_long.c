#include "../../inc/unit_test_h/check_long.h"

START(last_positive_long)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%ld", LONG_MAX);
    ck_assert_int_eq(strcmp(str, "9223372036854775807"), 0);
}
END

START(last_negative_long)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%ld", LONG_MIN);
    ck_assert_int_eq(strcmp(str, "-9223372036854775808"), 0);
}
END

START(zero)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%ld", 0);
    ck_assert_int_eq(strcmp(str, "0"), 0);
}
END

SUITE *long_tests(void)
{
    SUITE *s;
    TCASE *pos_tests;


    s = suite_create("Long tests");

    pos_tests = tcase_create("Positives");

    tcase_add_test(pos_tests, last_negative_long);
    tcase_add_test(pos_tests, last_positive_long);
    tcase_add_test(pos_tests, zero);

    suite_add_tcase(s, pos_tests);

    return s;
}