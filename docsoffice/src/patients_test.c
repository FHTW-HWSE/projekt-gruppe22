#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "unity.h"
#include "patient.h"

void setUp(void) {
    // Set up initial state before each test
}

void tearDown(void) {
    // Clean up after each test
}

void test_getPatientByName_validName_shouldReturnPatient(void) {
    // Arrange
    Patient patients[] = {
        { .name = "John", .age = 30 },
        { .name = "Jane", .age = 25 },
        { .name = "Mike", .age = 40 }
    };
    int numPatients = sizeof(patients) / sizeof(patients[0]);

    // Act
    Patient* patient = getPatientByName(patients, numPatients, "Jane");

    // Assert
    TEST_ASSERT_NOT_NULL(patient);
    TEST_ASSERT_EQUAL_STRING("Jane", patient->name);
    TEST_ASSERT_EQUAL(25, patient->age);
}

void test_getPatientByName_invalidName_shouldReturnNull(void) {
    // Arrange
    Patient patients[] = {
        { .name = "John", .age = 30 },
        { .name = "Jane", .age = 25 },
        { .name = "Mike", .age = 40 }
    };
    int numPatients = sizeof(patients) / sizeof(patients[0]);

    // Act
    Patient* patient = getPatientByName(patients, numPatients, "David");

    // Assert
    TEST_ASSERT_NULL(patient);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_getPatientByName_validName_shouldReturnPatient);
    RUN_TEST(test_getPatientByName_invalidName_shouldReturnNull);
    UNITY_END();

    return 0;
}
