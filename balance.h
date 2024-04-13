#ifndef BALANCE_H
#define BALANCE_H
#define MAX_ACCOUNTS 10

extern int balances[MAX_ACCOUNTS];
extern char *accounts[MAX_ACCOUNTS];

extern int accounts_size;

int returnBalance(char *account);
int setBalance(char *account, int amount);
void appendArrays(int newBalance, const char *newAccount);

#endif /* BALANCE_H */
