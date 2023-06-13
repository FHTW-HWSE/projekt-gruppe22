#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "unity.h"
#include "patient.h"

void setUp(void) {}

void tearDown(void) {}

void test_editPatient_patientFound_shouldUpdateInformation(void) {
    // Create an array of patients
    Patient patients[] = {
        {"1234", "John", "Doe", "01012000", "123 Main St", "Apt 4", "12345", "City", 170.0, 70.0},
        {"5678", "Jane", "Smith", "02022000", "456 Elm St", "Apt 8", "67890", "Town", 160.0, 60.0}
    };
    int numPatients = sizeof(patients) / sizeof(patients[0]);

    // Call the editPatient function
    TEST_ASSERT_TRUE(editPatient(patients, numPatients));

    // Verify that the patient information has been updated
    TEST_ASSERT_EQUAL_STRING("John", patients[0].firstName);
    TEST_ASSERT_EQUAL_STRING("Doe", patients[0].lastName);
    TEST_ASSERT_EQUAL_STRING("01012000", patients[0].birthdate);
    TEST_ASSERT_EQUAL_STRING("123 Main St", patients[0].street);
    TEST_ASSERT_EQUAL_STRING("Apt 4", patients[0].streetno);
    TEST_ASSERT_EQUAL_STRING("12345", patients[0].zipCode);
    TEST_ASSERT_EQUAL_STRING("City", patients[0].city);
    TEST_ASSERT_EQUAL_FLOAT(170.0, patients[0].height);
    TEST_ASSERT_EQUAL_FLOAT(70.0, patients[0].weight);
}

void test_editPatient_patientNotFound_shouldReturnFalse(void) {
    // Create an array of patients
    Patient patients[] = {
        {"1234", "John", "Doe", "01012000", "123 Main St", "Apt 4", "12345", "City", 170.0, 70.0},
        {"5678", "Jane", "Smith", "02022000", "456 Elm St", "Apt 8", "67890", "Town", 160.0, 60.0}
    };
    int numPatients = sizeof(patients) / sizeof(patients[0]);

    // Call the editPatient function with an insurance number that doesn't exist
    TEST_ASSERT_FALSE(editPatient(patients, numPatients));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_editPatient_patientFound_shouldUpdateInformation);
    RUN_TEST(test_editPatient_patientNotFound_shouldReturnFalse);

    UNITY_END();
}
