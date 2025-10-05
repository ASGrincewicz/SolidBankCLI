// SPDX-License-Identifier: LicenseRef-Proprietary
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /
#include "bank.h"

#include "AccountUtils.h"

Bank::Bank() : checkingBalance(0), savingsBalance(0){}
double Bank::getBalance(AccountType account) const {
    switch (account) {
        case AccountType::Checking:
            return checkingBalance;
        case AccountType::Savings:
            return savingsBalance;
        default:
            return 0;
    }
}

bool Bank::deposit(AccountType account, double amount){
    if (amount <= 0) return false;

    std::string timestamp = getCurrentTimestamp();
    switch (account) {
        case AccountType::Checking:
            checkingBalance += amount;
            break;
        case AccountType::Savings:
            savingsBalance += amount;
            break;
        default:
            return false;
    }

    transactionLog.addTransaction(Transaction(
        TransactionType::Deposit, amount, timestamp, account,account
    ));
    return true;
}

bool Bank::withdraw(AccountType account, double amount) {
    if (amount <= 0) return false;

    std::string timestamp = getCurrentTimestamp();
    bool success = false;

    switch (account) {
        case AccountType::Checking:
            if (checkingBalance >= amount) {
                checkingBalance -= amount;
                success = true;
            }
            break;
        case AccountType::Savings:
            if (savingsBalance >= amount) {
                savingsBalance -= amount;
                success = true;
            }
            break;
        default:
            return false;
    }

    if (success) {
        transactionLog.addTransaction(Transaction(
            TransactionType::Withdrawal, amount, timestamp, account,account
        ));
    }

    return success;
}

bool Bank::transfer(AccountType source, AccountType destination, double amount) {
    if (source == destination|| amount <= 0) return false;

    if (!withdraw(source, amount)) return false;
    deposit(destination, amount);

    std::string timestamp = getCurrentTimestamp();
    transactionLog.addTransaction(Transaction(
        TransactionType::Transfer, amount, timestamp, source, destination
    ));
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
       << std::setw(10) << "Amount"
       << std::setw(22) << "Timestamp"
       << std::setw(10) << "From"
       << std::setw(10) << "To" << "\n";
    ss << "--------------------------------------------------------------\n";

    for (const auto& tx : transactionLog.getAllTransactions()) {
        std::string typeStr;
        switch (tx.type) {
            case TransactionType::Deposit: typeStr = "Deposit"; break;
            case TransactionType::Withdrawal: typeStr = "Withdrawal"; break;
            case TransactionType::Transfer: typeStr = "Transfer"; break;
            default: typeStr = "Unknown"; break;
        }

        ss << std::left << std::setw(12) << typeStr
           << std::setw(10) << std::fixed << std::setprecision(2) << tx.amount
           << std::setw(22) << tx.timestamp
           << std::setw(10) << accountToString(tx.sourceAccount)
           << std::setw(10) << accountToString(tx.destinationAccount) << "\n";
    }

    ss << "--------------------------------------------------------------\n";
    ss << "Checking Balance: $" << std::fixed << std::setprecision(2) << checkingBalance << "\n";
    ss << "Savings Balance:  $" << std::fixed << std::setprecision(2) << savingsBalance << "\n";
    return ss.str();
}

