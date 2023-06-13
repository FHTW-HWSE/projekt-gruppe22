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
#include "SearchPatientbyInsurance.h"

void switchcase() {
    int choice;

    /*WaitingRoom* waitingRoom = createWaitingRoom();
    if (waitingRoom == NULL) {
        printf("Failed to allocate memory for the waiting room.\n");
        exit(1);
    }
    
    loadWaitingRoom(waitingRoom);
	*/
    do {
        displayMenu();
        printf("\nEnter your choice (0-8): ");

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
				/*char insuranceNumber[20];
				printf("Enter the insurance number: ");
                scanf("%s", insuranceNumber);
                getchar();  // Consume newline character
				searchPatientbyInsurance(patients, numPatients, insuranceNumber);
				printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter*/
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
            /*case 6: {
                char insuranceNumber[20];
                printf("Enter the insurance number: ");
                scanf("%s", insuranceNumber);
                getchar();  // Consume newline character
                Patient* patient = searchPatientbyInsurance(patients, numPatients, insuranceNumber);
                if (patient != NULL) {
                    enqueue(waitingRoom, patient);
                    saveWaitingRoom(waitingRoom);
                } 
                
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            }
            case 7: {
                printWaitingRoom(waitingRoom);
                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            }*/
            case 8: 
				dequeuePatient();
				printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
				break;
			
			/*{
                char insuranceNumber[20];
                printf("Enter the insurance number of the patient to dequeue: ");
                scanf("%s", insuranceNumber);
                getchar();

                if (dequeuePatient(insuranceNumber, waitingRoom)) {
                    if (removePatientFromSeat(insuranceNumber, waitingRoom)) {
                        saveWaitingRoom(waitingRoom);
                        printf("Patient with insurance number %s has been removed from the waiting room.\n", insuranceNumber);
                    } else {
                        printf("Patient with insurance number %s not found in the waiting room.\n", insuranceNumber);
                    }
                } else {
                    printf("Patient with insurance number %s not found in the queue.\n", insuranceNumber);
                }

                printf("\nPress Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            }*/
            case 0:
                printf("\nExiting program.\n");
                savePatients();
                //saveWaitingRoom(waitingRoom);
                saveQueue();
                //destroyWaitingRoom(waitingRoom); // Deallocate memory for waiting room
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);
}
