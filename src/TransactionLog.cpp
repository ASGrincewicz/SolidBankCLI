//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

#include "TransactionLog.h"
#include <sstream>
#include <fstream>

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

bool TransactionLog::exportToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    //write header
    file << "Timestamp,Type,Amount\n";

    for (const auto& tx : log) {
        std::string typeStr;
        switch (tx.type) {
            case TransactionType::Deposit:  typeStr = "Deposit"; break;
            case TransactionType::Withdrawal: typeStr = "Withdrawal"; break;
            default: typeStr = "Unknown"; break;
        }

        file << tx.timestamp << "," << typeStr << "," << tx.amount << "\n";
    }
    file.close();
    return true;
}

