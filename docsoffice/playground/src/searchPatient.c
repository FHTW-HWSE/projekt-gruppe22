#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"


void searchPatient(Patient* patients, int numPatients) {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("Insurance Number: %s\n", patients[i].insuranceNumber);
            printf("First Name: %s\n", patients[i].firstName);
            printf("Last Name: %s\n", patients[i].lastName);
            printf("Birthdate: %s\n", patients[i].birthdate);
            printf("Street: %s\n", patients[i].street);
            printf("Zip Code: %s\n", patients[i].zipCode);
            printf("City: %s\n", patients[i].city);
            printf("Height: %.2f\n", patients[i].height);
            printf("Weight: %.2f\n", patients[i].weight);
            return;
        }
    }

    printf("Patient not found.\n");
}
