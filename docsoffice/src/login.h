#ifndef LOGIN_H
#define LOGIN_H

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void loadUsers();
void saveUsers();
bool authenticate(const char* username, const char* password);
void performLogin();
void registerUser();
void loginMenu();

#endif

