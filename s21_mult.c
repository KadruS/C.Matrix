#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (isNull(A) || isNull(result)) {
    return INCORRECT_MATRIX;
  }
  if (isnan(number) || isinf(number) || isInfOrNan(A)) {
    return CALCULATION_ERROR;
  }

  int error = s21_create_matrix(A->rows, A->columns, result);

  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {  // доделать
  if (isNull(A) || isNull(result) || isNull(B)) {
    return INCORRECT_MATRIX;
  }
  if (isInfOrNan(B) || isInfOrNan(A) || A->columns != B->rows) {
    return CALCULATION_ERROR;
  }

  int error = s21_create_matrix(A->rows, B->columns, result);

  if (error == OK) {
    int k = 1;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return error;
}
