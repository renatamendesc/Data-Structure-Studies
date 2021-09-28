#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix Matrix;

Matrix * create_matrix (int rows, int columns);

void free_matrix (Matrix * mat);
int set_matrix (Matrix * mat, int i, int j, int value);
int get_matrix (Matrix * mat, int i, int j, int * value);
int get_rows (Matrix * mat);
int get_columns (Matrix * mat);

#endif