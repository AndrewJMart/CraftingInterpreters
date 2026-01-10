#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"linkedlist.h"

List *list_create(Node *head){
    List *return_list = malloc(sizeof(struct List));
    return_list->head = head;
    
    return return_list;
}

Node *node_create(char *value) {
    Node *return_node = malloc(sizeof(struct Node));
    return_node->prev = NULL;
    return_node->value = value;
    return_node->next = NULL;

    return return_node;
}

void node_free(Node *node){
    free(node->value);
    free(node);
    return;
}

void list_free(List *list) {
    Node *head_reference = list->head;
    
    // Empty List
    if (head_reference == NULL) {
        free(list);
        return;
    }

    // Loop Through List
    while (head_reference != NULL) {
        // Check If At Last Node
        if (head_reference->next == NULL) {
            node_free(head_reference);
            break;
        }
        // If Not Last Node Move Head Reference & Free Prev
        head_reference = head_reference->next;
        node_free(head_reference->prev);
    }
    
    // Free List
    free(list);
    return;
}

void node_add(List *list, char *value) {
    Node *return_node = node_create(value);
    Node *head_reference = list->head;

    // Loop Through Until Last Node
    while (head_reference->next != NULL) {
        head_reference = head_reference->next;
    }

    // Add To End Of List
    head_reference->next = return_node;
    return;
}

void node_remove(List *list, char *value) {
    Node *head_reference = list->head;

    while (head_reference != NULL) {
        // Check if string matches
        if (!strcmp(head_reference->value, value)) {
            // Item Is First In List
            if (head_reference->prev == NULL) {
                // One Item In List
                if (head_reference->next == NULL) {
                    list->head = NULL;
                    node_free(head_reference);
                    return;
                }
                // Items After First Item In List
                list->head = head_reference->next;
                node_free(head_reference);
                return;
            }
            // Item Is Not First In List
            head_reference->prev->next = head_reference->next;
            // Item Is Last In List
            if (head_reference->next == NULL) { 
                node_free(head_reference);
                return; 
            }
            // Item Is Not Last In List
            head_reference->next->prev = head_reference->prev;
            node_free(head_reference);
            return;
        }
    }
    // Item Not In List
    return;
}

bool node_find(List *list, char *value) {
    Node *head_reference = list->head;

    // Loop Through List
    while (head_reference != NULL) {
        // Value In List
        if (!strcmp(value, head_reference->value)) { return true; }
    }

    // Value Not In List
    return false;
}

void list_print(List *list) {
    Node *head_reference = list->head;

    if (head_reference == NULL) {
        printf("The List Is Empty\n");
        return;
    }
    int node_counter = 0;
    while (head_reference != NULL) {
        printf("Node: %d, Node Address: %p, Node Value: %s\n", node_counter, (void *)head_reference, head_reference->value);
        head_reference = head_reference->next;
    }
    return;
}


