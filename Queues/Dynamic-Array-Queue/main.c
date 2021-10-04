#include "queue.h"
#include <stdio.h>

int main (void) {

    Queue * queue = create_queue();

    if (empty_queue(queue)) printf("A fila esta vazia!\n\n");
    else printf("A fila nao esta vazia!\n\n");

    insert_queue(queue, 10);
    insert_queue(queue, 7);
    insert_queue(queue, 4);
    insert_queue(queue, 55);
    insert_queue(queue, 6);
    insert_queue(queue, 9);
    insert_queue(queue, 99);
    insert_queue(queue, 12);
    insert_queue(queue, 22);

    printf("Value: %.1f\n", remove_queue(queue));
    printf("Value: %.1f\n", remove_queue(queue));
    printf("Value: %.1f\n", remove_queue(queue));
    printf("Value: %.1f\n", remove_queue(queue));

    if (empty_queue(queue)) printf("\nA fila esta vazia!\n");
    else printf("\nA fila nao esta vazia!\n");

    free_queue(queue);

    return 0;
}