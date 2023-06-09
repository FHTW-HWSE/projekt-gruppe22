#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100

typedef struct {
    char insuranceNumber[20];
} Seat;

extern char queue[MAX_QUEUE_SIZE][20];
extern int queueSize;
extern Seat* seatingArrangement[5][5];

void loadQueue();
void saveQueue();
void addPatientToQueue();
void showQueue();
void dequeuePatient(const char* insuranceNumber);
void assignSeatToPatient();

#endif /* QUEUE_H */
