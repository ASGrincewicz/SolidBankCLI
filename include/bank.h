//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

#pragma once
class Bank {
public:
    Bank();
    double getBalance() const;
    bool deposit(double);
    bool withdraw(double);

private:
    double balance;
};
