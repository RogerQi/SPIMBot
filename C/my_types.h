#ifndef MY_TYPES_H_
#define MY_TYPES_H_

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3
#define STILL 4
#define STOP 5

#define MAXIMUM_NODE_NUM 900

typedef struct {
    char s_open;
    char w_open;
    char n_open;
    char e_open;
} maze_cell;

typedef struct {
    maze_cell map[30][30]; // hold the maze map
} maze_map;

#endif
