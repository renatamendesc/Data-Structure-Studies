#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue * create_element_queue (char info);

int empty_queue (Queue * head);
int size_queue (Queue * head);
int insert_queue (Queue ** head, char info);
int remove_queue (Queue ** head);
void free_queue (Queue ** head);

#endif