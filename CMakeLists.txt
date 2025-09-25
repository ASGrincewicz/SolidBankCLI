cmake_minimum_required(VERSION 3.16)
project(SolidBankCLI VERSION 1.0 LANGUAGES CXX)

# Force console subsystem for MinGW
if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mconsole")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable coverage flags (optional, for GCC/Clang)
option(CODE_COVERAGE "Enable coverage reporting" ON)
if(CODE_COVERAGE)
    message(STATUS "Code coverage enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Main executable
add_executable(SolidBankCLI ${SOURCES})

# Catch2 setup
include(FetchContent)
FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0 # Use latest stable
)
FetchContent_MakeAvailable(catch2)

# Test executable
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS tests/*.cpp)
add_executable(SolidBankTests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(SolidBankTests PRIVATE Catch2::Catch2WithMain)

# Enable test discovery in CLion
include(CTest)
enable_testing()
add_test(NAME SolidBankTests COMMAND SolidBankTests)


target_include_directories(SolidBankCLI PRIVATE include)
target_include_directories(SolidBankTests PRIVATE include)