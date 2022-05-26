#include <stdlib.h>
#include <string.h>
#include "./car/car.h"



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