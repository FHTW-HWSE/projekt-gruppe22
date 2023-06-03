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
    printf("3. Add a new patient\n");
    printf("4. Add patient to waiting queue\n");
    printf("5. Show waiting queue\n");
    printf("6. Dequeue patient\n");
    printf("7. Mark patient as cleared\n");
    printf("8. Show seating arrangement\n");
    printf("9. Exit\n");
}

void searchPatient() {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("Patient found!\n");
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
            printf("Patient found!\n");
            printf("Enter new first name: ");
            scanf("%s", patients[i].firstName);
            printf("Enter new last name: ");
            scanf("%s", patients[i].lastName);
            printf("Enter new birthdate: ");
            scanf("%s", patients[i].birthdate);
            printf("Enter new street: ");
            scanf("%s", patients[i].street);
            printf("Enter new zip code: ");
            scanf("%s", patients[i].zipCode);
            printf("Enter new city: ");
            scanf("%s", patients[i].city);
            printf("Enter new height: ");
            scanf("%lf", &patients[i].height);
            printf("Enter new weight: ");
            scanf("%lf", &patients[i].weight);
            printf("Patient information updated.\n");
            return;
        }
    }

    printf("Patient not found.\n");
}

void addPatient() {
    if (numPatients == MAX_QUEUE_SIZE) {
        printf("The maximum number of patients has been reached.\n");
        return;
    }

    printf("Enter insurance number: ");
    char insuranceNumber[20];
    scanf("%s", insuranceNumber);

    // Check if the patient already exists
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("Patient with the same insurance number already exists.\n");
            return;
        }
    }

    // Add the new patient
    strcpy(patients[numPatients].insuranceNumber, insuranceNumber);
    printf("Enter first name: ");
    scanf("%s", patients[numPatients].firstName);
    printf("Enter last name: ");
    scanf("%s", patients[numPatients].lastName);
    printf("Enter birthdate: ");
    scanf("%s", patients[numPatients].birthdate);
    printf("Enter street: ");
    scanf("%s", patients[numPatients].street);
    printf("Enter zip code: ");
    scanf("%s", patients[numPatients].zipCode);
    printf("Enter city: ");
    scanf("%s", patients[numPatients].city);
    printf("Enter height: ");
    scanf("%lf", &patients[numPatients].height);
    printf("Enter weight: ");
    scanf("%lf", &patients[numPatients].weight);

    numPatients++;
    printf("Patient added successfully.\n");
}

void addToQueue() {
    if (queueSize == MAX_QUEUE_SIZE) {
        printf("The waiting queue is full.\n");
        return;
    }

    char insuranceNumber[20];
    printf("Enter the insurance number of the patient: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            strcpy(queue[queueSize], insuranceNumber);
            queueSize++;
            printf("Patient added to the waiting queue.\n");
            return;
        }
    }

    printf("Patient not found.\n");
}

void showQueue() {
    printf("Waiting Queue:\n");
    for (int i = 0; i < queueSize; i++) {
        printf("%d. %s\n", i + 1, queue[i]);
    }
}

void dequeuePatient() {
    if (queueSize == 0) {
        printf("The waiting queue is empty.\n");
        return;
    }

    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to dequeue: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < queueSize; i++) {
        if (strcmp(queue[i], insuranceNumber) == 0) {
            for (int j = i; j < queueSize - 1; j++) {
                strcpy(queue[j], queue[j + 1]);
            }
            queueSize--;
            printf("Patient dequeued.\n");
            return;
        }
    }

    printf("Patient not found in the waiting queue.\n");
}

/*void markCleared() {
    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to mark as cleared: ");
    scanf("%s", insuranceNumber);

    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            printf("Patient cleared.\n");
            return;
        }
    }

    printf("Patient not found.\n");
}*/

void showSeatingArrangement() {
    printf("Seating Arrangement:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%s\t", seatingArrangement[i][j]);
        }
        printf("\n");
    }
}

int main() {
    loadPatients();
    loadQueue();

    int option;
    do {
        displayMenu();
        printf("Enter your choice (1-9): ");
        scanf("%d", &option);

        switch (option) {
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
                addToQueue();
                break;
            case 5:
                showQueue();
                break;
            case 6:
                dequeuePatient();
                break;
            case 7:
                dequeuePatient();
                break;
            case 8:
                showSeatingArrangement();
                break;
            case 9:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        printf("\n");
    } while (option != 9);

    savePatients();
    saveQueue();

    return 0;
}
