#include "balance.h"
#include "transfer.h"
#include <stdio.h>
#include <string.h>

#define MAX_USERS 10 // Maximum number of registered users

void login() {
    while (1) {
        char account[50];
        char password[50];

        printf("Type in your account: ");
        scanf("%s", account);

        printf("Type in your password: ");
        scanf("%s", password);

        int account_index = -1;

        for (int i = 0; i < accounts_size; i++) {
            if (strcmp(account, accounts[i]) == 0 && strcmp(password, passwords[i]) == 0) {
                printf("\nWelcome, %s!\n", account);
                account_index = i;
                break; // Exit the loop once the account is found
            }
        }

        if (account_index == -1) {
            printf("Invalid account or password.\n");
            break;
        }

        while (1) {
            int choice;

            printf("\n||||| LOGGED IN ||||||\n");
            printf("Choose your action: \n");
            printf("1. Check your balance\n");
            printf("2. Transfer money\n");
            printf("3. Logout\n");

            if (scanf("%d", &choice) != 1) {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }

            char receiver[50];
            int amount_to_transfer = 0;

            if (choice == 1) {
                printf("Balance: %d\n", returnBalance(account));
            } else if (choice == 2) {
                printf("Type in receiver: \n");
                getchar();
                fgets(receiver, sizeof(receiver), stdin);
                receiver[strcspn(receiver, "\n")] = '\0'; // Remove trailing newline character

                int accountFound = 0;

                // Check if receiver is in the array
                for (int i = 0; i < accounts_size; i++) {
                    if (strcmp(receiver, accounts[i]) == 0) {
                        accountFound = 1;
                        break;
                    }
                }

                if (accountFound == 0) {
                    printf("No such account!\n");
                    continue;
                }

                if (strcmp(receiver, account) == 0) {
                    printf("Cannot transfer money to yourself!\n");
                    continue; // Go back to the start of the loop
                }

                printf("Type in amount: \n");
                scanf("%d", &amount_to_transfer);
                if (amount_to_transfer < 0) {
                    printf("Amount must be more than zero!\n");
                    continue;
                }
                transfer(account, receiver, amount_to_transfer);

            } else if (choice == 3) {
                printf("Logged out.\n");
                return;
            } else {
                printf("Invalid choice. Please choose again.\n");
            }
        }
    }
}

void registerUser() {
    if (accounts_size >= MAX_USERS) {
        printf("Maximum number of users reached. Cannot add more users.\n");
        return;
    }

    char new_user[50];
    char new_password[50];

    printf("Name of new user: ");
    getchar();
    fgets(new_user, sizeof(new_user), stdin);
    new_user[strcspn(new_user, "\n")] = '\0'; // Remove trailing newline character

    printf("Password for %s: ", new_user);
    scanf("%s", new_password);

    appendAccounts(0, new_user, new_password);

    printf("New user %s added.\n", new_user);
}

void showRegisteredUsers() {
    for (int i = 0; i < accounts_size; i++) {
        printf("%s", accounts[i]);
        if (i != accounts_size - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
}
