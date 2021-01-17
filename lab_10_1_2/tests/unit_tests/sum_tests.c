#include "../../inc/unit_h/sum_tests.h"

START(check_addition_fun)
{
    ll_polynome_t *polynome;
    ll_polynome_t *sec_polynome;
   
    ck_assert_int_ne(create_ll_node(&polynome), error);
    ck_assert_int_ne(create_ll_node(&sec_polynome), error);
   
    ck_assert_int_ne(push(polynome, create_node(4, 3)), error);
    ck_assert_int_ne(push(polynome, create_node(3, 2)), error);
    ck_assert_int_ne(push(polynome, create_node(2, 1)), error);
    ck_assert_int_ne(push(polynome, create_node(1, 0)), error);
   
    ck_assert_int_ne(push(sec_polynome, create_node(4, 3)), error);
    ck_assert_int_ne(push(sec_polynome, create_node(3, 2)), error);
    ck_assert_int_ne(push(sec_polynome, create_node(2, 1)), error);
    ck_assert_int_ne(push(sec_polynome, create_node(1, 0)), error);
   
    ll_polynome_t *res = polynome_addition(polynome, sec_polynome);
   
    ck_assert_ptr_nonnull(res);
    ck_assert_ptr_nonnull(res->head);
    ck_assert_int_eq(res->head->coeff, 8);
    ck_assert_int_eq(res->head->pow, 3);

    ck_assert_ptr_nonnull(res->head->next);
    ck_assert_int_eq(res->head->next->coeff, 6);
    ck_assert_int_eq(res->head->next->pow, 2);

    ck_assert_ptr_nonnull(res->head->next->next);
    ck_assert_int_eq(res->head->next->next->coeff, 4);
    ck_assert_int_eq(res->head->next->next->pow, 1);

    ck_assert_ptr_nonnull(res->head->next->next->next);
    ck_assert_int_eq(res->head->next->next->next->coeff, 2);
    ck_assert_int_eq(res->head->next->next->next->pow, 0);
    free_list(polynome);
    free_list(sec_polynome);
    free_list(res);
}
END

START(check_addition_fun_2)
{
    ll_polynome_t *polynome;
    ll_polynome_t *sec_polynome;
   
    ck_assert_int_ne(create_ll_node(&polynome), error);
    ck_assert_int_ne(create_ll_node(&sec_polynome), error);
   
    ck_assert_int_ne(push(polynome, create_node(4, 2)), error);
    ck_assert_int_ne(push(polynome, create_node(12, 1)), error);
    ck_assert_int_ne(push(polynome, create_node(1, 0)), error);
   
    ck_assert_int_ne(push(sec_polynome, create_node(12, 10)), error);
    ck_assert_int_ne(push(sec_polynome, create_node(8, 1)), error);
    ck_assert_int_ne(push(sec_polynome, create_node(12, 0)), error);
   
    ll_polynome_t *res = polynome_addition(polynome, sec_polynome);
   
    ck_assert_ptr_nonnull(res);
    ck_assert_ptr_nonnull(res->head);
    ck_assert_int_eq(res->head->coeff, 12);
    ck_assert_int_eq(res->head->pow, 10);

    ck_assert_ptr_nonnull(res->head->next);
    ck_assert_int_eq(res->head->next->coeff, 4);
    ck_assert_int_eq(res->head->next->pow, 2);

    ck_assert_ptr_nonnull(res->head->next);
    ck_assert_int_eq(res->head->next->next->coeff, 20);
    ck_assert_int_eq(res->head->next->next->pow, 1);

    ck_assert_ptr_nonnull(res->head->next->next);
    ck_assert_int_eq(res->head->next->next->next->coeff, 13);
    ck_assert_int_eq(res->head->next->next->next->pow, 0);

    free_list(polynome);
    free_list(sec_polynome);
    free_list(res);
}
END

START(check_addition_fun_3)
{
    ll_polynome_t *polynome;
    ll_polynome_t *sec_polynome;
   
    ck_assert_int_ne(create_ll_node(&polynome), error);
    ck_assert_int_ne(create_ll_node(&sec_polynome), error);
   
    ck_assert_int_ne(push(polynome, create_node(12, 10)), error);
    ck_assert_int_ne(push(polynome, create_node(10, 5)), error);
    ck_assert_int_ne(push(polynome, create_node(4, 2)), error);
    ck_assert_int_ne(push(polynome, create_node(12, 1)), error);
    ck_assert_int_ne(push(polynome, create_node(1, 0)), error);
   
    ck_assert_int_ne(push(sec_polynome, create_node(8, 1)), error);
    ck_assert_int_ne(push(sec_polynome, create_node(12, 0)), error);
      
    ll_polynome_t *res = polynome_addition(polynome, sec_polynome);
   
    
    ck_assert_ptr_nonnull(res);
    ck_assert_ptr_nonnull(res->head);
    ck_assert_int_eq(res->head->coeff, 12);
    ck_assert_int_eq(res->head->pow, 10);

    ck_assert_ptr_nonnull(res->head->next);
    ck_assert_int_eq(res->head->next->coeff, 10);
    ck_assert_int_eq(res->head->next->pow, 5);

    ck_assert_ptr_nonnull(res->head->next->next);
    ck_assert_int_eq(res->head->next->next->coeff, 4);
    ck_assert_int_eq(res->head->next->next->pow, 2);

    ck_assert_ptr_nonnull(res->head->next->next->next);
    ck_assert_int_eq(res->head->next->next->next->coeff, 20);
    ck_assert_int_eq(res->head->next->next->next->pow, 1);

    ck_assert_ptr_nonnull(res->head->next->next->next->next);
    ck_assert_int_eq(res->head->next->next->next->next->coeff, 13);
    ck_assert_int_eq(res->head->next->next->next->next->pow, 0);

    free_list(polynome);
    free_list(sec_polynome);
    free_list(res);
}
END


SUITE *addtion_function_tests(void)
{
    SUITE *s;
    TCASE *pos_tes;

    s = suite_create("Sum function");

    pos_tes = tcase_create("Positives");
    
    tcase_add_test(pos_tes, check_addition_fun);
    tcase_add_test(pos_tes, check_addition_fun_2);
    tcase_add_test(pos_tes, check_addition_fun_3);
    suite_add_tcase(s, pos_tes);

    return s;
}