#!/bin/sh
cd build && rm -rf *&& cmake .. && cmake --build . && ./main

