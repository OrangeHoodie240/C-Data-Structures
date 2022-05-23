#include "singlylinkedlist.h"
#include <string.h>
#include <stdio.h>
#include "singlylinkedlist.tests.helpers.h"


void free_everything(sll *list, car cars[], unsigned long size){

    for(unsigned long i = 0; i < size; i++){
        free(cars[i].color);
    }
    destroy_sll(list);
}

char sll_push_appends_node(){
    sll *list = create_sll(add_for_car, delete_for_car);

    car c1; 
    c1.color = malloc(sizeof(char) * 5); 
    strcpy(c1.color, "blue");
    c1.weight = 3.2; 

    car c2; 
    c2.color = malloc(sizeof(char) * 6); 
    strcpy(c2.color, "green");
    c2.weight = 1.2; 

    car cars[2] = {c1, c2}; 

    unsigned long length_before = list->length; 

    sll_push(list, &c1); 


    // assert the length increased by one
    unsigned long length_after_first = list->length; 
    if(length_after_first != length_before + 1){
        free_everything(list, cars, 2);
        return 0; 
    }

    car * c_from_list = sll_get(list, 0); 
    
    // assert does not return NULL 
    if(c_from_list == NULL){
        free_everything(list, cars, 2);
        return 0; 
    }


    // assert there was a node appended with the correct values
    if(c_from_list->weight != c1.weight || strcmp(c_from_list->color, c1.color) != 0){
        free_everything(list, cars, 2);
        return 0; 
    }


    sll_push(list, &c2); 
    unsigned long length_after_second = list->length;

    // assert correct length after pushing second
    if(length_after_second != length_after_first + 1){
        free_everything(list, cars, 2);
        return 0; 
    }

     c_from_list = sll_get(list, 1);
    // assert does not return NULL 
    if(c_from_list == NULL){
        free_everything(list, cars, 2);
        return 0; 
    }

    // assert second node was appended and with the correct values 
    if(c_from_list->weight != c2.weight || strcmp(c_from_list->color, c2.color) != 0){
        free_everything(list, cars, 2);
        return 0; 
    }


    free_everything(list, cars, 2);
    return 1; 
}



char sll_pop_removes_node(){
    sll *list = create_sll(add_for_car, delete_for_car);
    car c1, c2, c3, c4; 
    c1.weight = 1.2; 
    c2.weight = 2.3; 
    c3.weight = 3.4;
    c4.weight = 41.2;

    c1.color = malloc(sizeof(char) * 4);
    strcpy(c1.color, "red");
    c2.color = malloc(sizeof(char) * 4);
    strcpy(c2.color, "blue");
    c3.color = malloc(sizeof(char) * 6);
    strcpy(c3.color, "green");
    c4.color = malloc(sizeof(char) * 5);
    strcpy(c4.color, "gray");

    car cars[4] = {c1, c2, c3, c4};
    for(int i = 0; i < 4; i++){
        sll_push(list, &cars[i]);
    }

    // assert that the length dwindles accordingly
    sll_pop(list, 0);
    unsigned long should_be_3 = list->length; 

    sll_pop(list, 0);
    unsigned long should_be_2 = list->length; 

    sll_pop(list, 0);
    unsigned long should_be_1 = list->length; 

    sll_pop(list, 0);
    unsigned long should_be_0 = list->length; 

    sll_pop(list, 0);
    unsigned long should_still_be_0 = list->length; 

    if(should_be_3 != 3 || should_be_2 != 2 || should_be_1 != 1 || should_be_0 != 0 || should_still_be_0 != 0){
        free_everything(list, cars, 4);
        return 0; 
    }

    sll_push(list, &c1);
    sll_push(list, &c2);
    sll_push(list, &c3);
    sll_push(list, &c4);

    // assert reach pop returns a node with the correct value when 1 is passed to return_item
    car *c_from_list;
    for(int i = 3; i >=0; i--){
        c_from_list = sll_pop(list, 1);
        if(c_from_list->weight != cars[i].weight || strcmp(c_from_list->color, cars[i].color) != 0){
            return 0; 
        }
    }

    free_everything(list, cars, 4);
    return 1; 
}


