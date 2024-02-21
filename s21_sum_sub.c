#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (isNull(A) || isNull(B)) {
    return INCORRECT_MATRIX;
  } else if (!isEqualSize(A, B) || isInfOrNan(A) || isInfOrNan(B)) {
    return CALCULATION_ERROR;
  }

  int error = s21_create_matrix(A->rows, A->columns, result);

  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (isNull(A) || isNull(B) || isNull(result)) {
    return INCORRECT_MATRIX;
  } else if (!isEqualSize(A, B) || isInfOrNan(A) || isInfOrNan(B)) {
    return CALCULATION_ERROR;
  }

  int error = s21_create_matrix(A->rows, A->columns, result);

  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return error;
}