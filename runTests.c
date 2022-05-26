#include "singly_linked_list/singlylinkedlist.tests.h"
#include "sll_float/sll_float.tests.h"
#include "sll_double/sll_double.tests.h"
#include "sll_char/sll_char.tests.h"
#include "sll_uchar/sll_uchar.tests.h"
#include "sll_short/sll_short.tests.h"
#include "sll_ushort/sll_ushort.tests.h"
#include "sll_int/sll_int.tests.h"
#include "sll_long/sll_long.tests.h"
#include "sll_llong/sll_llong.tests.h"
#include "sll_uint/sll_uint.tests.h"
#include "sll_ulong/sll_ulong.tests.h"
#include "sll_ullong/sll_ullong.tests.h"



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

    // sll tests
    printf("\nStarting sll tests\n");
    run_test(sll_push_appends_node, "sll_push_appends_node", &tracker); 
    run_test(sll_pop_removes_node, "sll_pop_removes_node", &tracker); 
    run_test(sll_unshift_prepends_node, "sll_unshift_prepends_node", &tracker); 
    run_test(sll_inserts_correctly, "sll_inserts_correctly", &tracker); 
    run_test(sll_shift_deletes_first_node, "sll_shift_deletes_first_node", &tracker); 
    run_test(sll_delete_deletes_from_middle, "sll_delete_deletes_from_middle", &tracker); 
    run_test(sll_for_each_test, "sll_for_each_test", &tracker);
    run_test(sll_test_reduce, "sll_test_reduce", &tracker); 
    run_test(sll_test_sll_map, "sll_test_sll_map", &tracker); 
    run_test(sll_test_find, "sll_test_find", &tracker); 

    // sll_float tests
    printf("\nStarting sll_float tests\n");
    run_test(sll_float_push_appends_node, "sll_float_push_appends_node", &tracker); 
    run_test(sll_float_pop_returns_and_removes_node, "sll_float_pop_returns_and_removes_node", &tracker); 
    run_test(sll_float_test_sll_float_get, "sll_float_test_sll_float_get", &tracker); 
    run_test(sll_float_test_sll_float_unshift, "sll_float_test_sll_float_unshift", &tracker); 
    run_test(sll_float_test_sll_float_shift, "sll_float_test_sll_float_shift", &tracker); 
    run_test(sll_float_test_sll_float_insert, "sll_float_test_sll_float_insert", &tracker); 
    run_test(sll_float_test_sll_float_delete, "sll_float_test_sll_float_delete", &tracker); 
    run_test(sll_float_test_sll_float_for_each, "sll_float_test_sll_float_for_each", &tracker); 
    run_test(sll_float_test_sll_float_map, "sll_float_test_sll_float_map", &tracker); 
    run_test(sll_float_test_sll_float_reduce, "sll_float_test_sll_float_reduce", &tracker); 
    run_test(sll_float_test_sll_float_find, "sll_float_test_sll_float_find", &tracker); 


    // sll_double tests
    printf("\nStarting sll_double tests\n");
    run_test(sll_double_push_appends_node, "sll_double_push_appends_node", &tracker); 
    run_test(sll_double_pop_returns_and_removes_node, "sll_double_pop_returns_and_removes_node", &tracker); 
    run_test(sll_double_test_sll_double_get, "sll_double_test_sll_double_get", &tracker); 
    run_test(sll_double_test_sll_double_unshift, "sll_double_test_sll_double_unshift", &tracker); 
    run_test(sll_double_test_sll_double_shift, "sll_double_test_sll_double_shift", &tracker); 
    run_test(sll_double_test_sll_double_insert, "sll_double_test_sll_double_insert", &tracker); 
    run_test(sll_double_test_sll_double_delete, "sll_double_test_sll_double_delete", &tracker); 
    run_test(sll_double_test_sll_double_for_each, "sll_double_test_sll_double_for_each", &tracker); 
    run_test(sll_double_test_sll_double_map, "sll_double_test_sll_double_map", &tracker); 
    run_test(sll_double_test_sll_double_reduce, "sll_double_test_sll_double_reduce", &tracker); 
    run_test(sll_double_test_sll_double_find, "sll_double_test_sll_double_find", &tracker); 

    // sll_char tests
    printf("\nStarting sll_char tests\n");
    run_test(sll_char_push_appends_node, "sll_char_push_appends_node", &tracker); 
    run_test(sll_char_pop_returns_and_removes_node, "sll_char_pop_returns_and_removes_node", &tracker); 
    run_test(sll_char_test_sll_char_get, "sll_char_test_sll_char_get", &tracker); 
    run_test(sll_char_test_sll_char_unshift, "sll_char_test_sll_char_unshift", &tracker); 
    run_test(sll_char_test_sll_char_shift, "sll_char_test_sll_char_shift", &tracker); 
    run_test(sll_char_test_sll_char_insert, "sll_char_test_sll_char_insert", &tracker); 
    run_test(sll_char_test_sll_char_delete, "sll_char_test_sll_char_delete", &tracker); 
    run_test(sll_char_test_sll_char_for_each, "sll_char_test_sll_char_for_each", &tracker); 
    run_test(sll_char_test_sll_char_map, "sll_char_test_sll_char_map", &tracker); 
    run_test(sll_char_test_sll_char_reduce, "sll_char_test_sll_char_reduce", &tracker); 
    run_test(sll_char_test_sll_char_find, "sll_char_test_sll_char_find", &tracker); 

    //sll_uchar tests
    printf("\nStarting sll_uchar tests\n");
    run_test(sll_uchar_push_appends_node, "sll_uchar_push_appends_node", &tracker); 
    run_test(sll_uchar_pop_returns_and_removes_node, "sll_uchar_pop_returns_and_removes_node", &tracker); 
    run_test(sll_uchar_test_sll_uchar_get, "sll_uchar_test_sll_uchar_get", &tracker); 
    run_test(sll_uchar_test_sll_uchar_unshift, "sll_uchar_test_sll_uchar_unshift", &tracker); 
    run_test(sll_uchar_test_sll_uchar_shift, "sll_uchar_test_sll_uchar_shift", &tracker); 
    run_test(sll_uchar_test_sll_uchar_insert, "sll_uchar_test_sll_uchar_insert", &tracker); 
    run_test(sll_uchar_test_sll_uchar_delete, "sll_uchar_test_sll_uchar_delete", &tracker); 
    run_test(sll_uchar_test_sll_uchar_for_each, "sll_uchar_test_sll_uchar_for_each", &tracker); 
    run_test(sll_uchar_test_sll_uchar_map, "sll_uchar_test_sll_uchar_map", &tracker); 
    run_test(sll_uchar_test_sll_uchar_reduce, "sll_uchar_test_sll_uchar_reduce", &tracker); 
    run_test(sll_uchar_test_sll_uchar_find, "sll_uchar_test_sll_uchar_find", &tracker); 

    // sll_short tests
    printf("\nStarting sll_short tests\n");
    run_test(sll_short_push_appends_node, "sll_short_push_appends_node", &tracker); 
    run_test(sll_short_pop_returns_and_removes_node, "sll_short_pop_returns_and_removes_node", &tracker); 
    run_test(sll_short_test_sll_short_get, "sll_short_test_sll_short_get", &tracker); 
    run_test(sll_short_test_sll_short_unshift, "sll_short_test_sll_short_unshift", &tracker); 
    run_test(sll_short_test_sll_short_shift, "sll_short_test_sll_short_shift", &tracker); 
    run_test(sll_short_test_sll_short_insert, "sll_short_test_sll_short_insert", &tracker); 
    run_test(sll_short_test_sll_short_delete, "sll_short_test_sll_short_delete", &tracker); 
    run_test(sll_short_test_sll_short_for_each, "sll_short_test_sll_short_for_each", &tracker); 
    run_test(sll_short_test_sll_short_map, "sll_short_test_sll_short_map", &tracker); 
    run_test(sll_short_test_sll_short_reduce, "sll_short_test_sll_short_reduce", &tracker); 
    run_test(sll_short_test_sll_short_find, "sll_short_test_sll_short_find", &tracker); 


    // sll_ushort tests
    printf("\nStarting sll_ushort tests\n");
    run_test(sll_ushort_push_appends_node, "sll_ushort_push_appends_node", &tracker); 
    run_test(sll_ushort_pop_returns_and_removes_node, "sll_ushort_pop_returns_and_removes_node", &tracker); 
    run_test(sll_ushort_test_sll_ushort_get, "sll_ushort_test_sll_ushort_get", &tracker); 
    run_test(sll_ushort_test_sll_ushort_unshift, "sll_ushort_test_sll_ushort_unshift", &tracker); 
    run_test(sll_ushort_test_sll_ushort_shift, "sll_ushort_test_sll_ushort_shift", &tracker); 
    run_test(sll_ushort_test_sll_ushort_insert, "sll_ushort_test_sll_ushort_insert", &tracker); 
    run_test(sll_ushort_test_sll_ushort_delete, "sll_ushort_test_sll_ushort_delete", &tracker); 
    run_test(sll_ushort_test_sll_ushort_for_each, "sll_ushort_test_sll_ushort_for_each", &tracker); 
    run_test(sll_ushort_test_sll_ushort_map, "sll_ushort_test_sll_ushort_map", &tracker); 
    run_test(sll_ushort_test_sll_ushort_reduce, "sll_ushort_test_sll_ushort_reduce", &tracker); 
    run_test(sll_ushort_test_sll_ushort_find, "sll_ushort_test_sll_ushort_find", &tracker); 


    // sll_int tests
    printf("\nStarting sll_int tests\n");
    run_test(sll_int_push_appends_node, "sll_int_push_appends_node", &tracker); 
    run_test(sll_int_pop_returns_and_removes_node, "sll_int_pop_returns_and_removes_node", &tracker); 
    run_test(sll_int_test_sll_int_get, "sll_int_test_sll_int_get", &tracker); 
    run_test(sll_int_test_sll_int_unshift, "sll_int_test_sll_int_unshift", &tracker); 
    run_test(sll_int_test_sll_int_shift, "sll_int_test_sll_int_shift", &tracker); 
    run_test(sll_int_test_sll_int_insert, "sll_int_test_sll_int_insert", &tracker); 
    run_test(sll_int_test_sll_int_delete, "sll_int_test_sll_int_delete", &tracker); 
    run_test(sll_int_test_sll_int_for_each, "sll_int_test_sll_int_for_each", &tracker); 
    run_test(sll_int_test_sll_int_map, "sll_int_test_sll_int_map", &tracker); 
    run_test(sll_int_test_sll_int_reduce, "sll_int_test_sll_int_reduce", &tracker); 
    run_test(sll_int_test_sll_int_find, "sll_int_test_sll_int_find", &tracker); 


    // sll_long tests
    printf("\nStarting sll_long tests\n");
    run_test(sll_long_push_appends_node, "sll_long_push_appends_node", &tracker); 
    run_test(sll_long_pop_returns_and_removes_node, "sll_long_pop_returns_and_removes_node", &tracker); 
    run_test(sll_long_test_sll_long_get, "sll_long_test_sll_long_get", &tracker); 
    run_test(sll_long_test_sll_long_unshift, "sll_long_test_sll_long_unshift", &tracker); 
    run_test(sll_long_test_sll_long_shift, "sll_long_test_sll_long_shift", &tracker); 
    run_test(sll_long_test_sll_long_insert, "sll_long_test_sll_long_insert", &tracker); 
    run_test(sll_long_test_sll_long_delete, "sll_long_test_sll_long_delete", &tracker); 
    run_test(sll_long_test_sll_long_for_each, "sll_long_test_sll_long_for_each", &tracker); 
    run_test(sll_long_test_sll_long_map, "sll_long_test_sll_long_map", &tracker); 
    run_test(sll_long_test_sll_long_reduce, "sll_long_test_sll_long_reduce", &tracker); 
    run_test(sll_long_test_sll_long_find, "sll_long_test_sll_long_find", &tracker); 



    // sll_llong tests
    printf("\nStarting sll_llong tests\n");
    run_test(sll_llong_push_appends_node, "sll_llong_push_appends_node", &tracker); 
    run_test(sll_llong_pop_returns_and_removes_node, "sll_llong_pop_returns_and_removes_node", &tracker); 
    run_test(sll_llong_test_sll_llong_get, "sll_llong_test_sll_llong_get", &tracker); 
    run_test(sll_llong_test_sll_llong_unshift, "sll_llong_test_sll_llong_unshift", &tracker); 
    run_test(sll_llong_test_sll_llong_shift, "sll_llong_test_sll_llong_shift", &tracker); 
    run_test(sll_llong_test_sll_llong_insert, "sll_llong_test_sll_llong_insert", &tracker); 
    run_test(sll_llong_test_sll_llong_delete, "sll_llong_test_sll_llong_delete", &tracker); 
    run_test(sll_llong_test_sll_llong_for_each, "sll_llong_test_sll_llong_for_each", &tracker); 
    run_test(sll_llong_test_sll_llong_map, "sll_llong_test_sll_llong_map", &tracker); 
    run_test(sll_llong_test_sll_llong_reduce, "sll_llong_test_sll_llong_reduce", &tracker); 
    run_test(sll_llong_test_sll_llong_find, "sll_llong_test_sll_llong_find", &tracker); 


    // sll_uint tests
    printf("\nStarting sll_uint tests\n");
    run_test(sll_uint_push_appends_node, "sll_uint_push_appends_node", &tracker); 
    run_test(sll_uint_pop_returns_and_removes_node, "sll_uint_pop_returns_and_removes_node", &tracker); 
    run_test(sll_uint_test_sll_uint_get, "sll_uint_test_sll_uint_get", &tracker); 
    run_test(sll_uint_test_sll_uint_unshift, "sll_uint_test_sll_uint_unshift", &tracker); 
    run_test(sll_uint_test_sll_uint_shift, "sll_uint_test_sll_uint_shift", &tracker); 
    run_test(sll_uint_test_sll_uint_insert, "sll_uint_test_sll_uint_insert", &tracker); 
    run_test(sll_uint_test_sll_uint_delete, "sll_uint_test_sll_uint_delete", &tracker); 
    run_test(sll_uint_test_sll_uint_for_each, "sll_uint_test_sll_uint_for_each", &tracker); 
    run_test(sll_uint_test_sll_uint_map, "sll_uint_test_sll_uint_map", &tracker); 
    run_test(sll_uint_test_sll_uint_reduce, "sll_uint_test_sll_uint_reduce", &tracker); 
    run_test(sll_uint_test_sll_uint_find, "sll_uint_test_sll_uint_find", &tracker); 

    // sll_ulong tests
    printf("\nStarting sll_ulong tests\n");
    run_test(sll_ulong_push_appends_node, "sll_ulong_push_appends_node", &tracker); 
    run_test(sll_ulong_pop_returns_and_removes_node, "sll_ulong_pop_returns_and_removes_node", &tracker); 
    run_test(sll_ulong_test_sll_ulong_get, "sll_ulong_test_sll_ulong_get", &tracker); 
    run_test(sll_ulong_test_sll_ulong_unshift, "sll_ulong_test_sll_ulong_unshift", &tracker); 
    run_test(sll_ulong_test_sll_ulong_shift, "sll_ulong_test_sll_ulong_shift", &tracker); 
    run_test(sll_ulong_test_sll_ulong_insert, "sll_ulong_test_sll_ulong_insert", &tracker); 
    run_test(sll_ulong_test_sll_ulong_delete, "sll_ulong_test_sll_ulong_delete", &tracker); 
    run_test(sll_ulong_test_sll_ulong_for_each, "sll_ulong_test_sll_ulong_for_each", &tracker); 
    run_test(sll_ulong_test_sll_ulong_map, "sll_ulong_test_sll_ulong_map", &tracker); 
    run_test(sll_ulong_test_sll_ulong_reduce, "sll_ulong_test_sll_ulong_reduce", &tracker); 
    run_test(sll_ulong_test_sll_ulong_find, "sll_ulong_test_sll_ulong_find", &tracker); 

    // sll_ullong tests
    printf("\nStarting sll_ullong tests\n");
    run_test(sll_ullong_push_appends_node, "sll_ullong_push_appends_node", &tracker); 
    run_test(sll_ullong_pop_returns_and_removes_node, "sll_ullong_pop_returns_and_removes_node", &tracker); 
    run_test(sll_ullong_test_sll_ullong_get, "sll_ullong_test_sll_ullong_get", &tracker); 
    run_test(sll_ullong_test_sll_ullong_unshift, "sll_ullong_test_sll_ullong_unshift", &tracker); 
    run_test(sll_ullong_test_sll_ullong_shift, "sll_ullong_test_sll_ullong_shift", &tracker); 
    run_test(sll_ullong_test_sll_ullong_insert, "sll_ullong_test_sll_ullong_insert", &tracker); 
    run_test(sll_ullong_test_sll_ullong_delete, "sll_ullong_test_sll_ullong_delete", &tracker); 
    run_test(sll_ullong_test_sll_ullong_for_each, "sll_ullong_test_sll_ullong_for_each", &tracker); 
    run_test(sll_ullong_test_sll_ullong_map, "sll_ullong_test_sll_ullong_map", &tracker); 
    run_test(sll_ullong_test_sll_ullong_reduce, "sll_ullong_test_sll_ullong_reduce", &tracker); 
    run_test(sll_ullong_test_sll_ullong_find, "sll_ullong_test_sll_ullong_find", &tracker); 


    printf("\nTests Passed: %d\nTests Failed: %d\nTotal Tests: %d", tracker.passed, tracker.failed, tracker.passed + tracker.failed);
    return 0; 
}