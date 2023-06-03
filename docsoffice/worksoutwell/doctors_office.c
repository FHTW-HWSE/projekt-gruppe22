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
    printf("2. Add a patient to the waiting queue\n");
    printf("3. Show the waiting queue\n");
    printf("4. Dequeue a patient\n");
    printf("5. Mark a patient as clear\n");
    printf("6. Show the seating arrangement\n");
    printf("7. Exit\n");
}

void searchPatient() {
    char insuranceNumber[20];
    printf("Enter insurance number: ");
    scanf("%s", insuranceNumber);

    int found = 0;
    int index = -1;
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found) {
        Patient* patient = &patients[index];
        printf("\nInsurance Number: %s\n", patient->insuranceNumber);
        printf("First Name: %s\n", patient->firstName);
        printf("Last Name: %s\n", patient->lastName);
        printf("Birthdate: %s\n", patient->birthdate);
        printf("Street: %s\n", patient->street);
        printf("Zip Code: %s\n", patient->zipCode);
        printf("City: %s\n", patient->city);
        printf("Height: %.2f\n", patient->height);
        printf("Weight: %.2f\n", patient->weight);

        int row, col;
        if (getPatientSeat(insuranceNumber, &row, &col)) {
            printf("\nSeating Neighbours:\n");
            printSeatNeighbor(row, col, -1, 0);
            printSeatNeighbor(row, col, 1, 0);
            printSeatNeighbor(row, col, 0, -1);
            printSeatNeighbor(row, col, 0, 1);
        }
    } else {
        printf("Patient with insurance number %s not found.\n", insuranceNumber);
    }
}

void printSeatNeighbor(int row, int col, int rowOffset, int colOffset) {
    int neighborRow = row + rowOffset;
    int neighborCol = col + colOffset;

    if (neighborRow >= 0 && neighborRow < 5 && neighborCol >= 0 && neighborCol < 5 &&
        seatingArrangement[neighborRow][neighborCol][0] != '\0') {
        char insuranceNumber[20];
        strcpy(insuranceNumber, seatingArrangement[neighborRow][neighborCol]);

        time_t currentTimestamp = time(NULL);
        struct tm* currentTime = localtime(&currentTimestamp);
        printf("- Seat (%d, %d): %s (Visited at %02d:%02d)\n",
               neighborRow, neighborCol, insuranceNumber,
               currentTime->tm_hour, currentTime->tm_min);
    }
}

int getPatientSeat(const char* insuranceNumber, int* row, int* col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (seatingArrangement[i][j][0] != '\0' &&
                strcmp(seatingArrangement[i][j], insuranceNumber) == 0) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

void editPatient(int index) {
    Patient* patient = &patients[index];

    printf("\nInsurance Number: %s\n", patient->insuranceNumber);
    printf("First Name: %s\n", patient->firstName);
    printf("Last Name: %s\n", patient->lastName);
    printf("Birthdate: %s\n", patient->birthdate);
    printf("Street: %s\n", patient->street);
    printf("Zip Code: %s\n", patient->zipCode);
    printf("City: %s\n", patient->city);
    printf("Height: %.2f\n", patient->height);
    printf("Weight: %.2f\n", patient->weight);

    printf("\nEnter new information:\n");
    printf("First Name: ");
    scanf("%s", patient->firstName);
    printf("Last Name: ");
    scanf("%s", patient->lastName);
    printf("Birthdate: ");
    scanf("%s", patient->birthdate);
    printf("Street: ");
    scanf("%s", patient->street);
    printf("Zip Code: ");
    scanf("%s", patient->zipCode);
    printf("City: ");
    scanf("%s", patient->city);
    printf("Height: ");
    scanf("%f", &patient->height);
    printf("Weight: ");
    scanf("%f", &patient->weight);

    savePatients();

    printf("Patient information updated successfully.\n");
}

void addPatient() {
    char insuranceNumber[20];
    printf("Enter insurance number: ");
    scanf("%s", insuranceNumber);

    int found = 0;
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Patient with insurance number %s already exists.\n", insuranceNumber);
        return;
    }

    if (queueSize == MAX_QUEUE_SIZE) {
        printf("Queue is full. Cannot add more patients.\n");
        return;
    }

    strcpy(queue[queueSize], insuranceNumber);
    queueSize++;

    char visitType[20];
    printf("Visit Type (1: Self, 2: Ambulance): ");
    scanf("%s", visitType);

    if (strcmp(visitType, "1") == 0) {
        int row, col;
        if (getFreeSeat(&row, &col)) {
            strcpy(seatingArrangement[row][col], insuranceNumber);
        } else {
            printf("No available seat. Patient added to the queue.\n");
        }
    }

    saveQueue();

    printf("Patient with insurance number %s added to the waiting queue.\n", insuranceNumber);
}

void showQueue() {
    printf("\nWaiting Queue:\n");
    for (int i = 0; i < queueSize; i++) {
        printf("%d. %s\n", i + 1, queue[i]);
    }
}

void dequeuePatient() {
    char insuranceNumber[20];
    printf("Enter insurance number: ");
    scanf("%s", insuranceNumber);

    int found = 0;
    for (int i = 0; i < queueSize; i++) {
        if (strcmp(queue[i], insuranceNumber) == 0) {
            found = 1;

            // Remove the patient from the queue
            for (int j = i; j < queueSize - 1; j++) {
                strcpy(queue[j], queue[j + 1]);
            }
            queueSize--;

            // Free the seat if the patient had one
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    if (seatingArrangement[row][col][0] != '\0' &&
                        strcmp(seatingArrangement[row][col], insuranceNumber) == 0) {
                        seatingArrangement[row][col][0] = '\0';
                        break;
                    }
                }
            }

            printf("Patient with insurance number %s dequeued.\n", insuranceNumber);
            saveQueue();
            return;
        }
    }

    if (!found) {
        printf("Patient with insurance number %s is not in the queue.\n", insuranceNumber);
    }
}

void markAsClear() {
    char insuranceNumber[20];
    printf("Enter insurance number: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("\nPatient Details:\n");
            printf("Insurance Number: %s\n", patients[i].insuranceNumber);
            printf("First Name: %s\n", patients[i].firstName);
            printf("Last Name: %s\n", patients[i].lastName);
            printf("Birthdate: %s\n", patients[i].birthdate);
            printf("Street: %s\n", patients[i].street);
            printf("Zip Code: %s\n", patients[i].zipCode);
            printf("City: %s\n", patients[i].city);
            printf("Height: %.2f\n", patients[i].height);
            printf("Weight: %.2f\n", patients[i].weight);

            printf("\nPatient marked as clear.\n");
            return;
        }
    }

    printf("Patient with insurance number %s not found.\n", insuranceNumber);
}

void showSeatingArrangement() {
    printf("\nSeating Arrangement:\n");
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (seatingArrangement[row][col][0] != '\0') {
                printf("Seat (%d, %d): %s\n", row, col, seatingArrangement[row][col]);
            }
        }
    }
}

int getFreeSeat(int* row, int* col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (seatingArrangement[i][j][0] == '\0') {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}
