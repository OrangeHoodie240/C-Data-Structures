#ifndef singly_linked_list_defined 
#define singly_linked_list_defined 


typedef struct singly_linked_list_node {
    struct singly_linked_list_node *next; 
    void *value; 
} singly_linked_list_node; 


typedef struct singly_linked_list {
    singly_linked_list_node *head; 
    singly_linked_list_node *tail; 
    unsigned long length; 
    void (*add_function)(singly_linked_list_node *node, void *value); 
    void (*delete_function)(singly_linked_list_node *node); 
} singly_linked_list; 


// singly_linked_list will take two functions arguments: 
//      1. A function used when adding our custom type as a value to a node in the linked list. 
//      2. A function used when destroying a node value.
//
// The second function is optional and only necessary when our custom type has members that require freeing from the 
// heap. When our type does not have members needing freeing, we can pass NULL as the second argument. 
//
// void add_function(singly_linked_list_node *node, void value*)
//      takes node pointer and value void pointer for the node value. 
//      What we need to do is set the node value to the value of the void pointer
//      to do this we need to cast to the correct type for the void pointer 
//      if the type is a struct with members on the heap we need to 
//          1. create location on the heap and copy the values from those members. 
//          2. Set the pointer members to the address of these new locations
//
// void delete_function(singly_linked_list_node * node)
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
//void add_for_car(singly_linked_list_node *node, void *value){
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
//void delete_for_car(singly_linked_list_node *node){
//    free(((car *)(node->value))->color);
//    free(node->value);
//}
singly_linked_list *create_singly_linked_list(void (*f)(singly_linked_list_node *node, void *value), void (*g)(singly_linked_list_node * node));

// Takes the singly_linked_list and then the address to the value to append to the singly_linked_list
// This function will copy apply the add_function in order to create a copy of the value at a place on the heap that the node will
// point to. 
unsigned long singly_linked_list_push(singly_linked_list *list, void *item);

// Removes the last node from the singly_linked_list
// Takes the singly_linked_list and a char, return_item, that determines whether or not the item should be returned. 
// If we set return_item to 0, the memory on the heap for the value is freed and NULL is returned. 
// If we use any value other than 0, the value is returned a void *. 
void * singly_linked_list_pop(singly_linked_list *list, char return_item);
void *singly_linked_list_get(singly_linked_list *list, unsigned long index);
void destroy_singly_linked_list(singly_linked_list *list);

#endif