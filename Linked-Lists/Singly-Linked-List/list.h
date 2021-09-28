#ifndef LIST_H
#define LIST_H

typedef struct node Node;

Node * list_create_node (int info);

int list_is_empty (Node * head);
int list_size (Node * head);
int list_insert_first (Node ** head, int info);
int list_insert_last (Node ** head, int info);
int list_exists (Node * head, int info);

void list_clear (Node ** head);
void list_print (Node * head, char * message);

int list_remove (Node ** head, int info);
int list_insert_sorted (Node ** head, int info);
int list_insert_index (Node ** head, int index, int info);
int list_remove_index (Node ** head, int index);

#endif