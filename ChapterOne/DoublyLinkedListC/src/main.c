#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedlist.h"

int main() {
    
    // Test 1: Create List/Node & Print
    char *test_1 = malloc(6);
    strcpy(test_1, "Heelo");

    List *list_1 = list_create(test_1);

    list_print(list_1);

    list_free(list_1);

    // Test 2: Add 2 Nodes To Empty List Then Remove
    char *test_21 = malloc(6);
    char *test_22 = malloc(6);

    strcpy(test_21, "TEST1");
    strcpy(test_22, "TEST2");

    List *test_2_list = list_create(test_21);
    list_add(test_2_list, test_22);

    list_print(test_2_list);

    list_remove(test_2_list, test_21);
    
    list_print(test_2_list);

    list_remove(test_2_list, test_22);

    list_print(test_2_list);

    list_free(test_2_list);

    return 1;
}
