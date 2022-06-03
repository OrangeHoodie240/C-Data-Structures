#include "truck/sll_truck.h"
#include "truck/truck.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void print_all(truck *tr, unsigned long ind){
    printf("\nTruck # %d: \n", ind + 1);
    printf("\tColor: %s\n", tr->color);
    printf("\tWeight:: %f\n", tr->weight);
    printf("\tHorse: %d\n", tr->horse_power);
    printf("\tYear: %d\n",tr->year );
}

int main(){
    srand(time(NULL));
    
    sll_truck *list = create_sll_truck(); 

    for(int i = 0; i < 50; i++){
            truck t; 
            t.color = malloc(sizeof(char) * 4); 
            t.horse_power = rand() % 2000; 
            t.weight = 33.21;
            t.year = rand() % 2000;
            sll_truck_push(list, t);
    }

    sll_truck_for_each(list, print_all);

}