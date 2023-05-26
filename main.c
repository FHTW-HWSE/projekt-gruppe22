#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "doctors_office.h" //.h file for testing

int main() {
    loadPatients(); //function to load patient.csv
    loadQueue(); //function to load queue.csv
    srand(time(NULL)); //timestamps

    int choice; //GUI cases
    do {
        displayMenu(); //function to show main menu
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                searchPatient(); //function to search patients
                break;
            case 2:
                addPatientToQueue(); //add Patient to Queue TODO: change with add Patients / rearrange
                break;
            case 3:
                showQueue();
                break;
            case 4:
                dequeuePatient(); //function to dequeue a patient and removing from seating arrangement even if they haven't shown up to the doctor
                break;
            case 5:
                markAsClear(); //function to mark as clear after showing up at the doctor
                break;
            case 6:
                showSeatingArrangement();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            case 8:
                addNewPatient(); //TODO rearrange
                break;
            case 9: {
                int seatIndex = getPatientSeat(); //TODO this is shit
                if (seatIndex != -1) {
                    int row = seatIndex / 5;
                    int col = seatIndex % 5;
                    editPatient(index);
                } else {
                    printf("Patient not found in the seating arrangement.\n");
                }
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    savePatients(); //make sure to save stuff
    saveQueue(); // as said

    return 0;
}

