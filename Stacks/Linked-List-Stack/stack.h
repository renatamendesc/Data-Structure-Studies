#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack * create_element (float info);
int push_stack (Stack ** head, float info);
float pop_stack (Stack ** head);
int empty_stack (Stack * head);
int size_stack (Stack * head);
void free_stack (Stack ** head);

#endif