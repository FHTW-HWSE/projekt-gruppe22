#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "patient.h"
#include "menu.h"
#include "switchcase.h"
#include "waitingRoom.h"
#include "unity.h" // Include Unity testing framework
#include "patient.h" // Include the patient header file
#include "queue.h" // Include the queue header file

// Mock variables
extern Patient* patients;
extern int numPatients;
extern int maxPatients;


// Setup function
void setUp(void) {
    // Initialize any necessary resources before each test case
}

// Teardown function
void tearDown(void) {
    // Clean up any resources after each test case
}

// Test cases
void test_addPatientToQueue(void) {
    // Initialize patients
    numPatients = 2;
    maxPatients = 2;
    patients = malloc(maxPatients * sizeof(Patient));

    // Add some patients
    strcpy(patients[0].insuranceNumber, "1234");
    strcpy(patients[1].insuranceNumber, "5678");

    // Set up mock for user input
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to add to the queue: ");
    scanf("%s", insuranceNumber);

    // Run the function
    addPatientToQueue();

    // Assertion
    TEST_ASSERT_EQUAL_STRING("1234", queue[0]);
    TEST_ASSERT_EQUAL(1, queueSize);

    // Clean up
    free(patients);
    patients = NULL;
    numPatients = 0;
    maxPatients = 0;
}

void test_dequeuePatient(void) {
    // Initialize the queue
    queueSize = 3;
    strcpy(queue[0], "1234");
    strcpy(queue[1], "5678");
    strcpy(queue[2], "9012");

    // Set up mock for user input
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to dequeue: ");
    scanf("%s", insuranceNumber);

    // Run the function
    bool result = dequeuePatient(insuranceNumber);

    // Assertion
    TEST_ASSERT_TRUE(result);
    TEST_ASSERT_EQUAL_STRING("5678", queue[0]);
    TEST_ASSERT_EQUAL_STRING("9012", queue[1]);
    TEST_ASSERT_EQUAL(2, queueSize);

    // Clean up
    queueSize = 0;
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_addPatientToQueue);
    RUN_TEST(test_dequeuePatient);

    return UNITY_END();
}
