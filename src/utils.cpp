// SPDX-License-Identifier: LicenseRef-Proprietary
//  // Copyright © 2025 Aaron Steven Grincewicz
//  // All rights reserved.
//  // Unauthorized use, modification, or redistribution is prohibited.
//  /

#include "utils.h"

#include <chrono>
#include <iomanip>
#include <sstream>

std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%Y-%m-%dT%H:%M:%S");
    return ss.str();
}
