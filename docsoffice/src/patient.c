#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "patient.h"
#include "menu.h"
#include "switchcase.h"

Patient* patients = NULL;
int numPatients = 0;
int maxPatients = 0;


void loadPatients() {
    FILE* file = fopen("patients.csv", "r");
    if (file == NULL) {
        printf("Error opening patients.csv file.\n");
        return;
    }

    char line[256];
    Patient* tempPatients = malloc(maxPatients * sizeof(Patient));
    if (tempPatients == NULL) {
        printf("Error allocating memory for patients.\n");
        fclose(file);
        return;
    }

    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        if (i >= maxPatients) {
            maxPatients += 10;  // Increase capacity by 10
            Patient* newTemp = realloc(tempPatients, maxPatients * sizeof(Patient));
            if (newTemp == NULL) {
                printf("Error reallocating memory for patients.\n");
                fclose(file);
                free(tempPatients);
                return;
            }
            tempPatients = newTemp;  // Update tempPatients pointer with the new memory address
        }

        char* token = strtok(line, ",");
        strcpy(tempPatients[i].insuranceNumber, token);

        // Remaining code for populating the patient fields...
        token = strtok(NULL, ",");
        strcpy(tempPatients[i].firstName, token);

        token = strtok(NULL, ",");
        strcpy(tempPatients[i].lastName, token);

        token = strtok(NULL, ",");
        strcpy(tempPatients[i].birthdate, token);

        token = strtok(NULL, ",");
        strcpy(tempPatients[i].street, token);

        token = strtok(NULL, ",");
        strcpy(tempPatients[i].zipCode, token);

        token = strtok(NULL, ",");
        strcpy(tempPatients[i].city, token);

        token = strtok(NULL, ",");
        tempPatients[i].height = atof(token);

        token = strtok(NULL, ",");
        tempPatients[i].weight = atof(token);

        i++;
    }

    fclose(file);

    // Assign tempPatients to patients and update numPatients
    patients = malloc(i * sizeof(Patient));
    if (patients == NULL) {
        printf("Error allocating memory for patients.\n");
        free(tempPatients);
        return;
    }

    memcpy(patients, tempPatients, i * sizeof(Patient));
    numPatients = i;
    maxPatients = i;

    free(tempPatients);
}



void savePatients() {
    FILE* file = fopen("patients.csv", "w");
    if (file == NULL) {
        printf("Error opening patients.csv file.\n");
        return;
    }

    for (int i = 0; i < numPatients; i++) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%.2f,%.2f\n",
            patients[i].insuranceNumber,
            patients[i].firstName,
            patients[i].lastName,
            patients[i].birthdate,
            patients[i].street,
            patients[i].zipCode,
            patients[i].city,
            patients[i].height,
            patients[i].weight
        );
    }

    fclose(file);
}


void cleanup() {
    free(patients);
    patients = NULL;
    numPatients = 0;
    maxPatients = 0;
}

void addPatient() {
    if (numPatients == maxPatients) {
        // Increase capacity by 10 when maximum capacity is reached
        int newMaxPatients = maxPatients + 10;
        Patient* newPatients = realloc(patients, newMaxPatients * sizeof(Patient));
        if (newPatients == NULL) {
            printf("Error reallocating memory for patients.\n");
            return;
        }
        patients = newPatients;
        maxPatients = newMaxPatients;
    }

    printf("Please enter the patient's details:\n");
    printf("Insurance Number (xxxxddmmyy): ");
    scanf("%s", patients[numPatients].insuranceNumber);

    printf("First Name: ");
    scanf("%s", patients[numPatients].firstName);

    printf("Last Name: ");
    scanf("%s", patients[numPatients].lastName);

    printf("Birthdate (yyyy-mm-dd): ");
    scanf("%s", patients[numPatients].birthdate);

    printf("Street and number: ");
    scanf("%s", patients[numPatients].street);

    printf("Zip Code: ");
    scanf("%s", patients[numPatients].zipCode);

    printf("City: ");
    scanf("%s", patients[numPatients].city);

    printf("Height in cm: ");
    scanf("%f", &patients[numPatients].height);

    printf("Weight in cm: ");
    scanf("%f", &patients[numPatients].weight);

    numPatients++;
    printf("Patient added successfully.\n");
	
}




