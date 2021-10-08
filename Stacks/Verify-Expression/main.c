#include "stackChar.h"
#include <stdio.h>

#define TAM 20

int isPair (char character1, char character2) {

    if (character1 == '(' && character2 == ')') return 1;
    else if (character1 == '{' && character2 == '}') return 1;
    else if (character1 == '[' && character2 == ']') return 1;
    else return 0;

}

int verifyExpression (char *str) {

    Stack * stack = NULL;

    int index = 0;

    while (str[index] != '\0') {

        if (str[index] == '[' || str[index] == '(' || str[index] == '{') {

            push_stack(&stack, str[index]);

        } else if (str[index] == ']' || str[index] == ')' || str[index] == '}') {

            if (empty_stack(stack)) return 0;
            if (!isPair(pop_stack(&stack), str[index])) return 0;

        }

        index++;
    }

    if (empty_stack(stack)) return 1;
    else return 0;

}

int main (void) {

    char expression[TAM];

    printf("Expression: ");
    fgets(expression, TAM, stdin);

    int flag = verifyExpression(expression);

    if (flag) printf("Expression is balanced\n");
    else printf("Expression is not balanced\n");

    return 0;
}