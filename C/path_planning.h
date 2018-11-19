#ifndef PATH_PLANNING_H_
#define PATH_PLANNING_H_

#include "my_types.h"

//obsolete
//0 - clear; 1 - barrier; 2 - unknown
//unsigned int current_maze[61][61];

//path planning function signature
/**
 * @param current_map: pointer to maze_map struct (processed and all unexplored cells are stored as open path)
 * @param command_buffer: pointer to command buffer (e.g. EAST SOUTH STOP), which is terminated with a STOP
 * @param target_point: an int array of LENGTH 2 (x, y) in cell coordinate (spimbot_x / 10, spimbot_y / 10)
 */
typedef void (*path_planning)(maze_map current_map, int* command_buffer, int* target_point);

#endif
