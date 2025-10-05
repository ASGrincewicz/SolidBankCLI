// SPDX-License-Identifier: LicenseRef-Proprietary
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /
#pragma once
#include <string>
#include "utils.h"

enum class TransactionType {Deposit, Withdrawal, Transfer};
enum class AccountType {Checking, Savings};

inline std::string toString(AccountType account) {
    switch (account) {
        case AccountType::Checking: return "Checking";
        case AccountType::Savings: return "Savings";
        default: return "Unknown";
    }
}

struct Transaction{
    TransactionType type;
    double amount;
    std::string timestamp;
    AccountType sourceAccount;
    AccountType destinationAccount; // optional for Transfers

    Transaction(TransactionType type, double amount, const std::string& timestamp,
                         AccountType source, AccountType destination)
    : type(type), amount(amount), timestamp(timestamp),
      sourceAccount(source), destinationAccount(destination) {}

    std::string toString() const;

};