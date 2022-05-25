#ifndef sll_float_loaded 
#define sll_float_loaded

typedef struct sll_float_node {
    struct sll_float_node *next; 
    float value; 
} sll_float_node; 


typedef struct sll_float {
    sll_float_node *head; 
    sll_float_node *tail; 
    unsigned long length; 
} sll_float; 


sll_float *create_sll_float();
// adds item to back
unsigned long sll_float_push(sll_float *list, float item);
// removes and returns last item
float sll_float_pop(sll_float *list);
// returns value at specified index
float sll_float_get(sll_float *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_float(sll_float *list);
// adds item to start of list
unsigned long sll_float_unshift(sll_float *list, float item);
// removes first value
void sll_float_shift(sll_float *list);
// inserts value at index
void sll_float_insert(sll_float *list, unsigned long index, float item);
// removes value at index
void sll_float_delete(sll_float *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_float_for_each(sll_float *list, void (*f)(float value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_float_reduce(sll_float *list, void * (*f)(float value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_float *sll_float_map(sll_float *list, float (*callback)(float current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_float_find(sll_float *list, float target);


#endif