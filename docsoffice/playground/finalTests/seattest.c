#include <stdio.h>
#include "seats.h"

int main() {
    initializeSeats();

    // Assign seats
    assignSeat(123);
    assignSeat(456);
    assignSeat(789);

    // Show current seating arrangement
    showSeats();

    // Remove a seat
    removeSeat(456);

    // Show current seating arrangement
    showSeats();

    // Show neighbours of seats with a specific timestamp
    showNeighboursByTimestamp(0);

    // Load seats from a file
    loadSeatsFromFile("seats.csv");

    // Save seats to a file
    saveSeatsToFile("seats_backup.csv");

    return 0;
}
