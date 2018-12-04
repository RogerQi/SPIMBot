# SPIMBot
## Bot description

See README.md in main/

## Important Numbers

* (rule1 only) Average Cycles required to solve soduku puzzle: : 650k cycles/38 keys per game
* (rule1 and rule2) Average Cycles required to solve soduku puzzle: : 550k cycles/46 keys per game
* Size of the map: 30 by 30, each cell contains info about surrounding walls. Note that this **may not be consistent**.
* Supercorn: costs 1 key and gives 1 point
* Treasure chest: costs 2 keys and gives 5 and reveal surrounding 7x7 area

## Current path planning TODO

* Fix astray caused by timer interrupt.
* Add inertial navigation.

## Current Decision Making TODO

* TBD

## Long-term Goals

* C implementation of simple structure for C code debugging
* (Optional) C implementation of SpimBot?
* (Optional) Is there a better algorithm for solving soduku?
* Modify makefile for profiling and simulation contests

## Solved TODO

* Get a basic path planning algorithm for test runs (Flood fill and BFS vs. A*)
* Think about scheduling (don't do stuffs inside interrupts. use a for loop to mock scheduler)

## Dev Goals

After building basic libraries, we will build different versions of robot (with different implementation of path finding and decisiong making algorithm) and use
the best one for official contest

## File Structs

See organized directory.
