#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "patient.h"
#include "waitingRoom.h"
#include "searchPatient.h"
#include "SearchPatientbyInsurance.h"

WaitingRoom waitingRoom;

void loadWaitingRoom(WaitingRoom* room, Patient* patients) {
    FILE* file = fopen("waiting_room.csv", "r");
    if (file == NULL) {
        printf("Error opening waiting_room.csv file.\n");
        return;
    }

    // Clear the waiting room array before loading the data
    memset(room->patients, 0, sizeof(room->patients));

    char line[256];
    int row = 0;
    int col = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character from the line
        line[strcspn(line, "\n")] = '\0';

        // Add the patient to the waiting room
        Patient* patient = searchPatientbyInsurance(patients);
        if (patient != NULL) {
            room->patients[row][col] = patient;
            col++;
            if (col == WAITING_ROOM_COLS) {
                col = 0;
                row++;
                if (row == WAITING_ROOM_ROWS) {
                    break;  // Reached maximum waiting room capacity
                }
            }
        }
    }

    fclose(file);
}




void saveWaitingRoom(const WaitingRoom* room) {
    FILE* file = fopen("waiting_room.csv", "w");
    if (file == NULL) {
        printf("Error opening waiting_room.csv file.\n");
        return;
    }

    for (int row = 0; row < WAITING_ROOM_ROWS; row++) {
        for (int col = 0; col < WAITING_ROOM_COLS; col++) {
            Patient* patient = room->patients[row][col];
            if (patient != NULL) {
                fprintf(file, "%s\n", patient->insuranceNumber);
            }
        }
    }

    fclose(file);
}

void enqueue(WaitingRoom* room, Patient* patients) {
    if (isWaitingRoomFull(room)) {
        printf("Cannot add more patients to the waiting room. Maximum capacity reached.\n");
        return;
    }

    for (int row = 0; row < WAITING_ROOM_ROWS; row++) {
        for (int col = 0; col < WAITING_ROOM_COLS; col++) {
            if (room->patients[row][col] == NULL) {
                room->patients[row][col] = (Patient*)malloc(sizeof(Patient));
                if (room->patients[row][col] == NULL) {
                    printf("Error allocating memory for the patient.\n");
                    return;
                }
                memcpy(room->patients[row][col], patients, sizeof(Patient));
                return;
            }
        }
    }
}




void printWaitingRoom(const WaitingRoom* room) {
    printf("Waiting room:\n");
    for (int row = 0; row < WAITING_ROOM_ROWS; row++) {
        for (int col = 0; col < WAITING_ROOM_COLS; col++) {
            Patient* patient = room->patients[row][col];
            if (patient != NULL) {
                printf("%d,%d: %s %s\n", row + 1, col + 1, patient->firstName, patient->lastName);
            }
        }
    }
}

bool isWaitingRoomFull(const WaitingRoom* room) {
    for (int row = 0; row < WAITING_ROOM_ROWS; row++) {
        for (int col = 0; col < WAITING_ROOM_COLS; col++) {
            if (room->patients[row][col] == NULL) {
                return false;
            }
        }
    }
    return true;
}


/*void addPatientToWaitingRoom(WaitingRoom* room) {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to add to the waiting room: ");
    scanf("%s", insuranceNumber);

    Patient* patient = searchPatientbyInsurance(insuranceNumber);
    if (patient == NULL) {
        printf("Patient not found.\n");
        return;
    }

    enqueue(room, patient);
    saveWaitingRoom(room);  // Save the updated waiting room to file
}

bool dequeuePatientFromWaitingRoom(WaitingRoom* room, const char* insuranceNumber) {
    for (int row = 0; row < WAITING_ROOM_ROWS; row++) {
        for (int col = 0; col < WAITING_ROOM_COLS; col++) {
            Patient* patient = room->patients[row][col];
            if (patient != NULL && strcmp(patient->insuranceNumber, insuranceNumber) == 0) {
                room->patients[row][col] = NULL;
                saveWaitingRoom(room);  // Save the updated waiting room to file
                return true;
            }
        }
    }

    return false;
}
*/