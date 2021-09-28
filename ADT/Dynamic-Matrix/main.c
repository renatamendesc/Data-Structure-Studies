#include "matrix.h"
#include <stdio.h>

int main (void) {

    Matrix * A = create_matrix(3, 2);

    int contador = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            set_matrix(A, i, j, contador);
            contador++;
        }
    }

    printf("%d rows\n%d columns\n\n", get_rows(A), get_columns(A));

    int value;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 2; j++) {
            get_matrix(A, i, j, &value);
            printf("%d ", value);
        }

        printf("\n");
    }

    free_matrix(A);

    return 0;
}