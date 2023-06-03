#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100

extern char queue[MAX_QUEUE_SIZE][20];
extern int queueSize;

void loadQueue();
void saveQueue();

#endif /* QUEUE_H */
