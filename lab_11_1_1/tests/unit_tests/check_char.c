#include "../../inc/unit_test_h/check_char.h"

START(last_positive_char)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%c", 127);
    ck_assert_int_eq(str[0] - 0, 127);
}
END

START(last_negative_char)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%c", -128);
    ck_assert_int_eq(str[0] - 0, -128);
}
END

START(zero)
{
    char str[40];
    my_snprintf(str, sizeof(str), "%c", 0);
    ck_assert_int_eq(str[0], 0);
}
END

SUITE *char_tests(void)
{
    SUITE *s;
    TCASE *pos_tests;

    s = suite_create("Char tests");

    pos_tests = tcase_create("Positives");

    tcase_add_test(pos_tests, last_negative_char);
    tcase_add_test(pos_tests, last_positive_char);
    tcase_add_test(pos_tests, zero);

    suite_add_tcase(s, pos_tests);

    return s;
}