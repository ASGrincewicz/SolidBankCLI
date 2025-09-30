### SolidBankCLI
A small C++23 command-line application that simulates basic banking operations (deposit, withdraw) and prints a formatted transaction ledger. It is designed to run locally and has a minimal codebase with unit tests.

### Tech Stack
- Language: C++23
- Build system: CMake (minimum 3.16; presets require 3.21+)
- Generator: Ninja (used by the provided CMake presets)
- Test framework: Catch2 v3 (fetched via CMake `FetchContent`)

### Requirements
- C++ compiler with C++23 support
    - macOS: Clang/LLVM (Xcode Command Line Tools)
    - Linux: GCC 13+ or Clang 16+
    - Windows: MSVC (Visual Studio 2022) or LLVM/Clang
- CMake 3.21+ recommended (presets are defined); minimum 3.16 if configuring manually
- Ninja build tool (for the provided presets)

### Project Structure
```
SolidBankCLI/
├─ CMakeLists.txt
├─ CMakePresets.json
├─ License.txt
├─ README.md
├─ run.sh
├─ include/
│  ├─ bank.h
│  ├─ transaction.h
│  └─ utils.h
├─ src/
│  ├─ main.cpp          # Entry point
│  ├─ bank.cpp
│  ├─ transaction.cpp
│  └─ utils.cpp
└─ tests/
   └─ test_bank.cpp
```

### Building and Running
You can use the provided CMake presets or configure manually.

#### macOS (preset: `macos-debug`)
- Using the helper script:
```
./run.sh
```
- Equivalent explicit commands:
```
cmake --preset macos-debug
cmake --build --preset macos-debug
./cmake-build-mac/SolidBankCLI
```

#### Windows (preset: `windows-debug`)
```
cmake --preset windows-debug
cmake --build --preset windows-debug
./cmake-build-win/SolidBankCLI.exe
```

#### Manual configure (any platform, without presets)
```
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target SolidBankCLI
./build/SolidBankCLI
```

### Running Tests
Tests are built into a separate executable and are also registered with CTest.
- Build and run the test binary directly:
```
cmake --build <build-dir> --target SolidBankTests && <build-dir>/SolidBankTests
```
- Or via CTest (after building):
```
ctest --test-dir <build-dir> --output-on-failure
```

### Available CMake Targets
- `SolidBankCLI`: main CLI application
- `SolidBankTests`: unit tests (Catch2 with main)

### Scripts
- `run.sh`: Convenience script for macOS to configure, build, and run the CLI using the `macos-debug` preset.

### Configuration Options
- `CODE_COVERAGE` (CMake option, default ON in this project):
    - When enabled with GCC/Clang, adds `-fprofile-arcs -ftest-coverage -g` to compilation flags.
    - Enable/disable via configure step, for example:
```
cmake --preset macos-debug -DCODE_COVERAGE=ON
# or, manual configure
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCODE_COVERAGE=ON
```
- Note: Generating coverage reports (e.g., with `gcov`, `lcov`, `genhtml`) is not configured here. TODO: Document coverage tooling and report generation steps.

### Environment Variables
- None required by the application.
- No `.env` file is used.

### CLI Behavior (demo)
The current `main` function seeds a few transactions and prints the ledger. Example run:
```
Welcome to SolidBankCLI
Current balance: $<amount>
=== Transaction Ledger ===
Type           Amount    Timestamp
------------------------------
Deposit         XXXX.XX    YYYY-MM-DDTHH:MM:SS
Withdrawal      XXXX.XX    YYYY-MM-DDTHH:MM:SS
------------------------------
Current Balance: $XXXX.XX
```

### Branching Strategy and Naming Convention
This project follows a structured branching model to maintain clarity and authorship integrity. Each branch represents a distinct narrative thread in the development process.

- Prefixes:
    - `feature/` New functionality or module
    - `bugfix/` Fixes for identified issues
    - `refactor/` Code cleanup or restructuring
    - `hotfix/` Urgent patches for critical bugs
    - `release/` Version prep and finalization
    - `test/` Experimental or sandbox work

- Examples:
    - `feature/account-creation`
    - `bugfix/cli-input-validation`
    - `refactor/transaction-module`
    - `hotfix/negative-balance-crash`
    - `release/v1.0.0`

### Licensing
- This repository now includes `License.txt` at the project root.
- Summary (non-exhaustive; the file governs):
    - Copyright © 2025 Aaron Steven Grincewicz. All rights reserved.
    - The software and source code are proprietary intellectual property.
    - Unauthorized reproduction, distribution, or modification is prohibited without explicit written permission from the author.
    - For inquiries, contact: `ASGrincewicz@icloud.com`.
- Developers should retain the existing copyright and usage notices present in source headers.

### Future Improvements (TODOs)
- Add interactive CLI (read user input for deposits/withdrawals)
- Add persistence (save/load transactions)
- Document and integrate code coverage report generation
- Provide cross-platform release packaging instructions
