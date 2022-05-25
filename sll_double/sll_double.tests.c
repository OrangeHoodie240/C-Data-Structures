#include "sll_double.h"
#include <stdio.h>

typedef struct loaded_data {
    sll_double *list; 
    double array[5];
} loaded_data; 


static loaded_data get_data(){
    loaded_data data;
    data.array[0] = 11.0; 
    data.array[1] = 55.0; 
    data.array[2] = 33.0; 
    data.array[3] = 5.0; 
    data.array[4] = 99.0; 

    sll_double *list = create_sll_double(); 
    for(int i = 0; i < 5; i++){
        sll_double_push(list, data.array[i]);
    }
    data.list = list; 
    return data; 
}


char sll_double_push_appends_node(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_double_push(data.list, 77.0); 
    

    double value = sll_double_pop(data.list);
    if(value != 77.0){
        printf("\nFailed testing popped value equals value we just pushed\n");
        result = 0;        
    }

    destroy_sll_double(data.list);
    return result;
}


char sll_double_pop_returns_and_removes_node(){
    loaded_data data = get_data(); 
    char result = 1; 

    unsigned long length = 5; 
    for(int i = 0; i < 5; i++){
        double value = sll_double_pop(data.list);
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


    destroy_sll_double(data.list);
    return result;
}


char sll_double_test_sll_double_get(){
    loaded_data data = get_data(); 
    char result = 1; 

    double value = sll_double_get(data.list, 3);

    if(value != 5.0){
        printf("\nFailed value from get being as expected\n");
        result = 0;
    }

    destroy_sll_double(data.list);
    return result;
}


char sll_double_test_sll_double_unshift(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_double_unshift(data.list, 21.990);
    if(data.list->length != 6){
        printf("Failed list.length being the expected value");
        result = 0; 
    }

    double value = sll_double_get(data.list, 0); 
    if(result && value != 21.990000){
        printf("Failed the first node having the correct value from unshift");
        result = 0;
    }

    destroy_sll_double(data.list);
    return result;
}

char sll_double_test_sll_double_shift(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_double_shift(data.list);
    if(data.list->length != 4){
        printf("Failed list.length being the expected value");
        result = 0; 
    }

    double value = sll_double_get(data.list, 0); 
    if(result && value != 55.0){
        printf("Failed the first node having the correct value from shift");
        result = 0;
    }

    destroy_sll_double(data.list);
    return result;
}


char sll_double_test_sll_double_insert(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_double_insert(data.list, 2, 68.3);
    double value = sll_double_get(data.list, 2); 

    if(data.list->length != 6){
        printf("\nFailed to get expected list length\n"); 
        result = 0; 
    }

    if(value != 68.3){
        printf("\nFailed inserted value being as expected upon retrieval\n"); 
        result = 0; 
    }

    destroy_sll_double(data.list);
    return result;
}


char sll_double_test_sll_double_delete(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_double_delete(data.list, 2); 

    if(data.list->length != 4){
        printf("\nFailed to get expected list length\n"); 
        result = 0; 
    }

    double value = sll_double_get(data.list, 2);
    if(value != 5.0){
        printf("\nFailed inserted value being as expected upon retrieval\n"); 
        result = 0; 
    }

    destroy_sll_double(data.list);
    return result;
}


static double test_data[5] = {11.0, 55.0, 33.0, 5.0, 99.0};
static char test_for_each_result;
void sll_double_for_each_test_helper(double item, unsigned long index){
    if(item != test_data[index]){
        printf("\nWas expecting %f but got %f\n", test_data[index], item);
        test_for_each_result = 0; 
    }
}

char sll_double_test_sll_double_for_each(){
    loaded_data data = get_data(); 
    test_for_each_result = 1; 

    sll_double_for_each(data.list, sll_double_for_each_test_helper);

    destroy_sll_double(data.list);
    return test_for_each_result;
}

double sll_double_map_test_helper(double current, unsigned long index){
    return current * 2; 
}

char sll_double_test_sll_double_map(){
    loaded_data data = get_data(); 
    char result = 1; 

    sll_double *new_list = sll_double_map(data.list, sll_double_map_test_helper);

    for(unsigned long i = 0; i < 5; i++){
        if(sll_double_get(data.list, i) * 2 != sll_double_get(new_list, i)){
            printf("\nComparison between item in list * 2 and item in map failed \n");
            result = 0; 
            break;
        }
    }
    destroy_sll_double(data.list);
    destroy_sll_double(new_list);
    return result;
}

void *sll_double_test_sll_double_reduce_helper(double value, void *accumulator, unsigned long index){
    *(double *)accumulator += value; 
    return accumulator;
}
char sll_double_test_sll_double_reduce(){
    loaded_data data = get_data(); 
    char result = 1;

    double sum = 0;
    sum = *(double *)sll_double_reduce(data.list, sll_double_test_sll_double_reduce_helper, &sum);
    if(sum != 203.0f){
        printf("\nFailed summed value being expected\n");
        result = 0;
    }

    destroy_sll_double(data.list);
    return result;
}

char sll_double_test_sll_double_find(){
    loaded_data data = get_data(); 
    char result = 1;

    if(sll_double_find(data.list, 33.0) != 2){
        printf("\nFailed returning wrong index value\n");
        result = 0; 
    }
    else if(sll_double_find(data.list, 58.211) != -1){
        printf("\nFailed saying we had an element we didn't\n");
        result = 0; 
    }

    destroy_sll_double(data.list);
    return result;
}

