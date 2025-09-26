#include "bank.h"

Bank::Bank() : balance(0) {}
double Bank::getBalance() const { return balance; }

void Bank::deposit(double amount)
{
    balance += amount;
}

bool Bank::withdraw(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}
