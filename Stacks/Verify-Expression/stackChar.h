#ifndef STACK_CHAR_H
#define STACK_CHAR_H

typedef struct stack Stack;

Stack * create_element (char info);
int push_stack (Stack ** head, char info);
int pop_stack (Stack ** head);
int empty_stack (Stack * head);
int size_stack (Stack * head);
void free_stack (Stack ** head);

#endif