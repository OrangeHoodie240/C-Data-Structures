#include "sll_uchar.h"
#include <stdio.h>

typedef struct loaded_data {
    sll_uchar *list; 
    unsigned char array[5];
} loaded_data; 


static loaded_data get_data(){
    loaded_data data;
    data.array[0] = 1; 
    data.array[1] = 15; 
    data.array[2] = 3; 
    data.array[3] = 5; 
    data.array[4] = 9; 

    sll_uchar *list = create_sll_uchar(); 
    for(int i = 0; i < 5; i++){
        sll_uchar_push(list, data.array[i]);
    }
    data.list = list; 
    return data; 
}


char sll_uchar_push_appends_node(){
    loaded_data data = get_data(); 
    unsigned char result = 1; 

    sll_uchar_push(data.list, 77); 
    

    unsigned char value = sll_uchar_pop(data.list);
    if(value != 77){
        printf("\nFailed testing popped value equals value we just pushed\n");
        result = 0;        
    }

    destroy_sll_uchar(data.list);
    return result;
}


char sll_uchar_pop_returns_and_removes_node(){
    loaded_data data = get_data(); 
    unsigned char result = 1; 

    unsigned long length = 5; 
    for(int i = 0; i < 5; i++){
        unsigned char value = sll_uchar_pop(data.list);
        if(data.list->length != length - 1){
            printf("\nFailed testing length after pop\n");
            result = 0; 
            break;
        }
        if(data.array[4 - i] != value){
            printf("\nFailed testing popped value equals expected value\n");
            result = 0;
            break;
        }

        length -= 1; 
    }       


    destroy_sll_uchar(data.list);
    return result;
}


char sll_uchar_test_sll_uchar_get(){
    loaded_data data = get_data(); 
    unsigned char result = 1; 

    unsigned char value = sll_uchar_get(data.list, 3);

    if(value != 5.0){
        printf("\nFailed value from get being as expected\n");
        result = 0;
    }

    destroy_sll_uchar(data.list);
    return result;
}


char sll_uchar_test_sll_uchar_unshift(){
    loaded_data data = get_data(); 
    unsigned char result = 1; 

    sll_uchar_unshift(data.list, 21);
    if(data.list->length != 6){
        printf("Failed list.length being the expected value");
        result = 0; 
    }

    unsigned char value = sll_uchar_get(data.list, 0); 
    if(result && value != 21){
        printf("Failed the first node having the correct value from unshift");
        result = 0;
    }

    destroy_sll_uchar(data.list);
    return result;
}

char sll_uchar_test_sll_uchar_shift(){
    loaded_data data = get_data(); 
    unsigned char result = 1; 

    sll_uchar_shift(data.list);
    if(data.list->length != 4){
        printf("Failed list.length being the expected value");
        result = 0; 
    }

    unsigned char value = sll_uchar_get(data.list, 0); 
    if(result && value != 15){
        printf("Failed the first node having the correct value from shift");
        result = 0;
    }

    destroy_sll_uchar(data.list);
    return result;
}


char sll_uchar_test_sll_uchar_insert(){
    loaded_data data = get_data(); 
    unsigned char result = 1; 

    sll_uchar_insert(data.list, 2, 68);
    unsigned char value = sll_uchar_get(data.list, 2); 

    if(data.list->length != 6){
        printf("\nFailed to get expected list length\n"); 
        result = 0; 
    }

    if(value != 68){
        printf("\nFailed inserted value being as expected upon retrieval\n"); 
        result = 0; 
    }

    destroy_sll_uchar(data.list);
    return result;
}


char sll_uchar_test_sll_uchar_delete(){
    loaded_data data = get_data(); 
    unsigned char result = 1; 

    sll_uchar_delete(data.list, 2); 

    if(data.list->length != 4){
        printf("\nFailed to get expected list length\n"); 
        result = 0; 
    }

    unsigned char value = sll_uchar_get(data.list, 2);
    if(value != 5){
        printf("\nFailed inserted value being as expected upon retrieval\n"); 
        result = 0; 
    }

    destroy_sll_uchar(data.list);
    return result;
}


static unsigned char test_data[5] = {1, 15, 3, 5, 9};
static unsigned char test_for_each_result;
void sll_uchar_for_each_test_helper(char item, unsigned long index){
    if(item != test_data[index]){
        printf("\nWas expecting %d but got %d\n", test_data[index], item);
        test_for_each_result = 0; 
    }
}

char sll_uchar_test_sll_uchar_for_each(){
    loaded_data data = get_data(); 
    test_for_each_result = 1; 

    sll_uchar_for_each(data.list, sll_uchar_for_each_test_helper);

    destroy_sll_uchar(data.list);
    return test_for_each_result;
}

unsigned char sll_uchar_map_test_helper(char current, unsigned long index){
    return current * 2; 
}

char sll_uchar_test_sll_uchar_map(){
    loaded_data data = get_data(); 
    unsigned char result = 1; 

    sll_uchar *new_list = sll_uchar_map(data.list, sll_uchar_map_test_helper);

    for(unsigned long i = 0; i < 5; i++){
        if(sll_uchar_get(data.list, i) * 2 != sll_uchar_get(new_list, i)){
            printf("\nComparison between item in list * 2 and item in map failed \n");
            result = 0; 
            break;
        }
    }
    destroy_sll_uchar(data.list);
    destroy_sll_uchar(new_list);
    return result;
}

void *sll_uchar_test_sll_uchar_reduce_helper(char value, void *accumulator, unsigned long index){
    *(char *)accumulator += value; 
    return accumulator;
}
char sll_uchar_test_sll_uchar_reduce(){
    loaded_data data = get_data(); 
    unsigned char result = 1;

    unsigned char sum = 0;
    sum = *(char *)sll_uchar_reduce(data.list, sll_uchar_test_sll_uchar_reduce_helper, &sum);
    if(sum != 33){
        printf("\nFailed summed value being expected\n");
        result = 0;
    }

    destroy_sll_uchar(data.list);
    return result;
}

char sll_uchar_test_sll_uchar_find(){
    loaded_data data = get_data(); 
    unsigned char result = 1;

    if(sll_uchar_find(data.list, 3) != 2){
        printf("\nFailed returning wrong index value\n");
        result = 0; 
    }
    else if(sll_uchar_find(data.list, 58) != -1){
        printf("\nFailed saying we had an element we didn't\n");
        result = 0; 
    }

    destroy_sll_uchar(data.list);
    return result;
}




