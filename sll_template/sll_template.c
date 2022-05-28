#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include "sll_template.h"
#include "car.h"

static void sll_car_delete_function(car value){
    free(value.color);
}

sll_car *create_sll_car(){
    sll_car *list = malloc(sizeof(sll_car));
    if(list == NULL){
        printf("\nError\n");
        exit(1);
    } 
    list->head = NULL; 
    list->tail = NULL; 
    list->length = 0; 
    return list; 
}

unsigned long sll_car_push(sll_car *list, car car){
    sll_car_node *next; 
    next = malloc(sizeof(sll_car_node)); 
    next->value = car; 

    next->next = NULL; 
    if(list->head == NULL){
        list->head = next; 
        list->tail = next; 
    }
    else{
        list->tail->next = next; 
        list->tail = next; 
    }

    list->length += 1; 
    return list->length; 
}

car *sll_car_pop(sll_car *list, char return_item){
    car *result = NULL; 
    if(list->length == 0){
        return result; 
    }
    
    if(list->head == list->tail){
        if(return_item == 0){
            sll_car_delete_function(list->head->value);
        }
        else{
            result = &(list->head->value); 
        }

        free(list->head);

        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_car_node *cur = list->head; 
        while(cur->next != list->tail){
            cur = cur->next; 
        }

        if(return_item == 0){
            sll_car_delete_function(cur->next->value);
        }
        else{
            result = &(cur->next->value); 
        }

        free(cur->next); 
        cur->next = NULL; 
        list->tail = cur; 
    }
    
    list->length--; 
    return result;
}




car *sll_car_get(sll_car *list, unsigned long index){
    if(list->length - 1 < index){
        return NULL; 
    }

    sll_car_node *cur_node = list->head; 
    unsigned long cur_ind = 0;  
    while(cur_ind < index){
        cur_node = cur_node->next; 
        cur_ind++; 
    }

    return &(cur_node->value); 
}


void destroy_sll_car(sll_car *list){
    if(list->length == 0){
        free(list); 
        return;
    }

    sll_car_node *collection[list->length]; 

    sll_car_node *cur = list->head; 
    collection[0] = cur;
    for(unsigned long i = 1; i < list->length; i++){
        collection[i] = cur->next; 
        cur = cur->next; 
    }


    for(unsigned long i = list->length - 1; i > 0; i--){
        cur = collection[i]; 
        sll_car_delete_function(cur->value);
        free(cur->next); 
    }

    cur = collection[0];
    if(cur != NULL){
        free(cur->next); 
        sll_car_delete_function(cur->value);
        free(cur); 
    }

    free(list); 
}

unsigned long sll_car_unshift(sll_car *list, car item){
    sll_car_node *new_node = malloc(sizeof(sll_car_node));
    new_node->value = item; 
    sll_car_node *prev_head = list->head; 
    list->head = new_node; 
    new_node->next = prev_head; 

    list->length += 1; 
    return list->length;
}


void sll_car_insert(sll_car *list, unsigned long index, car item){
    if(index > list->length){
        return; 
    }
    else if(index == list->length){
        sll_car_push(list, item);
        return;
    }
    else if(index == 0){
        sll_car_unshift(list, item); 
        return;
    }

    sll_car_node *new_node = malloc(sizeof(sll_car_node)); 
    new_node->value = item;
    sll_car_node *node_before = list->head; 
    for(int i = 1; i < index; i++){
        node_before = node_before->next;
    }

    new_node->next = node_before->next; 
    node_before->next = new_node;

    list->length += 1; 
}

void sll_car_shift(sll_car *list){
    if(list->length == 0) {
        return; 
    }
    
    sll_car_delete_function(list->head->value); 

    if(list->length == 1){
        free(list->head);
        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_car_node *original_head = list->head; 
        list->head = list->head->next;         

        free(original_head);
    }

    list->length -= 1; 
}


void sll_car_delete(sll_car *list, unsigned long index){
    if(index == list->length - 1){
        sll_car_pop(list, 0);
    }
    else if(index >= list->length){
        return; 
    }
    else if(index == 0){
        sll_car_shift(list); 
    }

    sll_car_node *node_before = list->head; 
    unsigned long i = 0; 
    while(i != index - 1){
        node_before = node_before->next; 
        i++;
    }
    
    sll_car_node *target_node = node_before->next; 
    node_before->next = target_node->next; 
    sll_car_delete_function(target_node->value); 
    free(target_node);
    
    list->length -=1; 
}


void sll_car_for_each(sll_car *list, void (*f)(car *value, unsigned long index)){
    if(list->head == NULL){
        return;
    }

    sll_car_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        f(&(cur->value), index); 
        cur = cur->next;
        index++; 
    }
}



void *sll_car_reduce(sll_car *list, void * (*f)(car current, void *accumulator, unsigned long index),  void *accumulator){
    if(list->length == 0){
        return accumulator;
    }

    sll_car_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        accumulator = f(cur->value, accumulator, index); 
        cur = cur->next;
        index++; 
    }

    return accumulator; 
}


sll_car *sll_car_map(sll_car *list, car (*callback)(car current, unsigned long index)){
    if(list->length == 0) {
        return NULL;
    }
    
    sll_car *new_list = create_sll_car();

    sll_car_node *cur = list->head; 
    unsigned long index = 0;

    while(cur != NULL){
        sll_car_push(new_list, callback(cur->value, index));
        cur = cur->next;
        index++;
    }

    return new_list;
}




// returns direct pointer to item
// does not return copy
car *sll_car_find(sll_car *list, car *(callback)(car *value)){
    if(list->length == 0){
        return NULL; 
    }
    sll_car_node *cur = list->head; 
    unsigned long index = 0;
    
    car *item = NULL;  
    while(cur != NULL){
        item = callback(&(cur->value)); 
        if(item != NULL){
            break;
        }

        cur = cur->next;
        index++;
    }

    return item; 
}

