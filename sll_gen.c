#include <stdio.h>


int main(){



    FILE *input = fopen("sll_car/sll_car.c", "r");
    FILE *output = fopen("sll_car/gen.c", "w");

    int next = fgetc(input);
    while(next != EOF){
        fputc(next, output);
        next = fgetc(input);
    }

    fclose(input);



    fclose(output);

    // build sll_type.h
    input = fopen("sll_template.h", "r"); 
    output = fopen("sll_car/sll_type.h", "w"); 

    next = fgetc(input);
    while(next != EOF){
        fputc(next, output);
        next = fgetc(input);
    }

    fclose(input);
    fclose(output);


}