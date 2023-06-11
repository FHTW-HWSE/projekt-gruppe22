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
#include "waitingRoom.h"

void switchcase() {
    int choice;

    do {
        displayMenu();
        printf("\nEnter your choice (0-8): ");

        // Read an integer value using scanf
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please try again (0-8).\n");
            while (getchar() != '\n'); // Clear remaining input
            continue;
        }

        // Clear remaining input if necessary
        while (getchar() != '\n');

        if (choice < 0 || choice > 8) {
            printf("\nInvalid input. Please try again (0-8).\n");
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
                savePatients();
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            case 3:
                if (editPatient(patients, numPatients)) {
                    printf("Patient information updated.\n");
                }
                savePatients();
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
            case 7: {
                
                /*printf("Enter the insurance number of the patient to assign a seat: ");
                scanf("%s", insuranceNumber);*/
				//if (searchPatientbyInsurance(patients, numPatients)) {
				//addPatientToWaitingRoom();
				//}
				//else {
                //    printf("Patient not found.\n");
                //}
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
                
            }
            /*case 8:
				printWaitingRoom(waitingRoom);
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;*/
            case 0:
                printf("\nExiting program.\n");
                savePatients();
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);
}
