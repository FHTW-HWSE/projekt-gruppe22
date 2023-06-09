#ifndef WAITINGROOM_H
#define WAITINGROOM_H

#include "patient.h"

#define WAITING_ROOM_ROWS 5
#define WAITING_ROOM_COLS 5

typedef struct {
    Patient* patients[WAITING_ROOM_ROWS][WAITING_ROOM_COLS];
} WaitingRoom;

WaitingRoom* createWaitingRoom();
void destroyWaitingRoom(WaitingRoom* room);
void loadWaitingRoom(WaitingRoom* room);
void saveWaitingRoom(const WaitingRoom* room);
void enqueue(WaitingRoom* room, Patient* patient);
void printWaitingRoom(const WaitingRoom* room);
bool isWaitingRoomFull(const WaitingRoom* room);
bool removePatientFromSeat(const char* insuranceNumber, WaitingRoom* room);

#endif // WAITINGROOM_H
