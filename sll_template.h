
#include "car/car.h"
#ifndef sll_car_defined 
#define sll_car_defined 


typedef struct sll_car_node {
    struct sll_car_node *next; 
    car value; 
} sll_car_node; 


typedef struct sll_car {
    sll_car_node *head; 
    sll_car_node *tail; 
    unsigned long length; 
    void (*add_function)(sll_car_node *node, car value); 
    void (*delete_function)(sll_car_node *node); 
} sll_car; 


// sll_car, singly linked list, will take two functions arguments: 
//      1. A function used when adding our custom type as a value to a node in the linked list. 
//      2. A function used when destroying a node value.
//
// The second function is optional and only necessary when our custom type has members that require freeing from the 
// heap. When our type does not have members needing freeing, we can pass NULL as the second argument. 
//
// void add_function(sll_car_node *node, void value*)
//      takes node pointer and value void pointer for the node value. 
//      What we need to do is set the node value to the value of the void pointer
//      to do this we need to cast to the correct type for the void pointer 
//      if the type is a struct with members on the heap we need to 
//          1. create location on the heap and copy the values from those members. 
//          2. Set the pointer members to the address of these new locations
//
// void delete_function(sll_car_node * node)
//      we pass when our value type has members on the heap that need to be freed. 
//      When our type does not have members on the heap we pass NULL
//      Inside we: 
//          1. we pass node->value->member_name to free() for each member that is on the heap
//          2. pass node-value to free() at the end of the function.
// 
// ********************EXAMPLE******************
// Custom Type: 
//____________________________
//typedef struct car {
//  char *color; 
//  float weight; 
//} car;
//
// add_function:
//____________________________ 
//void add_for_car(sll_car_node *node, void *value){
//  car *c = malloc(sizeof(car)); 
//  *c = *(car*)value; 
//  char *color = malloc(strlen(c->color) + 1); 
//  strcpy(color, c->color);
//  c->color = color; 
//  node->value = c;   
//}
// 
// delete_function: 
//___________________________
//void delete_for_car(sll_car_node *node){
//    free(((car *)(node->value))->color);
//    free(node->value);
//}
sll_car *create_sll_car(void (*f)(sll_car_node *node, car value), void (*g)(sll_car_node * node));


// Takes the sll_car and then the address to the value to append to the sll_car
// This function will copy apply the add_function in order to create a copy of the value at a place on the heap that the node will
// point to. 
unsigned long sll_car_push(sll_car *list, car item);

// Removes the last node from the sll_car
// Takes the sll_car and a char, return_item, that determines whether or not the item should be returned. 
// If we set return_item to 0, the memory on the heap for the value is freed and NULL is returned. 
// If we use any value other than 0, the value is returned a void *. 
car *sll_car_pop(sll_car *list, char return_item);

car sll_car_get(sll_car *list, unsigned long index);
void destroy_sll_car(sll_car *list);
unsigned long sll_car_unshift(sll_car *list, car item); 
void sll_car_insert(sll_car *list, unsigned long index, car item);
void sll_car_shift(sll_car *list); 
void sll_car_delete(sll_car *list, unsigned long index);


// Allows a for each loop while iterating by means of the .next property on each nodes instead of 
// starting from the head of the sll_car for each iteration. 

// Takes list and then a function, void *f(void *value, unsigned long index) and finally  Then executes 
// the function on each sll_car_node value property and passing its index.

void sll_car_for_each(sll_car *list, void (*f)(void *value, unsigned long index));

// add function for float types
void sll_car_add_for_float(sll_car_node *node, void *item);

void *sll_car_reduce(sll_car *list, void * (*f)(void *current, void *accumulator, unsigned long index),  void *accumulator);
sll_car *sll_car_map(sll_car *list, void *(*callback)(void *current, unsigned long index), void (*add_function)(sll_car_node *node, void *item), void (*delete_function)(sll_car_node *node));
void *sll_car_find(sll_car *list, void *(callback)(void *value)); 


#endif