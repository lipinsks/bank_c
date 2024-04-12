#include "transfer.h"
#include "balance.h"
#include <stdio.h>
#include <string.h>

void transfer(char *from, char *to, int amount) {

    int decreased_amount = returnBalance(from) - amount;
    int increased_amount = returnBalance(from) + amount;

    if (decreased_amount >= 0) {

        setBalance(from, decreased_amount);
        printf("Account: %s, Balance: %d\n", from, returnBalance(from));

        setBalance(to, increased_amount);
        printf("Account: %s, Balance: %d\n", to, returnBalance(to));

    } else {
        printf("Not enough in the bank.\n");
        printf("balance: %d, chosen amount: %d\n", returnBalance(from), amount);
    }
}
