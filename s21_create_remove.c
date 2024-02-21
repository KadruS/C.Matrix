#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (isNegativeSize(rows, columns) || isNull(result)) {
    return INCORRECT_MATRIX;
  }

  int error = OK;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  error = (result->matrix == NULL) ? CALCULATION_ERROR : OK;

  if (error == OK) {
    for (int i = 0; i < rows && error == OK; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        error = CALCULATION_ERROR;
        for (int j = 0; j < i; j++) {
          free(result->matrix[j]);
          result->matrix[j] = NULL;
        }
      }
    }
  }

  result->rows = (error == OK) ? rows : 0;
  result->columns = (error == OK) ? columns : 0;
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (isNull(A) || A->rows < 0 || A->columns < 0) {
    return;
  }

  for (int i = 0; i < A->rows; i++) {
    if (A->matrix[i] != NULL) {
      free(A->matrix[i]);
      A->matrix[i] = NULL;
    }
  }
  free(A->matrix);
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}