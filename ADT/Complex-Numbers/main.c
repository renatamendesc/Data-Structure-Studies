#include "complexNumbers.h"
#include <stdio.h>

int main (void) {

    ComplexNumbers * num1, * num2;

    num1 = create_number(2, 3);
    num2 = create_number(4, 7);

    float real, imaginary;

    get_number(num1, &real, &imaginary);
    printf("Operations: (%.1f + %.1fi) and ", real, imaginary);

    get_number(num2, &real, &imaginary);
    printf("(%.1f + %.1fi)\n\n", real, imaginary);

    addition(num1, num2, &real, &imaginary);
    printf("Addition: %.1f + %.1fi\n", real, imaginary);

    subtraction(num1, num2, &real, &imaginary);
    printf("Subtraction: %.1f + %.1fi\n", real, imaginary);

    multiplication(num1, num2, &real, &imaginary);
    printf("Multiplication: %.1f + %.1fi\n", real, imaginary);

    division(num1, num2, &real, &imaginary);
    printf("Division: %.1f + %.1fi\n", real, imaginary);

    free_number(num1);
    free_number(num2);

    return 0;
}