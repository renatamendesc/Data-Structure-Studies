#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack * create_element (int info);
int push_stack (Stack ** head, int info);
int pop_stack (Stack ** head);
int empty_stack (Stack * head);
int size_stack (Stack * head);
void free_stack (Stack ** head);

#endif