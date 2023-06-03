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
                addPatient();
                break;
            case 3:
                showQueue();
                break;
            case 4:
                dequeuePatient();
                break;
            case 5:
                markAsClear();
                break;
            case 6:
                showSeatingArrangement();
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 7);

    return 0;
}
