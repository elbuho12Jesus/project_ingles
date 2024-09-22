#!/bin/sh
cd build && rm -rf * && mkdir Debug Release && cd Debug && cmake -DCMAKE_BUILD_TYPE=Debug ../.. && cmake --build . && ./main

