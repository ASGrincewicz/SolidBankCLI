// SPDX-License-Identifier: LicenseRef-Proprietary
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
    transactionLog.addTransaction(Transaction(TransactionType::Deposit, amount, getCurrentTimestamp()));
    return true;
}

bool Bank::withdraw(double amount) {
    if (amount <= 0.0 || amount > balance) return false;
    balance -= amount;
    transactionLog.addTransaction(Transaction(TransactionType::Withdrawal, amount, getCurrentTimestamp()));
    return true;
}

std::vector<Transaction> Bank::getTransactions()
{
    return transactionLog.getAllTransactions();
}

std::string Bank::getFormattedLedger() const {
    std::stringstream ss;
    ss << "=== Transaction Ledger ===\n";
    ss << std::left << std::setw(12) << "Type"
       << std::right << std::setw(10) << "Amount"
       << "    Timestamp\n";
    ss << "------------------------------\n";

    for (const auto& tx : transactionLog.getAllTransactions()) {
        std::string typeStr = (tx.type == TransactionType::Deposit) ? "Deposit" : "Withdrawal";
        ss << std::left << std::setw(12) << typeStr
           << std::right << std::setw(10) << std::fixed << std::setprecision(2) << tx.amount
           << "    " << tx.timestamp << "\n";
    }

    ss << "------------------------------\n";
    ss << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    return ss.str();
}

