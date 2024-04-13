#include "balance.h"
#include "transfer.h"
#include <stdio.h>
#include <string.h>

void login() {
    while (1) { // Loop indefinitely until user chooses to exit
        char account[50]; // Allocate memory for the account name

        printf("Type in your account: ");
        scanf("%s", account);

        int account_index = -1; // Variable to store the index of the account

        for (int i = 0; i < accounts_size; i++) {
            if (strcmp(account, accounts[i]) == 0) {
                printf("Welcome, %s!\n", account);
                account_index = i;
                break; // Exit the loop once the account is found
            }
        }

        if (account_index == -1) {
            printf("Account not found.\n");
            continue; // Go back to the beginning of the loop to allow logging in again
        }

        while (1) {
            int choice = 10;

            printf("Choose your action: \n");
            printf("1. Check your balance\n");
            printf("2. Transfer money\n");
            printf("3. Logout\n");
            printf("4. Exit program\n");
            printf("5. Add new user\n");

            scanf("%d", &choice);

            char receiver[50]; // Allocate memory for the receiver name
            int amount_to_transfer = 0;

            if (choice == 1) {
                printf("Balance: %d\n", returnBalance(account));
            } else if (choice == 2) {
                printf("Type in receiver: \n");
                scanf("%s", receiver);
                if (strcmp(receiver, account) == 0) {
                    printf("Cannot transfer money to yourself!\n");
                    continue; // Go back to the start of the loop
                }
                printf("Type in amount: \n");
                scanf("%d", &amount_to_transfer);
                if (amount_to_transfer < 0) {
                    printf("Amount must be more than zero!\n");
                    continue; // Go back to the start of the loop
                }
                transfer(account, receiver, amount_to_transfer);
            } else if (choice == 3) {
                printf("Logged out.\n");
                break; // Exit the inner loop if user chooses to logout
            } else if (choice == 4) {
                printf("Exiting program.\n");
                return; // Exit the function if user chooses to exit program
            } else if (choice == 5) {
                if(accounts_size < MAX_ACCOUNTS) {
                    char new_user[50]; // Allocate enough memory to store the new user's name
                    printf("Name of new user: ");
                    getchar(); // Consume newline left by previous scanf
                    fgets(new_user, 50, stdin); // Read the whole line including spaces
                    // Remove trailing newline character
                    new_user[strcspn(new_user, "\n")] = '\0';
                    appendArrays(0, new_user);
                    printf("New user %s added.\n", new_user);
                } else {
                    printf("Maximum number of users reached. Cannot add more users.\n");
                }
            }
            else {
                printf("Invalid choice. Please choose again.\n");
            }
        }
    }
}
