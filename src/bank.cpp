#include "bank.h"

Bank::Bank() : balance(0) {}
double Bank::getBalance() const { return balance; }

bool Bank::deposit(double amount)
{
    if(amount <= 0.00)
    {
        return false;
    }
    balance += amount;
    return true;
}

bool Bank::withdraw(double amount) {
    if (amount <= 0.0 || amount > balance) return false;
    balance -= amount;
    return true;
}
