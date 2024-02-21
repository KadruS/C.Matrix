#include "tests.h"

START_TEST(create_minor_1) {
  matrix_t A = {0};
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  setMatrixStatic(&A, 3.4);

  matrix_t *minor = createMinor(0, 0, A);
  // printMatrix(A);
  // printMatrix(*minor);
  matrix_t expectation = {0};
  s21_create_matrix(A.rows - 1, A.columns - 1, &expectation);
  expectation.matrix[0][0] = 6.8, expectation.matrix[0][1] = 10.2;
  expectation.matrix[1][0] = 10.2, expectation.matrix[1][1] = 13.6;

  int result = s21_eq_matrix(minor, &expectation);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(minor);
  s21_remove_matrix(&expectation);
  free(minor);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A = {};
  matrix_t reality = {};
  matrix_t expectation = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &expectation);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;
  ck_assert_int_eq(s21_transpose(&A, &reality), OK);
  expectation.matrix[0][0] = 1, expectation.matrix[0][1] = 2,
  expectation.matrix[0][2] = 3;
  expectation.matrix[1][0] = 4, expectation.matrix[1][1] = 5,
  expectation.matrix[1][2] = 6;
  ck_assert_int_eq(s21_eq_matrix(&reality, &expectation), SUCCESS);
  ck_assert_int_eq(reality.rows, 2);
  ck_assert_int_eq(reality.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expectation);
  s21_remove_matrix(&reality);
}
END_TEST

START_TEST(determinant_1) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 21);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(2, 2, &A);
  setMatrix(&A, 3, 3);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, -18);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 3, &A);
  setMatrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant_tests(void) {
  Suite *s = suite_create("\033[44m-=TRANSPOSE_DETERMINANT=-\033[0m");
  TCase *tc = tcase_create("determinant_tc");

  tcase_add_test(tc, create_minor_1);
  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);

  suite_add_tcase(s, tc);
  return s;
}