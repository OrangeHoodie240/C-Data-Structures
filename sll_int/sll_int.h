#ifndef sll_int_loaded 
#define sll_int_loaded

typedef struct sll_int_node {
    struct sll_int_node *next; 
    int value; 
} sll_int_node; 


typedef struct sll_int {
    sll_int_node *head; 
    sll_int_node *tail; 
    unsigned long length; 
} sll_int; 


sll_int *create_sll_int();
// adds item to back
unsigned long sll_int_push(sll_int *list, int item);
// removes and returns last item
int sll_int_pop(sll_int *list);
// returns value at specified index
int sll_int_get(sll_int *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_int(sll_int *list);
// adds item to start of list
unsigned long sll_int_unshift(sll_int *list, int item);
// removes first value
void sll_int_shift(sll_int *list);
// inserts value at index
void sll_int_insert(sll_int *list, unsigned long index, int item);
// removes value at index
void sll_int_delete(sll_int *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_int_for_each(sll_int *list, void (*f)(int value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_int_reduce(sll_int *list, void * (*f)(int value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_int *sll_int_map(sll_int *list, int (*callback)(int current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_int_find(sll_int *list, int target);

#endif