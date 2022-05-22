#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include "singlylinkedlist.h"


sll *create_sll(void (*f)(sll_node *node, void *value), void (*g)(sll_node * node)){
    sll *list = malloc(sizeof(sll));
    if(list == NULL){
        printf("\nError\n");
        exit(1);
    } 
    list->head = NULL; 
    list->tail = NULL; 
    list->length = 0; 
    list->add_function = f; 
    list->delete_function = g; 
    return list; 
}

unsigned long sll_push(sll *list, void *item){
    sll_node *next; 
    next = malloc(sizeof(sll_node)); 

    list->add_function(next, item); 

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

void * sll_pop(sll *list, char return_item){
    void * result = NULL; 
    if(list->length == 0){
        return result; 
    }
    
    if(list->head == list->tail){
        if(return_item == 0){
            if(list->delete_function != NULL){
                list->delete_function(list->head);
            }
            else{
                free(list->head->value);
            }
        }
        else{
            result = list->head->value; 
        }

        free(list->head);

        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        sll_node *cur = list->head; 
        while(cur->next != list->tail){
            cur = cur->next; 
        }

        if(return_item == 0){
            if(list->delete_function != NULL){
                list->delete_function(cur->next); 
            }
            else{
                free(cur->next->value); 
            }
        }
        else{
            result = cur->next->value; 
        }

        free(cur->next); 
        cur->next = NULL; 
        list->tail = cur; 
    }
    
    list->length--; 
    return result;
}




void *sll_get(sll *list, unsigned long index){
    if(list->length - 1 < index){
        return NULL; 
    }

    sll_node *cur_node = list->head; 
    unsigned long cur_ind = 0;  
    while(cur_ind < index){
        cur_node = cur_node->next; 
        cur_ind++; 
    }

    return cur_node->value; 
}


void destroy_sll(sll *list){
    if(list->length == 0){
        free(list); 
        return;
    }

    sll_node *collection[list->length]; 

    sll_node *cur = list->head; 
    collection[0] = cur;
    for(unsigned long i = 1; i < list->length; i++){
        collection[i] = cur->next; 
        cur = cur->next; 
    }

    for(unsigned long i = list->length - 1; i > 0; i--){
        cur = collection[i]; 
        if(list->delete_function != NULL){
            list->delete_function(cur);
        }
        else{
            free(cur->value); 
        }
        free(cur->next); 
    }

    cur = collection[0];
    if(cur != NULL){
        free(cur->next); 
        if(list->delete_function != NULL){
            list->delete_function(cur);
        }
        else{
            free(cur->value); 
        }
        free(cur); 
    }

    free(list); 
}

unsigned long sll_unshift(sll *list, void *item){
    sll_node *new_node = malloc(sizeof(sll_node));
    list->add_function(new_node, item); 
    
    sll_node *prev_head = list->head; 
    list->head = new_node; 
    new_node->next = prev_head; 

    list->length += 1; 
    return list->length;
}


void sll_insert(sll *list, unsigned long index, void *item){
    if(index > list->length){
        return; 
    }
    else if(index == list->length){
        sll_push(list, item);
        return;
    }
    else if(index == 0){
        sll_unshift(list, item); 
        return;
    }

    sll_node *new_node = malloc(sizeof(sll_node)); 
    list->add_function(new_node, item);

    sll_node *node_before = list->head; 
    for(int i = 1; i < index; i++){
        node_before = node_before->next;
    }

    new_node->next = node_before->next; 
    node_before->next = new_node;

    list->length += 1; 
}

void sll_shift(sll *list){
    if(list->length == 0) {
        return; 
    }
    
    if(list->delete_function != NULL){
        list->delete_function(list->head); 
    }
    else{
        free(list->head->value); 
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


void sll_delete(sll *list, unsigned long index){
    if(index == list->length - 1){
        sll_pop(list, 0);
    }
    else if(index >= list->length){
        return; 
    }
    else if(index == 0){
        sll_shift(list); 
    }

    sll_node *node_before = list->head; 
    unsigned long i = 0; 
    while(i != index - 1){
        node_before = node_before->next; 
        i++;
    }
    
    sll_node *target_node = node_before->next; 
    node_before->next = target_node->next; 
        
    if(list->delete_function != NULL){
        list->delete_function(target_node); 
    }
    else{
        free(target_node->value); 
    }    
    free(target_node);
    
    list->length -=1; 
}