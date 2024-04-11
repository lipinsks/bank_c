#include <stdio.h>
#include <string.h> // Include the string.h header for strcmp function

int returnBalance(char *account);
void setBalance(char *account, int amount);
void transfer(char *from, char *to);

int balances[] = {100, 200, 300};
char *accounts[3] = {"lebron", "stephen", "luka"};
int accounts_size = sizeof(accounts) / sizeof(accounts[0]);

int main() {
    transfer("luka", "lebron");
    return 0;
}

void transfer(char *from, char *to) {
    int amount = 0;
    printf("Amount: ");
    scanf("%d", &amount);

    for (int i = 0; i < accounts_size; i++) {
        if (strcmp(accounts[i], from) == 0) {
            setBalance(from, balances[i] - amount);
        }
    }

    printf("account: %s, balance: %d, \n", from , returnBalance(from));

    for (int i = 0; i < accounts_size; i++) {
        if (strcmp(accounts[i], to) == 0) {
            setBalance(to, balances[i] + amount);
        }
    }

    printf("account: %s, balance: %d, \n", to , returnBalance(to));
}

void setBalance(char *account, int amount) {
    for (int i = 0; i < accounts_size; i++) {
        if (strcmp(account, accounts[i]) == 0) { // Use strcmp for string comparison
            balances[i] = amount;
        }
    }
}

int returnBalance(char *account) {
    for (int i = 0; i < accounts_size; i++) {
        if (strcmp(account, accounts[i]) == 0) { // Use strcmp for string comparison
            return balances[i];
        }
    }
}


