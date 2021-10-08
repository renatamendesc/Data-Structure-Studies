#include "../Linked-List-Stack/stack.h"
#include <stdio.h>

int main (void) {

    Stack * stack = NULL;
    int decimal;

    printf("Type a decimal number: ");
    scanf("%d", &decimal);

    while (1) {

        push_stack(&stack, decimal % 2);
        decimal /= 2;

        if (decimal == 0) break;
    }

    printf("Binary: ");
    while (!empty_stack(stack)) printf("%d", pop_stack(&stack));
    printf("\n");

    free_stack(&stack);

    return 0;
}