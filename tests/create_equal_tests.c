#include "tests.h"

START_TEST(create_1) {
  matrix_t A = {0};
  int rows = 3;
  int columns = 3;
  int result = s21_create_matrix(rows, columns, &A);

  // printMatrix(A);

  ck_assert_int_eq(A.rows, A.columns);
  ck_assert_int_eq(result, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_2) {
  matrix_t A = {0};
  int rows = -3;
  int columns = 3;
  int result = s21_create_matrix(rows, columns, &A);

  // printMatrix(A);

  ck_assert_int_eq(A.rows, A.columns);
  ck_assert_int_eq(result, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_3) {
  matrix_t A;
  int rows = 7;
  int columns = 7;
  s21_create_matrix(rows, columns, &A);

  // printMatrix(A);

  ck_assert_int_eq(A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(equal_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  setRandomMatrix(&A);
  setRandomMatrix(&B);

  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(equal_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(equal_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  setMatrixStatic(&A, -1);
  setMatrixStatic(&B, 22.1);
  // printMatrix(A);
  // printMatrix(B);
  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(equal_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(5, 3, &A);
  s21_create_matrix(3, 5, &B);

  setMatrixStatic(&A, -1);
  setMatrixStatic(&B, 22.1);
  // printMatrix(A);
  // printMatrix(B);
  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *create_equal_tests(void) {
  Suite *s = suite_create("\033[44m-=CREATE_EQUAL=-\033[0m");
  TCase *tc = tcase_create("create_equal_tc");

  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  tcase_add_test(tc, equal_1);
  tcase_add_test(tc, equal_2);
  tcase_add_test(tc, equal_3);
  tcase_add_test(tc, equal_4);

  suite_add_tcase(s, tc);
  return s;
}