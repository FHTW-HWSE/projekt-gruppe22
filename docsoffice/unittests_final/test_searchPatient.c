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
void test_searchPatient(void) {
    // Initialize patients
    int numPatients = 2;
    Patient* patients = malloc(numPatients * sizeof(Patient));
    
    // Set up patient data
    strcpy(patients[0].insuranceNumber, "1234");
    strcpy(patients[0].firstName, "John");
    strcpy(patients[0].lastName, "Doe");
    strcpy(patients[0].birthdate, "1990-01-01");
    strcpy(patients[0].street, "Main Street");
    strcpy(patients[0].streetno, "123");
    strcpy(patients[0].zipCode, "12345");
    strcpy(patients[0].city, "Cityville");
    patients[0].height = 175.5;
    patients[0].weight = 70.0;
    
    strcpy(patients[1].insuranceNumber, "5678");
    strcpy(patients[1].firstName, "Jane");
    strcpy(patients[1].lastName, "Smith");
    strcpy(patients[1].birthdate, "1995-05-05");
    strcpy(patients[1].street, "Second Street");
    strcpy(patients[1].streetno, "456");
    strcpy(patients[1].zipCode, "54321");
    strcpy(patients[1].city, "Townville");
    patients[1].height = 160.0;
    patients[1].weight = 55.5;
    
    // Set up mock for user input
    char insuranceNumber[20];
    printf("Enter the patient's insurance number: ");
    scanf("%s", insuranceNumber);

    // Run the function
    bool result = searchPatient(patients, numPatients);

    // Assertion
    TEST_ASSERT_TRUE(result);

    // Clean up
    free(patients);
    patients = NULL;
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_searchPatient);

    return UNITY_END();
}
