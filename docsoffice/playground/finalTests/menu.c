#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <ctype.h>
#include "menu.h"
#include "switchcase.h"
#include "patient.h"
#include "queue.h"
#include "searchPatient.h"
#include "waitingRoom.h"

void displayMenu() {
    printf("\nWelcome to Jai Singh's Doctor's Office!\n");
    printf("\nPlease select an option:\n");
    printf("1.  Search for a patient\n");
    printf("2.  Add a patient\n");
    printf("3.  Edit patient information\n");
    printf("4.  Add a patient to the queue\n");
    printf("5.  View patient queue\n");
	printf("6.  Assign Seat to a Patient\n");
	printf("7.  Show Seating Arrangement\n");
    printf("8.  Dequeue Patient\n");
    printf("0.  Exit\n");
    fflush(stdout); // Ensure the output is flushed immediately
}
