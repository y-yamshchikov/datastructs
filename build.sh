#!/bin/bash
mv exe old_exe
g++ -c stack.cpp -std=c++17
g++ -c queue.cpp -std=c++17
g++ -c datastructs.cpp -std=c++17
g++ -o exe stack.o queue.o datastructs.o -std=c++17

