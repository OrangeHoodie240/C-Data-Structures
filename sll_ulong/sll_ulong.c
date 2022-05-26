#include "sll_ulong.h"
#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 


sll_ulong *create_sll_ulong(){
    sll_ulong *list = malloc(sizeof(sll_ulong));
    if(list == NULL){
        printf("\nError\n");
        exit(1);
    } 
    list->head = NULL; 
    list->tail = NULL; 
    list->length = 0; 
    return list; 
}

unsigned long sll_ulong_push(sll_ulong *list, unsigned long item){
    sll_ulong_node *next; 
    next = malloc(sizeof(sll_ulong_node)); 
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

unsigned long sll_ulong_pop(sll_ulong *list){
    if(list->length == 0){
        printf("Error! used pop on an empty sll_ulong");
        exit(1); 
    }
    
    unsigned long result; 

    if(list->head == list->tail){
        result = list->head->value; 
        free(list->head);
        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_ulong_node *cur = list->head; 
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




unsigned long sll_ulong_get(sll_ulong *list, unsigned long index){
    if(list->length - 1 < index){
        printf("out of bounds error sll_get"); 
        exit(1); 
    }

    sll_ulong_node *cur_node = list->head; 
    unsigned long cur_ind = 0;  
    while(cur_ind < index){
        cur_node = cur_node->next; 
        cur_ind++; 
    }

    return cur_node->value; 
}


void destroy_sll_ulong(sll_ulong *list){
    if(list->length == 0){
        free(list); 
        return;
    }

    sll_ulong_node *collection[list->length]; 

    sll_ulong_node *cur = list->head; 
    sll_ulong_node *hold; 
    while(cur != NULL){
        hold = cur->next; 
        free(cur); 
        cur = hold;
    }

    free(list); 
}

unsigned long sll_ulong_unshift(sll_ulong *list, unsigned long item){
    sll_ulong_node *new_node = malloc(sizeof(sll_ulong_node));
    new_node->value = item;    
    sll_ulong_node *prev_head = list->head; 
    list->head = new_node; 
    new_node->next = prev_head; 

    list->length += 1; 
    return list->length;
}


void sll_ulong_insert(sll_ulong *list, unsigned long index, unsigned long item){
    if(index > list->length){
        return; 
    }
    else if(index == list->length){
        sll_ulong_push(list, item);
        return;
    }
    else if(index == 0){
        sll_ulong_unshift(list, item); 
        return;
    }

    sll_ulong_node *new_node = malloc(sizeof(sll_ulong_node)); 
    new_node->value = item;

    sll_ulong_node *node_before = list->head; 
    for(int i = 1; i < index; i++){
        node_before = node_before->next;
    }

    new_node->next = node_before->next; 
    node_before->next = new_node;

    list->length += 1; 
}

void sll_ulong_shift(sll_ulong *list){
    if(list->length == 0) {
        return; 
    }

    if(list->length == 1){
        free(list->head);
        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_ulong_node *original_head = list->head; 
        list->head = list->head->next;         

        free(original_head);
    }

    list->length -= 1; 
}


void sll_ulong_delete(sll_ulong *list, unsigned long index){
    if(index == list->length - 1){
        sll_ulong_pop(list);
    }
    else if(index >= list->length){
        return; 
    }
    else if(index == 0){
        sll_ulong_shift(list); 
    }

    sll_ulong_node *node_before = list->head; 
    unsigned long i = 0; 
    while(i != index - 1){
        node_before = node_before->next; 
        i++;
    }
    
    sll_ulong_node *target_node = node_before->next; 
    node_before->next = target_node->next; 
    free(target_node);
    
    list->length -=1; 
}


void sll_ulong_for_each(sll_ulong *list, void (*f)(unsigned long value, unsigned long index)){
    if(list->head == NULL){
        return;
    }

    sll_ulong_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        f(cur->value, index); 
        cur = cur->next;
        index++; 
    }
}



void *sll_ulong_reduce(sll_ulong *list, void * (*f)(unsigned long value, void *accumulator, unsigned long index),  void *accumulator){
    if(list->length == 0){
        return accumulator;
    }

    sll_ulong_node *cur = list->head; 
    unsigned long index = 0; 
    while(cur != NULL){
        accumulator = f(cur->value, accumulator, index); 
        cur = cur->next;
        index++; 
    }

    return accumulator; 
}


sll_ulong *sll_ulong_map(sll_ulong *list, unsigned long (*callback)(unsigned long current, unsigned long index)){
    if(list->length == 0) {
        return NULL;
    }
    
    sll_ulong *new_list = create_sll_ulong();

    sll_ulong_node *cur = list->head; 
    unsigned long index = 0;

    while(cur != NULL){
        sll_ulong_push(new_list, callback(cur->value, index));
        cur = cur->next;
        index++;
    }

    return new_list;
}

unsigned long sll_ulong_find(sll_ulong *list, unsigned long target){
    if(list->length == 0){
        return 0; 
    }
    sll_ulong_node *cur = list->head; 
    

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

