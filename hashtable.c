#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define hash_size(n) ((unsigned long)1 << n)
#define hash_mask(n) (hash_size(n) - 1)


typedef enum type {
    d, 
    ld, 
    lld, 
    u, 
    lu, 
    llu,
    f, 
    lf, 
    s
} type; 



typedef struct map_node_d {
    char *key; 
    int value; 
} map_node; 
