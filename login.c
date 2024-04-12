#include "balance.h"
#include "transfer.h"
#include <stdio.h>
#include <string.h>

void login() {
    char account[50]; // Allocate memory for the account name

    printf("Type in your account: ");
    scanf("%s", account);

    int account_found = 0; // Flag to indicate whether the account is found

    for (int i = 0; i < accounts_size; i++) {
        if (strcmp(account, accounts[i]) == 0) {
            printf("Welcome, %s!\n", account);
            account_found = 1;
            break; // Exit the loop once the account is found
        }
    }

    if (!account_found) {
        printf("Account not found.\n");
    }
}
