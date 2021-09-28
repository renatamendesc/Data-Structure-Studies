#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complexNumbers ComplexNumbers;

ComplexNumbers * create_number (float real, float imaginary);

int get_number (ComplexNumbers * num, float * real, float * imaginary);
int set_number (ComplexNumbers * num, float real, float imaginary);

int addition (ComplexNumbers * num1, ComplexNumbers * num2, float * real, float * imaginary);
int subtraction (ComplexNumbers * num1, ComplexNumbers * num2, float * real, float * imaginary);
int multiplication (ComplexNumbers * num1, ComplexNumbers * num2, float * real, float * imaginary);
int division (ComplexNumbers * num1, ComplexNumbers * num2, float * real, float * imaginary);

void free_number (ComplexNumbers * num);

#endif