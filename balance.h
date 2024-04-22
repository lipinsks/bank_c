#ifndef BALANCE_H
#define BALANCE_H
#define MAX_ACCOUNTS 10

extern int balances[MAX_ACCOUNTS];
extern char *accounts[MAX_ACCOUNTS];
extern char *passwords[MAX_ACCOUNTS];

extern int accounts_size;

int returnBalance(char *account);
int setBalance(char *account, int amount);
void appendAccounts(int newBalance, const char *newAccount, char *password);

#endif /* BALANCE_H */
