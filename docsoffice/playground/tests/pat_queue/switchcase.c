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


void switchcase() {
    int choice;

    do {
        displayMenu();
        printf("\nEnter your choice (0-7): ");

        // Read an integer value using scanf
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please try again (0-7).\n");
            while (getchar() != '\n'); // Clear remaining input
            continue;
        }

        // Clear remaining input if necessary
        while (getchar() != '\n');

        if (choice < 0 || choice > 7) {
            printf("\nInvalid input. Please try again (0-7).\n");
            continue;
        }

        switch (choice) {
            case 1:
                if (searchPatient(patients, numPatients)) {
                    printf("\nPress Enter to continue...");
                    getchar(); // Wait for the user to press Enter
                }
                break;
            case 2:
                addPatient();
				savePatients(); //never forgetti
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            case 3:
                if (editPatient(patients, numPatients)) {
                    printf("Patient information updated.\n");
                }
				savePatients(); //savesavesave
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
                printf("\nShow Seating Arrangement\n");
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            case 0:
                printf("\nExiting program.\n");
				savePatients(); //save
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
