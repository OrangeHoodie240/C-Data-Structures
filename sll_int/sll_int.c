#include "sll_int.h"
#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 


sll_int *create_sll_int(){
    sll_int *list = malloc(sizeof(sll_int));
    if(list == NULL){
        printf("\nError\n");
        exit(1);
    } 
    list->head = NULL; 
    list->tail = NULL; 
    list->length = 0; 
    return list; 
}

unsigned long sll_int_push(sll_int *list, int item){
    sll_int_node *next; 
    next = malloc(sizeof(sll_int_node)); 
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

int sll_int_pop(sll_int *list){
    if(list->length == 0){
        printf("Error! used pop on an empty sll_int");
        exit(1); 
    }
    
    int result; 

    if(list->head == list->tail){
        result = list->head->value; 
        free(list->head);
        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_int_node *cur = list->head; 
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




int sll_int_get(sll_int *list, unsigned long index){
    if(list->length - 1 < index){
        printf("out of bounds error sll_get"); 
        exit(1); 
    }

    sll_int_node *cur_node = list->head; 
    unsigned long cur_ind = 0;  
    while(cur_ind < index){
        cur_node = cur_node->next; 
        cur_ind++; 
    }

    return cur_node->value; 
}


void destroy_sll_int(sll_int *list){
    if(list->length == 0){
        free(list); 
        return;
    }

    sll_int_node *collection[list->length]; 

    sll_int_node *cur = list->head; 
    sll_int_node *hold; 
    while(cur != NULL){
        hold = cur->next; 
        free(cur); 
        cur = hold;
    }

    free(list); 
}

unsigned long sll_int_unshift(sll_int *list, int item){
    sll_int_node *new_node = malloc(sizeof(sll_int_node));
    new_node->value = item;    
    sll_int_node *prev_head = list->head; 
    list->head = new_node; 
    new_node->next = prev_head; 

    list->length += 1; 
    return list->length;
}


void sll_int_insert(sll_int *list, unsigned long index, int item){
    if(index > list->length){
        return; 
    }
    else if(index == list->length){
        sll_int_push(list, item);
        return;
    }
    else if(index == 0){
        sll_int_unshift(list, item); 
        return;
    }

    sll_int_node *new_node = malloc(sizeof(sll_int_node)); 
    new_node->value = item;

    sll_int_node *node_before = list->head; 
    for(int i = 1; i < index; i++){
        node_before = node_before->next;
    }

    new_node->next = node_before->next; 
    node_before->next = new_node;

    list->length += 1; 
}

void sll_int_shift(sll_int *list){
    if(list->length == 0) {
        return; 
    }

    if(list->length == 1){
        free(list->head);
        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_int_node *original_head = list->head; 
        list->head = list->head->next;         

        free(original_head);
    }

    list->length -= 1; 
}


void sll_int_delete(sll_int *list, unsigned long index){
    if(index == list->length - 1){
        sll_int_pop(list);
    }
    else if(index >= list->length){
        return; 
    }
    else if(index == 0){
        sll_int_shift(list); 
    }

    sll_int_node *node_before = list->head; 
    unsigned long i = 0; 
    while(i != index - 1){
        node_before = node_before->next; 
        i++;
    }
    
    sll_int_node *target_node = node_before->next; 
    node_before->next = target_node->next; 
    free(target_node);
    
    list->length -=1; 
}


void sll_int_for_each(sll_int *list, void (*f)(int value, unsigned long index)){
    if(list->head == NULL){
        return;
    }

    sll_int_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        f(cur->value, index); 
        cur = cur->next;
        index++; 
    }
}



void *sll_int_reduce(sll_int *list, void * (*f)(int value, void *accumulator, unsigned long index),  void *accumulator){
    if(list->length == 0){
        return accumulator;
    }

    sll_int_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        accumulator = f(cur->value, accumulator, index); 
        cur = cur->next;
        index++; 
    }

    return accumulator; 
}


sll_int *sll_int_map(sll_int *list, int (*callback)(int current, unsigned long index)){
    if(list->length == 0) {
        return NULL;
    }
    
    sll_int *new_list = create_sll_int();

    sll_int_node *cur = list->head; 
    unsigned long index = 0;

    while(cur != NULL){
        sll_int_push(new_list, callback(cur->value, index));
        cur = cur->next;
        index++;
    }

    return new_list;
}

unsigned long sll_int_find(sll_int *list, int target){
    if(list->length == 0){
        return 0; 
    }
    sll_int_node *cur = list->head; 
    

    unsigned long index = -1;
    unsigned long list_length = list->length;
    for(unsigned long i = 0; i < list_length; i++){
        if(cur->value == target){
            index = i; 
            break;
        }

        cur = cur->next;
    } 

    return index; 
}

