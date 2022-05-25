#ifndef sll_short_loaded 
#define sll_short_loaded

typedef struct sll_short_node {
    struct sll_short_node *next; 
    short value; 
} sll_short_node; 


typedef struct sll_short {
    sll_short_node *head; 
    sll_short_node *tail; 
    unsigned long length; 
} sll_short; 


sll_short *create_sll_short();
// adds item to back
unsigned long sll_short_push(sll_short *list, short item);
// removes and returns last item
short sll_short_pop(sll_short *list);
// returns value at specified index
short sll_short_get(sll_short *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_short(sll_short *list);
// adds item to start of list
unsigned long sll_short_unshift(sll_short *list, short item);
// removes first value
void sll_short_shift(sll_short *list);
// inserts value at index
void sll_short_insert(sll_short *list, unsigned long index, short item);
// removes value at index
void sll_short_delete(sll_short *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_short_for_each(sll_short *list, void (*f)(short value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_short_reduce(sll_short *list, void * (*f)(short value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_short *sll_short_map(sll_short *list, short (*callback)(short current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_short_find(sll_short *list, short target);

#endif