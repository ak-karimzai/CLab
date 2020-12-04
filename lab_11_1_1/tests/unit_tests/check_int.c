#include "../../inc/unit_test_h/check_int.h"

START(last_positive_int)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%d", 2147483647);
    ck_assert_int_eq(strcmp(str, "2147483647"), 0);
}
END

START(last_negative_int)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%d", -2147483648);
    ck_assert_int_eq(strcmp(str, "-2147483648"), 0);
}
END

START(zero)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%d", 0);
    ck_assert_int_eq(strcmp(str, "0"), 0);
}
END

SUITE *int_tests(void)
{
    SUITE *s;
    TCASE *pos_tests;


    s = suite_create("Int tests");

    pos_tests = tcase_create("Positives");

    tcase_add_test(pos_tests, last_negative_int);
    tcase_add_test(pos_tests, last_positive_int);
    tcase_add_test(pos_tests, zero);

    suite_add_tcase(s, pos_tests);

    return s;
}