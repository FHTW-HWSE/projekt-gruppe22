#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "menu.h"

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
