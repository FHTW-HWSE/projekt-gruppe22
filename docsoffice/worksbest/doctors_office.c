#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "doctors_office.h"

#define MAX_QUEUE_SIZE 100

Patient patients[MAX_QUEUE_SIZE];
int numPatients = 0;
char queue[MAX_QUEUE_SIZE][20];
int queueSize = 0;
char seatingArrangement[5][5][20];

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
                patients[i].birthdate, patients[i].street, patients[i].zipCode, patients[i].city,
                patients[i].height, patients[i].weight);
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
    printf("\n========== Doctors Office ==========\n");
    printf("1. Search for a patient and show their data\n");
    printf("2. Add a new patient\n");
    printf("3. Add a patient to the waiting queue\n");
    printf("4. Show the waiting queue\n");
    printf("5. Dequeue a patient\n");
    printf("6. Mark a patient as clear\n");
    printf("7. Show the seating arrangement\n");
    printf("8. Edit patient information\n");
    printf("0. Exit\n");
}

void searchPatient() {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient: ");
    scanf("%s", insuranceNumber);

    int found = 0;
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("\nPatient Found:\n");
            printf("Insurance Number: %s\n", patients[i].insuranceNumber);
            printf("First Name: %s\n", patients[i].firstName);
            printf("Last Name: %s\n", patients[i].lastName);
            printf("Birthdate: %s\n", patients[i].birthdate);
            printf("Street: %s\n", patients[i].street);
            printf("Zip Code: %s\n", patients[i].zipCode);
            printf("City: %s\n", patients[i].city);
            printf("Height: %.2f\n", patients[i].height);
            printf("Weight: %.2f\n", patients[i].weight);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
}

void addNewPatient() {
    if (numPatients == MAX_QUEUE_SIZE) {
        printf("Cannot add more patients. Maximum capacity reached.\n");
        return;
    }

    printf("\nEnter patient details:\n");
    printf("Insurance Number: ");
    scanf("%s", patients[numPatients].insuranceNumber);
    printf("First Name: ");
    scanf("%s", patients[numPatients].firstName);
    printf("Last Name: ");
    scanf("%s", patients[numPatients].lastName);
    printf("Birthdate (DD/MM/YYYY): ");
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

    printf("\nPatient added successfully.\n");
}

void addPatientToQueue() {
    if (queueSize == MAX_QUEUE_SIZE) {
        printf("Cannot add patient to the queue. Maximum capacity reached.\n");
        return;
    }

    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to add to the queue: ");
    scanf("%s", insuranceNumber);

    int found = 0;
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            strcpy(queue[queueSize], patients[i].insuranceNumber);
            queueSize++;
            printf("Patient added to the queue successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found. Unable to add to the queue.\n");
    }
}

void showSeatingArrangement() {
    printf("\nSeating Arrangement:\n");
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (strcmp(seatingArrangement[row][col], "") == 0) {
                printf("[Empty]\t");
            } else {
                printf("[%s]\t", seatingArrangement[row][col]);
            }
        }
        printf("\n");
    }
}

void dequeuePatient() {
    if (queueSize == 0) {
        printf("Queue is empty. No patients to dequeue.\n");
        return;
    }

    printf("Dequeued patient with insurance number: %s\n", queue[0]);

    // Shift the queue to the left
    for (int i = 0; i < queueSize - 1; i++) {
        strcpy(queue[i], queue[i + 1]);
    }

    queueSize--;
}

void markPatientAsClear() {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to mark as clear: ");
    scanf("%s", insuranceNumber);

    int found = 0;
    for (int i = 0; i < queueSize; i++) {
        if (strcmp(queue[i], insuranceNumber) == 0) {
            printf("Patient with insurance number %s is marked as clear.\n", queue[i]);
            strcpy(queue[i], "");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found in the queue.\n");
    }
}

void editPatientInformation() {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to edit: ");
    scanf("%s", insuranceNumber);

    int found = 0;
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("\nEnter new patient details:\n");
            printf("Insurance Number: ");
            scanf("%s", patients[i].insuranceNumber);
            printf("First Name: ");
            scanf("%s", patients[i].firstName);
            printf("Last Name: ");
            scanf("%s", patients[i].lastName);
            printf("Birthdate (DD/MM/YYYY): ");
            scanf("%s", patients[i].birthdate);
            printf("Street: ");
            scanf("%s", patients[i].street);
            printf("Zip Code: ");
            scanf("%s", patients[i].zipCode);
            printf("City: ");
            scanf("%s", patients[i].city);
            printf("Height: ");
            scanf("%f", &patients[i].height);
            printf("Weight: ");
            scanf("%f", &patients[i].weight);

            printf("Patient information updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found. Unable to edit information.\n");
    }
}

void showQueue() {
    if (queueSize == 0) {
        printf("Queue is empty. No patients in the waiting queue.\n");
        return;
    }

    printf("\nWaiting Queue:\n");
    for (int i = 0; i < queueSize; i++) {
        printf("%d. %s\n", i + 1, queue[i]);
    }
}

int main() {
    loadPatients();
    loadQueue();

    int choice;
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

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
                showQueue();
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
                editPatientInformation();
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    savePatients();
    saveQueue();

    return 0;
}


