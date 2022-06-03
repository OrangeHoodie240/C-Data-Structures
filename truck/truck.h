#ifndef truck_header_defined
#define truck_header_defined

#include <stdlib.h>

typedef struct truck {
    char *color; 
    float weight; 
    short year; 
    short horse_power; 
} truck; 


void delete_function(truck tr){
    free(tr.color);
}


#endif