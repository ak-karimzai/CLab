#include "../../inc/unit_test_h/push_tst.h"

START_TEST(push_to_null_list_pb)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    
    node_t *temp = create_node(input_file);
    ck_assert_ptr_nonnull(temp);
    node_t *head = NULL;
    
    push_back(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    free_elements(&head);
    fclose(input_file);
}
END_TEST

START_TEST(push_to_list_with_head_pb)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    
    node_t *temp = create_node(input_file);
    ck_assert_ptr_nonnull(temp);
    node_t *head = NULL;
    
    push_back(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    temp = create_node(input_file);
    ck_assert_ptr_nonnull(temp);
    
    push_back(&head, temp);
    ck_assert_ptr_nonnull(head->next);
    
    free_elements(&head);
    fclose(input_file);
}
END_TEST

START_TEST(push_to_null_list_pu)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    
    node_t *temp = create_node(input_file);
    ck_assert_ptr_nonnull(temp);
    node_t *head = NULL;
    
    push_front(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    free_elements(&head);
    fclose(input_file);
}
END_TEST

START_TEST(push_to_list_with_head_pu)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    
    node_t *temp = create_node(input_file);
    ck_assert_ptr_nonnull(temp);
    
    node_t *head = NULL;
    push_front(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    temp = create_node(input_file);
    ck_assert_ptr_nonnull(temp);
    push_front(&head, temp);
    ck_assert_ptr_nonnull(head->next);
    
    free_elements(&head);
    fclose(input_file);
}
END_TEST

SUITE *push_tests(void)
{
    SUITE *s;
    TCASE *tests;

    s = suite_create("push tests");

    tests = tcase_create("push Tests");

    tcase_add_test(tests, push_to_list_with_head_pb);
    tcase_add_test(tests, push_to_null_list_pb);
    tcase_add_test(tests, push_to_list_with_head_pu);
    tcase_add_test(tests, push_to_null_list_pu);

    suite_add_tcase(s, tests);

    return s;
}