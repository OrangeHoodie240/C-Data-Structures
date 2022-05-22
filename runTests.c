#include "singly_linked_list/singlylinkedlist.tests.h"
#include <stdio.h>


typedef struct test_tracker{
    short passed; 
    short failed; 
} test_tracker; 


void run_test(char (*f)(), char *name, test_tracker *tracker){
    int result = f(); 
    if(result == 0){
        tracker->failed += 1; 
        printf("\n %s failed\n", name);
    }
    else{
        tracker->passed += 1; 
    }
}


int main(){
    test_tracker tracker; 
    tracker.failed = 0; 
    tracker.passed = 0; 

    // singly_linked_list tests
    run_test(sll_push_appends_node, "sll_push_appends_node", &tracker); 
    run_test(sll_pop_removes_node, "sll_pop_removes_node", &tracker); 
    run_test(sll_unshift_prepends_node, "sll_unshift_prepends_node", &tracker); 
    run_test(sll_inserts_correctly, "sll_inserts_correctly", &tracker); 
    run_test(sll_shift_deletes_first_node, "sll_shift_deletes_first_node", &tracker); 
    run_test(sll_delete_deletes_from_middle, "sll_delete_deletes_from_middle", &tracker); 

    printf("\nTests Passed: %d\nTests Failed: %d\nTotal Tests: %d", tracker.passed, tracker.failed, tracker.passed + tracker.failed);
    return 0; 
}