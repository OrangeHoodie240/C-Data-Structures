gcc -o test_results.exe runTests.c singly_linked_list/singlylinkedlist.c singly_linked_list/singlylinkedlist.tests.c sll_float/sll_float.c sll_float/sll_float.tests.c sll_double/sll_double.c sll_double/sll_double.tests.c sll_char/sll_char.c sll_char/sll_char.tests.c 
./test_results.exe
rm test_results.exe