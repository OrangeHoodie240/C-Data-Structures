#ifndef sll_uchar_loaded 
#define sll_uchar_loaded

typedef struct sll_uchar_node {
    struct sll_uchar_node *next; 
    unsigned char value; 
} sll_uchar_node; 


typedef struct sll_uchar {
    sll_uchar_node *head; 
    sll_uchar_node *tail; 
    unsigned long length; 
} sll_uchar; 


sll_uchar *create_sll_uchar();
// adds item to back
unsigned long sll_uchar_push(sll_uchar *list, unsigned char item);
// removes and returns last item
char sll_uchar_pop(sll_uchar *list);
// returns value at specified index
char sll_uchar_get(sll_uchar *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_uchar(sll_uchar *list);
// adds item to start of list
unsigned long sll_uchar_unshift(sll_uchar *list, unsigned char item);
// removes first value
void sll_uchar_shift(sll_uchar *list);
// inserts value at index
void sll_uchar_insert(sll_uchar *list, unsigned long index, unsigned char item);
// removes value at index
void sll_uchar_delete(sll_uchar *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_uchar_for_each(sll_uchar *list, void (*f)(char value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_uchar_reduce(sll_uchar *list, void * (*f)(char value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_uchar *sll_uchar_map(sll_uchar *list, unsigned char (*callback)(char current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_uchar_find(sll_uchar *list, unsigned char target);

#endif