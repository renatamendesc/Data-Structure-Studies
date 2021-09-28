#include "array.h"
#include <stdio.h>
#include <stdlib.h>

struct array {

    int size;
    int dimension;
    float * elements; 

};

Array * create_array (int dimension) {

    Array * vector = (Array *) (malloc (sizeof (Array)));

    if (vector) {

        vector->size = 0;
        vector->dimension = dimension;

        vector->elements = (float *) (malloc (dimension * sizeof (float)));
    }

    return vector;
}

int insert_element (Array * vector, float value) {

    if (vector) {

        if (vector->size == vector->dimension) {
            vector->dimension++;
            vector->elements = (float *) realloc(vector->elements, vector->dimension * sizeof(float));
        }

        vector->elements[vector->size] = value;
        vector->size++;

        return 1;
    }

    return 0;
}

int get_element (Array * vector, int index, float * value) {

    if (vector) {
        
        * value = vector->elements[index];
        return 1;
    
    }

    return 0;
}

int get_size (Array * vector) {

    if (vector) return vector->size;

}

void free_array (Array * vector) {

    free (vector->elements);
    free (vector);

}
