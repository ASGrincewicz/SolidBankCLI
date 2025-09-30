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
    double getBalance() const;
    bool deposit(double);
    bool withdraw(double);
    std::vector<Transaction> getTransactions();
    std::string getFormattedLedger() const;

private:
    double balance;
    TransactionLog transactionLog;
};
