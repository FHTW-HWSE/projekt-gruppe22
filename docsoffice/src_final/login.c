#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "login.h"
#include "menu.h"
#include "switchcase.h"

#define MAX_USERS 100

User users[MAX_USERS];
int numUsers = 0;
bool loggedIn = false;

void loadUsers() {
    FILE* file = fopen("users.csv", "r");
    if (file == NULL) {
        printf("Failed to open users.csv for reading.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (numUsers >= MAX_USERS) {
            printf("Maximum number of users reached. Unable to load more users.\n");
            break;
        }

        char* username = strtok(line, ",");
        char* password = strtok(NULL, ",");
        if (username != NULL && password != NULL) {
            strcpy(users[numUsers].username, username);
            strcpy(users[numUsers].password, password);
            numUsers++;
        }
    }

    fclose(file);
}

void saveUsers() {
    FILE* file = fopen("users.csv", "w");
    if (file == NULL) {
        printf("Failed to open users.csv for writing.\n");
        return;
    }

    for (int i = 0; i < numUsers; i++) {
        fprintf(file, "%s,%s\n", users[i].username, users[i].password);
    }

    fclose(file);
}

bool authenticate(const char* username, const char* password) {
    printf("Attempting authentication: username=%s, password=%s\n", username, password);

    if (strcasecmp(username, "admin") == 0 && strcasecmp(password, "admin") == 0) {
        loggedIn = true;
        return true;
    }

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            loggedIn = true;
            return true;
        }
    }

    return false;
}


bool isLoggedIn() {
    return loggedIn;
}

void loginMenu() {
	
    int choice;
    char input[10];
    //char username[MAX_USERNAME_LENGTH];
    //char password[MAX_PASSWORD_LENGTH];

    do {
        printf("\n=== Login Menu ===\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", input);

        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            continue;
        }

        switch (choice) {
            case 1:
                performLogin();
                if (isLoggedIn()) {
                    return;
                } else {
                    break;
                }
            case 2:
                registerUser();
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
}

void performLogin() {
	loadUsers();
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("\n=== Login ===\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    printf("Please enter your password: ");
    scanf("%s", password);

    if (authenticate(username, password)) {
        printf("Login successful!\n");
        return;

    } else {
        printf("Invalid username or password. Login failed.\n");
    }
}

void registerUser() {
    char adminUsername[MAX_USERNAME_LENGTH];
    char adminPassword[MAX_PASSWORD_LENGTH];

    printf("\n=== User Registration ===\n");
    printf("Please enter the admin username: ");
    scanf("%s", adminUsername);

    printf("Please enter the admin password: ");
    scanf("%s", adminPassword);

    if (strcasecmp(adminUsername, "admin") == 0 && strcasecmp(adminPassword, "admin") == 0) {
        char newUsername[MAX_USERNAME_LENGTH];
        char newPassword[MAX_PASSWORD_LENGTH];

        printf("Please enter a new username: ");
        scanf("%s", newUsername);

        // Check if the username already exists
        for (int i = 0; i < numUsers; i++) {
            if (strcasecmp(users[i].username, newUsername) == 0) {
                printf("Username already exists. Please choose a different username.\n");
                return;
            }
        }

        printf("Please enter a new password: ");
        scanf("%s", newPassword);

        strcpy(users[numUsers].username, newUsername);
        strcpy(users[numUsers].password, newPassword);
        numUsers++;

        printf("User registration successful!\n");

        saveUsers();
    } else {
        printf("Invalid admin credentials. User registration failed.\n");
    }
}
