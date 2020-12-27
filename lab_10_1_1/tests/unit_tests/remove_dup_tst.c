#include "../../inc/unit_test_h/remove_dup_tst.h"

START_TEST(remove_duplicates_tst)
{
    FILE *input_file = fopen("./tests/data.txt", "r");
    ck_assert_ptr_nonnull(input_file);
    node_t *temp, *head;
    temp = head = NULL;
    while ((temp = create_node(input_file)))
        push_back(&head, temp);
    ck_assert_ptr_nonnull(head);
    
    remove_duplicates(&head, compare_by_price);
    
    temp = head;
    while (temp && temp->next)
    {
        ck_assert_int_eq(compare_by_price(temp->data, temp->next->data), 0);
        temp = temp->next;
    }

    free_elements(&head);
    fclose(input_file);
}
END_TEST

Suite *remove_dupli_tests(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("Remove dupli tests");

    tests = tcase_create("Remove Dupli Tests");

    tcase_add_test(tests, remove_duplicates_tst);

    suite_add_tcase(s, tests);

    return s;
}