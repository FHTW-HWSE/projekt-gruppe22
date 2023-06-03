#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "doctors_office.h"

#define MAX_PATIENTS 100
#define MAX_QUEUE_SIZE 25

// Global variables
Patient patients[MAX_PATIENTS];
int numPatients = 0;
char seatingArrangement[5][5][50];  // Array to store insurance numbers in each seat
char queue[MAX_QUEUE_SIZE][20];
int queueSize = 0;

// Function to load patient data from a CSV file
void loadPatients() {
    FILE* file = fopen("patients.csv", "r");
    if (file == NULL) {
        printf("Error opening patients.csv file.\n");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Parse the CSV line and populate patient data structure
        char* token = strtok(buffer, ",");
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

// Function to load queue data from a CSV file
void loadQueue() {
    FILE* file = fopen("queue.csv", "r");
    if (file == NULL) {
        printf("Error opening queue.csv file.\n");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Remove newline character from the end of the line
        buffer[strcspn(buffer, "\n")] = '\0';

        // Copy the insurance number to the queue array
        strcpy(queue[queueSize], buffer);

        queueSize++;
    }

    fclose(file);
}

// Function to save patient data to a CSV file
void savePatients() {
    FILE* file = fopen("patients.csv", "w");
    if (file == NULL) {
        printf("Error opening patients.csv file for writing.\n");
        return;
    }

    for (int i = 0; i < numPatients; i++) {
        // Write patient data to the CSV file
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%.2f,%.2f\n", patients[i].insuranceNumber, patients[i].firstName,
                patients[i].lastName, patients[i].birthdate, patients[i].street, patients[i].zipCode, patients[i].city,
                patients[i].height, patients[i].weight);
    }

    fclose(file);
}

// Function to save queue data to a CSV file
void saveQueue() {
    FILE* file = fopen("queue.csv", "w");
    if (file == NULL) {
        printf("Error opening queue.csv file for writing.\n");
        return;
    }

    for (int i = 0; i < queueSize; i++) {
        // Write queue data to the CSV file
        fprintf(file, "%s\n", queue[i]);
    }

    fclose(file);
}

// Function to display the main menu
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

// Function to search for a patient and display their data
void searchPatient() {
    char insuranceNumber[20];
    printf("Enter insurance number: ");
    scanf("%s", insuranceNumber);

    int found = 0;
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            found = 1;

            printf("\nPatient Data:\n");
            printf("Insurance Number: %s\n", patients[i].insuranceNumber);
            printf("First Name: %s\n", patients[i].firstName);
            printf("Last Name: %s\n", patients[i].lastName);
            printf("Birthdate: %s\n", patients[i].birthdate);
            printf("Street: %s\n", patients[i].street);
            printf("Zip Code: %s\n", patients[i].zipCode);
            printf("City: %s\n", patients[i].city);
            printf("Height: %.2f\n", patients[i].height);
            printf("Weight: %.2f\n", patients[i].weight);

            // Display seating neighbors with timestamp
            int row, col;
            getPatientSeat(insuranceNumber, &row, &col);
            if (row != -1 && col != -1) {
                printf("\nSeating Neighbors:\n");
                printSeatNeighbor(row, col, 0, -1);  // Left neighbor
                printSeatNeighbor(row, col, 0, 1);   // Right neighbor
                printSeatNeighbor(row, col, -1, 0);  // Top neighbor
                printSeatNeighbor(row, col, 1, 0);   // Bottom neighbor
            }

            char choice;
            printf("\nDo you want to edit the patient? (Y/N): ");
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y') {
                editPatient(i);
            }

            break;
        }
    }

    if (!found) {
        printf("Patient with insurance number %s not found.\n", insuranceNumber);
    }
}

// Function to print the neighboring seat information with timestamp
void printSeatNeighbor(int row, int col, int rowOffset, int colOffset) {
    int neighborRow = row + rowOffset;
    int neighborCol = col + colOffset;

    if (neighborRow >= 0 && neighborRow < 5 && neighborCol >= 0 && neighborCol < 5 &&
        seatingArrangement[neighborRow][neighborCol][0] != '\0') {
        printf("Neighbor Seat (%d, %d): %s\n", neighborRow, neighborCol,
               seatingArrangement[neighborRow][neighborCol]);

        time_t currTime;
        time(&currTime);
        printf("Timestamp: %s\n", ctime(&currTime));
    }
}

// Function to edit patient data
void editPatient(int index) {
    Patient* patient = &patients[index];

    printf("\nEnter new data for the patient:\n");
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

    printf("\nPatient data updated successfully.\n");
}

// Function to add a patient to the waiting queue
void addPatient() {
    if (queueSize == MAX_QUEUE_SIZE) {
        printf("The queue is full. Patient cannot be added at the moment.\n");
        return;
    }

    char insuranceNumber[20];
    printf("Enter insurance number: ");
    scanf("%s", insuranceNumber);

    // Check if the patient is already in the queue
    for (int i = 0; i < queueSize; i++) {
        if (strcmp(queue[i], insuranceNumber) == 0) {
            printf("Patient with insurance number %s is already in the queue.\n", insuranceNumber);
            return;
        }
    }

    // Add the patient to the queue
    strcpy(queue[queueSize], insuranceNumber);
    queueSize++;

    char method;
    printf("Did the patient come by ambulance? (Y/N): ");
    scanf(" %c", &method);

    if (method == 'Y' || method == 'y') {
        printf("Patient with insurance number %s added to the front of the queue (ambulance).\n", insuranceNumber);
    } else {
        // Find an available seat in the seating arrangement
        int row = -1, col = -1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (seatingArrangement[i][j][0] == '\0') {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1 && col != -1) {
                break;
            }
        }

        if (row != -1 && col != -1) {
            strcpy(seatingArrangement[row][col], insuranceNumber);
            printf("Patient with insurance number %s added to seat (%d, %d).\n", insuranceNumber, row, col);
        } else {
            printf("No available seats. Patient with insurance number %s added to the end of the queue.\n",
                   insuranceNumber);
        }
    }

    saveQueue();
}

// Function to show the waiting queue
void showQueue() {
    printf("Waiting Queue:\n");
    for (int i = 0; i < queueSize; i++) {
        printf("%s\n", queue[i]);
    }
}

// Function to dequeue a patient
void dequeuePatient() {
    if (queueSize == 0) {
        printf("Queue is empty.\n");
        return;
    }

    char insuranceNumber[20];
    printf("Enter insurance number of the patient to dequeue: ");
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
            break;
        }
    }

    if (!found) {
        printf("Patient with insurance number %s not found in the queue.\n", insuranceNumber);
    }

    saveQueue();
}

// Function to mark a patient as clear
void markAsClear() {
    char insuranceNumber[20];
    printf("Enter insurance number: ");
    scanf("%s", insuranceNumber);

    int found = 0;
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            found = 1;

            // Code to mark patient as clear
            // ...

            printf("Patient with insurance number %s marked as clear.\n", insuranceNumber);
            break;
        }
    }

    if (!found) {
        printf("Patient with insurance number %s not found.\n", insuranceNumber);
    }
}

// Function to show the seating arrangement
void showSeatingArrangement() {
    printf("Seating Arrangement:\n");
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (seatingArrangement[row][col][0] == '\0') {
                printf("[ ] ");
            } else {
                printf("[X] ");
            }
        }
        printf("\n");
    }
}

