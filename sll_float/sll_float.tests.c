#include "sll_float.h"
#include <stdio.h>

typedef struct loaded_data {
    sll_float *list; 
    float array[5];
} loaded_data; 


static loaded_data get_data(){
    loaded_data data;
    data.array[0] = 11.0; 
    data.array[1] = 55.0; 
    data.array[2] = 33.0; 
    data.array[3] = 5.0; 
    data.array[4] = 99.0; 

    sll_float *list = create_sll_float(); 
    for(int i = 0; i < 5; i++){
        sll_float_push(list, data.array[i]);
    }
    data.list = list; 
    return data; 
}


char sll_float_push_appends_node(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_float_push(data.list, 77.0); 
    

    float value = sll_float_pop(data.list);
    if(value != 77.0){
        printf("\nFailed testing popped value equals value we just pushed\n");
        result = 0;        
    }

    destroy_sll_float(data.list);
    return result;
}


char sll_float_pop_returns_and_removes_node(){
    loaded_data data = get_data(); 
    char result = 1; 

    unsigned long length = 5; 
    for(int i = 0; i < 5; i++){
        float value = sll_float_pop(data.list);
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


    destroy_sll_float(data.list);
    return result;
}


char sll_float_test_sll_float_get(){
    loaded_data data = get_data(); 
    char result = 1; 

    float value = sll_float_get(data.list, 3);

    if(value != 5.0){
        printf("\nFailed value from get being as expected\n");
        result = 0;
    }

    destroy_sll_float(data.list);
    return result;
}


char sll_float_test_sll_float_unshift(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_float_unshift(data.list, 21.990);
    if(data.list->length != 6){
        printf("Failed list.length being the expected value");
        result = 0; 
    }

    float value = sll_float_get(data.list, 0); 
    if(result && value != 21.990000f){
        printf("Failed the first node having the correct value from unshift");
        result = 0;
    }

    destroy_sll_float(data.list);
    return result;
}

char sll_float_test_sll_float_shift(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_float_shift(data.list);
    if(data.list->length != 4){
        printf("Failed list.length being the expected value");
        result = 0; 
    }

    float value = sll_float_get(data.list, 0); 
    if(result && value != 55.0f){
        printf("Failed the first node having the correct value from shift");
        result = 0;
    }

    destroy_sll_float(data.list);
    return result;
}


char sll_float_test_sll_float_insert(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_float_insert(data.list, 2, 68.3);
    float value = sll_float_get(data.list, 2); 

    if(data.list->length != 6){
        printf("\nFailed to get expected list length\n"); 
        result = 0; 
    }

    if(value != 68.3f){
        printf("\nFailed inserted value being as expected upon retrieval\n"); 
        result = 0; 
    }

    destroy_sll_float(data.list);
    return result;
}


char sll_float_test_sll_float_delete(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_float_delete(data.list, 2); 

    if(data.list->length != 4){
        printf("\nFailed to get expected list length\n"); 
        result = 0; 
    }

    float value = sll_float_get(data.list, 2);
    if(value != 5.0f){
        printf("\nFailed inserted value being as expected upon retrieval\n"); 
        result = 0; 
    }

    destroy_sll_float(data.list);
    return result;
}


static float test_data[5] = {11.0, 55.0, 33.0, 5.0, 99.0};
static char test_for_each_result;
void sll_float_for_each_test_helper(float item, unsigned long index){
    if(item != test_data[index]){
        printf("\nWas expecting %f but got %f\n", test_data[index], item);
        test_for_each_result = 0; 
    }
}

char sll_float_test_sll_float_for_each(){
    loaded_data data = get_data(); 
    test_for_each_result = 1; 

    sll_float_for_each(data.list, sll_float_for_each_test_helper);

    destroy_sll_float(data.list);
    return test_for_each_result;
}

float sll_float_map_test_helper(float current, unsigned long index){
    return current * 2; 
}

char sll_float_test_sll_float_map(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_float *new_list = sll_float_map(data.list, sll_float_map_test_helper);

    for(unsigned long i = 0; i < 5; i++){
        if(sll_float_get(data.list, i) * 2 != sll_float_get(new_list, i)){
            printf("\nComparison between item in list * 2 and item in map failed \n");
            result = 0; 
            break;
        }
    }
    destroy_sll_float(data.list);
    destroy_sll_float(new_list);
    return result;
}

void *sll_float_test_sll_float_reduce_helper(float value, void *accumulator, unsigned long index){
    *(float *)accumulator += value; 
    return accumulator;
}
char sll_float_test_sll_float_reduce(){
    loaded_data data = get_data(); 
    char result = 1;

    float sum = 0;
    sum = *(float *)sll_float_reduce(data.list, sll_float_test_sll_float_reduce_helper, &sum);
    if(sum != 203.0f){
        printf("\nFailed summed value being expected\n");
        result = 0;
    }

    destroy_sll_float(data.list);
    return result;
}

char sll_float_test_sll_float_find(){
    loaded_data data = get_data(); 
    char result = 1;

    if(sll_float_find(data.list, 33.0f) != 2){
        printf("\nFailed returning wrong index value\n");
        result = 0; 
    }
    else if(sll_float_find(data.list, 58.211f) != -1){
        printf("\nFailed saying we had an element we didn't\n");
        result = 0; 
    }

    destroy_sll_float(data.list);
    return result;
}


/*
char sll_float_contains(sll_float *list, float target);
*/