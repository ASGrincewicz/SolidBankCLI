cmake_minimum_required(VERSION 3.28)
project(SolidBankCLI)

set(CMAKE_CXX_STANDARD 26)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(SolidBankCLI ${SOURCES}
        include/UserManager.h
        src/UserManager.cpp)
