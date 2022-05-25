#ifndef sll_char_loaded 
#define sll_char_loaded

typedef struct sll_char_node {
    struct sll_char_node *next; 
    char value; 
} sll_char_node; 


typedef struct sll_char {
    sll_char_node *head; 
    sll_char_node *tail; 
    unsigned long length; 
} sll_char; 


sll_char *create_sll_char();
// adds item to back
unsigned long sll_char_push(sll_char *list, char item);
// removes and returns last item
char sll_char_pop(sll_char *list);
// returns value at specified index
char sll_char_get(sll_char *list, unsigned long index);
// destroys list and frees all memory for nodes and list
void destroy_sll_char(sll_char *list);
// adds item to start of list
unsigned long sll_char_unshift(sll_char *list, char item);
// removes first value
void sll_char_shift(sll_char *list);
// inserts value at index
void sll_char_insert(sll_char *list, unsigned long index, char item);
// removes value at index
void sll_char_delete(sll_char *list, unsigned long index);
// takes a function and carries out action on each element in the node
// USE THIS OVER NORMAL FOR LOOPS as this will use the underlying node object's next property
// to iterate instead of starting at the beginning of the list for each iteration
void sll_char_for_each(sll_char *list, void (*f)(char value, unsigned long index));
// iterates each node executing the passed callback function on it's value and the void *accumulator provided by the user
// The callback should return this same void *accumulator which itself is returned after fully iterating the list
void *sll_char_reduce(sll_char *list, void * (*f)(char value, void *accumulator, unsigned long index),  void *accumulator);
// Creates and returns a new list  * where each element is created from the value returned from passing the cooresponding 
// element from the provided list to the callback
sll_char *sll_char_map(sll_char *list, char (*callback)(char current, unsigned long index));
// searches for target value in list and returns its index if found, otherwise returns -1
unsigned long sll_char_find(sll_char *list, char target);

#endif