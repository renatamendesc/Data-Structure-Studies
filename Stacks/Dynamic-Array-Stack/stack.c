#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack {

    int size;
    int dimension;
    float * elements;

};

Stack * create_stack (void) {

    Stack * s = (Stack *) malloc(sizeof(Stack));

    s->dimension = 2;
    s->size = 0;
    s->elements = (float *) malloc(s->dimension * sizeof(float));

    return s;
}

void push_stack (Stack * s, float value) {

    if (s->size == s->dimension) {
        s->dimension *= 2;
        s->elements = (float *) realloc(s->elements, s->dimension * sizeof(float));
    }

    s->elements[s->size++] = value;
}

float pop_stack (Stack * s) {

    return s->elements[--s->size];
}

int empty_stack (Stack * s) {

    return s->size == 0;
}

void free_stack (Stack * s) {

    free(s->elements);
    free(s);
}
