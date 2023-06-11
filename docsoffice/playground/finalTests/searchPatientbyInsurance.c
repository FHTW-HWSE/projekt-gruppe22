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

Patient* searchPatientbyInsurance(Patient* patients, const char* insuranceNumber) {
    for (int i = 0; i < MAX_PATIENTS; i++) {
        if (strcmp(patients[i].insurance, insuranceNumber) == 0) {
            return &patients[i];
        }
    }
    return NULL;
}
