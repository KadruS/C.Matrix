#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (isNull(A) || isNull(result)) {
    return INCORRECT_MATRIX;
  }

  int error = s21_create_matrix(A->columns, A->rows, result);

  if (error == OK) {
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  int error = OK;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else if (A->rows > 2) {
    int sign = 1;
    *result = 0;
    for (int i = 0; i < A->columns && error == OK; i++) {
      matrix_t *minor = createMinor(0, i, *A);

      if (minor == NULL) {
        error = INCORRECT_MATRIX;
      } else {
        double minor_determinant = 0;
        error = s21_determinant(minor, &minor_determinant);
        if (!error) {
          *result += sign * A->matrix[0][i] * minor_determinant;
          sign = -sign;
        }
        s21_remove_matrix(minor);
        free(minor);
        minor = NULL;
      }
    }
  }

  return error;
}