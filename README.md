# Datastructures Library 


Tested library for C Datastructures

## Run Tests
    Tests can be run with ./runTests.sh

## Singly Linked List 
We have the following types of singly Linked Lists
    
    1. Singly linked lists for all primatives. sll_int, sll_uint (unsigned int), sll_long, sll_llong (long long) etc.
    
    2. Singly linked list for void *. This saves a deep copy of the item and requires you pass sll_create a constructor and destructor function.
    
    3. Singly linked list files can be generated for a struct type creating a statically typed list for your custom data types. The items are **saved by reference** to the list.



## Generating Statically Typed Singly Linked List
   
    1. You will need to create a header file, type_name.h, that will hold both the struct definition of your custom type, but also a destructor function. 
   
    2. This destructor definition should 

            1. Be weakly linked __attribute__((weakly))

            2. Be named delete_function

            3. Return void
            
            4. Take a single parameter of your custom type
            
            5. Free any fields that are stored on the stack. 

        __attribute__((weakly)) void delete_function(truck tr){
            free(tr.name);
            free(tr.color);
        }

    3. Use the terminal to generate the files with generate_sll.exe. You must pass the path to the .h file containing your type and its deconstructor as the only argument. This will be where the files will be generated so it's best to create a directory for this h file.


        ./generate_sll.exe truck/truck.h            
  
        



