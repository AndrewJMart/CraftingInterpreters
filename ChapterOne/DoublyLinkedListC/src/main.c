#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedlist.h"

int main() {
    
    // Test 1: Create List/Node & Print
    char *test_string = malloc(6);
    strcpy(test_string, "Heelo");

    List *list_1 = list_create(node_create(test_string));

    list_print(list_1);

    list_free(list_1);

    return 1;
}