char sll_unshift_prepends_node(){
    sll *list = create_sll(add_for_car, delete_for_car); 

    
    car c1, c2, c3, c4; 
    c1.weight = 1.2; 
    c2.weight = 2.3; 
    c3.weight = 3.4;
    c4.weight = 41.2;

    c1.color = malloc(sizeof(char) * 4);
    strcpy(c1.color, "red");
    c2.color = malloc(sizeof(char) * 4);
    strcpy(c2.color, "blue");
    c3.color = malloc(sizeof(char) * 6);
    strcpy(c3.color, "green");
    c4.color = malloc(sizeof(char) * 5);
    strcpy(c4.color, "gray");
    
    car prepended_car; 
    prepended_car.weight = -21; 
    prepended_car.color = malloc(sizeof(char) * 6);
    strcpy(prepended_car.color, "white");
    

    // prepended car will be added to the array but not the sll until later
    car cars[5] = {prepended_car, c1, c2, c3, c4};
    for(int i = 1; i < 5; i++){
        sll_push(list, &cars[i]);
    }

    sll_unshift(list, &prepended_car);

    // assert length is 5
    if(list->length != 5){
        free_everything(list, cars, 5);
        return 0;
    }

    // assert they all have the correct values
    for(int i = 0; i < 5; i++){
        car *retrieved = sll_get(list, i);
        if(retrieved->weight != cars[i].weight){
            free_everything(list, cars, 5);
            return 0;
        }
        if(strcmp(retrieved->color, cars[i].color) != 0){
            free_everything(list, cars, 5);
            return 0;
        }
    }

    free_everything(list, cars, 5);
    return 1;
}

char sll_inserts_correctly(){
    sll *list = create_sll(add_for_car, delete_for_car); 
 
   car c1, c2, c3, c4; 
    c1.weight = 1.2; 
    c2.weight = 2.3; 
    c3.weight = 3.4;
    c4.weight = 41.2;

    c1.color = malloc(sizeof(char) * 4);
    strcpy(c1.color, "red");
    c2.color = malloc(sizeof(char) * 4);
    strcpy(c2.color, "blue");
    c3.color = malloc(sizeof(char) * 6);
    strcpy(c3.color, "green");
    c4.color = malloc(sizeof(char) * 5);
    strcpy(c4.color, "gray");
    
    car inserted_car; 
    inserted_car.weight = -21; 
    inserted_car.color = malloc(sizeof(char) * 6);
    strcpy(inserted_car.color, "white");
    

    // inserted_car will be added to the array but not the sll until later
    car cars[5] = {c1, c2, inserted_car, c3, c4};
    for(int i = 0; i < 5; i++){
        if(i == 2){
            continue;
        }
        sll_push(list, &cars[i]);
    }

    sll_insert(list, 2, &inserted_car);

    // assert length is correct
    if(list->length != 5){
        free_everything(list, cars, 5);
        return 0;
    }

    // assert all the values are correct
    for(int i = 0; i < 5; i++){
        car *retrieved = sll_get(list, i); 
        if(retrieved->weight != cars[i].weight){
            free_everything(list, cars, 5);
            return 0; 
        }

        if(strcmp(retrieved->color, cars[i].color) != 0){
            free_everything(list, cars, 5);
            return 0;
        }
    }


    free_everything(list, cars, 5);
    return 1; 
}


char sll_shift_deletes_first_node(){
    sll *list = create_sll(add_for_car, delete_for_car);

    car c1, c2, c3, c4; 
    c1.weight = 1.2; 
    c2.weight = 2.3; 
    c3.weight = 3.4;
    c4.weight = 41.2;

    c1.color = malloc(sizeof(char) * 4);
    strcpy(c1.color, "red");
    c2.color = malloc(sizeof(char) * 4);
    strcpy(c2.color, "blue");
    c3.color = malloc(sizeof(char) * 6);
    strcpy(c3.color, "green");
    c4.color = malloc(sizeof(char) * 5);
    strcpy(c4.color, "gray");

    sll_push(list, &c1);
    sll_push(list, &c2);
    sll_push(list, &c3);
    sll_push(list, &c4);

    car cars[4] = {c1, c2, c3, c4};

    // assert removes first node and second node is new head
    sll_shift(list);
    car *head_car = list->head->value; 
    if(head_car->weight != c2.weight || strcmp(head_car->color, c2.color) != 0 || list->length != 3){
        free_everything(list, cars, 4);
        return 0; 
    }

    // assert it will empty it to length 0
    sll_shift(list);
    sll_shift(list);
    sll_shift(list);

    if(list->length != 0){
        free_everything(list, cars, 4);
        return 0;
    }

    free_everything(list, cars, 4);
    return 1; 

}


