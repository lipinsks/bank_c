#ifndef BALANCE_H
#define BALANCE_H

extern int balances[];
extern char *accounts[3];

extern int accounts_size;

int returnBalance(char *account);
int setBalance(char *account, int amount);

#endif /* BALANCE_H */
