#ifndef sll_ullong_loaded 
#define sll_ullong_loaded

typedef struct sll_ullong_node {
    struct sll_ullong_node *next; 
    unsigned long long value; 
} sll_ullong_node; 


typedef struct sll_ullong {
    sll_ullong_node *head; 
    sll_ullong_node *tail; 
    unsigned long length; 
} sll_ullong; 


sll_ullong *create_sll_ullong();
// adds item to back
unsigned long sll_ullong_push(sll_ullong *list, unsigned long long item);
// removes and returns last item
unsigned long sll_ullong_pop(sll_ullong *list);
// returns value at specified index
unsigned long long sll_ullong_get(sll_ullong *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_ullong(sll_ullong *list);
// adds item to start of list
unsigned long sll_ullong_unshift(sll_ullong *list, unsigned long long item);
// removes first value
void sll_ullong_shift(sll_ullong *list);
// inserts value at index
void sll_ullong_insert(sll_ullong *list, unsigned long index, unsigned long long item);
// removes value at index
void sll_ullong_delete(sll_ullong *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_ullong_for_each(sll_ullong *list, void (*f)(unsigned long long value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_ullong_reduce(sll_ullong *list, void * (*f)(unsigned long long value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_ullong *sll_ullong_map(sll_ullong *list, unsigned long long (*callback)(unsigned long long current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_ullong_find(sll_ullong *list, unsigned long long target);

#endif