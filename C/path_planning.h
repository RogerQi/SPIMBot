#ifndef PATH_PLANNING_H_
#define PATH_PLANNING_H_

#include "my_types.h"

/* General buffer */
int command_buffer[MAXIMUM_NODE_NUM];
int visited_mark[MAXIMUM_NODE_NUM];

/* BFS buffer */
int prv_pos[MAXIMUM_NODE_NUM]; //30 x 30

/* Flood fill buffer */
int prv_target_pts[2];
int weight_mat[MAXIMUM_NODE_NUM];

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

void bfs_with_weight_update(maze_map* current_map, int* target_point);

void map_preprocess(maze_map* raw_map, maze_map* processed_map);

void refresh_pp(void);

void bfs(maze_map* current_map, int* target_point);

void flood_fill(maze_map* current_map, int* target_point);

void plan_next_move(maze_map* cur_map, int* target_point);

void make_weight(void);

#endif
