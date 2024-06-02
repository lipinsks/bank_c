#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    char choice;
    while (1) {
        printf("\n|||||| MENU ||||||");
        printf("\nChoose your action:\n");
        printf("1. Register new user\n");
        printf("2. Login\n");
        printf("3. Show registered accounts\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (!isdigit(choice)) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case '1':
                registerUser();
                break;
            case '2':
                login();
                break;
            case '3':
                showRegisteredUsers();
                break;
            case '4':
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }
}
