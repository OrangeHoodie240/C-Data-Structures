#ifndef sll_float_loaded 
#define sll_float_loaded

typedef struct sll_float_node {
    struct sll_node *next; 
    float value; 
} sll_node; 


typedef struct sll_float {
    sll_float_node *head; 
    sll_float_node *tail; 
    unsigned long length; 
} sll_float; 


#endif