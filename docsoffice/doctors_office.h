#ifndef DOCTORS_OFFICE_H
#define DOCTORS_OFFICE_H

#define MAX_PATIENTS 100
#define MAX_QUEUE_SIZE 100

typedef struct {
    char insuranceNumber[20];
    char firstName[50];
    char lastName[50];
    char birthdate[15];
    char street[50];
    char zipCode[10];
    char city[50];
    double height;
    double weight;
} Patient;

extern Patient patients[MAX_PATIENTS];
extern int numPatients;

extern char queue[MAX_QUEUE_SIZE][20];
extern int queueSize;

void loadPatients();
void savePatients();

void loadQueue();
void saveQueue();

void displayMenu();

void searchPatient();
void editPatient();
void addPatient();

void addToQueue();
void showQueue();
void dequeuePatient();
//void markCleared();

void showSeatingArrangement();

#endif /* DOCTORS_OFFICE_H */
