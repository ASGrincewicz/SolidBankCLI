@echo off
cmake --preset windows-debug
cmake --build --preset windows-debug
cmake-build-win\SolidBankCLI.exe
