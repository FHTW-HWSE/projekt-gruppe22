#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"
#include "switchcase.h"
#include "waitingRoom.h"


char queue[MAX_QUEUE_SIZE][20];
int queueSize = 0;

void loadQueue() {
    FILE* file = fopen("queue.csv", "r");
    if (file == NULL) {
        printf("Error opening queue file.\n");
        return;
    }

    // Clear the queue array before loading the data
    queueSize = 0;
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        memset(queue[i], 0, sizeof(queue[i]));
    }

    char line[MAX_QUEUE_SIZE];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character from the line
        line[strcspn(line, "\n")] = '\0';

        // Add the patient to the queue
        strcpy(queue[queueSize], line);
        queueSize++;
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

void addPatientToQueue() {
    if (queueSize == MAX_QUEUE_SIZE) {
        printf("Cannot add more patients to the queue. Maximum capacity reached.\n");
        return;
    }

    char insuranceNumber[20];
    printf("Enter the insurance number of the patient to add to the queue: ");
    scanf("%s", insuranceNumber);

    // Check if the patient is already in the queue
    for (int i = 0; i < queueSize; i++) {
        if (strcmp(queue[i], insuranceNumber) == 0) {
            printf("Patient with insurance number %s is already in the queue.\n", insuranceNumber);
            return;
        }
    }

    // Check if the patient exists in the patient database
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].insuranceNumber, insuranceNumber) == 0) {
            strcpy(queue[queueSize], insuranceNumber);
            queueSize++;
            printf("Patient added to the queue successfully.\n");
            saveQueue();  // Save the updated queue to the file
            return;
        }
    }

    printf("Patient not found.\n");
}





void showQueue() {
    loadQueue();

    if (queueSize == 0) {
        printf("The queue is empty.\n");
        return;
    }

    printf("Patient Queue:\n");
    for (int i = 0; i < queueSize; i++) {
        printf("%d. %s\n", i + 1, queue[i]);
    }
}

bool dequeuePatient(const char* insuranceNumber) {
    if (queueSize == 0) {
        printf("Queue is empty. No patients to dequeue.\n");
        return false;
    }

    int found = 0;
    int i;

    for (i = 0; i < queueSize; i++) {
        if (strcmp(queue[i], insuranceNumber) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        // Shift elements to the left to overwrite the dequeued patient
        memmove(queue[i], queue[i + 1], (queueSize - i - 1) * sizeof(queue[0]));
        memset(queue[queueSize - 1], 0, sizeof(queue[0])); // Clear the last element
        queueSize--;
        printf("Patient with insurance number %s dequeued successfully.\n", insuranceNumber);
        saveQueue(); // Save the updated queue to the file
        return true;
    } else {
        printf("Patient with insurance number %s not found in the queue.\n", insuranceNumber);
        return false;
    }
}





