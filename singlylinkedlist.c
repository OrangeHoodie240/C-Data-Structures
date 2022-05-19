#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 

typedef struct singly_linked_list_node {
    struct singly_linked_list_node *next; 
    void *value; 
} singly_linked_list_node; 


typedef struct singly_linked_list {
    singly_linked_list_node *head; 
    singly_linked_list_node *tail; 
    unsigned long length; 
    void (*add_function)(singly_linked_list_node *node, void *value); 
    void (*delete_function)(singly_linked_list_node *node); 
} singly_linked_list; 


// singly_linked_list will take two functions arguments. The 2nd can be NULL if our type 

// void add_function(singly_linked_list_node *node, void value*)
//      takes node pointer and value void pointer for the node value. 
//      What we need to do is set the node value to the value of the void pointer
//      to do this we need to cast to the correct type for the void pointer 
//      if the type is a struct with members on the heap we need to 
//          1. create location on the heap and copy the values from those members. 
//          2. Set the pointer members to the address of these new locations

// void delete_function(singly_linked_list_node * node)
//      we pass when our value type has members on the heap that need to be freed. 
//      When our type does not have members on the heap we pass NULL
//      Inside we: 
//          1. we pass node->value->member_name to free() for each member that is on the heap
//          2. pass node-value to free() at the end of the function.

singly_linked_list *create_singly_linked_list(void (*f)(singly_linked_list_node *node, void *value), void (*g)(singly_linked_list_node * node)){
    singly_linked_list *list = malloc(sizeof(singly_linked_list));
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

unsigned long singly_linked_list_push(singly_linked_list *list, void *item){
    singly_linked_list_node *next; 
    next = malloc(sizeof(singly_linked_list_node)); 

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

unsigned long singly_linked_list_pop(singly_linked_list *list){
    if(list->length == 0){
        return 0; 
    }
    
    if(list->head == list->tail){
        if(list->delete_function != NULL){
            list->delete_function(list->head);
        }
        else{
            free(list->head->value);
        }
        free(list->head);
        list->head = NULL; 
        list->tail = NULL;
    }
    else{
        singly_linked_list_node *cur = list->head; 
        while(cur->next != list->tail){
            cur = cur->next; 
        }

        if(list->delete_function != NULL){
            list->delete_function(cur->next); 
        }
        else{
            free(cur->next->value); 
        }
        free(cur->next); 
        cur->next = NULL; 
        list->tail = cur; 
    }
    
    list->length--; 
    return list->length;
}




void *singly_linked_list_get(singly_linked_list *list, unsigned long index){
    if(list->length - 1 < index){
        return NULL; 
    }

    singly_linked_list_node *cur_node = list->head; 
    unsigned long cur_ind = 0;  
    while(cur_ind < index){
        cur_node = cur_node->next; 
        cur_ind++; 
    }

    return cur_node->value; 
}


void destroy_singly_linked_list(singly_linked_list *list){
    if(list->length == 0){
        free(list); 
        return;
    }

    singly_linked_list_node *collection[list->length]; 

    singly_linked_list_node *cur = list->head; 
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

typedef struct car {
    char *color; 
    float weight; 
} car;

