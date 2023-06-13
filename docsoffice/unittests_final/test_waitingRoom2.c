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

void test_loadWaitingRoom(void) {
    WaitingRoom* room = createWaitingRoom();
    TEST_ASSERT_NOT_NULL(room);

    loadWaitingRoom(room);

    // Assert that the waiting room has been loaded correctly
    // Test specific patient details or the overall count of patients

    // Clean up
    destroyWaitingRoom(room);
}

void test_saveWaitingRoom(void) {
    WaitingRoom* room = createWaitingRoom();
    TEST_ASSERT_NOT_NULL(room);

    // Add some patients to the waiting room

    // Save the waiting room
    saveWaitingRoom(room);

    // Assert that the waiting room has been saved correctly
    // Check if the file exists and its content matches the expected format

    // Clean up
    destroyWaitingRoom(room);
}

void test_removePatientFromSeat(void) {
    WaitingRoom* room = createWaitingRoom();
    TEST_ASSERT_NOT_NULL(room);

    // Add some patients to the waiting room

    // Remove a patient from the waiting room
    const char* insuranceNumber = "12345";
    bool result = removePatientFromSeat(insuranceNumber, room);

    // Assert that the patient has been removed correctly
    TEST_ASSERT_TRUE(result);
    // Assert that the patient with the given insurance number no longer exists in the waiting room

    // Clean up
    destroyWaitingRoom(room);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_loadWaitingRoom);
    RUN_TEST(test_saveWaitingRoom);
    RUN_TEST(test_removePatientFromSeat);
    return UNITY_END();
}
