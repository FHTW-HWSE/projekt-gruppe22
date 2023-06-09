#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

int main() {
    loadPatients();

    // Test the loaded patient data
    printf("Loaded %d patients:\n", numPatients);
    for (int i = 0; i < numPatients; i++) {
        printf("Insurance Number: %s\n", patients[i].insuranceNumber);
        // Print other patient fields...
    }

    // Perform additional tests or operations with the loaded patients

    savePatients();
    cleanup();

    return 0;
}
