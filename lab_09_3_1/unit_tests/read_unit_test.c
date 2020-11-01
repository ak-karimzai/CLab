#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/unit_test_headers/read_unit.h"

#define START START_TEST
#define END END_TEST
#define SUITE Suite
#define TCASE TCase
#define CKVER CK_VERBOSE

START(empty_file)
{
    FILE *input_file = fopen("./func_test/neg_1.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    
    int num_of_objs;
    
    product *products = NULL;
    int rc = read_from_file(input_file, &products, &num_of_objs);

    ck_assert_int_eq(num_of_objs, 0);
    ck_assert_ptr_null(products);
    ck_assert_int_eq(rc, error);
    free_product_arr(products, num_of_objs);
    if (input_file)
        fclose(input_file);
}
END

START(objs_less_than_fr_line)
{
    FILE *input_file = fopen("./func_test/neg_2.txt", "r");
    ck_assert_ptr_nonnull(input_file);

    int num_of_objs;
    product *products = NULL;
    int rc = read_from_file(input_file, &products, &num_of_objs);

    ck_assert_int_eq(num_of_objs, 0);
    ck_assert_ptr_null(products);
    ck_assert_int_eq(rc, error);
    free_product_arr(products, num_of_objs);
    if (input_file)
        fclose(input_file);
}
END

START(every_thing_ok)
{
    FILE *input_file = fopen("./func_test/in_1.txt", "r");
    ck_assert_ptr_nonnull(input_file);

    int num_of_objs;
    product *products = NULL;
    int rc = read_from_file(input_file, &products, &num_of_objs);

    ck_assert_int_ne(num_of_objs, 0);
    ck_assert_ptr_nonnull(products);
    ck_assert_int_eq(rc, ok);
    free_product_arr(products, num_of_objs);
    if (input_file)
        fclose(input_file);
}
END

SUITE *check_read_fun(void)
{
    SUITE *s;
    TCASE *tc_neg;
    TCASE *tc_pos;

    s = suite_create("Read From file");
    
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, every_thing_ok);
    
    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, empty_file);
    tcase_add_test(tc_neg, objs_less_than_fr_line);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}