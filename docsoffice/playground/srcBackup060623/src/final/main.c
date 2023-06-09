#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "editPatient.h"
//#include "seat.h"

extern void loadPatients();
extern void loadQueue();
extern void savePatients();
extern void saveQueue();
extern void switchcase();
extern void addPatientToQueue();
extern void dequeuePatient();
//extern void initializeSeats();

int main() {
    // Load data
    loadPatients();
    loadQueue();

    // Perform operations
    switchcase();

    // Save data
    savePatients();
    saveQueue();

    return 0;
}
