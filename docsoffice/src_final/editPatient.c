#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"

bool editPatient(Patient* patients, int numPatients) {
    char insuranceNumber[20];
    printf("\nPlease enter the patient's insurance number (xxxxddmmyy): ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("Current First Name: %s\n", patients[i].firstName);
            printf("Enter new First Name: ");
            scanf("%s", patients[i].firstName);

            printf("Current Last Name: %s\n", patients[i].lastName);
            printf("Enter new Last Name: ");
            scanf("%s", patients[i].lastName);

            printf("Current Birthdate: %s\n", patients[i].birthdate);
            printf("Enter new Birthdate: ");
            scanf("%s", patients[i].birthdate);

            printf("Current Street: %s\n", patients[i].street);
            printf("Enter new Street: ");
            scanf("%s", patients[i].street);
			
			printf("Current Streetnumber: %s\n", patients[i].streetno);
			printf("Enter new Streetnumber: ");
			scanf("%s", patients[i].streetno);

            printf("Current Zip Code: %s\n", patients[i].zipCode);
            printf("Enter new Zip Code: ");
            scanf("%s", patients[i].zipCode);

            printf("Current City: %s\n", patients[i].city);
            printf("Enter new City: ");
            scanf("%s", patients[i].city);

            printf("Current Height in cm: %.2f\n", patients[i].height);
            printf("Enter new Height in cm: ");
            scanf("%f", &patients[i].height);

            printf("Current Weight in kg: %.2f\n", patients[i].weight);
            printf("Enter new Weight in kg: ");
            scanf("%f", &patients[i].weight);

            printf("Patient information updated.\n");
            return true;
        }
    }

    printf("Patient not found.\n");
    return false;
}

