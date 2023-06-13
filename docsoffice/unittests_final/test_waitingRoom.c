#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "searchPatient.h"
#include "editPatient.h"
#include "SearchPatientbyInsurance.h"
#include "unity.h"
#include "queue.h"
#include "patient.h"
#include "waitingRoom.h"

void setUp(void) {}

void tearDown(void) {}

void test_enqueue(void) {
    WaitingRoom* room = createWaitingRoom();
    TEST_ASSERT_NOT_NULL(room);

    Patient patient;
    strcpy(patient.insuranceNumber, "12345");
    strcpy(patient.firstName, "John");
    strcpy(patient.lastName, "Doe");

    enqueue(room, &patient);

    // Assert that the patient has been added to the waiting room
    TEST_ASSERT_NOT_NULL(room->patients[0][0]);
    TEST_ASSERT_EQUAL_STRING("12345", room->patients[0][0]->insuranceNumber);
    TEST_ASSERT_EQUAL_STRING("John", room->patients[0][0]->firstName);
    TEST_ASSERT_EQUAL_STRING("Doe", room->patients[0][0]->lastName);

    // Clean up
    destroyWaitingRoom(room);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_enqueue);
    return UNITY_END();
}
