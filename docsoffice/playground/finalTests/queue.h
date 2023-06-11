#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100

extern char queue[MAX_QUEUE_SIZE][20];
extern int queueSize;
bool dequeuePatient();

void loadQueue();
void saveQueue();
void addPatientToQueue();


#endif /* QUEUE_H */
