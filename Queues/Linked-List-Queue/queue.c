#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct queue {

    int info;
    struct queue * next;

};

Queue * create_element (int info){

    Queue * queue = (Queue *) malloc(sizeof(Queue));

    if (queue) {
        queue->info = info;
        queue->next = NULL;
    }

    return queue;
}

int empty_queue (Queue * head) {

    if (head == NULL) return 1;
    else return 0;

}

int size_queue (Queue * head) {

    int counter = 0;

    while (head != NULL) {

        head = head->next;
        counter++;
    }

    return counter;
}

int insert_queue (Queue ** head, int info) {

    Queue * new = create_element(info);

    if (new) {

        if (empty_queue(* head)) {

            new->next = * head;
            * head = new;

            return 1;
        }

        Queue * element = * head;

        while (element->next != NULL) {
            element = element->next;
        }

        element->next = new;
        
        return 1;
    }

    return 0;
}

int remove_queue (Queue ** head) {

    Queue * element = * head;
    int value = element->info;

    * head = element->next;
    free (element);

    return value;
}

void free_queue (Queue ** head) {

    Queue * next =  NULL;
    Queue * element = * head;

    while (element->next != NULL) {

        next = element->next;
        free (element); 

        element = next;
    }

    * head = NULL; 
}
