// SPDX-License-Identifier: LicenseRef-Proprietary
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /
#pragma once
#include <vector>
#include <string>
#include "transaction.h"

class TransactionLog {
private:
    std::vector<Transaction> log;

public:
    void addTransaction(const Transaction& tx);
    std::vector<Transaction> getAllTransactions() const;
    std::string toString() const;
};
