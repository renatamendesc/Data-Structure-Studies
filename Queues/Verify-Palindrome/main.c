#include "../../Stacks/Verify-Expression/stackChar.h"
#include "queueChar.h"
#include <stdio.h>
#include <ctype.h>

#define TAM 50

int verifyPalindrome (char * str) {

    Stack * stack = NULL;
    Queue * queue = NULL;

    for (int i = 0; str[i] != '\0'; i++) {

        if (isalpha(str[i])) {
            push_stack(&stack, str[i]);
            insert_queue(&queue, str[i]);
        }

    }

    while (!empty_stack(stack) && !empty_queue(queue)) {

        char letter1, letter2;

        letter1 = pop_stack(&stack);
        letter2 = remove_queue(&queue);

        if (letter1 != letter2) return 0;

    }

    if (!empty_stack(stack) || !empty_queue(queue)) return 0;
    
    return 1;
}

int main (void) {

    char str[TAM];

    printf("Type something: ");
    fgets(str, TAM, stdin);

    int flag = verifyPalindrome(str);

    if (flag) printf("\nPalindrome\n");
    else printf("\nNot palindrome\n");

    return 0;
}
