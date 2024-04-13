#include "balance.h"
#include "transfer.h"
#include "login.h"
#include <stdio.h>

int main() {
    appendArrays(69420, "szymi");
    appendArrays(5555, "franek");

    // Print the updated arrays
    printf("\nAccounts:\n");
    for(int i = 0; i < accounts_size; i++) {
        printf("%s ", accounts[i]);
    }
    printf("\n");
    printf("Balances:\n");
    for(int i = 0; i < accounts_size; i++) {
        printf("%d ", balances[i]);
    }
    return 0;
}
