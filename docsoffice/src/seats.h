#ifndef SEATS_H
#define SEATS_H

typedef struct {
    int insuranceNumber;
} Seat;

void assignSeat(int insuranceNumber);
void showSeats();
void removeSeat(int row, int col);
void saveSeatsToFile();
void loadSeatsFromFile();

#endif
