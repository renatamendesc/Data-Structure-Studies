#include "circularList.h"
#include <stdio.h>

int main (void) {

    Node * list = NULL;

    list_insert_first(&list, 8);
    list_print(list, "My list:");

    list_insert_first(&list, 3);
    list_print(list, "My list:");

    list_remove_index(&list, 1);
    list_print(list, "My list:");

    list_insert_first(&list, 20);
    list_print(list, "My list:");

    list_insert_first(&list, 1);
    list_print(list, "My list:");

    list_insert_last(&list, 13);
    list_print(list, "My list:");

    list_insert_index(&list, 1, 10);
    list_print(list, "My list:");

    list_remove(&list, 3);
    list_print(list, "My list:");

    list_clear(&list);

    return 0;
}