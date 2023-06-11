#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "searchPatient.h"
#include "editPatient.h"
#include "SearchPatientbyInsurance.h"
#include "waitingRoom.h"

Patient* searchPatientbyInsurance(Patient* patients, int numPatients, const char* insuranceNumber) {
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("%s\n", patients[i].insuranceNumber);
            printf("%s\n", patients[i].firstName);
            printf("%s\n", patients[i].lastName);
            
            return &patients[i];
        }
    }

    printf("Patient not found.\n");
    return NULL;
}
