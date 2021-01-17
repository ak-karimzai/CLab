#include "../../inc/unit_h/devide_tests.h"

START(check_devide_fun)
{
    ll_polynome_t *polynome;
    ll_polynome_t *odd, *even;
   
    ck_assert_int_ne(create_ll_node(&polynome), error);
    ck_assert_int_ne(create_ll_node(&even), error);
    ck_assert_int_ne(create_ll_node(&odd), error);
   
    ck_assert_int_ne(push(polynome, create_node(4, 2)), error);
    ck_assert_int_ne(push(polynome, create_node(12, 1)), error);
    ck_assert_int_ne(push(polynome, create_node(1, 0)), error);
    ck_assert_int_ne(push(polynome, create_node(1, -2)), error);
    ck_assert_int_ne(push(polynome, create_node(1, -10)), error);
    ck_assert_int_ne(push(polynome, create_node(1, -115)), error);
    
    devide_pol_to_odd_even(polynome, odd, even);
    
    ck_assert_ptr_null(polynome->head);

    ck_assert_ptr_nonnull(odd->head);
    ck_assert_int_eq(odd->head->coeff, 12);
    ck_assert_int_eq(odd->head->pow, 1);

    ck_assert_ptr_nonnull(odd->head->next);
    ck_assert_int_eq(odd->head->next->coeff, 1);
    ck_assert_int_eq(odd->head->next->pow, -115);

    ck_assert_ptr_nonnull(even->head);
    ck_assert_int_eq(even->head->coeff, 4);
    ck_assert_int_eq(even->head->pow, 2);

    ck_assert_ptr_nonnull(even->head->next);
    ck_assert_int_eq(even->head->next->coeff, 1);
    ck_assert_int_eq(even->head->next->pow, 0);

    ck_assert_ptr_nonnull(even->head->next->next);
    ck_assert_int_eq(even->head->next->next->coeff, 1);
    ck_assert_int_eq(even->head->next->next->pow, -2);

    ck_assert_ptr_nonnull(even->head->next->next->next);
    ck_assert_int_eq(even->head->next->next->next->coeff, 1);
    ck_assert_int_eq(even->head->next->next->next->pow, -10);

    free_list(polynome);
    free_list(odd);
    free_list(even);
}
END

SUITE *devide_function_tests(void)
{
    SUITE *s;
    TCASE *pos_tes;

    s = suite_create("devide function");

    pos_tes = tcase_create("Positives");
    
    tcase_add_test(pos_tes, check_devide_fun);
    suite_add_tcase(s, pos_tes);

    return s;
}