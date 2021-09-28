#include "doublyList.h"
#include <stdio.h>

int main (void) {

    Node * list = NULL;

    list_insert_first(&list, 20);
    list_insert_first(&list, 12);
    list_insert_last(&list, 23);
    list_print(list, "My list:");

    list_insert_index(&list, 0, 14);
    list_print(list, "My list:");

    list_remove(&list, 12);
    list_print(list, "My list:");

    list_remove_index(&list, 2);
    list_print(list, "My list:");

    list_clear(&list);

    return 0;
}