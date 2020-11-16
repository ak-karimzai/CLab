#ifndef KEY_UNIT_TEST_H
#define KEY_UNIT_TEST_H

#include <check.h>
#include <stdlib.h>

#include "../error_code.h"
#include "../key.h"

#define SUITE Suite
#define TCASE TCase
#define CKVER CK_VERBOSE

int key_unit_tests(void);
SUITE *check_key_fun(void);

#endif // KEY_UNIT_TEST_H