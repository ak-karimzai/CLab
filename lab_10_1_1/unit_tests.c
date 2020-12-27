#include "./inc/unit_test_h/main.h"

int main()
{
    printf("%ud\n", run_all_tests());
    return run_all_tests();
}

int run_test(Suite *(*test)(void))
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test();
    runner = srunner_create(s);
    
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    
    srunner_free(runner);
    return no_failed;
}

int run_all_tests(void)
{
    unsigned int faileds = 0;
    faileds += run_test(find_tests);
    faileds += run_test(remove_dupli_tests);
    faileds += run_test(sort_tests);
    faileds += run_test(push_tests);
    faileds += run_test(insert_tests);
    return faileds;
}
