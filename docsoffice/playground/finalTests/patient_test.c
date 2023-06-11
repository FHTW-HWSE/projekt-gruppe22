#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "unity.h"
#include "patient.h"

void setUp(void) {
    // Set up initial state before each test
    numPatients = 0;
	maxPatients = 0;
    patients = NULL;
}

void tearDown(void) {
    // Clean up after each test
    cleanup();
}

void test_addPatient_shouldAddPatient(void) {
    // Arrange
    Patient patient = {
        .insuranceNumber = "123456789",
        .firstName = "John",
        .lastName = "Doe",
        .birthdate = "1990-01-01",
        .street = "123 Main St",
        .zipCode = "12345",
        .city = "City",
        .height = 180.0,
        .weight = 75.0
    };

    // Act
    addPatient(&patient);

    // Assert
    TEST_ASSERT_EQUAL(1, numPatients);
    TEST_ASSERT_EQUAL_STRING("123456789", patients[0].insuranceNumber);
    TEST_ASSERT_EQUAL_STRING("John", patients[0].firstName);
    TEST_ASSERT_EQUAL_STRING("Doe", patients[0].lastName);
    TEST_ASSERT_EQUAL_STRING("1990-01-01", patients[0].birthdate);
    TEST_ASSERT_EQUAL_STRING("123 Main St", patients[0].street);
    TEST_ASSERT_EQUAL_STRING("12345", patients[0].zipCode);
    TEST_ASSERT_EQUAL_STRING("City", patients[0].city);
    TEST_ASSERT_EQUAL_FLOAT(180.0, patients[0].height);
    TEST_ASSERT_EQUAL_FLOAT(75.0, patients[0].weight);
}

void test_addPatient_capacityReached_shouldIncreaseCapacity(void) {
    // Arrange
    maxPatients = MAX_PATIENTS - 1; // Change this line to set maxPatients to MAX_PATIENTS - 1
    patients = malloc(maxPatients * sizeof(Patient));
    numPatients = maxPatients;

    Patient patient = {
        .insuranceNumber = "987654321",
        .firstName = "Jane",
        .lastName = "Smith",
        .birthdate = "1985-05-05",
        .street = "456 Elm St",
        .zipCode = "54321",
        .city = "Town",
        .height = 165.0,
        .weight = 60.0
    };

    // Act
    addPatient(&patient);

    // Assert
    TEST_ASSERT_EQUAL(2, numPatients);
    TEST_ASSERT_EQUAL_STRING("987654321", patients[1].insuranceNumber);
    TEST_ASSERT_EQUAL_STRING("Jane", patients[1].firstName);
    TEST_ASSERT_EQUAL_STRING("Smith", patients[1].lastName);
    TEST_ASSERT_EQUAL_STRING("1985-05-05", patients[1].birthdate);
    TEST_ASSERT_EQUAL_STRING("456 Elm St", patients[1].street);
    TEST_ASSERT_EQUAL_STRING("54321", patients[1].zipCode);
    TEST_ASSERT_EQUAL_STRING("Town", patients[1].city);
    TEST_ASSERT_EQUAL_FLOAT(165.0, patients[1].height);
    TEST_ASSERT_EQUAL_FLOAT(60.0, patients[1].weight);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_addPatient_shouldAddPatient);
    RUN_TEST(test_addPatient_capacityReached_shouldIncreaseCapacity);
    UNITY_END();

    return 0;
}