char sll_delete_deletes_from_middle(){
     sll *list = create_sll(add_for_car, delete_for_car); 
 
    car c1, c2, c3, c4; 
    c1.weight = 1.2; 
    c2.weight = 2.3; 
    c3.weight = 3.4;
    c4.weight = 41.2;


    c1.color = malloc(sizeof(char) * 4);
    strcpy(c1.color, "red");
    c2.color = malloc(sizeof(char) * 4);
    strcpy(c2.color, "blue");
    c3.color = malloc(sizeof(char) * 6);
    strcpy(c3.color, "green");
    c4.color = malloc(sizeof(char) * 5);
    strcpy(c4.color, "gray");   

    sll_push(list, &c1);
    sll_push(list, &c2);
    sll_push(list, &c3);
    sll_push(list, &c4);

    sll_delete(list, 2); 
    car *car_at_2 = sll_get(list, 2); 
    char result = 1;
    // assert correct length and the new node at 2 is as anticipated
    if(list->length != 3 || car_at_2->weight != c4.weight || strcmp(car_at_2->color, c4.color) != 0){
        result = 0; 
    }

    free(c1.color);
    free(c2.color);
    free(c3.color);
    free(c4.color);
    destroy_sll(list);
    return result; 
}

void test_for_each_callback(void *value, unsigned long index){
    ((car*)value)->weight = 100.000; 
    strcpy(((car*)value)->color, "white"); 
}

char sll_for_each_test(){
    sll *list = create_sll(add_for_car, delete_for_car); 
 
    car c1, c2, c3, c4; 
    c1.weight = 1.2; 
    c2.weight = 2.3; 
    c3.weight = 3.4;
    c4.weight = 41.2;


    c1.color = malloc(sizeof(char) * 4);
    strcpy(c1.color, "red");
    c2.color = malloc(sizeof(char) * 4);
    strcpy(c2.color, "blue");
    c3.color = malloc(sizeof(char) * 6);
    strcpy(c3.color, "green");
    c4.color = malloc(sizeof(char) * 5);
    strcpy(c4.color, "gray");   

    sll_push(list, &c1);
    sll_push(list, &c2);
    sll_push(list, &c3);
    sll_push(list, &c4);


    car cars[4] = {c1, c2, c3, c4};


    // change nodes with sll_for_each
    sll_for_each(list, test_for_each_callback);

    for(int i = 0; i < 4; i++){
        car * c = sll_get(list, i);
        if(c->weight != 100.000 || strcmp(c->color, "white") != 0){
            free_everything(list, cars, 4);
            return 0; 
        }
    }


    free_everything(list, cars, 4);
    return 1;
}




void *sll_test_reduce_helper(void *current, void *accumulator, unsigned long index){
    *(float *)accumulator += (*(car *)current).weight;
    return accumulator;
}

char sll_test_reduce(){
    sll *list = create_sll(add_for_car, delete_for_car); 
 
    car c1, c2, c3, c4; 
    c1.weight = 12; 
    c2.weight = 23; 
    c3.weight = 34;
    c4.weight = 41;


    c1.color = malloc(sizeof(char) * 4);
    strcpy(c1.color, "red");
    c2.color = malloc(sizeof(char) * 4);
    strcpy(c2.color, "blue");
    c3.color = malloc(sizeof(char) * 6);
    strcpy(c3.color, "green");
    c4.color = malloc(sizeof(char) * 5);
    strcpy(c4.color, "gray");   
    car cars[4] = {c1, c2, c3, c4};

    sll_push(list, &c1);
    sll_push(list, &c2);
    sll_push(list, &c3);
    sll_push(list, &c4);

    float sum = 0; 
    sum = *(float *)sll_reduce(list, sll_test_reduce_helper, &sum);
    
    char result = 1; 
    if(sum != 110.000){
        result = 0;
    }

    free_everything(list, cars, 4);
    return result;
}

    

void *sll_test_sll_map_helper_callback(void *current, unsigned long index){
    void *weight = malloc(sizeof(float *));
    *(float *)weight = (*(car *)current).weight;
    return weight;
}

char sll_test_sll_map(){
    sll *list = create_sll(add_for_car, delete_for_car); 
 
    car c1, c2, c3, c4; 
    c1.weight = 12; 
    c2.weight = 23; 
    c3.weight = 34;
    c4.weight = 41;


    c1.color = malloc(sizeof(char) * 4);
    strcpy(c1.color, "red");
    c2.color = malloc(sizeof(char) * 4);
    strcpy(c2.color, "blue");
    c3.color = malloc(sizeof(char) * 6);
    strcpy(c3.color, "green");
    c4.color = malloc(sizeof(char) * 5);
    strcpy(c4.color, "gray");   
    car cars[4] = {c1, c2, c3, c4};

    sll_push(list, &c1);
    sll_push(list, &c2);
    sll_push(list, &c3);
    sll_push(list, &c4);

    sll *new_list = sll_map(list, sll_test_sll_map_helper_callback, sll_add_for_float, NULL); 

    float sum = 0; 
    for(int i = 0; i < 4; i++){
        float *weight = sll_get(new_list, i); 
        sum += *weight;
    }

    char result = 1;
    if(sum != 110.000){
        result = 0; 
    }

    free_everything(list, cars, 4);
    destroy_sll(new_list);
    return result;

}