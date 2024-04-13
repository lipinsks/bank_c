#include "balance.h"
#include "transfer.h"
#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10 // Maximum number of registered users

void menu();

int main() {
    menu();
    return 0;
}

void registerUser() {
    if (accounts_size >= MAX_USERS) {
        printf("Maximum number of users reached. Cannot add more users.\n");
        return;
    }

    char new_user[50];
    printf("Name of new user: ");
    getchar(); // Consume newline left by previous input
    fgets(new_user, sizeof(new_user), stdin);
    new_user[strcspn(new_user, "\n")] = '\0'; // Remove trailing newline character
    appendArrays(0, new_user);
    printf("New user %s added.\n", new_user);
}

void showRegisteredUsers() {
    // Implement logic to show registered users here
    printf("Functionality not implemented yet.\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\nChoose your action:\n");
        printf("1. Register new user\n");
        printf("2. Login\n");
        printf("3. Show registered accounts\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                showRegisteredUsers();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }
}
