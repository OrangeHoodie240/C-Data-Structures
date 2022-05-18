#include <string.h> 
#include <stdlib.h>

#define hashsize(n) ((unsigned long)1 << n)
#define hashmask(n) (hashsize(n) - 1)

unsigned long hash(char *key, unsigned long size, short bits){
    unsigned long hash = 0; 
    
    for(unsigned long i = 0; i < size; i++){
        hash += key[i]; 
        hash += hash << 10; 
        hash ^= hash >> 6; 
    }

    hash += hash << 3; 
    hash ^= hash >> 11; 
    hash += hash << 15; 

    return hash & hashmask(bits); 
}

typedef struct hash_node {
    char *key; 
    void *value; 
} hash_node; 


