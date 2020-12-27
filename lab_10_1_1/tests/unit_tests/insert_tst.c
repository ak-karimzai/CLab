#include "../../inc/unit_test_h/find_tests.h"

START_TEST(insert_before_head)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    node_t *temp, *head;
    temp = head = NULL;
    while ((temp = create_node(input_file)))
        push_back(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    node_t *l_head_before_insert = head;
    rewind(input_file);
    temp = create_node(input_file);
    ck_assert_ptr_nonnull(temp);

    insert(&head, temp, head);
    ck_assert_int_eq(compare_by_price(head->data, l_head_before_insert->data), 0);

    free_elements(&head);
    fclose(input_file);
}
END_TEST

START_TEST(insert_after_head)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    node_t *temp, *head;
    temp = head = NULL;
    while ((temp = create_node(input_file)))
        push_back(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    rewind(input_file);
    temp = create_node(input_file);
    ck_assert_ptr_nonnull(temp);

    insert(&head, temp, head->next);
    ck_assert_int_eq(compare_by_price(head->data, temp->data), 0);

    free_elements(&head);
    fclose(input_file);
}
END_TEST

SUITE *insert_tests(void)
{
    SUITE *s;
    TCASE *tests;

    s = suite_create("insert tests");

    tests = tcase_create("insert Tests");

    tcase_add_test(tests, insert_before_head);
    tcase_add_test(tests, insert_after_head);

    suite_add_tcase(s, tests);

    return s;
}