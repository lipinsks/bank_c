#include "balance.h"
#include <stdio.h>
#include <string.h>

int balances[] = {100, 200, 300};
char *accounts[3] = {"lebron", "stephen", "luka"};

int accounts_size = sizeof(accounts) / sizeof(accounts[0]);

int returnBalance(char *account) {
    for (int i = 0; i < accounts_size; i++) {
        if (strcmp(account, accounts[i]) == 0) {
            return balances[i];
        }
    }
    return -1; // Indicate account not found
}

int setBalance(char *account, int amount) {
    for (int i = 0; i < accounts_size; i++) {
        if (strcmp(account, accounts[i]) == 0) {
            balances[i] = amount;
            return 0; // Success
        }
    }
    return -1; // Indicate account not found
}
