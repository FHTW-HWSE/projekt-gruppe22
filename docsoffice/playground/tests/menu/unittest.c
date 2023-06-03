#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "menutest.h"

void displayMenu() {
    printf("Welcome to the Doctor's Office Management System!\n");
    printf("Please select an option:\n");
    printf("1. Search for a patient\n");
    printf("2. Edit patient information\n");
    printf("3. Add a patient\n");
    printf("4. Add a patient to the queue\n");
    printf("5. View patient queue\n");
    printf("6. Assign a seat to a patient\n");
    printf("7. Display seating arrangement\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

void test_displayMenu() {
    // Redirect stdout to a file
    FILE* stdout_file = freopen("output.txt", "w", stdout);

    // Call the function to display the menu
    displayMenu();

    // Close the file and restore stdout
    fclose(stdout_file);
    stdout_file = freopen("/dev/tty", "w", stdout);

    // Read the captured output from the file
    FILE* output_file = fopen("output.txt", "r");
    char capturedOutput[1024];
    fgets(capturedOutput, sizeof(capturedOutput), output_file);
    fclose(output_file);

    // Trim trailing newline character
    char* end = capturedOutput + strlen(capturedOutput) - 1;
    if (*end == '\n') {
        *end = '\0';
    }

    // Check the output
    char expectedOutput[] = "Welcome to the Doctor's Office Management System!\n"
                            "Please select an option:\n"
                            "1. Search for a patient\n"
                            "2. Edit patient information\n"
                            "3. Add a patient\n"
                            "4. Add a patient to the queue\n"
                            "5. View patient queue\n"
                            "6. Assign a seat to a patient\n"
                            "7. Display seating arrangement\n"
                            "8. Exit\n"
                            "Enter your choice";

    TEST_ASSERT_EQUAL_STRING(expectedOutput, capturedOutput);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_displayMenu);
    return UNITY_END();
}
