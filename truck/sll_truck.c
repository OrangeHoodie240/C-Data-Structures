#include "truck.h"
#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include "sll_truck.h"


sll_truck *create_sll_truck(){
    sll_truck *list = malloc(sizeof(sll_truck));
    if(list == NULL){
        printf("\nError\n");
        exit(1);
    } 
    list->head = NULL; 
    list->tail = NULL; 
    list->length = 0; 
    return list; 
}

unsigned long sll_truck_push(sll_truck *list, truck truck){
    sll_truck_node *next; 
    next = malloc(sizeof(sll_truck_node)); 
    next->value = truck; 

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

truck *sll_truck_pop(sll_truck *list, char return_item){
    truck *result = NULL; 
    if(list->length == 0){
        return result; 
    }
    
    if(list->head == list->tail){
        if(return_item == 0){
            delete_function(list->head->value);
        }
        else{
            result = &(list->head->value); 
        }

        free(list->head);

        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_truck_node *cur = list->head; 
        while(cur->next != list->tail){
            cur = cur->next; 
        }

        if(return_item == 0){
            delete_function(cur->next->value);
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




truck *sll_truck_get(sll_truck *list, unsigned long index){
    if(list->length - 1 < index){
        return NULL; 
    }

    sll_truck_node *cur_node = list->head; 
    unsigned long cur_ind = 0;  
    while(cur_ind < index){
        cur_node = cur_node->next; 
        cur_ind++; 
    }

    return &(cur_node->value); 
}


void destroy_sll_truck(sll_truck *list){
    if(list->length == 0){
        free(list); 
        return;
    }

    sll_truck_node *collection[list->length]; 

    sll_truck_node *cur = list->head; 
    collection[0] = cur;
    for(unsigned long i = 1; i < list->length; i++){
        collection[i] = cur->next; 
        cur = cur->next; 
    }


    for(unsigned long i = list->length - 1; i > 0; i--){
        cur = collection[i]; 
        delete_function(cur->value);
        free(cur->next); 
    }

    cur = collection[0];
    if(cur != NULL){
        free(cur->next); 
        delete_function(cur->value);
        free(cur); 
    }

    free(list); 
}

unsigned long sll_truck_unshift(sll_truck *list, truck item){
    sll_truck_node *new_node = malloc(sizeof(sll_truck_node));
    new_node->value = item; 
    sll_truck_node *prev_head = list->head; 
    list->head = new_node; 
    new_node->next = prev_head; 

    list->length += 1; 
    return list->length;
}


void sll_truck_insert(sll_truck *list, unsigned long index, truck item){
    if(index > list->length){
        return; 
    }
    else if(index == list->length){
        sll_truck_push(list, item);
        return;
    }
    else if(index == 0){
        sll_truck_unshift(list, item); 
        return;
    }

    sll_truck_node *new_node = malloc(sizeof(sll_truck_node)); 
    new_node->value = item;
    sll_truck_node *node_before = list->head; 
    for(int i = 1; i < index; i++){
        node_before = node_before->next;
    }

    new_node->next = node_before->next; 
    node_before->next = new_node;

    list->length += 1; 
}

void sll_truck_shift(sll_truck *list){
    if(list->length == 0) {
        return; 
    }
    
    delete_function(list->head->value); 

    if(list->length == 1){
        free(list->head);
        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_truck_node *original_head = list->head; 
        list->head = list->head->next;         

        free(original_head);
    }

    list->length -= 1; 
}


void sll_truck_delete(sll_truck *list, unsigned long index){
    if(index == list->length - 1){
        sll_truck_pop(list, 0);
    }
    else if(index >= list->length){
        return; 
    }
    else if(index == 0){
        sll_truck_shift(list); 
    }

    sll_truck_node *node_before = list->head; 
    unsigned long i = 0; 
    while(i != index - 1){
        node_before = node_before->next; 
        i++;
    }
    
    sll_truck_node *target_node = node_before->next; 
    node_before->next = target_node->next; 
    delete_function(target_node->value); 
    free(target_node);
    
    list->length -=1; 
}


void sll_truck_for_each(sll_truck *list, void (*f)(truck *value, unsigned long index)){
    if(list->head == NULL){
        return;
    }

    sll_truck_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        f(&(cur->value), index); 
        cur = cur->next;
        index++; 
    }
}



void *sll_truck_reduce(sll_truck *list, void * (*f)(truck current, void *accumulator, unsigned long index),  void *accumulator){
    if(list->length == 0){
        return accumulator;
    }

    sll_truck_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        accumulator = f(cur->value, accumulator, index); 
        cur = cur->next;
        index++; 
    }

    return accumulator; 
}


sll_truck *sll_truck_map(sll_truck *list, truck (*callback)(truck current, unsigned long index)){
    if(list->length == 0) {
        return NULL;
    }
    
    sll_truck *new_list = create_sll_truck();

    sll_truck_node *cur = list->head; 
    unsigned long index = 0;

    while(cur != NULL){
        sll_truck_push(new_list, callback(cur->value, index));
        cur = cur->next;
        index++;
    }

    return new_list;
}




// returns direct pointer to item
// does not return copy
truck *sll_truck_find(sll_truck *list, truck *(callback)(truck *value)){
    if(list->length == 0){
        return NULL; 
    }
    sll_truck_node *cur = list->head; 
    unsigned long index = 0;
    
    truck *item = NULL;  
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

