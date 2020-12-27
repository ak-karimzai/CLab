#include "../../inc/unit_test_h/find_tests.h"

static node_t *ptr_to_last(node_t *head)
{
    node_t *temp = head;
    while (temp->next)
        temp = temp->next;
    return temp;
}

START_TEST(find_head_elem)
{
    FILE *input_file = fopen("tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    node_t *temp, *head;
    head = NULL;
    temp = create_node(input_file);
    while (temp)
    {
        push_back(&head, temp);
        temp = create_node(input_file);
    }
    
    ck_assert_ptr_nonnull(head);
    
    temp = find(head, head->data, compare_by_price);
    ck_assert_ptr_nonnull(temp);
    
    ck_assert_int_eq(compare_by_price(head->data, temp->data), 0);
    
    free_elements(&head);
    fclose(input_file);
}
END_TEST

START_TEST(find_last_elem)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    node_t *temp, *head;
    temp = head = NULL;
    while ((temp = create_node(input_file)))
        push_back(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    node_t *last_node = ptr_to_last(head);
    ck_assert_ptr_nonnull(last_node);
    
    temp = find(head, last_node->data, compare_by_price);
    ck_assert_ptr_nonnull(temp);
    ck_assert_int_eq(compare_by_price(temp->data, last_node->data), 0);

    free_elements(&head);
    fclose(input_file);
}
END_TEST

Suite *find_tests(void)
{
    Suite *s;
    TCase *tests;
    s = suite_create("find tests");

    tests = tcase_create("Find Tests");

    tcase_add_test(tests, find_head_elem);
    tcase_add_test(tests, find_last_elem);

    suite_add_tcase(s, tests);

    return s;
}