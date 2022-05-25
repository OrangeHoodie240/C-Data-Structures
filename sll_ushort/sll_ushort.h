#ifndef sll_ushort_loaded 
#define sll_ushort_loaded

typedef struct sll_ushort_node {
    struct sll_ushort_node *next; 
    short value; 
} sll_ushort_node; 


typedef struct sll_ushort {
    sll_ushort_node *head; 
    sll_ushort_node *tail; 
    unsigned long length; 
} sll_ushort; 


sll_ushort *create_sll_ushort();
// adds item to back
unsigned long sll_ushort_push(sll_ushort *list, unsigned short item);
// removes and returns last item
unsigned short sll_ushort_pop(sll_ushort *list);
// returns value at specified index
unsigned short sll_ushort_get(sll_ushort *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_ushort(sll_ushort *list);
// adds item to start of list
unsigned long sll_ushort_unshift(sll_ushort *list, unsigned short item);
// removes first value
void sll_ushort_shift(sll_ushort *list);
// inserts value at index
void sll_ushort_insert(sll_ushort *list, unsigned long index, unsigned short item);
// removes value at index
void sll_ushort_delete(sll_ushort *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_ushort_for_each(sll_ushort *list, void (*f)(unsigned short value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_ushort_reduce(sll_ushort *list, void * (*f)(unsigned short value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_ushort *sll_ushort_map(sll_ushort *list, unsigned short (*callback)(unsigned short current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_ushort_find(sll_ushort *list, unsigned short target);

#endif