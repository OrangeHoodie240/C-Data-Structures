#ifndef sll_uint_loaded 
#define sll_uint_loaded

typedef struct sll_uint_node {
    struct sll_uint_node *next; 
    int value; 
} sll_uint_node; 


typedef struct sll_uint {
    sll_uint_node *head; 
    sll_uint_node *tail; 
    unsigned long length; 
} sll_uint; 


sll_uint *create_sll_uint();
// adds item to back
unsigned long sll_uint_push(sll_uint *list, unsigned int item);
// removes and returns last item
unsigned int sll_uint_pop(sll_uint *list);
// returns value at specified index
unsigned int sll_uint_get(sll_uint *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_uint(sll_uint *list);
// adds item to start of list
unsigned long sll_uint_unshift(sll_uint *list, unsigned int item);
// removes first value
void sll_uint_shift(sll_uint *list);
// inserts value at index
void sll_uint_insert(sll_uint *list, unsigned long index, unsigned int item);
// removes value at index
void sll_uint_delete(sll_uint *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_uint_for_each(sll_uint *list, void (*f)(unsigned int value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_uint_reduce(sll_uint *list, void * (*f)(unsigned int value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_uint *sll_uint_map(sll_uint *list, unsigned int (*callback)(unsigned int current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_uint_find(sll_uint *list, unsigned int target);

#endif