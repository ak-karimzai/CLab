
#ifndef _COLLECT_UNIT_TESTS_H
#define _COLLECT_UNIT_TESTS_H

#define SUITE Suite
#define CKVER CK_VERBOSE
#define SRUNNER SRunner

SUITE *addition_unit_tests_suite(void);
SUITE *multiplication_unit_tests_suite(void);

#endif //_COLLECT_UNIT_TESTS_H