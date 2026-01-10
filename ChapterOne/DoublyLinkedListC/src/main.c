#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedlist.h"

int main() {
    char *test_string = malloc(6);
    strcpy(test_string, "Heelo");

    printf("%s", test_string);

    Node *test_node = node_create(test_string);

    printf("%s", test_node->value);

    return 1;
}
