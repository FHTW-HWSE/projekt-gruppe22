#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "editPatient.h"
#include "seats.h"
#include "waitingRoom.h"

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
	
	 /*WaitingRoom* waitingRoom = createWaitingRoom();  // Create the waiting room

    if (waitingRoom == NULL) {
        printf("Failed to create the waiting room.\n");
        return 1;
    }
	*/

    // Perform operations
    switchcase();

    // Save data
    savePatients();
    saveQueue();

    return 0;
}
