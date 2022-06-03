#include"example.h"

#ifndef sll_example_defined 
#define sll_example_defined 


typedef struct sll_example_node {
    struct sll_example_node *next; 
    example value; 
} sll_example_node; 


typedef struct sll_example {
    sll_example_node *head; 
    sll_example_node *tail; 
    unsigned long length; 
    void (*delete_function)(sll_example_node *node); 
} sll_example; 


// sll_example, singly linked list, will take two functions arguments: 
//      1. A function used when adding our custom type as a value to a node in the linked list. 
//      2. A function used when destroying a node value.
//
// The second function is optional and only necessary when our custom type has members that require freeing from the 
// heap. When our type does not have members needing freeing, we can pass NULL as the second argument. 
//
// void add_function(sll_example_node *node, void value*)
//      takes node pointer and value void pointer for the node value. 
//      What we need to do is set the node value to the value of the void pointer
//      to do this we need to cast to the correct type for the void pointer 
//      if the type is a struct with members on the heap we need to 
//          1. create location on the heap and copy the values from those members. 
//          2. Set the pointer members to the address of these new locations
//
// void delete_function(sll_example_node * node)
//      we pass when our value type has members on the heap that need to be freed. 
//      When our type does not have members on the heap we pass NULL
//      Inside we: 
//          1. we pass node->value->member_name to free() for each member that is on the heap
//          2. pass node-value to free() at the end of the function.
// 
// ********************EXAMPLE******************
// Custom Type: 
//____________________________
//typedef struct example {
//  char *color; 
//  float weight; 
//} example;
//
// add_function:
//____________________________ 
//void add_for_example(sll_example_node *node, void *value){
//  example *c = malloc(sizeof(example)); 
//  *c = *(example*)value; 
//  char *color = malloc(strlen(c->color) + 1); 
//  strcpy(color, c->color);
//  c->color = color; 
//  node->value = c;   
//}
// 
// delete_function: 
//___________________________
//void delete_for_example(sll_example_node *node){
//    free(((example *)(node->value))->color);
//    free(node->value);
//}
sll_example *create_sll_example();


// Takes the sll_example and then the address to the value to append to the sll_example
// This function will copy apply the add_function in order to create a copy of the value at a place on the heap that the node will
// point to. 
unsigned long sll_example_push(sll_example *list, example item);

// Removes the last node from the sll_example
// Takes the sll_example and a char, return_item, that determines whether or not the item should be returned. 
// If we set return_item to 0, the memory on the heap for the value is freed and NULL is returned. 
// If we use any value other than 0, the value is returned a void *. 
example *sll_example_pop(sll_example *list, char return_item);

example *sll_example_get(sll_example *list, unsigned long index);
void destroy_sll_example(sll_example *list);
unsigned long sll_example_unshift(sll_example *list, example item); 
void sll_example_insert(sll_example *list, unsigned long index, example item);
void sll_example_shift(sll_example *list); 
void sll_example_delete(sll_example *list, unsigned long index);


// Allows a for each loop while iterating by means of the .next property on each nodes instead of 
// starting from the head of the sll_example for each iteration. 

// Takes list and then a function, void *f(void *value, unsigned long index) and finally  Then executes 
// the function on each sll_example_node value property and passing its index.

void sll_example_for_each(sll_example *list, void (*f)(example *value, unsigned long index));

// add function for float types
void sll_example_add_for_float(sll_example_node *node, void *item);

void *sll_example_reduce(sll_example *list, void * (*f)(example current, void *accumulator, unsigned long index),  void *accumulator);
sll_example *sll_example_map(sll_example *list, example (*callback)(example current, unsigned long index));
example *sll_example_find(sll_example *list, example *(callback)(example *value)); 


#endif