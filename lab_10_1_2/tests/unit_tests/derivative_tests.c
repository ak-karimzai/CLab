#include "../../inc/unit_h/derivative_tests.h"

START_TEST(check_derivative_fun)
{
    ll_polynome_t *polynome;
   
    ck_assert_int_ne(create_ll_node(&polynome), error);
   
    ck_assert_int_ne(push(polynome, create_node(4, 2)), error);
    ck_assert_int_ne(push(polynome, create_node(12, 1)), error);
    ck_assert_int_ne(push(polynome, create_node(1, 0)), error);
    
    derivative_of_polynome(polynome);
    ck_assert_int_eq(polynome->head->coeff, 8);
    ck_assert_int_eq(polynome->head->pow, 1);
    ck_assert_int_eq(polynome->head->next->coeff, 12);
    ck_assert_int_eq(polynome->head->next->pow, 0);
    ck_assert_int_eq(polynome->head->next->next->coeff, 0);

    free_list(polynome);
}
END_TEST

START_TEST(check_derivative_fun_2)
{
    ll_polynome_t *polynome;
   
    ck_assert_int_ne(create_ll_node(&polynome), error);
   
    ck_assert_int_ne(push(polynome, create_node(6, 4)), error);
    ck_assert_int_ne(push(polynome, create_node(4, 3)), error);
    ck_assert_int_ne(push(polynome, create_node(10, 2)), error);
    ck_assert_int_ne(push(polynome, create_node(1, 0)), error);
    ck_assert_int_ne(push(polynome, create_node(34, -1)), error);
    ck_assert_int_ne(push(polynome, create_node(23, -2)), error);
    ck_assert_int_ne(push(polynome, create_node(34, -3)), error);
   
    derivative_of_polynome(polynome);

    ck_assert_int_eq(polynome->head->coeff, 24);
    ck_assert_int_eq(polynome->head->pow, 3);

    ck_assert_int_eq(polynome->head->next->coeff, 12);
    ck_assert_int_eq(polynome->head->next->pow, 2);

    ck_assert_int_eq(polynome->head->next->next->coeff, 20);
    ck_assert_int_eq(polynome->head->next->next->pow, 1);

    ck_assert_int_eq(polynome->head->next->next->next->coeff, 0);
    ck_assert_int_eq(polynome->head->next->next->next->pow, -1);

    ck_assert_int_eq(polynome->head->next->next->next->next->coeff, -34);
    ck_assert_int_eq(polynome->head->next->next->next->next->pow, -2); 

    ck_assert_int_eq(polynome->head->next->next->next->next->next->coeff, -46);
    ck_assert_int_eq(polynome->head->next->next->next->next->next->pow, -3);

    ck_assert_int_eq(polynome->head->next->next->next->next->next->next->coeff, -102);
    ck_assert_int_eq(polynome->head->next->next->next->next->next->next->pow, -4);

    free_list(polynome);
}
END_TEST

Suite *derivative_function_tests(void)
{
    Suite *s;
    TCase *pos_tes;

    s = suite_create("derivative function");

    pos_tes = tcase_create("Positives");
    
    tcase_add_test(pos_tes, check_derivative_fun);
    tcase_add_test(pos_tes, check_derivative_fun_2);
    suite_add_tcase(s, pos_tes);

    return s;
}