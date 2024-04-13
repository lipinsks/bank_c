#include "balance.h"
#include "transfer.h"
#include "login.h"
#include <stdio.h>

// TODO registering new user needs to be outside of login loop,
// TODO add menu, from which its possible to choose action like login, or register
// TODO add passwords system
// TODO format the code, so that login is one of possibilities and not the whole program
// TODO maybe get familiar with memory operations and allocations

int main() {
    login();
    return 0;
}
