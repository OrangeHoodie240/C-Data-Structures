#ifndef example_defined 
#define example_defined 

#include <stdlib.h>

void delete_function(example ex){
    free(example.string);
}

tyepdef struct example {
    short intger; 
    char *string; 
    float *decimal; 
} example; 

#endif