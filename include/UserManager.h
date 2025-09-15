//
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//

#pragma once
#include <string>

class UserManager {
public:
    bool userExists(const std::string& username);
    void registerUser(const std::string& username, const std::string& password);
};