#include "transfer.h"
#include "balance.h"
#include <stdio.h>
#include <string.h>

void transfer(char *from, char *to, int amount) {

    setBalance(from, returnBalance(from) - amount);
    printf("Account: %s, Balance: %d\n", from, returnBalance(from));

    setBalance(to, returnBalance(to) + amount);
    printf("Account: %s, Balance: %d\n", to, returnBalance(to));
}
