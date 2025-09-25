//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

#include <iostream>
#include "bank.h"

int main() {
    Bank bank;
    std::cout << "Welcome to SolidBankCLI\n";
    std::cout << "Current balance: $" << bank.getBalance() << "\n";
    return 0;
}
