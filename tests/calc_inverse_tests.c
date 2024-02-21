#include "tests.h"

START_TEST(calc_1) {
  matrix_t A = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expectation);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &reality), OK);
  expectation.matrix[0][0] = 0, expectation.matrix[0][1] = 10,
  expectation.matrix[0][2] = -20;
  expectation.matrix[1][0] = 4, expectation.matrix[1][1] = -14,
  expectation.matrix[1][2] = 8;
  expectation.matrix[2][0] = -8, expectation.matrix[2][1] = -2,
  expectation.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(calc_2) {
  matrix_t A = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expectation);
  A.matrix[0][0] = 33, A.matrix[0][1] = 7, A.matrix[0][2] = 23;
  A.matrix[1][0] = 0, A.matrix[1][1] = 12, A.matrix[1][2] = 2;
  A.matrix[2][0] = 8, A.matrix[2][1] = 12, A.matrix[2][2] = 19;
  ck_assert_int_eq(s21_calc_complements(&A, &reality), OK);
  expectation.matrix[0][0] = 204, expectation.matrix[0][1] = 16,
  expectation.matrix[0][2] = -96;
  expectation.matrix[1][0] = 143, expectation.matrix[1][1] = 443,
  expectation.matrix[1][2] = -340;
  expectation.matrix[2][0] = -262, expectation.matrix[2][1] = -66,
  expectation.matrix[2][2] = 396;
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(calc_3) {
  matrix_t A = {};
  matrix_t reality = {};
  s21_create_matrix(1, 3, &A);
  setMatrix(&A, 1, 3);
  ck_assert_int_eq(s21_calc_complements(&A, &reality), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_1) {
  matrix_t A = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expectation);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;
  expectation.matrix[0][0] = 1, expectation.matrix[0][1] = -1,
  expectation.matrix[0][2] = 1;
  expectation.matrix[1][0] = -38, expectation.matrix[1][1] = 41,
  expectation.matrix[1][2] = -34;
  expectation.matrix[2][0] = 27, expectation.matrix[2][1] = -29,
  expectation.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(&A, &reality), OK);
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t A = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expectation);
  A.matrix[0][0] = 23, A.matrix[0][1] = 12, A.matrix[0][2] = 7;
  A.matrix[1][0] = 5, A.matrix[1][1] = 9, A.matrix[1][2] = 1;
  A.matrix[2][0] = 4, A.matrix[2][1] = 11, A.matrix[2][2] = 0;
  expectation.matrix[0][0] = (double)11 / 72,
  expectation.matrix[0][1] = (double)-77 / 72,
  expectation.matrix[0][2] = (double)17 / 24;
  expectation.matrix[1][0] = (double)-1 / 18,
  expectation.matrix[1][1] = (double)7 / 18,
  expectation.matrix[1][2] = (double)-1 / 6;
  expectation.matrix[2][0] = (double)-19 / 72,
  expectation.matrix[2][1] = (double)205 / 72,
  expectation.matrix[2][2] = (double)-49 / 24;
  ck_assert_int_eq(s21_inverse_matrix(&A, &reality), OK);
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t A = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &expectation);
  A.matrix[0][0] = 44;
  expectation.matrix[0][0] = 1.0 / 44.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &reality), OK);
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reality);
  s21_remove_matrix(&expectation);
}
END_TEST

START_TEST(inverse_4) {
  matrix_t A = {};
  matrix_t reality = {};
  s21_create_matrix(3, 3, &A);
  setMatrix(&A, 1, 1);
  ck_assert_int_eq(s21_inverse_matrix(&A, &reality), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

Suite *calc_inverse_tests(void) {
  Suite *s = suite_create("\033[44m-=CALC_INVERSE=-\033[0m");
  TCase *tc = tcase_create("calc_inverse_tc");

  tcase_add_test(tc, calc_1);
  tcase_add_test(tc, calc_2);
  tcase_add_test(tc, calc_3);
  tcase_add_test(tc, inverse_1);
  tcase_add_test(tc, inverse_2);
  tcase_add_test(tc, inverse_3);
  tcase_add_test(tc, inverse_4);

  suite_add_tcase(s, tc);
  return s;
}