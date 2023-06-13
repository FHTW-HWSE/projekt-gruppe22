#include <stdbool.h>

#ifndef SWITCHCASE_H
#define SWITCHCASE_H

void loadPatients();
void savePatients();
void loadQueue();
void saveQueue();
void displayMenu();
bool editPatient();
bool searchPatient();
void addPatientToQueue();
void showQueue();
bool dequeuePatient();
void assignSeat();
bool searchPatientByInsurance();


#endif /* SWITCHCASE_H */
