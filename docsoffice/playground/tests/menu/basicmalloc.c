#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // Redirect stdout to a file
    FILE* file = freopen("output.txt", "w", stdout);
    if (file == NULL) {
        printf("Error opening output.txt file.\n");
        return;
    }

    // Call the function to display the menu
    displayMenu();

    // Close the file to flush the output
    fclose(file);
}

int main() {
    testDisplayMenu();

    // Read the content of the file
    FILE* file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Error opening output.txt file.\n");
        return 1;
    }

    // Check the output
    char* line = NULL;
    size_t lineLength = 0;
    int lineCount = 1;
    while (getline(&line, &lineLength, file) != -1) {
        switch (lineCount) {
            case 1:
                if (strcmp(line, "Welcome to the Doctor's Office Management System!\n") != 0) {
                    printf("Error: Unexpected output for line %d.\n", lineCount);
                    fclose(file);
                    free(line);
                    return 1;
                }
                break;
            case 2:
                if (strcmp(line, "Please select an option:\n") != 0) {
                    printf("Error: Unexpected output for line %d.\n", lineCount);
                    fclose(file);
                    free(line);
                    return 1;
                }
                break;
            // Add more checks for other lines if necessary
        }

        lineCount++;
    }

    // Close the file
    fclose(file);

    // Free dynamically allocated memory
    free(line);

    printf("displayMenu test passed.\n");

    return 0;
}
