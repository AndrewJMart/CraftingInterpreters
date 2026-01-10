#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdbool.h>

typedef struct List{
    struct Node *head;
} List;

typedef struct Node{
    struct Node *prev;
    char *value;
    struct Node *next;
} Node;

List *list_create(Node *head);
Node *node_create(char *value);
void node_add(List *list, char *value);
void node_free(Node *node);
void node_remove(List *list, char *value);
bool node_find(List *list, char *value);
void list_print(List *list);
void list_free(List *list);



#endif
