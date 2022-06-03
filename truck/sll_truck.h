#include"truck.h"

#ifndef sll_truck_defined 
#define sll_truck_defined 


typedef struct sll_truck_node {
    struct sll_truck_node *next; 
    truck value; 
} sll_truck_node; 


typedef struct sll_truck {
    sll_truck_node *head; 
    sll_truck_node *tail; 
    unsigned long length; 
    // void (*delete_function)(sll_truck_node *node); 
} sll_truck; 


// sll_truck, singly linked list, will take two functions arguments: 
//      1. A function used when adding our custom type as a value to a node in the linked list. 
//      2. A function used when destroying a node value.
//
// The second function is optional and only necessary when our custom type has members that require freeing from the 
// heap. When our type does not have members needing freeing, we can pass NULL as the second argument. 
//
// void add_function(sll_truck_node *node, void value*)
//      takes node pointer and value void pointer for the node value. 
//      What we need to do is set the node value to the value of the void pointer
//      to do this we need to cast to the correct type for the void pointer 
//      if the type is a struct with members on the heap we need to 
//          1. create location on the heap and copy the values from those members. 
//          2. Set the pointer members to the address of these new locations
//
// void delete_function(sll_truck_node * node)
//      we pass when our value type has members on the heap that need to be freed. 
//      When our type does not have members on the heap we pass NULL
//      Inside we: 
//          1. we pass node->value->member_name to free() for each member that is on the heap
//          2. pass node-value to free() at the end of the function.
// 
// ********************EXAMPLE******************
// Custom Type: 
//____________________________
//typedef struct truck {
//  char *color; 
//  float weight; 
//} truck;
//
// add_function:
//____________________________ 
//void add_for_truck(sll_truck_node *node, void *value){
//  truck *c = malloc(sizeof(truck)); 
//  *c = *(truck*)value; 
//  char *color = malloc(strlen(c->color) + 1); 
//  strcpy(color, c->color);
//  c->color = color; 
//  node->value = c;   
//}
// 
// delete_function: 
//___________________________
//void delete_for_truck(sll_truck_node *node){
//    free(((truck *)(node->value))->color);
//    free(node->value);
//}
sll_truck *create_sll_truck();


// Takes the sll_truck and then the address to the value to append to the sll_truck
// This function will copy apply the add_function in order to create a copy of the value at a place on the heap that the node will
// point to. 
unsigned long sll_truck_push(sll_truck *list, truck item);

// Removes the last node from the sll_truck
// Takes the sll_truck and a char, return_item, that determines whether or not the item should be returned. 
// If we set return_item to 0, the memory on the heap for the value is freed and NULL is returned. 
// If we use any value other than 0, the value is returned a void *. 
truck *sll_truck_pop(sll_truck *list, char return_item);

truck *sll_truck_get(sll_truck *list, unsigned long index);
void destroy_sll_truck(sll_truck *list);
unsigned long sll_truck_unshift(sll_truck *list, truck item); 
void sll_truck_insert(sll_truck *list, unsigned long index, truck item);
void sll_truck_shift(sll_truck *list); 
void sll_truck_delete(sll_truck *list, unsigned long index);


// Allows a for each loop while iterating by means of the .next property on each nodes instead of 
// starting from the head of the sll_truck for each iteration. 

// Takes list and then a function, void *f(void *value, unsigned long index) and finally  Then executes 
// the function on each sll_truck_node value property and passing its index.

void sll_truck_for_each(sll_truck *list, void (*f)(truck *value, unsigned long index));

// add function for float types
void sll_truck_add_for_float(sll_truck_node *node, void *item);

void *sll_truck_reduce(sll_truck *list, void * (*f)(truck current, void *accumulator, unsigned long index),  void *accumulator);
sll_truck *sll_truck_map(sll_truck *list, truck (*callback)(truck current, unsigned long index));
truck *sll_truck_find(sll_truck *list, truck *(callback)(truck *value)); 


#endif