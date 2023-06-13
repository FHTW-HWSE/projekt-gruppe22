#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "waitingRoom.h"

#include "unity.h"
#include "patient.h"

extern Patient* patients;
extern int numPatients;
extern int maxPatients;

void setUp() {
    // Set up the patients array
    maxPatients = 10;
    patients = malloc(maxPatients * sizeof(Patient));
    numPatients = 0;
}

void tearDown() {
    // Clean up the patients array
    free(patients);
    patients = NULL;
    numPatients = 0;
    maxPatients = 0;
}

void test_loadPatients(void) {
    // Create a sample patients.csv file with patient data
    FILE* file = fopen("patients.csv", "w");
    if (file == NULL) {
        TEST_FAIL_MESSAGE("Failed to create patients.csv file");
    }

    fprintf(file, "1234ddmmyy,John,Doe,01012000,Main St,123,12345,Cityville,180,75\n");
    fprintf(file, "5678ddmmyy,Jane,Smith,02022000,Second St,456,67890,Townville,160,60\n");

    fclose(file);

    // Call the function to load patients
    loadPatients();

    // Verify the loaded patients
    TEST_ASSERT_EQUAL_INT(2, numPatients);

    TEST_ASSERT_EQUAL_STRING("1234ddmmyy", patients[0].insuranceNumber);
    TEST_ASSERT_EQUAL_STRING("John", patients[0].firstName);
    TEST_ASSERT_EQUAL_STRING("Doe", patients[0].lastName);
    TEST_ASSERT_EQUAL_STRING("01012000", patients[0].birthdate);
    TEST_ASSERT_EQUAL_STRING("Main St", patients[0].street);
    TEST_ASSERT_EQUAL_STRING("123", patients[0].streetno);
    TEST_ASSERT_EQUAL_STRING("12345", patients[0].zipCode);
    TEST_ASSERT_EQUAL_STRING("Cityville", patients[0].city);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 180.0, patients[0].height);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 75.0, patients[0].weight);

    TEST_ASSERT_EQUAL_STRING("5678ddmmyy", patients[1].insuranceNumber);
    TEST_ASSERT_EQUAL_STRING("Jane", patients[1].firstName);
    TEST_ASSERT_EQUAL_STRING("Smith", patients[1].lastName);
    TEST_ASSERT_EQUAL_STRING("02022000", patients[1].birthdate);
    TEST_ASSERT_EQUAL_STRING("Second St", patients[1].street);
    TEST_ASSERT_EQUAL_STRING("456", patients[1].streetno);
    TEST_ASSERT_EQUAL_STRING("67890", patients[1].zipCode);
    TEST_ASSERT_EQUAL_STRING("Townville", patients[1].city);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 160.0, patients[1].height);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 60.0, patients[1].weight);

    // Print a success message
    TEST_PASS_MESSAGE("Load patients test passed successfully!");
}

