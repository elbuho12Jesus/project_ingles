#!/bin/sh
cd build && rm -rf * && mkdir Debug Release && cd Release && cmake -DCMAKE_BUILD_TYPE=Release ../.. && cmake --build . && ./main

