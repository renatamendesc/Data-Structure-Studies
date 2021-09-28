#include "array.h"
#include <stdio.h>

int main (void) {

    Array * vector;

    vector = create_array(10);

    for (int i = 0; i < 20; i++) {
        insert_element(vector, 10+i);
    }

    float value;

    for (int i = 0; i < get_size(vector); i++) {
        get_element (vector, i, &value); 
        printf ("vector[%d]: %.1f\n", i+1, value);
    }

    free_array(vector);

    return 0;
}