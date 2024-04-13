#include "balance.h"
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 10

// accounts and their balances are only linked to each other using indexes
int balances[MAX_ACCOUNTS] = {100, 200, 300};
char *accounts[MAX_ACCOUNTS] = {"lebron", "stephen", "luka"};
int accounts_size = 3;

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

void appendArrays(int newBalance, const char *newAccount) {
    if(accounts_size < MAX_ACCOUNTS) {
        balances[accounts_size] = newBalance;
        accounts[accounts_size] = strdup(newAccount); // strdup dynamically allocates memory for the new string
        if(accounts[accounts_size] == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        accounts_size++;
    } else {
        printf("Arrays are already full!\n");
    }
}
