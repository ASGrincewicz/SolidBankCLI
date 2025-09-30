cmake_minimum_required(VERSION 3.16)
project(SolidBankCLI VERSION 1.0 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: Enable coverage flags for GCC/Clang
option(CODE_COVERAGE "Enable coverage reporting" ON)
if(CODE_COVERAGE)
    message(STATUS "Code coverage enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -g")
endif()

# Include directories
include_directories(include)

# CLI sources (includes main.cpp)
set(CLI_SOURCES
        src/main.cpp
        src/bank.cpp
        src/transaction.cpp
        src/utils.cpp
        src/TransactionLog.cpp
)

# Test sources (excludes main.cpp)
set(TEST_SOURCES
        tests/test_bank.cpp
        src/bank.cpp
        src/transaction.cpp
        src/TransactionLog.cpp
        src/utils.cpp
)

# Main executable
add_executable(SolidBankCLI ${CLI_SOURCES})
target_include_directories(SolidBankCLI PRIVATE include)

# Catch2 setup
include(FetchContent)
FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(catch2)

# Test executable
add_executable(SolidBankTests ${TEST_SOURCES})
target_include_directories(SolidBankTests PRIVATE include)
target_link_libraries(SolidBankTests PRIVATE Catch2::Catch2WithMain)

# Enable test discovery
include(CTest)
enable_testing()
add_test(NAME SolidBankTests COMMAND SolidBankTests)