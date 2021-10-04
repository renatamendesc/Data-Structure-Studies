#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack * create_stack (void);
void push_stack (Stack * s, float value);
float pop_stack (Stack * s);
int empty_stack (Stack * s);
void free_stack (Stack * s);

#endif