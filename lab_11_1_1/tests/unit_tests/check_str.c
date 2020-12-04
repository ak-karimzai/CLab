#include "../../inc/unit_test_h/check_str.h"

START(one_symbol)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%s", "s");
    ck_assert_int_eq(strcmp(str, "s"), 0);
}
END

START(string)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%s", "Ahmad Khaid Karimzai");
    ck_assert_int_eq(strcmp(str, "Ahmad Khaid Karimzai"), 0);
}
END

START(zero)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%s", "");
    ck_assert_int_eq(strcmp(str, ""), 0);
}
END

SUITE *str_tests(void)
{
    SUITE *s;
    TCASE *pos_tests;


    s = suite_create("Str tests");

    pos_tests = tcase_create("Positives");

    tcase_add_test(pos_tests, one_symbol);
    tcase_add_test(pos_tests, string);
    tcase_add_test(pos_tests, zero);

    suite_add_tcase(s, pos_tests);

    return s;
}