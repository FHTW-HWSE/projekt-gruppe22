#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "editPatient.h"
#include "seats.h"

extern void loadPatients();
extern void loadQueue();
extern void savePatients();
extern void saveQueue();
extern void switchcase();
extern void addPatientToQueue();
extern bool dequeuePatient();
//extern void loadSeatsFromFile;

int main() {
    // Load data
    loadPatients();
    loadQueue();
	loadSeatsFromFile();

    // Perform operations
    switchcase();

    // Save data
    savePatients();
    saveQueue();

    return 0;
}
