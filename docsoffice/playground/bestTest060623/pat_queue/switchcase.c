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
bool dequeuePatient();
void assignSeat();

void switchcase() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");

        // Read an integer value using scanf
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n'); // Clear remaining input
            continue;
        }

        // Clear remaining input if necessary
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                if (searchPatient(patients, numPatients)) {
                    printf("\nPress Enter to continue...");
                    getchar(); // Wait for the user to press Enter
                }
                break;
            case 2:
                addPatient();
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            case 3:
                if (editPatient(patients, numPatients)) {
                    printf("Patient information updated.\n");
                }
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            case 4:
                addPatientToQueue();
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            case 5:
                showQueue();
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            case 6: {
                char insuranceNumber[20];
                printf("Enter the insurance number of the patient to dequeue: ");
                scanf("%s", insuranceNumber);
                dequeuePatient(insuranceNumber);
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            }
            case 7:
                int insuranceNumber;
                assignSeat(insuranceNumber);
                printf("\nPress Enter to continue...");
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
