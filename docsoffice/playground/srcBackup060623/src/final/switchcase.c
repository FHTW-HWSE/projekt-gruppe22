#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "searchPatient.h"
#include "editPatient.h"

void loadPatients();
void savePatients();
void loadQueue();
void saveQueue();
void displayMenu();
bool editPatient();
bool searchPatient();
void addPatientToQueue();
void showQueue();
void dequeuePatient();
//void assignSeatToPatient();

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
                    if (searchPatient(patients, numPatients)) {
                        printf("\nPress Enter to continue...");
                        while ((c = getchar()) != '\n' && c != EOF); // Clear remaining input
                        getchar(); // Wait for the user to press Enter
                    }
                    break;
                case 2:
                    addPatient();
                    printf("\nPress Enter to continue...");
                    while ((c = getchar()) != '\n' && c != EOF); // Clear remaining input
                    getchar(); // Wait for the user to press Enter
                    break;
                case 3:
                    if (editPatient(patients, numPatients)) {
                        printf("Patient information updated.\n");
                    }
                    printf("\nPress Enter to continue...");
                    while ((c = getchar()) != '\n' && c != EOF); // Clear remaining input
                    getchar(); // Wait for the user to press Enter
                    break;
                case 4:
                    addPatientToQueue();
                    printf("\nPress Enter to continue...");
                    while ((c = getchar()) != '\n' && c != EOF); // Clear remaining input
                    getchar(); // Wait for the user to press Enter
                    break;
                case 5:
                    showQueue();
                    printf("\nPress Enter to continue...");
                    while ((c = getchar()) != '\n' && c != EOF); // Clear remaining input
                    getchar(); // Wait for the user to press Enter
                    break;
                case 6: {
                    char insuranceNumber[20];
                    printf("Enter the insurance number of the patient to dequeue: ");
                    scanf("%s", insuranceNumber);
                    dequeuePatient(insuranceNumber);
                    printf("\nPress Enter to continue...");
                    while ((c = getchar()) != '\n' && c != EOF); // Clear remaining input
                    getchar(); // Wait for the user to press Enter
                    break;
                }
                case 7:
                    void assignSeatToPatient();
                    printf("\nPress Enter to continue...");
                    while ((c = getchar()) != '\n' && c != EOF); // Clear remaining input
                    getchar(); // Wait for the user to press Enter
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
    } while (1);
}


/* void addPatientToQueue() {
    printf("\nAdd Patient to Queue\n");
}
*/
/*void showQueue() {
    printf("\nShow Waiting Queue\n");
}
*/
/*void dequeuePatient() {
    printf("\nDequeue Patient\n");
}
*/
void assignSeatToPatient() {
    printf("\nShow Seating Arrangement\n");
}
