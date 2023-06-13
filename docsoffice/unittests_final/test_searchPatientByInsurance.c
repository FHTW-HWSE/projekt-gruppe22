#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "searchPatient.h"
#include "editPatient.h"
#include "SearchPatientbyInsurance.h"
#include "waitingRoom.h"
#include "unity.h" // Include Unity testing framework

// Setup function
void setUp(void) {
    // Initialize any necessary resources before each test case
}

// Teardown function
void tearDown(void) {
    // Clean up any resources after each test case
}

// Test case
void test_searchPatientbyInsurance(void) {
    // Initialize patients
    int numPatients = 2;
    Patient* patients = malloc(numPatients * sizeof(Patient));
    
    // Set up patient data
    strcpy(patients[0].insuranceNumber, "1234");
    strcpy(patients[0].firstName, "John");
    strcpy(patients[0].lastName, "Doe");
    
    strcpy(patients[1].insuranceNumber, "5678");
    strcpy(patients[1].firstName, "Jane");
    strcpy(patients[1].lastName, "Smith");
    
    // Set up mock for user input
    char insuranceNumber[20];
    printf("Enter the insurance number to search for: ");
    scanf("%s", insuranceNumber);

    // Run the function
    Patient* result = searchPatientbyInsurance(patients, numPatients, insuranceNumber);

    // Assertion
    TEST_ASSERT_NOT_NULL(result);

    // Clean up
    free(patients);
    patients = NULL;
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_searchPatientbyInsurance);

    return UNITY_END();
}