void test_savePatients(void) {
    // Add sample patients to the patients array
    numPatients = 2;
    maxPatients = 2;
    patients = malloc(maxPatients * sizeof(Patient));

    strcpy(patients[0].insuranceNumber, "1234ddmmyy");
    strcpy(patients[0].firstName, "John");
    strcpy(patients[0].lastName, "Doe");
    strcpy(patients[0].birthdate, "01012000");
    strcpy(patients[0].street, "Main St");
    strcpy(patients[0].streetno, "123");
    strcpy(patients[0].zipCode, "12345");
    strcpy(patients[0].city, "Cityville");
    patients[0].height = 180.0;
    patients[0].weight = 75.0;

    strcpy(patients[1].insuranceNumber, "5678ddmmyy");
    strcpy(patients[1].firstName, "Jane");
    strcpy(patients[1].lastName, "Smith");
    strcpy(patients[1].birthdate, "02022000");
    strcpy(patients[1].street, "Second St");
    strcpy(patients[1].streetno, "456");
    strcpy(patients[1].zipCode, "67890");
    strcpy(patients[1].city, "Townville");
    patients[1].height = 160.0;
    patients[1].weight = 60.0;

    // Call the function to save patients
    savePatients();

    // Read the saved patients.csv file
    FILE* file = fopen("patients.csv", "r");
    if (file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open patients.csv file for reading");
    }

    char line[256];
    fgets(line, sizeof(line), file);  // Skip the header line

    // Verify the saved patient data
    for (int i = 0; i < numPatients; i++) {
        fgets(line, sizeof(line), file);
        char* token = strtok(line, ",");

        TEST_ASSERT_EQUAL_STRING(patients[i].insuranceNumber, token);

        // Remaining code for validating the saved patient data...
        token = strtok(NULL, ",");
        TEST_ASSERT_EQUAL_STRING(patients[i].firstName, token);

        token = strtok(NULL, ",");
        TEST_ASSERT_EQUAL_STRING(patients[i].lastName, token);

        token = strtok(NULL, ",");
        TEST_ASSERT_EQUAL_STRING(patients[i].birthdate, token);

        token = strtok(NULL, ",");
        TEST_ASSERT_EQUAL_STRING(patients[i].street, token);

        token = strtok(NULL, ",");
        TEST_ASSERT_EQUAL_STRING(patients[i].streetno, token);

        token = strtok(NULL, ",");
        TEST_ASSERT_EQUAL_STRING(patients[i].zipCode, token);

        token = strtok(NULL, ",");
        TEST_ASSERT_EQUAL_STRING(patients[i].city, token);

        token = strtok(NULL, ",");
        TEST_ASSERT_FLOAT_WITHIN(0.001, patients[i].height, atof(token));

        token = strtok(NULL, ",");
        TEST_ASSERT_FLOAT_WITHIN(0.001, patients[i].weight, atof(token));
    }

    fclose(file);

    // Print a success message
    TEST_PASS_MESSAGE("Save patients test passed successfully!");
}

void test_cleanup(void) {
    // Add sample patients to the patients array
    numPatients = 2;
    maxPatients = 2;
    patients = malloc(maxPatients * sizeof(Patient));

    // Call the function to perform cleanup
    cleanup();

    // Verify that patients array is cleaned up
    TEST_ASSERT_NULL(patients);
    TEST_ASSERT_EQUAL_INT(0, numPatients);
    TEST_ASSERT_EQUAL_INT(0, maxPatients);

    // Print a success message
    TEST_PASS_MESSAGE("Cleanup test passed successfully!");
}

void test_addPatient(void) {
    // Redirect stdin to a file to simulate user input
    FILE* file = freopen("test_input.txt", "w", stdin);
    if (file == NULL) {
        TEST_FAIL_MESSAGE("Failed to redirect stdin to a file");
    }

    // Enter the patient details in the simulated user input
    fprintf(file, "1234ddmmyy\n");
    fprintf(file, "John\n");
    fprintf(file, "Doe\n");
    fprintf(file, "01012000\n");
    fprintf(file, "Main St\n");
    fprintf(file, "123\n");
    fprintf(file, "12345\n");
    fprintf(file, "Cityville\n");
    fprintf(file, "180\n");
    fprintf(file, "75\n");

    // Close the file and restore stdin
    fclose(file);
    file = freopen("/dev/stdin", "r", stdin);
    if (file == NULL) {
        TEST_FAIL_MESSAGE("Failed to restore stdin");
    }

    // Call the function to add a patient
    addPatient();

    // Verify the added patient
    TEST_ASSERT_EQUAL_STRING("1234ddmmyy", patients[0].insuranceNumber);
    TEST_ASSERT_EQUAL_STRING("John", patients[0].firstName);
    TEST_ASSERT_EQUAL_STRING("Doe", patients[0].lastName);
    TEST_ASSERT_EQUAL_STRING("01012000", patients[0].birthdate);
    TEST_ASSERT_EQUAL_STRING("Main St", patients[0].street);
    TEST_ASSERT_EQUAL_STRING("123", patients[0].streetno);
    TEST_ASSERT_EQUAL_STRING("12345", patients[0].zipCode);
    TEST_ASSERT_EQUAL_STRING("Cityville", patients[0].city);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 180.0, patients[0].height);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 75.0, patients[0].weight);

    // Print a success message
    TEST_PASS_MESSAGE("Add patient test passed successfully!");
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_loadPatients);
    RUN_TEST(test_savePatients);
    RUN_TEST(test_cleanup);
    RUN_TEST(test_addPatient);

    return UNITY_END();
}
