Welcome to the doctor's office program by Jai SINGH ic22b037!

A working version of the program is in the docsoffice/src_final folder. The final tests are located in docsoffice/unittests_final. The program is compiled by ./compile.sh which includes all necessary source files. 
These two directories are the most important. Other files outside of those directories are old testscenarios, testfunctions, beta, etc..

The username and password for the administrator is hardcoded and is "admin" "admin". The user saving doesn't work yet. There must be 3 .csv files. patients.csv queue.csv and waiting_room.csv. In write mode they made problems.

The implemented and tested functions are everything but waitingRoom.c and waitingRoom.h. Those files are tested but still under construction. In docsoffice/playground/finalTests it almost works but is still a bit buggy.

In the playground folder there are numerous tests. Most of the tests are located in the folder docsoffice/playground/finalTests and /pat_queue.  

ToDo: User-Login doesnt work after restart (only hardcoded admin). Therefore loadUsers() is not in the main atm. File saves with blank line as well. / Seating arrangement and priority call. / Bugfix: Rows and Colums get always written into .csv again. / Delete patient.

Requirements:

Doctor's Office with a 5x5 waiting room. Patients must be added and saved. They must be added to a queue and also be able to be dequeued. If a patient arrives by ambulance they get priority in the queue. 
