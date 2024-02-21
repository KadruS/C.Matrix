#include "tests.h"

START_TEST(sum_1) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expectation);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &reality), OK);
  expectation.matrix[0][0] = 2, expectation.matrix[0][1] = 2,
  expectation.matrix[0][2] = 3;
  expectation.matrix[1][0] = 2, expectation.matrix[1][1] = 4,
  expectation.matrix[1][2] = 5;
  expectation.matrix[2][0] = 3, expectation.matrix[2][1] = 4,
  expectation.matrix[2][2] = 7;
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(sum_2) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expectation);
  A.matrix[0][0] = 23, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 11, A.matrix[2][1] = 3, A.matrix[2][2] = 7;
  B.matrix[0][0] = 3, B.matrix[0][1] = -1, B.matrix[0][2] = 5;
  B.matrix[1][0] = 2, B.matrix[1][1] = 3, B.matrix[1][2] = 4;
  B.matrix[2][0] = -7, B.matrix[2][1] = 5, B.matrix[2][2] = 0;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &reality), OK);
  expectation.matrix[0][0] = 26, expectation.matrix[0][1] = 1,
  expectation.matrix[0][2] = 8;
  expectation.matrix[1][0] = 6, expectation.matrix[1][1] = 8,
  expectation.matrix[1][2] = 10;
  expectation.matrix[2][0] = 4, expectation.matrix[2][1] = 8,
  expectation.matrix[2][2] = 7;
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(sum_3) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_4) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t reality = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &reality), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_1) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expectation);
  A.matrix[0][0] = 23, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 11, A.matrix[2][1] = 3, A.matrix[2][2] = 7;
  B.matrix[0][0] = 3, B.matrix[0][1] = -1, B.matrix[0][2] = 5;
  B.matrix[1][0] = 2, B.matrix[1][1] = 3, B.matrix[1][2] = 4;
  B.matrix[2][0] = -7, B.matrix[2][1] = 5, B.matrix[2][2] = 0;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &reality), OK);
  expectation.matrix[0][0] = 20, expectation.matrix[0][1] = 3,
  expectation.matrix[0][2] = -2;
  expectation.matrix[1][0] = 2, expectation.matrix[1][1] = 2,
  expectation.matrix[1][2] = 2;
  expectation.matrix[2][0] = 18, expectation.matrix[2][1] = -2,
  expectation.matrix[2][2] = 7;
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(sub_2) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(sub_3) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t reality = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &reality), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_4) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expectation);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &reality), OK);
  expectation.matrix[0][0] = 0, expectation.matrix[0][1] = 2,
  expectation.matrix[0][2] = 3;
  expectation.matrix[1][0] = -2, expectation.matrix[1][1] = 4,
  expectation.matrix[1][2] = 5;
  expectation.matrix[2][0] = -3, expectation.matrix[2][1] = -4,
  expectation.matrix[2][2] = 5;
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

Suite *sum_sub_tests(void) {
  Suite *s = suite_create("\033[44m-=SUM_SUB=-\033[0m");
  TCase *tc = tcase_create("sum_sub_tc");

  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);
  tcase_add_test(tc, sum_3);
  tcase_add_test(tc, sum_4);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);

  suite_add_tcase(s, tc);
  return s;
}