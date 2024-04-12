#include "balance.h"
#include "transfer.h"
#include <stdio.h>
#include <string.h>

void login() {
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
        return; // Exit the function if account not found
    }

    while (1) {
        int choice = 10;

        printf("Choose your action: \n");
        printf("1. Check your balance\n");
        printf("2. Transfer money\n");
        printf("3. Logout\n");
        printf("4. Exit program\n");

        scanf("%d", &choice);

        char receiver[50]; // Allocate memory for the receiver name
        int amount_to_transfer = 0;

        if (choice == 1) {
            printf("Balance: %d\n", returnBalance(account));
        } else if (choice == 2) {
            printf("Type in receiver and amount: \n");
            scanf("%s %d", receiver, &amount_to_transfer);
            transfer(account, receiver, amount_to_transfer);
        } else if (choice == 3) {
            printf("Logged out.\n");
            break; // Exit the loop if user chooses to logout
        } else if (choice == 4) {
            printf("Exiting program.\n");
            return; // Exit the function if user chooses to exit program
        } else {
            printf("Invalid choice. Please choose again.\n");
        }
    }
}
