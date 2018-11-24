#include "path_planning.h"
#include <stdio.h>

int stack[MAXIMUM_NODE_NUM * 5];

int my_abs(int val) {
    if (val >= 0)
        return val;
    return -val;
}

//should only be called after floodfill
void plan_next_move(maze_map* cur_map, int* target_point) {
    int cur_x = 9; //In MIPS, this should be updated with BOT's coordinates
    int cur_y = 1;

    int tar_x = target_point[0];
    int tar_y = target_point[1];
    int command_buffer_ptr = 0;
    while (cur_x != tar_x || cur_y != tar_y) {
        //dont need to care about obstacles, just go to any neighboring cell with -1 weight
        int cur_node = cur_y * 30 + cur_x;
        printf("Cur x: %d, cur y: %d\n", cur_x, cur_y);
        int cur_weight = weight_mat[cur_node];
        if ((cur_node + 1) / 30 == cur_y && weight_mat[cur_node + 1] == cur_weight - 1) {
            if (cur_map->map[cur_y][cur_x].e_open) {
                ++cur_x; //travel to east
                command_buffer[command_buffer_ptr++] = EAST;
                continue;
            }
        }
        if ((cur_node - 1) / 30 == cur_y && weight_mat[cur_node - 1] == cur_weight - 1) {
            if (cur_map->map[cur_y][cur_x].w_open) {
                --cur_x; //travel to west
                command_buffer[command_buffer_ptr++] = WEST;
                continue;
            }
        }
        if ((cur_node - 30) >= 0 && weight_mat[cur_node - 30] == cur_weight - 1) {
            if (cur_map->map[cur_y][cur_x].n_open) {
                --cur_y; //travel to north
                command_buffer[command_buffer_ptr++] = NORTH;
                continue;
            }
        }
        if ((cur_node + 30) < MAXIMUM_NODE_NUM && weight_mat[cur_node + 30] == cur_weight - 1) {
            if (cur_map->map[cur_y][cur_x].s_open) {
                ++cur_y; //travel to south
                command_buffer[command_buffer_ptr++] = SOUTH;
                continue;
            }
        }
    }
    command_buffer[command_buffer_ptr] = -1; //mark end
}

// prv_target_pts should be inited to -10000, -10000
// matrix should be inited to manhattan distance. However the initial run of bfs
// will do this job for us
// in main function
void flood_fill(maze_map* current_map, int* target_point) {
    if (target_point[0] == prv_target_pts[0] && target_point[1] == prv_target_pts[1]) {
        //locally update the matrix
        int bot_x = 9; //in MIPS, use I/O to get real location instead
        int bot_y = 1;
        int current_node = bot_y * 30 + bot_x;
        //bot_x and bot_y can be released
        // if (visited_mark[current_node]) {
        //     // already visited!
        //     return;
        // }
        int stack_ptr = 0;
        stack[0] = current_node;
        if(bot_x != 0)
            stack[++stack_ptr] = current_node - 1;
        if(bot_x != 29)
            stack[++stack_ptr] = current_node + 1;
        if(bot_y != 0) {
            stack[++stack_ptr] = current_node - 30;
            if (bot_x != 0) //north west
                stack[++stack_ptr] = current_node - 31;
            if (bot_x != 29) //north east
                stack[++stack_ptr] = current_node - 29;
        }
        if(bot_y != 29) {
            stack[++stack_ptr] = current_node + 30;
            if (bot_x != 0) //south west
                stack[++stack_ptr] = current_node + 29;
            if (bot_x != 29) //south east
                stack[++stack_ptr] = current_node + 31;
        }
        while(stack_ptr >= 0) {
            printf("Stack ptr: %d\n", stack_ptr);
            int cur_pos = stack[stack_ptr--];
            printf("CUR POS: %d\n", cur_pos);
            int node_y = cur_pos / 30;
            int node_x = cur_pos - (node_y * 30);
            int min_val = 2000; //note that weight of 1000 is impossible
            if (current_map->map[node_y][node_x].e_open) {
                if (node_x != 29) {
                    //east cell is an accessible neighbor
                    //also note that this ensures the cell is not an edge case
                    if (weight_mat[cur_pos + 1] < min_val)
                        min_val = weight_mat[cur_pos + 1];
                }
            }
            if (current_map->map[node_y][node_x].w_open) {
                if (node_x != 0) {
                    //east cell is an accessible neighbor
                    //also note that this ensures the cell is not an edge case
                    if (weight_mat[cur_pos - 1] < min_val)
                        min_val = weight_mat[cur_pos - 1];
                }
            }
            if (current_map->map[node_y][node_x].n_open) {
                //east cell is an accessible neighbor
                //also note that this ensures the cell is not an edge case
                if (node_y != 0) {
                    if (weight_mat[cur_pos - 30] < min_val)
                        min_val = weight_mat[cur_pos - 30];
                }
            }
            if (current_map->map[node_y][node_x].s_open) {
                if (node_y != 29) {
                    //east cell is an accessible neighbor
                    //also note that this ensures the cell is not an edge case
                    if (weight_mat[cur_pos + 30] < min_val)
                        min_val = weight_mat[cur_pos + 30];
                }
            }
            if (min_val != weight_mat[cur_pos] - 1) {
                if (weight_mat[cur_pos] == 0)
                    continue;
                //inconsistency found
                weight_mat[cur_pos] = ++min_val;
                if (current_map->map[node_y][node_x].e_open) {
                    if (node_x != 29)
                        stack[++stack_ptr] = cur_pos + 1;
                }
                if (current_map->map[node_y][node_x].w_open) {
                    if (node_x != 0)
                        stack[++stack_ptr] = cur_pos - 1;
                }
                if (current_map->map[node_y][node_x].n_open) {
                    if (node_y != 0)
                        stack[++stack_ptr] = cur_pos - 30;
                }
                if (current_map->map[node_y][node_x].s_open) {
                    if (node_y != 29)
                        stack[++stack_ptr] = cur_pos + 30;
                }
            }
        }
    } else {
        //new target point assigned! Updating the entire matrix
        //reflood
        printf("[FF] UPDATING ENTIRE MAT\n");
        bfs_with_weight_update(current_map, target_point);
        prv_target_pts[0] = target_point[0];
        prv_target_pts[1] = target_point[1];
    }
    return;
}
