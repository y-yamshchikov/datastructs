#!/bin/bash
mv exe old_exe
g++ -c datastructs.cpp -std=c++17
g++ -o exe datastructs.o -std=c++17

