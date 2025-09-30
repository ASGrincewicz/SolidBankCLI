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
    transactions.push_back({TransactionType::Deposit, amount, getCurrentTimestamp()});
    return true;
}

bool Bank::withdraw(double amount) {
    if (amount <= 0.0 || amount > balance) return false;
    balance -= amount;
    transactions.push_back({TransactionType::Withdrawal, amount,getCurrentTimestamp()});
    return true;
}

const std::vector<Transaction>& Bank::getTransactions() const
{
    return transactions;
}

std::string Bank::getFormattedLedger() const {
    std::stringstream ss;
    ss << "=== Transaction Ledger ===\n";
    ss << std::left << std::setw(12) << "Type"
       << std::right << std::setw(10) << "Amount"
       << "    Timestamp\n";
    ss << "------------------------------\n";

    for (const auto& tx : transactions) {
        std::string typeStr = (tx.type == TransactionType::Deposit) ? "Deposit" : "Withdrawal";
        ss << std::left << std::setw(12) << typeStr
           << std::right << std::setw(10) << std::fixed << std::setprecision(2) << tx.amount
           << "    " << tx.timestamp << "\n";
    }

    ss << "------------------------------\n";
    ss << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    return ss.str();
}

