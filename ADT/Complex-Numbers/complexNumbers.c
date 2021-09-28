#include "complexNumbers.h"
#include <stdio.h>
#include <stdlib.h>

struct complexNumbers {

    float real;
    float imaginary;

};

ComplexNumbers * create_number (float real, float imaginary) {

    ComplexNumbers * num = (ComplexNumbers *) (malloc (sizeof(ComplexNumbers)));

    if (num) {

        num->real = real;
        num->imaginary = imaginary;

    }

    return num;

}

int addition (ComplexNumbers * num1, ComplexNumbers * num2, float * real, float * imaginary) {

    if (num1 && num2) {

        * real = num1->real + num2->real;
        * imaginary = num1->imaginary + num2->imaginary;

        return 1;
    }

    return 0;
}

int subtraction (ComplexNumbers * num1, ComplexNumbers * num2, float * real, float * imaginary) {

    if (num1 && num2) {

        * real = num1->real - num2->real;
        * imaginary = num1->imaginary - num2->imaginary;

        return 1;
    }

    return 0;
}

int multiplication (ComplexNumbers * num1, ComplexNumbers * num2, float * real, float * imaginary) {

    if (num1 && num2) {

        * real = (num1->real * num2->real) - (num1->imaginary * num2->imaginary);
        * imaginary = (num1->imaginary * num2->real) + (num1->real * num2->imaginary);

       return 1; 
    }

    return 0;
}

int division (ComplexNumbers * num1, ComplexNumbers * num2, float * real, float * imaginary) {

    if (num1 && num2)  {    
        
        * real = ((num1->real * num2->real) + (num1->imaginary * num2->imaginary)) / ((num2->real * num2->real) + (num2->imaginary * num2->imaginary));
        * imaginary = ((num1->imaginary * num2->real) - (num1->real * num2->imaginary)) / ((num2->real * num2->real) + (num2->imaginary * num2->imaginary));
    
        return 1;
    }

    return 0;
}

int get_number (ComplexNumbers * num, float * real, float * imaginary) {

    if (num){ 
        * real = num->real;
        * imaginary = num->imaginary;
         
        return 1;
    }

    return 0;
}

int set_number (ComplexNumbers * num, float real, float imaginary) {

    if (num) {
        num->real = real;
        num->imaginary = imaginary;

        return 1;
    }

    return 0;
}

void free_number (ComplexNumbers * num) {

    free (num);

}