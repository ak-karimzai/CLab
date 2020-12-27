#include "../../inc/unit_test_h/remove_dup_tst.h"

START(remove_duplicates_tst)
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
    node_t *sec_temp;
    while (temp && temp->next)
    {
        sec_temp = temp->next;
        while (sec_temp)
        {
            ck_assert_int_ne(compare_by_price(temp->data, sec_temp->data), 0);
            sec_temp = sec_temp->next;
        }
        temp = temp->next;
    }

    free_elements(&head);
    fclose(input_file);
}
END

SUITE *remove_dupli_tests(void)
{
    SUITE *s;
    TCASE *tests;

    s = suite_create("Remove dupli tests");

    tests = tcase_create("Remove Dupli Tests");

    tcase_add_test(tests, remove_duplicates_tst);

    suite_add_tcase(s, tests);

    return s;
}