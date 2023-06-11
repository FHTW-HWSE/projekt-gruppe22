#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unity.h"
#include "waitingRoom.h"
#include "patient.h"

void setUp() {
    // Set up any resources or initialization steps for the tests
}

void tearDown() {
    // Clean up any resources or perform any necessary clean-up steps after the tests
}

void testLoadWaitingRoom() {
    WaitingRoom room;
    Patient patient1 = { "John", "Doe", "12345" };
    Patient patient2 = { "Jane", "Smith", "67890" };

    // Save the waiting room to a file
    FILE* file = fopen("waiting_room.csv", "w");
    if (file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open the waiting_room.csv file");
    }

    fprintf(file, "%s\n", patient1.insuranceNumber);
    fprintf(file, "%s\n", patient2.insuranceNumber);

    fclose(file);

    // Load the waiting room
    loadWaitingRoom(&room, NULL);

    TEST_ASSERT_EQUAL_PTR(&patient1, room.patients[0][0]);
    TEST_ASSERT_EQUAL_PTR(&patient2, room.patients[0][1]);
}


void testEnqueuePatient() {
    WaitingRoom room;
    Patient patient1 = { "John", "Doe", "12345" };
    Patient patient2 = { "Jane", "Smith", "67890" };

    // Enqueue patient1
    enqueue(&room, &patient1);
    TEST_ASSERT_EQUAL_PTR(&patient1, room.patients[0][0]);

    // Enqueue patient2
    enqueue(&room, &patient2);
    TEST_ASSERT_EQUAL_PTR(&patient1, room.patients[0][0]);
    TEST_ASSERT_EQUAL_PTR(&patient2, room.patients[0][1]);
}

void testPrintWaitingRoom() {
    WaitingRoom room;
    Patient patient1 = { "John", "Doe", "12345" };
    Patient patient2 = { "Jane", "Smith", "67890" };

    // Enqueue patient1
    enqueue(&room, &patient1);

    // Enqueue patient2
    enqueue(&room, &patient2);

    // Redirect stdout to a file
    FILE* file = freopen("output.txt", "w", stdout);
    if (file == NULL) {
        TEST_FAIL_MESSAGE("Failed to redirect stdout to a file");
    }

    // Print the waiting room
    printWaitingRoom(&room);

    // Restore stdout
    freopen("/dev/tty", "w", stdout);

    // Read the contents of the file
    file = fopen("output.txt", "r");
    if (file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open the output file");
    }

    char line[100];
    fgets(line, sizeof(line), file);
    TEST_ASSERT_EQUAL_STRING("Waiting room:", line);

    fgets(line, sizeof(line), file);
    TEST_ASSERT_EQUAL_STRING("1,1: John Doe", line);

    fgets(line, sizeof(line), file);
    TEST_ASSERT_EQUAL_STRING("1,2: Jane Smith", line);

    fclose(file);
}

int main() {
    UNITY_BEGIN();

	RUN_TEST(testLoadWaitingRoom);
    RUN_TEST(testEnqueuePatient);
    RUN_TEST(testPrintWaitingRoom);

    return UNITY_END();
}
