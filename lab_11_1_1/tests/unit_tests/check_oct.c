#include "../../inc/unit_test_h/check_oct.h"

START(last_positive_int)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%o", 2147483647);
    ck_assert_int_eq(strcmp(str, "17777777777"), 0);
}
END

START(last_unsigned_int)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%o", 4294967295);
    ck_assert_int_eq(strcmp(str, "37777777777"), 0);
}
END

START(zero)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%o", 0);
    ck_assert_int_eq(strcmp(str, "0"), 0);
}
END

SUITE *oct_tests(void)
{
    SUITE *s;
    TCASE *pos_tests;


    s = suite_create("Oct tests");

    pos_tests = tcase_create("Positives");

    tcase_add_test(pos_tests, last_unsigned_int);
    tcase_add_test(pos_tests, last_positive_int);
    tcase_add_test(pos_tests, zero);

    suite_add_tcase(s, pos_tests);

    return s;
}