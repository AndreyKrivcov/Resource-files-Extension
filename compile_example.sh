#!/bin/bash

mkdir -p Example/build
cd Example/build
cmake ..
make

echo "==============================="
echo "check Example/build directory"
