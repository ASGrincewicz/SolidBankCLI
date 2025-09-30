// SPDX-License-Identifier: LicenseRef-Proprietary
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

#include "transaction.h"
#include <sstream>
#include <iomanip>

std::string Transaction::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "[" << timestamp << "] "
        << (type == TransactionType::Deposit ? "Deposit" : "Withdrawal")
        << ": $" << amount;
    return oss.str();
}