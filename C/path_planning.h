#ifndef PATH_PLANNING_H_
#define PATH_PLANNING_H_

//obsolete
//0 - clear; 1 - barrier; 2 - unknown
//unsigned int current_maze[61][61];

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3
#define STILL 4
#define STOP 5

struct maze_cell {
    char s_open;
    char w_open;
    char n_open;
    char e_open;
};

struct maze_map {
    maze_cell map[30][30]; // hold the maze map
};

//path planning function signature
/**
 * @param current_map: pointer to maze_map struct
 * @param command_buffer: pointer to command buffer (e.g. EAST SOUTH STOP), which is terminated with a STOP
 */
typedef void (*path_planning)(maze_map current_map, int* command_buffer);

#endif
