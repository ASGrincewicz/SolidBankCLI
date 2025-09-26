//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

// tests/test_bank.cpp
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "bank.h"

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