#ifndef DOCTORS_OFFICE_H
#define DOCTORS_OFFICE_H

#define MAX_INSURANCE_NUMBER_SIZE 20
#define MAX_FIRST_NAME_SIZE 50
#define MAX_LAST_NAME_SIZE 50
#define MAX_BIRTHDATE_SIZE 15
#define MAX_STREET_SIZE 50
#define MAX_ZIP_CODE_SIZE 10
#define MAX_CITY_SIZE 50

typedef struct {
    char insuranceNumber[MAX_INSURANCE_NUMBER_SIZE];
    char firstName[MAX_FIRST_NAME_SIZE];
    char lastName[MAX_LAST_NAME_SIZE];
    char birthdate[MAX_BIRTHDATE_SIZE];
    char street[MAX_STREET_SIZE];
    char zipCode[MAX_ZIP_CODE_SIZE];
    char city[MAX_CITY_SIZE];
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
void addNewPatient();
void addPatientToQueue();
void showWaitingQueue();
void dequeuePatient();
void markPatientAsClear();
void showSeatingArrangement();
int getFreeSeat();
int getPatientSeat();

#endif  // DOCTORS_OFFICE_H
