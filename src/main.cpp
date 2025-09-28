//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

#include <iostream>
#include "bank.h"

int main() {
    Bank bank;
    bank.deposit(40.13);
    bank.deposit(1243.98);
    bank.withdraw(650.99);
    std::cout << "Welcome to SolidBankCLI\n";
    std::cout << "Current balance: $" << bank.getBalance() << "\n";
    std::cout << bank.getFormattedLedger();
    return 0;
}
