#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"

int main() {
    // Test addPatientToQueue() and showQueue()
    addPatientToQueue();
    showQueue();

    // Test dequeuePatient()
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to dequeue: ");
    scanf("%s", insuranceNumber);
    dequeuePatient(insuranceNumber);

    // Show the updated queue
    showQueue();

    return 0;
}
