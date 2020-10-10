#ifndef KEY_UNIT_TEST_H
#define KEY_UNIT_TEST_H

enum error_code
{
    ok,
    error
};
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif // KEY_UNIT_TEST_H