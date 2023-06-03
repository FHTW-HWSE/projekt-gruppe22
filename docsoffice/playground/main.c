#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "doctors_office.h"

int main() {
    loadPatients();
    loadQueue();

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

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

    savePatients();
    saveQueue();

    return 0;
}
