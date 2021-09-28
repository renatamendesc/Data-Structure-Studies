#include "list.h"
#include <stdio.h>

int main (void) {

    Node * list = NULL;

    list_insert_last (&list, 3);
    list_insert_last (&list, 8);

    list_insert_sorted (&list, 1);
    list_insert_first (&list, 0);
    list_insert_index (&list, 3, 10);
    
    list_print (list, "My list:");

    list_remove_index (&list, 1);

    printf ("Size: %d\n", list_size (list));
    list_clear (&list); 

    return 0;
}