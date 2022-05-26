#ifndef sll_ulong_loaded 
#define sll_ulong_loaded

typedef struct sll_ulong_node {
    struct sll_ulong_node *next; 
    unsigned long value; 
} sll_ulong_node; 


typedef struct sll_ulong {
    sll_ulong_node *head; 
    sll_ulong_node *tail; 
    unsigned long length; 
} sll_ulong; 


sll_ulong *create_sll_ulong();
// adds item to back
unsigned long sll_ulong_push(sll_ulong *list, unsigned long item);
// removes and returns last item
unsigned long sll_ulong_pop(sll_ulong *list);
// returns value at specified index
unsigned long sll_ulong_get(sll_ulong *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_ulong(sll_ulong *list);
// adds item to start of list
unsigned long sll_ulong_unshift(sll_ulong *list, unsigned long item);
// removes first value
void sll_ulong_shift(sll_ulong *list);
// inserts value at index
void sll_ulong_insert(sll_ulong *list, unsigned long index, unsigned long item);
// removes value at index
void sll_ulong_delete(sll_ulong *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_ulong_for_each(sll_ulong *list, void (*f)(unsigned long value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_ulong_reduce(sll_ulong *list, void * (*f)(unsigned long value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_ulong *sll_ulong_map(sll_ulong *list, unsigned long (*callback)(unsigned long current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_ulong_find(sll_ulong *list, unsigned long target);

#endif