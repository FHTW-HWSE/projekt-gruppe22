#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
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

void testDisplayMenu() {
    printf("Running displayMenu test...\n");

    // Capture stdout
    fflush(stdout);
    int stdout_backup = dup(fileno(stdout));
    int pipefd[2];
    pipe(pipefd);
    dup2(pipefd[1], fileno(stdout));
    close(pipefd[1]);

    // Call the function to display the menu
    displayMenu();

    // Restore stdout
    fflush(stdout);
    dup2(stdout_backup, fileno(stdout));

    // Read the captured output from the pipe
    char capturedOutput[1024];
    read(pipefd[0], capturedOutput, sizeof(capturedOutput));
    capturedOutput[sizeof(capturedOutput) - 1] = '\0';
    close(pipefd[0]);

    // Trim trailing whitespace characters
    char* end = capturedOutput + strlen(capturedOutput) - 1;
    while (end > capturedOutput && isspace(*end)) {
        *end = '\0';
        end--;
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
                            "Enter your choice: ";

    if (strcmp(capturedOutput, expectedOutput) == 0) {
        printf("displayMenu test passed.\n");
    } else {
        printf("displayMenu test failed.\n");
        printf("Expected output:\n");
        printf("%s\n", expectedOutput);
        printf("Captured output:\n");
        for (int i = 0; i < strlen(capturedOutput); i++) {
            printf("%c - %d\n", capturedOutput[i], capturedOutput[i]);
        }
    }
}

int main() {
    testDisplayMenu();
    return 0;
}
