#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "searchPatient.h"
#include "editPatient.h"
#include "waitingRoom.h"
#include "SearchPatientbyInsurance.h"
#include "unity.h"



// Setup function
void setUp(void) {
    // Initialize any necessary resources before each test case
}

// Teardown function
void tearDown(void) {
    // Clean up any resources after each test case
}

// Function pointer for scanf
int (*scanf_ptr)(const char*, ...);

// Mock function for scanf
int mock_scanf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    // Simulate user input based on the format string
    if (strcmp(format, "%d") == 0) {
        int* num = va_arg(args, int*);
        *num = 1; // Set the user input value
        va_end(args);
        return 1; // Return the number of items read
    }
    if (strcmp(format, "%s") == 0) {
        char* str = va_arg(args, char*);
        strcpy(str, "1234"); // Set the user input value
        va_end(args);
        return 1; // Return the number of items read
    }

    va_end(args);
    return 0;
}

// Function declaration for switchcase
void switchcase(int (*scanf_func)(const char*, ...));


// Test case
void test_switchcase(void) {
    // Assign the mock_scanf function to the scanf_ptr
    scanf_ptr = mock_scanf;

    // Run the function with the function pointer
    switchcase(scanf_ptr);

    // Assertion
    // Add your assertions here to check the expected outputs or behavior

    // Clean up
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_switchcase);

    return UNITY_END();
}