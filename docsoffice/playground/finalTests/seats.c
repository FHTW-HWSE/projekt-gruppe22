#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "seats.h"
#include "switchcase.h"

#define ROWS 5
#define COLS 5

Seat seats[ROWS][COLS];

void assignSeat(int insuranceNumber) {
    int row = 0, col = 0;
    bool seatAssigned = false;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j].insuranceNumber == 0) {
                seats[i][j].insuranceNumber = insuranceNumber;
                seatAssigned = true;
                row = i;
                col = j;
                break;
            }
        }
        if (seatAssigned) {
            break;
        }
    }

    if (seatAssigned) {
        printf("Seat assigned successfully. Row: %d, Column: %d\n", row, col);
    } else {
        printf("No available seats.\n");
    }
}

void showSeats() {
    printf("Seating Arrangement:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", seats[i][j].insuranceNumber);
        }
        printf("\n");
    }
}

void removeSeat(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        seats[row][col].insuranceNumber = 0;
        printf("Seat at Row: %d, Column: %d removed successfully.\n", row, col);
    } else {
        printf("Invalid seat coordinates.\n");
    }
}

void saveSeatsToFile() {
    FILE* file = fopen("seats.csv", "w");
    if (file == NULL) {
        printf("Error opening seats.csv file.\n");
        return;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(file, "%d,", seats[i][j].insuranceNumber);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}


void loadSeatsFromFile() {
    FILE* file = fopen("seats.csv", "r");
    if (file == NULL) {
        printf("Error opening seats.csv file.\n");
        return;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%d,", &seats[i][j].insuranceNumber);
        }
    }

    fclose(file);
}
