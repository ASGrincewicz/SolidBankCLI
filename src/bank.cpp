//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /
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
    transactions.push_back({TransactionType::Deposit, amount, "2025-09-25T20:45:00"});
    return true;
}

bool Bank::withdraw(double amount) {
    if (amount <= 0.0 || amount > balance) return false;
    balance -= amount;
    transactions.push_back({TransactionType::Withdrawal, amount,"2025-09-25T20:45:00"});
    return true;
}

const std::vector<Transaction>& Bank::getTransactions() const
{
    return transactions;
}
