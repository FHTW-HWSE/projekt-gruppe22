#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"

void loadPatients();
void savePatients();
void loadQueue();
void saveQueue();
void displayMenu();

void switchcase() {
    int choice;
    int c;

    do {
        displayMenu();
        printf("Enter your choice: ");

        // Read characters until newline character is encountered
        while ((c = getchar()) != '\n' && c != EOF) {
            // Convert character to integer
            if (c >= '0' && c <= '9') {
                choice = c - '0';
                break;
            }
        }

        if (c == EOF) {
            printf("Error reading input.\n");
            return;
        }

        switch (choice) {
            case 1:
                searchPatient();
                break;
            case 2:
                addNewPatient();
                break;
            case 3:
                addPatientToQueue();
                break;
            case 4:
                showWaitingQueue();
                break;
            case 5:
                dequeuePatient();
                break;
            case 6:
                markPatientAsClear();
                break;
            case 7:
                showSeatingArrangement();
                break;
            case 8:
                editPatient();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
}

// Tests
void searchPatient() {
    printf("Search Patient\n");
}

void addNewPatient() {
    printf("Add New Patient\n");
}

void addPatientToQueue() {
    printf("Add Patient to Queue\n");
}

void showWaitingQueue() {
    printf("Show Waiting Queue\n");
}

void dequeuePatient() {
    printf("Dequeue Patient\n");
}

void markPatientAsClear() {
    printf("Mark Patient as Clear\n");
}

void showSeatingArrangement() {
    printf("Show Seating Arrangement\n");
}

void editPatient() {
    printf("Edit Patient\n");
}
