#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "unity.h"
#include "menu.h"
#include "switchcase.h"
#include "patient.h"
#include "queue.h"
#include "searchPatient.h"
#include "waitingRoom.h"

void setUp(void) {
    // Set up any necessary initialization steps or preconditions
}

void tearDown(void) {
    // Clean up any resources allocated in the setUp function
}

void test_displayMenu(void) {
    // Create a string buffer to capture the output
    char buffer[1000];
    memset(buffer, 0, sizeof(buffer));

    // Redirect stdout to the string buffer
    fflush(stdout);
    setbuf(stdout, buffer);

    // Call the function to display the menu
    displayMenu();

    // Restore stdout
    fflush(stdout);
    setbuf(stdout, NULL);

    // Validate the captured output
    const char* expectedOutput = "Welcome to Jai Singh's Doctor's Office!\nPlease select an option:\n1.  Search for a patient\n2.  Add a patient\n3.  Edit patient information\n4.  Add a patient to the queue\n5.  View patient queue\n8.  Dequeue Patient\n0.  Exit\n";
    TEST_ASSERT_EQUAL_STRING(expectedOutput, buffer);

    // Print the captured output for debugging
    printf("Captured output:\n%s", buffer);

    TEST_PASS_MESSAGE("Display menu test passed successfully!");
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_displayMenu);

    UNITY_END();
}
