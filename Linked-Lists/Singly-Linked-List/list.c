#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node {

    int info;
    struct node * next;

};

Node * list_create_node (int info) {

    Node * node = (Node *) malloc(sizeof(Node));

    if (node) {
        node->info = info;
        node->next = NULL;
    }

    return node;
}

int list_is_empty (Node * head) {

    if (head == NULL) return 1;
    else return 0;

}

int list_size (Node * head) {

    int counter = 0;

    while (head != NULL) {

        head = head->next;
        counter++;
    }

    return counter;
}

int list_insert_first (Node ** head, int info) { 

    Node * new = list_create_node (info); 

    if (new) {

        new->next = * head;
        * head = new; 
        
        return 1;
    }

    return 0;
}

int list_insert_last (Node ** head, int info) {

    if (list_is_empty (* head)) return list_insert_first (head, info);

    Node * new = list_create_node (info);

    if (new) {

        Node * element = * head;

        while (element->next != NULL) {
            element = element->next;
        }

        element->next = new;
        
        return 1;
    }

    return 0;
}

int list_exists (Node * head, int info) {

    if (list_is_empty (head)) return 0; 

    while (head != NULL) { 

        if (head->info == info) return 1;

        head = head->next; 
    }

    return 0;
}

void list_clear (Node ** head) {

    Node * next =  NULL;
    Node * element = * head;

    while (element->next != NULL) {

        next = element->next;
        free (element); 

        element = next;
    }

    * head = NULL; 
}

void list_print (Node * head, char * message)  {

    printf ("%s ", message);

    while (head != NULL) { 

        printf ("%d ", head->info);
        head = head->next;
    }

    printf ("\n");

}

int list_remove (Node ** head, int info) { 

    Node * previous = NULL;
    Node * element = * head; 

    int found = 0;

    while (element != NULL) {

        if (element->info == info) { 

            found = 1; 
            break;
        }

        previous = element; 
        element = element->next; 
    }

    if (found) { 

        if (previous == NULL) { 
            
            * head = element->next;
            free (element);

            return 1;
        }

        previous->next = element->next; 
        free (element);

        return 1;
    }

    return 0;
}

int list_insert_sorted (Node ** head, int info) {

    if (list_is_empty (* head)) return list_insert_first (head, info); 

    Node * new = list_create_node (info);

    if (new) {

        Node * previous = NULL;
        Node * element = * head;

        while (element != NULL && element->info < info) { 
            previous = element;
            element = element->next;
        }

        if (previous == NULL) { 
            new->next = * head;
            * head = new;
            
            return 1;
        }

        new->next = previous->next;
        previous->next = new;

        return 1;
    }

    return 0;
}

int list_insert_index (Node ** head, int index, int info) {

    if (index >= list_size(*head)) return 0;

    Node * new = list_create_node (info);

    if (new) {

        Node * previous = NULL;
        Node * element = * head;

        for (int i = 0; i < index; i++) {

            if (element != NULL) {
                previous = element;
                element = element->next;
            }

        }

        if (previous == NULL) { 
            new->next = * head;
            * head = new;
            
            return 1;
        }

        new->next = previous->next;
        previous->next = new;

        return 1;
    }

    return 0;

}

int list_remove_index (Node ** head, int index) {

    Node * previous = NULL;
    Node * element = * head;

    for (int i = 0; i < index; i++) {

        if (element != NULL) {
            previous = element;
            element = element->next;
        }

    }

    if (previous == NULL) { 
        
        * head = element->next;
        free (element);

        return 1;
    }

    previous->next = element->next; 
    free (element);

    return 1;
}