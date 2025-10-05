// SPDX-License-Identifier: LicenseRef-Proprietary
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

// tests/test_bank.cpp
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <fstream>
#include <sstream>

#include "bank.h"
#include "Transaction.h"
#include "TransactionLog.h"
#include "utils.h"

TEST_CASE("Bank initializes with zero balance", "[bank]") {
    Bank b;
    REQUIRE(b.getBalance() == Catch::Approx(0.0));
}

TEST_CASE("Deposit increases balance", "[bank]")
{
    Bank b;
    bool success = b.deposit(50.00);
    REQUIRE(success);
    REQUIRE(b.getBalance() == Catch::Approx(50.00));

}

TEST_CASE("Withdraw decreases balance", "[bank]")
{
    Bank b;
    b.deposit(100.00);
    bool success = b.withdraw(40.00);
    REQUIRE(success);
    REQUIRE(b.getBalance() == Catch::Approx(60.00));
}

TEST_CASE("Withdraw fails if amount exceeds balance", "[bank]")
{
    Bank b;
    b.deposit(30.00);
    bool success = b.withdraw(50.00);
    REQUIRE_FALSE(success);
    REQUIRE(b.getBalance() == Catch::Approx(30.00));
}

TEST_CASE("Withdraw exact balance succeeds", "[bank]")
{
    Bank b;
    b.deposit(30.00);
    bool success = b.withdraw(30.00);
    REQUIRE(success);
    REQUIRE(b.getBalance() == Catch::Approx(0.00));
}

TEST_CASE("Deposit rejects negative amount", "[bank]")
{
    Bank b;
    bool success = b.deposit(-20.00);
    REQUIRE_FALSE(success);
    REQUIRE(b.getBalance() == Catch::Approx(0.00));
}

TEST_CASE("Withdraw rejects negative amount", "[bank]")
{
    Bank b;
    b.deposit(100.00);
    bool success = b.withdraw(-50.00);
    REQUIRE_FALSE(success);
    REQUIRE(b.getBalance() == Catch::Approx(100.00));
}

TEST_CASE("Bank logs transactions", "[bank]"){
    Bank b;
    b.deposit(100.00);
    b.withdraw(60.00);

    const auto& log = b.getTransactions();
    REQUIRE(log.size() == 2);
    REQUIRE(log[0].type == TransactionType::Deposit);
    REQUIRE(log[1].type == TransactionType::Withdrawal);
}

TEST_CASE("Timestamp format is ISO-like", "[utils]") {
    std::string ts = getCurrentTimestamp();
    REQUIRE(!ts.empty());
    REQUIRE(ts.find("T") != std::string::npos);  // e.g. 2025-09-28T11:59:00
}

TEST_CASE("Formatted ledger includes transactions", "[bank]") {
    Bank b;
    b.deposit(100.0);
    b.withdraw(40.0);
    std::string ledger = b.getFormattedLedger();

    REQUIRE(ledger.find("Deposit") != std::string::npos);
    REQUIRE(ledger.find("Withdrawal") != std::string::npos);
    REQUIRE(ledger.find("Current Balance") != std::string::npos);
}

TEST_CASE("Transaction constructor sets fields correctly", "[Transaction]") {
    Transaction t(TransactionType::Deposit, 100.0, "2025-09-28T11:59:00");
    REQUIRE(t.type == TransactionType::Deposit);
    REQUIRE(t.amount == Catch::Approx(100.0));
    REQUIRE(t.timestamp == "2025-09-28T11:59:00");
}

TEST_CASE("Transaction toString formats output correctly", "[Transaction]") {
    Transaction tx(TransactionType::Withdrawal, 75.25, "2025-09-30T18:30:00");
    std::string expected = "[2025-09-30T18:30:00] Withdrawal: $75.25";

    REQUIRE(tx.toString() == expected);
}

TEST_CASE("TransactionLog stores and formats transactions", "[TransactionLog]") {
    TransactionLog log;
    Transaction tx1(TransactionType::Deposit, 100.0, "2025-09-30T18:00:00");
    Transaction tx2(TransactionType::Withdrawal, 50.0, "2025-09-30T18:05:00");

    log.addTransaction(tx1);
    log.addTransaction(tx2);

    auto allTx = log.getAllTransactions();
    REQUIRE(allTx.size() == 2);
    REQUIRE(allTx[0].amount == Catch::Approx(100.0));
    REQUIRE(allTx[1].type == TransactionType::Withdrawal);

    std::string expected =
        "[2025-09-30T18:00:00] Deposit: $100.00\n"
        "[2025-09-30T18:05:00] Withdrawal: $50.00\n";

    REQUIRE(log.toString() == expected);
}

TEST_CASE("TransactionLog exports to CSV","[TransactionLog][Export]") {
    TransactionLog log;
    log.addTransaction(Transaction(TransactionType::Deposit, 100.0, "2025-10-04T18:00:00"));
    log.addTransaction(Transaction(TransactionType::Withdrawal, 50.0, "2025-10-04T18:05:00"));

    std::string filename = "test_export.csv";
    REQUIRE(log.getAllTransactions().size() == 2);
    REQUIRE(log.exportToCSV(filename));

    std::ifstream file(filename);
    REQUIRE(file.is_open());

    std::stringstream buffer;
    buffer << file.rdbuf();
   std::string contents = buffer.str();

    std::string expected =
        "Timestamp,Type,Amount\n"
        "2025-10-04T18:00:00,Deposit,100\n"
        "2025-10-04T18:05:00,Withdrawal,50\n";
    REQUIRE(contents == expected);
}