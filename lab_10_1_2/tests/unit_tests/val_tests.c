#include "../../inc/unit_h/val_tests.h"

START_TEST(check_value_function)
{
    ll_polynome_t *polynome;
    const int x_value = 7, res = 1373;
    ck_assert_int_ne(create_ll_node(&polynome), error);
    ck_assert_int_ne(push(polynome, create_node(4, 3)), error);
    ck_assert_int_ne(push(polynome, create_node(1, 0)), error);
    ck_assert_int_eq(polynome_val(polynome, x_value), res);
    free_list(polynome);
}
END_TEST

START_TEST(check_value_function_2)
{
    ll_polynome_t *polynome;
    const int x_value = 34, res = 6917581;
    ck_assert_int_ne(create_ll_node(&polynome), error);
    ck_assert_int_ne(push(polynome, create_node(5, 4)), error);
    ck_assert_int_ne(push(polynome, create_node(6, 3)), error);
    ck_assert_int_ne(push(polynome, create_node(2, 1)), error);
    ck_assert_int_ne(push(polynome, create_node(9, 0)), error);
    ck_assert_int_eq(polynome_val(polynome, x_value), res);
    free_list(polynome);
}
END_TEST

Suite *value_function_tests(void)
{
    Suite *s;
    TCase *pos_tes;

    s = suite_create("Value function");

    pos_tes = tcase_create("Positives");
    
    tcase_add_test(pos_tes, check_value_function);
    tcase_add_test(pos_tes, check_value_function_2);
    suite_add_tcase(s, pos_tes);

    return s;
}