//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

//
// Created by Aaron Grincewicz on 10/4/25.
//

#pragma once
#include "transaction.h"

inline std::string accountToString(AccountType account) {
    switch (account) {
        case AccountType::Checking: return "Checking";
        case AccountType::Savings: return "Savings";
        default: return "Unknown";
    }
}