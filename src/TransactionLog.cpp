//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

#include "TransactionLog.h"
#include <sstream>

void TransactionLog::addTransaction(const Transaction& tx) {
    log.push_back(tx);
}

std::vector<Transaction> TransactionLog::getAllTransactions() const {
    return log;
}

std::string TransactionLog::toString() const {
    std::ostringstream oss;
    for (const auto& tx : log) {
        oss << tx.toString() << "\n";
    }
    return oss.str();
}