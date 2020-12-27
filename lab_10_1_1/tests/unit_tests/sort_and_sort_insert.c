#include "../../inc/unit_test_h/remove_dup_tst.h"

START(sort_tst)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    node_t *temp, *head;
    temp = head = NULL;
    while ((temp = create_node(input_file)))
        push_back(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    head = sort(head, compare_by_price);
    
    temp = head;
    while (temp && temp->next)
    {
        ck_assert_int_le(((product *) temp->data)->price, ((product *) temp->next->data)->price);
        temp = temp->next;
    }

    free_elements(&head);
    fclose(input_file);
}
END

START(sort_when_one_node)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    node_t *temp, *head;
    temp = head = NULL;
    temp = create_node(input_file);
    ck_assert_ptr_nonnull(temp);
    push_back(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    head = sort(head, compare_by_price);

    free_elements(&head);
    fclose(input_file);
}
END

START(sorted_insert_test)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    node_t *temp, *head;
    temp = head = NULL;
    while ((temp = create_node(input_file)))
        sorted_insert(&head, temp, compare_by_price);
    ck_assert_ptr_nonnull(head);
    
    temp = head;
    while (temp && temp->next)
    {
        ck_assert_int_le(((product *) temp->data)->price, ((product *) temp->next->data)->price);
        temp = temp->next;
    }

    free_elements(&head);
    fclose(input_file);
}
END

SUITE *sort_tests(void)
{
    SUITE *s;
    TCASE *tests;

    s = suite_create("sort and sorted insert tests");

    tests = tcase_create("sort and sorted insert Tests");

    tcase_add_test(tests, sorted_insert_test);
    tcase_add_test(tests, sort_when_one_node);
    tcase_add_test(tests, sort_tst);

    suite_add_tcase(s, tests);

    return s;
}