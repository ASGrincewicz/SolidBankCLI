// SPDX-License-Identifier: LicenseRef-Proprietary
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /
#pragma once
#include <string>
#include "utils.h"

enum class TransactionType {Deposit, Withdrawal};

struct Transaction{
    TransactionType type;
    double amount;
    std::string timestamp;

    Transaction(TransactionType type, double amount, const std::string& timestamp) : type(type), amount(amount), timestamp(timestamp) {}

    std::string toString() const;

};