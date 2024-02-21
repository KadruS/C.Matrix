#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->rows == 1 || A->columns == 1) {
    return CALCULATION_ERROR;
  }

  int error = s21_create_matrix(A->rows, A->columns, result);

  if (error == 0) {
    for (int i = 0; i < A->rows && error == OK; i++) {
      for (int j = 0; j < A->columns && error == OK; j++) {
        int sign = pow(-1, i + j);
        matrix_t *minor = createMinor(i, j, *A);
        if (minor == NULL) {
          error = INCORRECT_MATRIX;
        } else {
          double determinanterminant = 0;
          error = s21_determinant(minor, &determinanterminant);
          if (!isfinite(determinanterminant)) {
            error = CALCULATION_ERROR;
          }
          if (!error) {
            result->matrix[i][j] = sign * determinanterminant;
          }
          s21_remove_matrix(minor);
          free(minor);
          minor = NULL;
        }
      }
    }
  }

  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }

  double determinant = 0;
  int error = s21_determinant(A, &determinant);
  if (!error && determinant != 0 && (A->rows == A->columns)) {
    if (A->rows == 1) {
      error = s21_create_matrix(A->rows, A->columns, result);
      if (!error) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      }
    } else {
      matrix_t A_complements = {0};
      matrix_t A_trans = {0};
      error = s21_calc_complements(A, &A_complements);
      if (!error) {
        error = s21_transpose(&A_complements, &A_trans);
      }
      if (!error) {
        error = s21_mult_number(&A_trans, 1 / determinant, result);
      }
      s21_remove_matrix(&A_complements);
      s21_remove_matrix(&A_trans);
    }
  } else {
    error = CALCULATION_ERROR;
  }

  return error;
}
