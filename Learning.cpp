// Learning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void show_stack_growth() {
    int local1 = 256;
    int local2 = 0xFFFFFF;
    
    std::cout << "Address of local1: " << &local1 << std::endl;
    std::cout << "Address of local2: " << &local2 << std::endl;

    local1 = INT_MAX;
    std::cout << "Address of local1: " << &local1 << std::endl;
    std::cout << "Value of local1: " << local1 << std::endl;

    local2 = 0xF;
    std::cout << "Address of local1: " << &local2 << std::endl;
    std::cout << "Value of local1: " << local2 << std::endl;
    // Which address is higher? This tells you stack direction
}

void test_alignment() {
    int local1;
    int local2;
    int local3;
    int local4;

    printf("local1: %p\n", &local1);
    printf("local2: %p\n", &local2);
    printf("local3: %p\n", &local3);
    printf("local4: %p\n", &local4);
}

void function_b() {
    int var_b = 2;
    std::cout << "In function_b, var_b at: " << &var_b << std::endl;
}

void function_a() {
    int var_a = 1;
    std::cout << "In function_a, var_a at: " << &var_a << std::endl;
    function_b();
}

void empty_function() {
    // No local variables at all
}

void test_uninitialized() {
    int arr[100];  // Don't initialize
    // In release mode, might contain garbage
    // In debug mode, probably zeros due to rep stos

    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";  // What values do you see?
    }
}

/*int main()
{
    function_a();
    test_uninitialized();
    //test_alignment();
    //show_stack_growth();

    return 0;
}*/
