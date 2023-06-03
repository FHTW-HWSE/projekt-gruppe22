#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "doctors_office.h"

#define MAX_PATIENTS 100
#define MAX_QUEUE_SIZE 100

Patient patients[MAX_PATIENTS];
int numPatients = 0;
char queue[MAX_QUEUE_SIZE][20];
int queueSize = 0;
Seat* seatingArrangement[5][5];

void loadPatients() {
    FILE* file = fopen("patients.csv", "r");
    if (file == NULL) {
        printf("Error opening patients.csv file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        strcpy(patients[numPatients].insuranceNumber, token);

        token = strtok(NULL, ",");
        strcpy(patients[numPatients].firstName, token);

        token = strtok(NULL, ",");
        strcpy(patients[numPatients].lastName, token);

        token = strtok(NULL, ",");
        strcpy(patients[numPatients].birthdate, token);

        token = strtok(NULL, ",");
        strcpy(patients[numPatients].street, token);

        token = strtok(NULL, ",");
        strcpy(patients[numPatients].zipCode, token);

        token = strtok(NULL, ",");
        strcpy(patients[numPatients].city, token);

        token = strtok(NULL, ",");
        patients[numPatients].height = atof(token);

        token = strtok(NULL, ",");
        patients[numPatients].weight = atof(token);

        numPatients++;
    }

    fclose(file);
}

void loadQueue() {
    FILE* file = fopen("queue.csv", "r");
    if (file == NULL) {
        printf("Error opening queue.csv file.\n");
        return;
    }

    char line[20];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';  // Remove the trailing newline character
        strcpy(queue[queueSize], line);
        queueSize++;
    }

    fclose(file);
}

void savePatients() {
    FILE* file = fopen("patients.csv", "w");
    if (file == NULL) {
        printf("Error opening patients.csv file.\n");
        return;
    }

    for (int i = 0; i < numPatients; i++) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%.2f,%.2f\n",
                patients[i].insuranceNumber, patients[i].firstName, patients[i].lastName,
                patients[i].birthdate, patients[i].street, patients[i].zipCode,
                patients[i].city, patients[i].height, patients[i].weight);
    }

    fclose(file);
}

void saveQueue() {
    FILE* file = fopen("queue.csv", "w");
    if (file == NULL) {
        printf("Error opening queue.csv file.\n");
        return;
    }

    for (int i = 0; i < queueSize; i++) {
        fprintf(file, "%s\n", queue[i]);
    }

    fclose(file);
}

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
    printf("Enter your choice: ");
}

void searchPatient() {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("Insurance Number: %s\n", patients[i].insuranceNumber);
            printf("First Name: %s\n", patients[i].firstName);
            printf("Last Name: %s\n", patients[i].lastName);
            printf("Birthdate: %s\n", patients[i].birthdate);
            printf("Street: %s\n", patients[i].street);
            printf("Zip Code: %s\n", patients[i].zipCode);
            printf("City: %s\n", patients[i].city);
            printf("Height: %.2f\n", patients[i].height);
            printf("Weight: %.2f\n", patients[i].weight);
            return;
        }
    }

    printf("Patient not found.\n");
}

void editPatient() {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("Current First Name: %s\n", patients[i].firstName);
            printf("Enter new First Name: ");
            scanf("%s", patients[i].firstName);

            printf("Current Last Name: %s\n", patients[i].lastName);
            printf("Enter new Last Name: ");
            scanf("%s", patients[i].lastName);

            printf("Current Birthdate: %s\n", patients[i].birthdate);
            printf("Enter new Birthdate: ");
            scanf("%s", patients[i].birthdate);

            printf("Current Street: %s\n", patients[i].street);
            printf("Enter new Street: ");
            scanf("%s", patients[i].street);

            printf("Current Zip Code: %s\n", patients[i].zipCode);
            printf("Enter new Zip Code: ");
            scanf("%s", patients[i].zipCode);

            printf("Current City: %s\n", patients[i].city);
            printf("Enter new City: ");
            scanf("%s", patients[i].city);

            printf("Current Height: %.2f\n", patients[i].height);
            printf("Enter new Height: ");
            scanf("%f", &patients[i].height);

            printf("Current Weight: %.2f\n", patients[i].weight);
            printf("Enter new Weight: ");
            scanf("%f", &patients[i].weight);

            printf("Patient information updated.\n");
            return;
        }
    }

    printf("Patient not found.\n");
}

void addPatient() {
    if (numPatients == MAX_PATIENTS) {
        printf("Cannot add more patients. Maximum capacity reached.\n");
        return;
    }

    printf("Enter patient details:\n");
    printf("Insurance Number: ");
    scanf("%s", patients[numPatients].insuranceNumber);

    printf("First Name: ");
    scanf("%s", patients[numPatients].firstName);

    printf("Last Name: ");
    scanf("%s", patients[numPatients].lastName);

    printf("Birthdate (yyyy-mm-dd): ");
    scanf("%s", patients[numPatients].birthdate);

    printf("Street: ");
    scanf("%s", patients[numPatients].street);

    printf("Zip Code: ");
    scanf("%s", patients[numPatients].zipCode);

    printf("City: ");
    scanf("%s", patients[numPatients].city);

    printf("Height: ");
    scanf("%f", &patients[numPatients].height);

    printf("Weight: ");
    scanf("%f", &patients[numPatients].weight);

    numPatients++;
    printf("Patient added successfully.\n");
}

void addPatientToQueue() {
    if (queueSize == MAX_QUEUE_SIZE) {
        printf("Cannot add more patients to the queue. Maximum capacity reached.\n");
        return;
    }

    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to add to the queue: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            strcpy(queue[queueSize], insuranceNumber);
            queueSize++;
            printf("Patient added to the queue successfully.\n");
            return;
        }
    }

    printf("Patient not found.\n");
}

void viewPatientQueue() {
    printf("Patient Queue:\n");
    for (int i = 0; i < queueSize; i++) {
        printf("%d. %s\n", i + 1, queue[i]);
    }
}

void assignSeatToPatient() {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < queueSize; i++) {
        if (strcmp(queue[i], insuranceNumber) == 0) {
            int row, column;
            printf("Enter the row (0-4) to assign a seat: ");
            scanf("%d", &row);

            printf("Enter the column (0-4) to assign a seat: ");
            scanf("%d", &column);

            if (seatingArrangement[row][column] != NULL) {
                printf("Seat already occupied. Please select a different seat.\n");
                return;
            }

            seatingArrangement[row][column] = (Seat*)malloc(sizeof(Seat));
            strcpy(seatingArrangement[row][column]->insuranceNumber, insuranceNumber);
            printf("Seat assigned successfully.\n");
            return;
        }
    }

    printf("Patient not found in the queue.\n");
}

void displaySeatingArrangement() {
    printf("Seating Arrangement:\n");
    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 5; column++) {
            if (seatingArrangement[row][column] != NULL) {
                printf("Row %d, Column %d: %s\n", row, column, seatingArrangement[row][column]->insuranceNumber);
            }
        }
    }
}

int main() {
    loadPatients();
    loadQueue();

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                searchPatient();
                break;
            case 2:
                editPatient();
                break;
            case 3:
                addPatient();
                break;
            case 4:
                addPatientToQueue();
                break;
            case 5:
                viewPatientQueue();
                break;
            case 6:
                assignSeatToPatient();
                break;
            case 7:
                displaySeatingArrangement();
                break;
            case 8:
                savePatients();
                saveQueue();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
