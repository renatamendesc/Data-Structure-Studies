#include "stack.h"
#include <stdio.h>

int main (void) {

    Stack * stack = create_stack();

    if (empty_stack(stack)) printf("A pilha esta vazia!\n\n");
    else printf("A pilha nao esta vazia!\n\n");

    push_stack(stack, 10);
    push_stack(stack, 7);
    push_stack(stack, 4);
    push_stack(stack, 55);
    push_stack(stack, 6);
    push_stack(stack, 9);
    push_stack(stack, 99);
    push_stack(stack, 12);
    push_stack(stack, 22);

    printf("Value: %.1f\n", pop_stack(stack));
    printf("Value: %.1f\n", pop_stack(stack));
    printf("Value: %.1f\n", pop_stack(stack));
    printf("Value: %.1f\n", pop_stack(stack));

    if (empty_stack(stack)) printf("\nA pilha esta vazia!\n");
    else printf("\nA pilha nao esta vazia!\n");

    free_stack(stack);

    return 0;
}