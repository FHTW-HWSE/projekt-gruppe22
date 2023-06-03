#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "patient.h"
#include "menu.h"
#include "switchcase.h"


Patient patients[MAX_PATIENTS]; // Remove the pointer declaration

int numPatients = 0;
int maxPatients = MAX_PATIENTS;


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

        i++;
    }

    fclose(file);

    // Assign tempPatients to patients and update numPatients
    memcpy(patients, tempPatients, maxPatients * sizeof(Patient));
    numPatients = i;

    free(tempPatients);
}


void savePatients() {
    FILE* file = fopen("patients.csv", "w");
    if (file == NULL) {
        printf("Error opening patients.csv file.\n");
        return;
    }

    for (int i = 0; i < numPatients; i++) {
        // Code for writing patient data to the file...
    }

    fclose(file);
}

void cleanup() {
 
}


