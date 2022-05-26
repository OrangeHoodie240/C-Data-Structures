#ifndef sll_llong_loaded 
#define sll_llong_loaded

typedef struct sll_llong_node {
    struct sll_llong_node *next; 
    long long value; 
} sll_llong_node; 


typedef struct sll_llong {
    sll_llong_node *head; 
    sll_llong_node *tail; 
    unsigned long length; 
} sll_llong; 


sll_llong *create_sll_llong();
// adds item to back
unsigned long sll_llong_push(sll_llong *list, long long item);
// removes and returns last item
long long sll_llong_pop(sll_llong *list);
// returns value at specified index
long long sll_llong_get(sll_llong *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_llong(sll_llong *list);
// adds item to start of list
unsigned long sll_llong_unshift(sll_llong *list, long long item);
// removes first value
void sll_llong_shift(sll_llong *list);
// inserts value at index
void sll_llong_insert(sll_llong *list, unsigned long index, long long item);
// removes value at index
void sll_llong_delete(sll_llong *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_llong_for_each(sll_llong *list, void (*f)(long long value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_llong_reduce(sll_llong *list, void * (*f)(long long value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_llong *sll_llong_map(sll_llong *list, long long (*callback)(long long current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_llong_find(sll_llong *list, long long target);

#endif