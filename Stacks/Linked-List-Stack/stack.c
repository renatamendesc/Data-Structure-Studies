#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack {

    int info;
    struct stack * next;

};

Stack * create_element (int info) {

    Stack * stack = (Stack *) malloc(sizeof(Stack));

    if (stack) {
        stack->info = info;
        stack->next = NULL;
    }

    return stack;
}

int push_stack (Stack ** head, int info) {

    Stack * new = create_element(info);

    if (new) {

        if (empty_stack(* head)) {

            new->next = * head;
            * head = new;

            return 1;
        }

        Stack * element = * head;

        while (element->next != NULL) {
            element = element->next;
        }

        element->next = new;
        
        return 1;
    }

    return 0;
}

int pop_stack (Stack ** head) {

    Stack * previous = NULL;
    Stack * element = * head;

    while (element->next != NULL) {
        previous = element; 
        element = element->next; 
    }

    int value = element->info;

    previous->next = element->next; 
    free (element);

    return value;
}

int empty_stack (Stack * head) {

    if (head == NULL) return 1;
    else return 0;
}

int size_stack (Stack * head) {

    int counter = 0;

    while (head != NULL) {

        head = head->next;
        counter++;
    }

    return counter;
}

void free_stack (Stack ** head) {

    Stack * next =  NULL;
    Stack * element = * head;

    while (element->next != NULL) {

        next = element->next;
        free (element); 

        element = next;
    }

    * head = NULL; 
}

