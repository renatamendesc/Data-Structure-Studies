#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue {

    int size;
    int dimension;
    int first;
    float * elements;

};

Queue * create_queue (void) {

    Queue * q = (Queue *) malloc(sizeof(Queue));

    q->size = 0;
    q->dimension = 4;
    q->elements = (float *) malloc(q->dimension * sizeof(float));
    q->first = 0;

    return q;
}

void insert_queue (Queue * q, float value) {

    // Verifies if its on maximum size
    if (q->size == q->dimension) {

        q->dimension *= 2;
        q->elements = (float *) realloc(q->elements, q->dimension * sizeof(float));

        if (q->first != 0) memmove(&q->elements[q->dimension-q->first], &q->elements[q->first], (q->size-q->first) * sizeof(float));
        
    }

    // Inserts element
    int end = (q->first+q->size) % q->dimension;
    q->elements[end] = value;
    q->size++;
}

float remove_queue (Queue * q) {

    float value = q->elements[q->first];
    q->first = (q->first + 1) % q->dimension;
    q->size--;

    return value;
}

int empty_queue (Queue * q) {

    return q->size == 0;
}

void free_queue (Queue * q) {

    free(q->elements);
    free(q);
}
