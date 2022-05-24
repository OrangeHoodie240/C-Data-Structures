#include <stdlib.h>
#include <string.h>

#ifndef singlylinkedlist_tests_helpers_defined
#define singlylinkedlist_tests_helpers_defined

typedef struct car {
    char *color; 
    float weight; 
} car;


void add_for_car(sll_node *node, void *value){
    car *c = malloc(sizeof(car)); 
    *c = *(car*)value; 
    
    char *color = malloc(strlen(c->color) + 1); 
    strcpy(color, c->color);
    c->color = color; 

    node->value = c;   
}

void delete_for_car(sll_node *node){
    free(((car *)(node->value))->color);
    free(node->value);
}
#endif