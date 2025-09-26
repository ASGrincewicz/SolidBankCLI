//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

#pragma once
#include <vector>
#include "transaction.h"

class Bank {
public:
    Bank();
    double getBalance() const;
    bool deposit(double);
    bool withdraw(double);
    const std::vector<Transaction>& getTransactions() const;

private:
    double balance;
    std::vector<Transaction> transactions;
};
