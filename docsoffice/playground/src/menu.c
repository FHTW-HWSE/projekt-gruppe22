#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include "menu.h"
#include "switchcase.h"
#include "patient.h"
#include "queue.h"
#include "searchPatient.h"

void displayMenu() {
    printf("Welcome to the Doctor's Office Management System!\n");
    printf("Please select an option:\n");
    printf("1.	Search for a patient\n");
    printf("2.  	Add a patient\n");  		//Dafuq
    printf("3.	Edit patient information\n");
    printf("4.	Add a patient to the queue\n");
    printf("5.	View patient queue\n");
    printf("6.	Assign a seat to a patient\n");
    printf("7.	Display seating arrangement\n");
    printf("0.	Exit\n");
    fflush(stdout);  // Ensure the output is flushed immediately
}
