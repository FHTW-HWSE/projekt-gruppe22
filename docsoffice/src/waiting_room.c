#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "waiting_room.h"
#include "switchcase.h"
#include "menu.h"

WaitingRoom* createWaitingRoom() {
    WaitingRoom* room = malloc(sizeof(WaitingRoom));
    if (room != NULL) {
        // Initialize the waiting room with NULL pointers
        for (int i = 0; i < WAITING_ROOM_ROWS; i++) {
            for (int j = 0; j < WAITING_ROOM_COLS; j++) {
                room->patients[i][j] = NULL;
            }
        }
    }
    return room;
}

void enqueue(WaitingRoom* room, Patient* patient) {
    int row, col;
    for (row = 0; row < WAITING_ROOM_ROWS; row++) {
        for (col = 0; col < WAITING_ROOM_COLS; col++) {
            if (room->patients[row][col] == NULL) {
                room->patients[row][col] = patient;
                return;
            }
        }
    }
    printf("Cannot add more patients to the waiting room. Maximum capacity reached.\n");
}

void printWaitingRoom(WaitingRoom* room) {
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
