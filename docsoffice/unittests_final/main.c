#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "editPatient.h"
#include "waitingRoom.h"
#include "login.h"

extern void loadPatients();
extern void loadQueue();
extern void savePatients();
extern void saveQueue();
extern void switchcase();
extern void addPatientToQueue();
extern bool dequeuePatient();
extern void loadUsers();
extern void loginMenu();

//extern void loadSeatsFromFile;

int main() {
	
	// Perform login
	
	loginMenu();
    
    	
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
	saveUsers();

    return 0;
}
