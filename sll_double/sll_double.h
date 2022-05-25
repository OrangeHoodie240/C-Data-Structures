#ifndef sll_double_loaded 
#define sll_double_loaded

typedef struct sll_double_node {
    struct sll_double_node *next; 
    double value; 
} sll_double_node; 


typedef struct sll_double {
    sll_double_node *head; 
    sll_double_node *tail; 
    unsigned long length; 
} sll_double; 


sll_double *create_sll_double();
// adds item to back
unsigned long sll_double_push(sll_double *list, double item);
// removes and returns last item
double sll_double_pop(sll_double *list);
// returns value at specified index
double sll_double_get(sll_double *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_double(sll_double *list);
// adds item to start of list
unsigned long sll_double_unshift(sll_double *list, double item);
// removes first value
void sll_double_shift(sll_double *list);
// inserts value at index
void sll_double_insert(sll_double *list, unsigned long index, double item);
// removes value at index
void sll_double_delete(sll_double *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_double_for_each(sll_double *list, void (*f)(double value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_double_reduce(sll_double *list, void * (*f)(double value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_double *sll_double_map(sll_double *list, double (*callback)(double current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_double_find(sll_double *list, double target);

#endif