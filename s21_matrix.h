#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <stdio.h>  // del
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum status_code { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int isNull(matrix_t *A);
int isNegativeSize(int rows, int columns);
int isEqualSize(matrix_t *A, matrix_t *B);
int isInfOrNan(matrix_t *A);
void printMatrix(matrix_t A);
void setRandomMatrix(matrix_t *A);
void setMatrixStatic(matrix_t *A, double c);
void setMatrix(matrix_t *A, double n, double m);
matrix_t *createMinor(int row, int column, matrix_t A);

#endif  // MATRIX.H