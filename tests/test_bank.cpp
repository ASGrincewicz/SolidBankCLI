//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

// tests/test_bank.cpp
#include <catch2/catch_test_macros.hpp>
#include "bank.h"

TEST_CASE("Bank initializes with zero balance", "[bank]") {
    Bank b;
    REQUIRE(b.getBalance() == 0);
}