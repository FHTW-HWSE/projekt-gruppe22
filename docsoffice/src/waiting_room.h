#ifndef WAITING_ROOM_H
#define WAITING_ROOM_H

#include "patient.h"

#define WAITING_ROOM_ROWS 5
#define WAITING_ROOM_COLS 5

typedef struct {
    Patient* patients[WAITING_ROOM_ROWS][WAITING_ROOM_COLS];
} WaitingRoom;

WaitingRoom* createWaitingRoom();
void enqueue(WaitingRoom* room, Patient* patient);
void printWaitingRoom(WaitingRoom* room);

#endif  // WAITING_ROOM_H
