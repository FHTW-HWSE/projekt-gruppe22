#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "patient.h"
#include "waitingRoom.h"
#include "searchPatient.h"
#include "SearchPatientbyInsurance.h"
#include "queue.h"

WaitingRoom waitingRoom;

WaitingRoom* createWaitingRoom() {
    WaitingRoom* room = (WaitingRoom*)malloc(sizeof(WaitingRoom));
    if (room != NULL) {
        memset(room->patients, 0, sizeof(room->patients));
    }
    return room;
}

void destroyWaitingRoom(WaitingRoom* room) {
    if (room != NULL) {
        for (int row = 0; row < WAITING_ROOM_ROWS; row++) {
            for (int col = 0; col < WAITING_ROOM_COLS; col++) {
                Patient* patient = room->patients[row][col];
                if (patient != NULL) {
                    free(patient);
                }
            }
        }
        free(room);
    }
}

void loadWaitingRoom(WaitingRoom* room) {
    FILE* file = fopen("waiting_room.csv", "r");
    if (file == NULL) {
        printf("Error opening waiting_room.csv file.\n");
        return;
    }

    memset(room->patients, 0, sizeof(room->patients));

    char line[256];
    int row = 0;
    int col = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        Patient* patient = (Patient*)malloc(sizeof(Patient));
        if (patient == NULL) {
            printf("Error allocating memory for the patient.\n");
            break;
        }
        strcpy(patient->insuranceNumber, line);
        room->patients[row][col] = patient;

        col++;
        if (col == WAITING_ROOM_COLS) {
            col = 0;
            row++;
            if (row == WAITING_ROOM_ROWS) {
                break;
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
                printf("Saving patient at row %d, column %d\n", row, col); // Debug statement
                fprintf(file, "%s,%s,%s\n", patient->insuranceNumber, patient->firstName, patient->lastName);
            }
        }
    }

    fclose(file);
}


void enqueue(WaitingRoom* room, Patient* patient) {
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
                memcpy(room->patients[row][col], patient, sizeof(Patient));
                printf("Patient with insurance number %s added to the waiting room.\n", patient->insuranceNumber);
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
                printf("Row: %d, Column %d: %s %s %s\n", row + 1, col + 1, patient->insuranceNumber, patient->firstName, patient->lastName);
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

bool removePatientFromSeat(const char* insuranceNumber, WaitingRoom* room) {
    for (int row = 0; row < WAITING_ROOM_ROWS; row++) {
        for (int col = 0; col < WAITING_ROOM_COLS; col++) {
            Patient* patient = room->patients[row][col];
            if (patient != NULL && strcmp(patient->insuranceNumber, insuranceNumber) == 0) {
                free(patient);
                room->patients[row][col] = NULL;
                //printf("Patient with insurance number %s has been removed from the waiting room.\n", insuranceNumber);
                return true;
            }
        }
    }

    printf("Patient with insurance number %s not found in the waiting room.\n", insuranceNumber);
    return false;
}
