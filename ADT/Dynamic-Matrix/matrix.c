#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

struct matrix {

    int rows;
    int columns;
    int ** values;

};

Matrix * create_matrix (int rows, int columns) { 

    Matrix * mat =  (Matrix *) malloc (sizeof (Matrix));

    if (mat) {

        mat->rows = rows;
        mat->columns = columns;

        mat->values = (int **) (malloc (rows * sizeof(int)));

        for (int i = 0; i < rows; i++) mat->values[i] = (int *) (malloc (columns * sizeof(int)));  

    }    

    return mat;
}

void free_matrix (Matrix * mat) {

    int rows = getRows(mat);

    for (int i = 0; i < rows; i++) free(mat->values[i]);

    free(mat->values);
    free(mat);

}

int get_matrix (Matrix * mat, int i, int j, int * value) {

    if (mat)  {

        * value = mat->values[i][j];

        return 1;
    }

    return 0;
}

int set_matrix (Matrix * mat, int i, int j, int value) {

    if (mat) {

        mat->values[i][j] = value;

        return 1;
    }

    return 0;
}

int get_rows (Matrix * mat) {

    if (mat) return mat->rows;

}

int get_columns (Matrix * mat) {

    if (mat) return mat->columns;

}