#include "../Linked-List-Stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 30

float calculate (char * expression) {

    Stack * stack = NULL;

    int index = 0;
    char number[TAM];

    while (expression[index]) {

        if (isdigit(expression[index])) {

            char aux[2] = "\0";
            aux[0] = expression[index];

            strcat(number, aux);

        } else if (expression[index] == ' ') {

            if (strlen(number) > 0) {
                push_stack(&stack, atof(number));
                strcpy(number, "");
            }

        } else {

            float num1, num2;
            
            if (expression[index] == '+') {

                num1 = pop_stack(&stack);
                num2 = pop_stack(&stack);

                push_stack(&stack, num2 + num1);

            } else if (expression[index] == '-') {

                num1 = pop_stack(&stack);
                num2 = pop_stack(&stack);

                push_stack(&stack, num2 - num1);

            } else if (expression[index] == '*') {

                num1 = pop_stack(&stack);
                num2 = pop_stack(&stack);

                push_stack(&stack, num2 * num1);
                
            } else if (expression[index] == '/') {

                num1 = pop_stack(&stack);
                num2 = pop_stack(&stack);

                push_stack(&stack, num2 / num1);
                
            }
        }

        index++;
    }

    return pop_stack(&stack);

}

int main (void) {

    char expression[TAM];

    printf("Type an expression: ");
    fgets(expression, TAM, stdin);

    printf("Result: %.1f\n", calculate(expression));

    return 0;
}