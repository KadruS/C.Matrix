#include "tests.h"

START_TEST(mul_num_1) {
  matrix_t A = {};
  matrix_t reality = {};
  double num = INFINITY;
  s21_create_matrix(4, 4, &A);
  setMatrix(&A, 1, 1);
  ck_assert_int_eq(s21_mult_number(&A, num, &reality), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mul_num_2) {
  matrix_t A = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  double number = 2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 3, A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &expectation);
  expectation.matrix[0][0] = 2, expectation.matrix[0][1] = 4,
  expectation.matrix[0][2] = 6;
  expectation.matrix[1][0] = 0, expectation.matrix[1][1] = 8,
  expectation.matrix[1][2] = 4;
  expectation.matrix[2][0] = 4, expectation.matrix[2][1] = 6,
  expectation.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, number, &reality), OK);
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(mul_num_3) {
  matrix_t A = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  double number = 4;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 13, A.matrix[0][1] = -4, A.matrix[0][2] = 31;
  A.matrix[1][0] = 0, A.matrix[1][1] = -5, A.matrix[1][2] = 2;
  A.matrix[2][0] = 7, A.matrix[2][1] = 9, A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &expectation);
  expectation.matrix[0][0] = 52, expectation.matrix[0][1] = -16,
  expectation.matrix[0][2] = 124;
  expectation.matrix[1][0] = 0, expectation.matrix[1][1] = -20,
  expectation.matrix[1][2] = 8;
  expectation.matrix[2][0] = 28, expectation.matrix[2][1] = 36,
  expectation.matrix[2][2] = 16;
  ck_assert_int_eq(s21_mult_number(&A, number, &reality), OK);
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(mul_mat_1) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t reality = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &reality), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mul_mat_2) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;
  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = -1, B.matrix[0][2] = 1;
  B.matrix[1][0] = 2, B.matrix[1][1] = 3, B.matrix[1][2] = 4;
  s21_create_matrix(3, 3, &expectation);
  expectation.matrix[0][0] = 9, expectation.matrix[0][1] = 11,
  expectation.matrix[0][2] = 17;
  expectation.matrix[1][0] = 12, expectation.matrix[1][1] = 13,
  expectation.matrix[1][2] = 22;
  expectation.matrix[2][0] = 15, expectation.matrix[2][1] = 15,
  expectation.matrix[2][2] = 27;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &reality), OK);
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(mul_mat_3) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 33, A.matrix[0][1] = 12, A.matrix[0][2] = -5;
  A.matrix[1][0] = 3, A.matrix[1][1] = 0, A.matrix[1][2] = 6;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 9, B.matrix[0][1] = 8, B.matrix[0][2] = 7;
  B.matrix[1][0] = 0, B.matrix[1][1] = 11, B.matrix[1][2] = -19;
  B.matrix[2][0] = 3, B.matrix[2][1] = 7, B.matrix[2][2] = 5;
  s21_create_matrix(3, 3, &expectation);
  expectation.matrix[0][0] = 282, expectation.matrix[0][1] = 361,
  expectation.matrix[0][2] = -22;
  expectation.matrix[1][0] = 45, expectation.matrix[1][1] = 66,
  expectation.matrix[1][2] = 51;
  expectation.matrix[2][0] = 90, expectation.matrix[2][1] = 207,
  expectation.matrix[2][2] = -58;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &reality), OK);
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

Suite *mul_tests(void) {
  Suite *s = suite_create("\033[44m-=MUL=-\033[0m");
  TCase *tc = tcase_create("mul_tc");

  tcase_add_test(tc, mul_num_1);
  tcase_add_test(tc, mul_num_2);
  tcase_add_test(tc, mul_num_3);
  tcase_add_test(tc, mul_mat_1);
  tcase_add_test(tc, mul_mat_2);
  tcase_add_test(tc, mul_mat_3);

  suite_add_tcase(s, tc);
  return s;
}