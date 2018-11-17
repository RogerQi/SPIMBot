# SPIMBot
## Important Numbers

* Average Cycles required to solve soduku puzzle: to be measured
* Size of the map: 30 by 30, each cell contains info about surrounding walls. So we use a 61 by 61 2D binary array to represent the map.
* Supercorn: costs 1 key and gives 1 point
* Treasure chest: costs 2 keys and gives 5 and reveal surrounding 7x7 area

## Current TODO

* build header files in C/ for iteration in C
* Finish puzzle solver in accordance with soduku.c provided in lab 8 and test it
* Get a basic path planning algorithm for test runs
* Think about scheduling

## Long-term Goals

* C implementation of simple structure for C code debugging
* (Optional) C implementation of SpimBot?
* (Optional) Is there a better algorithm for solving soduku?
* Modify makefile for profiling and simulation contests

## Dev Goals

After building basic libraries, we will build different versions of robot (with different implementation of path finding and decisiong making algorithm) and use
the best one for official contest

## File Structs

See organized directory.
