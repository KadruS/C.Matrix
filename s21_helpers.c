#include "s21_matrix.h"

int isNull(matrix_t *A) { return A == NULL; }

int isNegativeSize(int rows, int columns) { return rows <= 0 || columns <= 0; }

int isEqualSize(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

int isInfOrNan(matrix_t *A) {
  int result = OK;
  for (int i = 0; i < A->rows && result == OK; i++) {
    for (int j = 0; j < A->columns && result == OK; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        result = CALCULATION_ERROR;
      }
    }
  }
  return result;
}

void printMatrix(matrix_t A) {
  printf("%d %d\n", A.rows, A.columns);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("%f ", A.matrix[i][j]);
    }
    printf("\n");
  }
}

void setRandomMatrix(matrix_t *A) {
  int random_value = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      random_value = rand();
      random_value =
          (random_value > 1000) ? (random_value % 1000) : random_value;
      A->matrix[i][j] = random_value;
    }
  }
}

void setMatrixStatic(matrix_t *A, double c) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = (i + j) * c;
    }
  }
}

void setMatrix(matrix_t *A, double n, double m) {
  if (A != NULL && A->matrix != NULL) {
    double value = n;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += m;
      }
    }
  }
}

matrix_t *createMinor(int row, int column, matrix_t A) {
  if (&A == NULL || &A.matrix == NULL) {
    return NULL;
  }
  matrix_t *minor = calloc(1, sizeof(matrix_t));
  if (minor != NULL) {
    if (s21_create_matrix(A.rows - 1, A.columns - 1, minor) == OK) {
      for (int i = 0, minor_row = 0; i < A.rows; i++) {
        if (i != row) {
          for (int j = 0, minor_column = 0; j < A.columns; j++) {
            if (j != column) {
              minor->matrix[minor_row][minor_column] = A.matrix[i][j];
              minor_column++;
            }
          }
          minor_row++;
        }
      }
    }
  }

  return minor;
}
