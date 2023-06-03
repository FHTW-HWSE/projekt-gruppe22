#ifndef DOCTORS_OFFICE_H
#define DOCTORS_OFFICE_H

typedef struct {
    char insuranceNumber[20];
    char firstName[50];
    char lastName[50];
    char birthdate[15];
    char street[50];
    char zipCode[10];
    char city[50];
    float height;
    float weight;
} Patient;

void loadPatients();
void loadQueue();
void savePatients();
void saveQueue();
void displayMenu();
void searchPatient();
void printSeatNeighbor(int row, int col, int rowOffset, int colOffset);
void editPatient(int index);
void addPatient();
void showQueue();
void dequeuePatient();
void markAsClear();
void showSeatingArrangement();
int getFreeSeat();
int getPatientSeat();
void addNewPatient();

#endif  // DOCTORS_OFFICE_H
