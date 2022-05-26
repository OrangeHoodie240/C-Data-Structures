#ifndef sll_long_loaded 
#define sll_long_loaded

typedef struct sll_long_node {
    struct sll_long_node *next; 
    long value; 
} sll_long_node; 


typedef struct sll_long {
    sll_long_node *head; 
    sll_long_node *tail; 
    unsigned long length; 
} sll_long; 


sll_long *create_sll_long();
// adds item to back
unsigned long sll_long_push(sll_long *list, long item);
// removes and returns last item
long sll_long_pop(sll_long *list);
// returns value at specified index
long sll_long_get(sll_long *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_long(sll_long *list);
// adds item to start of list
unsigned long sll_long_unshift(sll_long *list, long item);
// removes first value
void sll_long_shift(sll_long *list);
// inserts value at index
void sll_long_insert(sll_long *list, unsigned long index, long item);
// removes value at index
void sll_long_delete(sll_long *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_long_for_each(sll_long *list, void (*f)(long value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_long_reduce(sll_long *list, void * (*f)(long value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_long *sll_long_map(sll_long *list, long (*callback)(long current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_long_find(sll_long *list, long target);

#endif