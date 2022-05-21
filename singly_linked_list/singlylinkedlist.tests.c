#include "singlylinkedlist.h"
#include <string.h>
#include <stdio.h>
#include "singlylinkedlist.tests.helpers.h"

char sll_push_appends_node(){
    singly_linked_list *list = create_singly_linked_list(add_for_car, delete_for_car);

    car c1; 
    c1.color = malloc(sizeof(char) * 5); 
    strcpy(c1.color, "blue");
    c1.weight = 3.2; 

    car c2; 
    c2.color = malloc(sizeof(char) * 6); 
    strcpy(c2.color, "green");
    c2.weight = 1.2; 

    unsigned long length_before = list->length; 

    singly_linked_list_push(list, &c1); 


    // assert the length increased by one
    unsigned long length_after_first = list->length; 
    if(length_after_first != length_before + 1){
        return 0; 
    }

    car * c_from_list = singly_linked_list_get(list, 0); 
    
    // assert does not return NULL 
    if(c_from_list == NULL){
        return 0; 
    }


    // assert there was a node appended with the correct values
    if(c_from_list->weight != c1.weight || strcmp(c_from_list->color, c1.color) != 0){
        return 0; 
    }


    singly_linked_list_push(list, &c2); 
    unsigned long length_after_second = list->length;

    // assert correct length after pushing second
    if(length_after_second != length_after_first + 1){
        return 0; 
    }

     c_from_list = singly_linked_list_get(list, 1);
    // assert does not return NULL 
    if(c_from_list == NULL){
        return 0; 
    }

    // assert second node was appended and with the correct values 
    if(c_from_list->weight != c2.weight || strcmp(c_from_list->color, c2.color) != 0){
        return 0; 
    }


    free(c1.color); 
    c1.color = NULL;    
    free(c2.color);
    c2.color = NULL; 
    destroy_singly_linked_list(list);

    return 1; 
}