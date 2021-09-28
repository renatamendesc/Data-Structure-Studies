#include "circularList.h"
#include <stdio.h>
#include <stdlib.h>

struct node {

    int info;
    struct node * next;

};

Node * list_create_node (int info){ // Creates new element

    Node * node = (Node *) malloc (sizeof (Node));

    if (node) {
        node->info = info;
        node->next = node;
    }

    return node;
}

int list_insert_first (Node ** head, int info){ // Inserts on first index

    Node * new = list_create_node(info);

    if (new) {
        
        if (list_is_empty(* head)) {

            * head = new;
            new->next = new;

            return 1;
        }

        Node * element = * head;

        while (element->next != * head) { 
            element = element->next; 
        }

        new->next = * head;
        * head = new;
        element->next = * head;
         
        return 1;
    }

    return 0;
}

int list_insert_last (Node ** head, int info){

    if (list_is_empty (* head)) return list_insert_first (head, info);

    Node * new = list_create_node (info);

    if (new) {

        Node * element = * head;

        while (element->next != * head) { 
            element = element->next; 
        }

        element->next = new;
        new->next = * head;

        return 1;
    }

    return 0;
}

int list_insert_index (Node ** head, int index, int info){

    if (index >= list_size(*head)) return 0;
    else if (index == 0) return list_insert_first(head, info);

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

int list_is_empty (Node * head){

    if (head == NULL) return 1;
    else return 0;

}

int list_exists (Node * head, int info){

    if (list_is_empty (head)) return 0; 

    while (head != NULL) { 

        if (head->info == info) return 1; 

        head = head->next; 
    }

    return 0;
}

int list_size (Node * head){

    if (list_is_empty(head)) return 0;

    Node * element = head;
    int counter = 1;

    while (element->next != head) {

        element = element->next;
        counter++;
    }

    return counter;
}

void list_print (Node * head, char * message){

    printf ("%s ", message);

    Node * element = head;

    if (!list_is_empty(head)) {

        printf ("%d ", element->info);
        element = element->next;   
    
    }

    while (element != head) {
        printf ("%d ", element->info);
        element = element->next;
    }

    printf ("\n");
}

int list_remove (Node ** head, int info){

    Node * previous = NULL;
    Node * element = * head; 

    int found = 0;

    if (!list_is_empty(* head)) {

        if (element->info == info) { 
            found = 1;
        } else {
            previous = element; 
            element = element->next;

            while (element != * head) {

                if (element->info == info) { 
                    found = 1; 
                    break;
                }

                previous = element; 
                element = element->next; 
            }
        }
    }

    if (found) {

        Node * last = * head;

        while (last->next != * head) { 
            last = last->next; 
        }

        if (previous == NULL) {
            
            * head = element->next;
            last->next = * head;
            free(element);

            return 1;
        }

        previous->next = element->next; 
        free(element);

        return 1;
    }

    return 0;
}

int list_remove_index (Node ** head, int index){

    Node * previous = NULL;
    Node * element = * head;

    int size = list_size(*head);

    if (index >= size) return 0;

    if (size == 1) {
        list_clear(head);
        return 1;
    }

    for (int i = 0; i < index; i++) {
        previous = element;
        element = element->next;
    }

    Node * last = * head;

    while (last->next != * head) { 
        last = last->next; 
    }

    if (previous == NULL) {

        * head = element->next;
        last->next = * head;
        free(element);

        return 1;

    }

    previous->next = element->next; 
    free(element);

    return 1;
}

void list_clear (Node ** head){

    Node * next =  NULL;
    Node * element = * head;

    while (element->next != * head) {

        next = element->next;
        free (element);

        element = next;
    }

    * head = NULL;
}