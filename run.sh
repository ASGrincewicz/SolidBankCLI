#!/bin/bash
cmake --preset macos-debug
cmake --build --preset macos-debug
./cmake-build-mac/SolidBankCLI
