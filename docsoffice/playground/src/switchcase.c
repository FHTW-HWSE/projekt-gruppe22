#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "searchPatient.h"

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
            else if (c != ' ') {
                printf("Invalid choice. Please try again.\n");
                while ((c = getchar()) != '\n' && c != EOF); // Clear remaining input
                choice = -1; // Set choice to an invalid value
                break;
            }
        }

        if (c == EOF) {
            printf("Error reading input.\n");
            return;
        }

        if (choice != -1) {
            switch (choice) {
                case 1:
                    searchPatient(patients, numPatients);
                    break;
                case 2:
                    addPatient();
                    break;
                case 3:
                    editPatient();
                    break;
                case 4:
                    addPatientToQueue();
                    break;
                case 5:
                    showWaitingQueue();
                    break;
                case 6:
                    dequeuePatient();
                    break;
                case 7:
                    showSeatingArrangement();
                    break;
                case 0:
                    printf("\nExiting program.\n");
                    exit(0);
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }
    } while (choice != 8);
}


// Tests

void addPatientToQueue() {
    printf("\nAdd Patient to Queue\n");
}

void showWaitingQueue() {
    printf("\nShow Waiting Queue\n");
}

void dequeuePatient() {
    printf("\nDequeue Patient\n");
}

void showSeatingArrangement() {
    printf("\nShow Seating Arrangement\n");
}

void editPatient() {
    printf("\nEdit Patient\n");
}
