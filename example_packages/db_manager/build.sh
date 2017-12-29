#!/bin/bash

if [[ ! -d build ]]; then
    rm -rf build/
    mkdir -p build
fi

cd build
# build also eclipse files.
cmake .. -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
make -j8
