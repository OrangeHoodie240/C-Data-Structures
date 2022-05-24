#include "sll_float.h"

#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 


sll_float *create_sll_float(){
    sll_float *list = malloc(sizeof(sll_float));
    if(list == NULL){
        printf("\nError\n");
        exit(1);
    } 
    list->head = NULL; 
    list->tail = NULL; 
    list->length = 0; 
    return list; 
}

unsigned long sll_float_push(sll_float *list, float item){
    sll_node *next; 
    next = malloc(sizeof(sll_node)); 
    next->value = item;

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

float sll_float_pop(sll_float *list){
    if(list->length == 0){
        printf("Error! used pop on an empty sll_float");
        exit(1); 
    }
    
    if(list->head == list->tail){
        result = list->head->value; 
        free(list->head);
        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_float_node *cur = list->head; 
        while(cur->next != list->tail){
            cur = cur->next; 
        }

        result = cur->next->value; 

        free(cur->next); 
        cur->next = NULL; 
        list->tail = cur; 
    }
    
    list->length--; 
    return result;
}




float sll_float_get(sll_float *list, unsigned long index){
    if(list->length - 1 < index){
        printf("out of bounds error sll_get"); 
        exit(1); 
    }

    sll_float_node *cur_node = list->head; 
    unsigned long cur_ind = 0;  
    while(cur_ind < index){
        cur_node = cur_node->next; 
        cur_ind++; 
    }

    return cur_node->value; 
}


void destroy_sll_float(sll_float *list){
    if(list->length == 0){
        free(list); 
        return;
    }

    sll_flot_node *collection[list->length]; 

    sll_float_node *cur = list->head; 
    sll_float_node *hold; 
    while(cur != NULL){
        hold = cur->next; 
        free(cur); 
        cur = hold;
    }

    free(list); 
}

unsigned long sll_float_unshift(sll *list, float item){
    sll_float_node *new_node = malloc(sizeof(sll_float_node));
    new_node->value = item;    
    sll_node *prev_head = list->head; 
    list->head = new_node; 
    new_node->next = prev_head; 

    list->length += 1; 
    return list->length;
}


void sll_insert(sll_float *list, unsigned long index, float item){
    if(index > list->length){
        return; 
    }
    else if(index == list->length){
        sll_float_push(list, item);
        return;
    }
    else if(index == 0){
        sll_float_unshift(list, item); 
        return;
    }

    sll_float_node *new_node = malloc(sizeof(sll_node)); 
    new_node->value = item;

    sll_float_node *node_before = list->head; 
    for(int i = 1; i < index; i++){
        node_before = node_before->next;
    }

    new_node->next = node_before->next; 
    node_before->next = new_node;

    list->length += 1; 
}

void sll_float_shift(sll_float *list){
    if(list->length == 0) {
        return; 
    }

    if(list->length == 1){
        free(list->head);
        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_node *original_head = list->head; 
        list->head = list->head->next;         

        free(original_head);
    }

    list->length -= 1; 
}


void sll_float_delete(sll_float *list, unsigned long index){
    if(index == list->length - 1){
        sll_float_pop(list, 0);
    }
    else if(index >= list->length){
        return; 
    }
    else if(index == 0){
        sll_float_shift(list); 
    }

    sll_float_node *node_before = list->head; 
    unsigned long i = 0; 
    while(i != index - 1){
        node_before = node_before->next; 
        i++;
    }
    
    sll_float_node *target_node = node_before->next; 
    node_before->next = target_node->next; 
    free(target_node);
    
    list->length -=1; 
}


void sll_float_for_each(sll_float *list, void (*f)(float value, unsigned long index)){
    if(list->head == NULL){
        return;
    }

    sll_float_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        f(cur->value, index); 
        cur = cur->next;
        index++; 
    }
}



void *sll_float_reduce(sll_float *list, void * (*f)(float value, void *accumulator, unsigned long index),  void *accumulator){
    if(list->length == 0){
        return accumulator;
    }

    sll_float_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        accumulator = f(cur->value, accumulator, index); 
        cur = cur->next;
        index++; 
    }

    return accumulator; 
}


sll *sll_map(sll_float *list, void *(*callback)(float current, unsigned long index)){
    if(list->length == 0) {
        return NULL;
    }
    
    sll_float *new_list = create_sll_float();

    sll_node_float *cur = list->head; 
    unsigned long index = 0;

    while(cur != NULL){
        sll_float_push(new_list, callback(cur->value, index));
        cur = cur->next;
        index++;
    }

    return new_list;
}



char sll_float_contains(sll_float *list, float target){
    if(list->length == 0){
        return 0; 
    }
    sll_float_node *cur = list->head; 
    
    char result = 0; 
    while(cur != NULL){
        if(cur->value == target){
            result = 1; 
            break;
        }

        cur = cur->next;
    }
    return result; 
}

