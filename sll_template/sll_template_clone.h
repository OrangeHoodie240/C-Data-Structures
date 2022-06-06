
#ifndef sll_car_defined 
#define sll_car_defined 


typedef struct sll_car_node {
    struct sll_car_node *next; 
    car value; 
} sll_car_node; 


typedef struct sll_car {
    sll_car_node *head; 
    sll_car_node *tail; 
    unsigned long length; 
} sll_car; 


// crates and returns the address of a new instance of sll_car
// The items in sll_car are stored by reference
sll_car *create_sll_car();


// Takes the sll_car and then the address to the value to append to the sll_car
// Returns the length of the sll_car list
// The car is stored by reference
unsigned long sll_car_push(sll_car *list, car item);

// Removes the last node from the sll_car
// Takes the sll_car and a char, return_item, that determines whether or not the item should be returned. 
// If we set return_item to 0, the memory on the heap for the value is freed and NULL is returned. 
// If we use any value other than 0, the value is returned as a car *. 
car *sll_car_pop(sll_car *list, char return_item);

// takes list and then the index and returns the address to the car
car *sll_car_get(sll_car *list, unsigned long index);

// takes sll_car and will free all memory of items and the list itself.
void destroy_sll_car(sll_car *list);

// adds car to front of list returns length 
// adds by reference
unsigned long sll_car_unshift(sll_car *list, car item); 

// inserts car at index 
// inserts by reference 
void sll_car_insert(sll_car *list, unsigned long index, car item);

// removes first car in list
void sll_car_shift(sll_car *list); 

// deletes car at index
void sll_car_delete(sll_car *list, unsigned long index);


// Allows a for each loop while iterating by means of the .next property on each nodes instead of 
// starting from the head of the sll_car for each iteration. 

// Takes list and then a function, void *f(car *value, unsigned long index) and finally  Then executes 
// the function on each sll_car_node value property and passing its index.
void sll_car_for_each(sll_car *list, void (*f)(car *value, unsigned long index));


// reduce function 
void *sll_car_reduce(sll_car *list, void * (*f)(car current, void *accumulator, unsigned long index),  void *accumulator);
sll_car *sll_car_map(sll_car *list, car (*callback)(car current, unsigned long index));
car *sll_car_find(sll_car *list, car *(callback)(car *value)); 


#endif