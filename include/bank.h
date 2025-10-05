//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

#pragma once
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "transaction.h"
#include "TransactionLog.h"
#include "utils.h"

class Bank {
public:
    Bank();
    double getBalance(AccountType account) const;
    bool deposit(AccountType account, double amount);
    bool withdraw(AccountType account, double amount);
    bool transfer(AccountType source, AccountType destination, double amount);
    std::vector<Transaction> getTransactions();
    std::string getFormattedLedger() const;

private:
    double checkingBalance = 0.0;
    double savingsBalance = 0.0;
    TransactionLog transactionLog;
};
