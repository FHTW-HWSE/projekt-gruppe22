#ifndef DOCTORS_OFFICE_H
#define DOCTORS_OFFICE_H

#define MAX_PATIENTS 100
#define MAX_QUEUE_SIZE 100

typedef struct {
	char firstName[50];
	char lastName[50];
    char insuranceNumber[20];
    char name[50];
    char birthdate[20];
    char street[50];
    char zipCode[10];
    char city[50];
    float height;
    float weight;
} Patient;

typedef struct Seat {
    char insuranceNumber[20];
    struct Seat* prev;
    struct Seat* next;
} Seat;

extern Patient patients[MAX_PATIENTS];
extern int numPatients;

extern char queue[MAX_QUEUE_SIZE][20];
extern int queueSize;

extern Seat* seatingArrangement[5][5];

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

void showSeatingArrangement();

#endif /* DOCTORS_OFFICE_H */
