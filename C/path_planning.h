#ifndef PATH_PLANNING_H_
#define PATH_PLANNING_H_

#include "my_types.h"

int command_buffer[MAXIMUM_NODE_NUM];
int visited_mark[MAXIMUM_NODE_NUM];
int prv_pos[MAXIMUM_NODE_NUM]; //30 x 30

//obsolete
//0 - clear; 1 - barrier; 2 - unknown
//unsigned int current_maze[61][61];

//path planning function signature
/**
 * @brief update command buffer
 * @param current_map: pointer to maze_map struct (processed and all unexplored cells are stored as open path)
 * @param target_point: an int array of LENGTH 2 (x, y) in cell coordinate (spimbot_x / 10, spimbot_y / 10)
 */
typedef void (*path_planning)(maze_map* current_map, int* target_point);

void refresh_pp(void);

void bfs(maze_map* current_map, int* target_point);

#endif
