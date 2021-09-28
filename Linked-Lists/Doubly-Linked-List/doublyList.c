#include "doublyList.h"
#include <stdio.h>
#include <stdlib.h>

struct node {

    int info;
    struct node * next;
    struct node * prev;

};

Node * list_create_node (int info) {

    Node * node = (Node *) malloc (sizeof (Node));

    if (node) {
        node->info = info;
        node->next = NULL;
        node->prev = NULL;
    }

    return node;
}

int list_insert_first (Node ** head, int info) {

    Node * new = list_create_node (info);

    if (new) {

        if (!list_is_empty) {
            Node * second = * head;
            second->prev = new;
        }

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
        new->prev = element;
        
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

            if (!list_is_empty) {
                Node * second = * head;
                second->prev = new;
            }

            new->next = * head;
            * head = new;
            
            return 1;
        }

        previous->next = new;
        new->prev = previous;

        new->next = element;
        element->prev = new;

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

    int counter = 0;

    while (head != NULL) {

        head = head->next;
        counter++;
    }

    return counter;
}

void list_print (Node * head, char * message){

    printf ("%s ", message);

    while (head != NULL) {

        printf ("%d ", head->info);
        head = head->next;
    }

    printf ("\n");

}

int list_remove (Node ** head, int info){

    if (!list_exists (*head, info)) return 0;

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

        if (element->next == NULL) {

            previous->next = NULL;
            free (element);

            return 1;

        } else {

            Node * new = element->next;

            if (previous == NULL) {
            
                new->prev = NULL;
                * head = new;
                
                free (element);

                return 1;
            }

            new->prev = previous;
            previous->next = new;

            free (element);

            return 1;
        }

    }

    return 0;
}

int list_remove_index (Node ** head, int index){

    if (index >= list_size(*head)) return 0;

    Node * previous = NULL;
    Node * element = * head;

    for (int i = 0; i < index; i++) {

        if (element != NULL) {
            previous = element;
            element = element->next;
        }

    }

    if (element->next == NULL) {

        previous->next = NULL;
        free (element);

        return 1;

    } else {

        Node * new = element->next;

        if (previous == NULL) {
        
            new->prev = NULL;
            * head = new;
            
            free (element);

            return 1;
        }

        new->prev = previous;
        previous->next = new;

        free (element);

        return 1;
    }

}

void list_clear (Node ** head){

    Node * next =  NULL;
    Node * element = * head;

    while (element->next != NULL) {

        next = element->next;
        free (element);

        element = next;
    }

    * head = NULL;
}