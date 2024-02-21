#ifndef MATRIX_TESTS_H
#define MATRIX_TESTS_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_matrix.h"

Suite *create_equal_tests(void);
Suite *sum_sub_tests(void);
Suite *mul_tests(void);
Suite *determinant_tests(void);
Suite *calc_inverse_tests(void);

#endif  // MATRIX_TESTS_H
