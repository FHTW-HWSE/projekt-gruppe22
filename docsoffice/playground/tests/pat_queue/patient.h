#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 100

typedef struct {
    char insuranceNumber[20];
    char firstName[50];
    char lastName[50];
    char birthdate[20];
    char street[50];
    char zipCode[10];
    char city[50];
    float height;
    float weight;
} Patient;

extern Patient patients[MAX_PATIENTS];
extern int numPatients;

void loadPatients();
void savePatients();

#endif /* PATIENT_H */
