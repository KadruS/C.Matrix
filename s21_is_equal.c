#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result =
      (isEqualSize(A, B) && !isNull(A) && !isNull(B)) ? SUCCESS : FAILURE;

  if (result == SUCCESS) {
    for (int i = 0; i < A->rows && result == SUCCESS; i++) {
      for (int j = 0; j < A->columns && result == SUCCESS; j++) {
        result = (fabs(A->matrix[i][j] - B->matrix[i][j]) < 1e-7) ? SUCCESS
                                                                  : FAILURE;
      }
    }
  }

  return result;
}