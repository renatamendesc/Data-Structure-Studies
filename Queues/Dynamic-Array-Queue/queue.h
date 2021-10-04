#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue * create_queue (void);
void insert_queue (Queue * q, float value);
float remove_queue (Queue * q);
int empty_queue (Queue * q);
void free_queue (Queue * q);

#endif