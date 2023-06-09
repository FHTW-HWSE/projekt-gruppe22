#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include "menu.h"

void displayMenu() {
    printf("Welcome to the Doctor's Office Management System!\n");
    printf("Please select an option:\n");
    printf("1. Search for a patient\n");
    printf("2. Edit patient information\n");
    printf("3. Add a patient\n");
    printf("4. Add a patient to the queue\n");
    printf("5. View patient queue\n");
    printf("6. Assign a seat to a patient\n");
    printf("7. Display seating arrangement\n");
    printf("8. Exit\n");
    printf("Enter your choice");
    fflush(stdout);  // Ensure the output is flushed immediately
}
