//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /
#pragma once
#include <string>

enum class TransactionType {Deposit, Withdrawal};

struct Transaction{
    TransactionType type;
    double amount;
    std::string timestamp;

};