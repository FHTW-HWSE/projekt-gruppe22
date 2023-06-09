#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

int maxPatients = 0;
int numPatients = 0;
Patient* patients = NULL;

void loadPatients();

int main() {
    loadPatients();

    // Print the loaded patients
    for (int i = 0; i < numPatients; i++) {
        printf("Insurance Number: %s\n", patients[i].insuranceNumber);
        printf("First Name: %s\n", patients[i].firstName);
        printf("Last Name: %s\n", patients[i].lastName);
        printf("Birthdate: %s\n", patients[i].birthdate);
        printf("Street: %s\n", patients[i].street);
        printf("Zip Code: %s\n", patients[i].zipCode);
        printf("City: %s\n", patients[i].city);
        printf("Height: %.2f\n", patients[i].height);
        printf("Weight: %.2f\n", patients[i].weight);
        printf("\n");
    }

    // Cleanup and free memory
    free(patients);
    patients = NULL;
    numPatients = 0;
    maxPatients = 0;

    return 0;
}

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
