#ifndef ARRAY_H
#define ARRAY_H

typedef struct array Array;

Array * create_array (int dim);

int insert_element (Array * vet, float value);
int get_element (Array * vet, int index, float * value);
int get_size (Array * vet);

void free_array (Array * vet);

#endif