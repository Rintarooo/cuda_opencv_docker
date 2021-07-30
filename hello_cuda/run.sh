#!/bin/bash

mkdir build
cd build
cmake ..
# cmake CMAKE_BUILD_TYPE=DEBUG ..
cmake --build .

# ./build/exe