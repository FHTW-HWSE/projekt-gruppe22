#include <stdio.h>
#include <stdlib.h>

void searchPatient() {
    printf("Search Patient\n");
}

void addNewPatient() {
    printf("Add New Patient\n");
}

void addPatientToQueue() {
    printf("Add Patient to Queue\n");
}

void showWaitingQueue() {
    printf("Show Waiting Queue\n");
}

void dequeuePatient() {
    printf("Dequeue Patient\n");
}

void markPatientAsClear() {
    printf("Mark Patient as Clear\n");
}

void showSeatingArrangement() {
    printf("Show Seating Arrangement\n");
}

void editPatient() {
    printf("Edit Patient\n");
}

void displayMenu() {
    printf("Menu Options:\n");
    printf("1. Search Patient\n");
    printf("2. Add New Patient\n");
    printf("3. Add Patient to Queue\n");
    printf("4. Show Waiting Queue\n");
    printf("5. Dequeue Patient\n");
    printf("6. Mark Patient as Clear\n");
    printf("7. Show Seating Arrangement\n");
    printf("8. Edit Patient\n");
    printf("0. Exit\n");
}

int main() {
    int choice;
    char* input = (char*)malloc(256 * sizeof(char));
    if (input == NULL) {
        printf("Failed to allocate memory for input array.\n");
        return 1;
    }

    do {
        displayMenu();
        printf("Enter your choice: ");
        fgets(input, 256, stdin);

        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                searchPatient();
                break;
            case 2:
                addNewPatient();
                break;
            case 3:
                addPatientToQueue();
                break;
            case 4:
                showWaitingQueue();
                break;
            case 5:
                dequeuePatient();
                break;
            case 6:
                markPatientAsClear();
                break;
            case 7:
                showSeatingArrangement();
                break;
            case 8:
                editPatient();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    free(input);

    return 0;
}
