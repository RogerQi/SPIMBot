#include "path_planning.h"
#include <stdio.h>

void map_preprocess(maze_map* raw_map, maze_map* processed_map) {
    int i = 0;
    for (; i < 900; ++i) {
        // In MIPS, this reduces to raw_map->[i] (why?)
        char e_open = raw_map->map[i / 30][i % 30].e_open;
        char w_open = raw_map->map[i / 30][i % 30].w_open;
        char n_open = raw_map->map[i / 30][i % 30].n_open;
        char s_open = raw_map->map[i / 30][i % 30].s_open;
        if (e_open | w_open | n_open | s_open) {
            //nothing
        } else {
            processed_map->map[i / 30][i % 30].e_open = 1;
            processed_map->map[i / 30][i % 30].w_open = 1;
            processed_map->map[i / 30][i % 30].n_open = 1;
            processed_map->map[i / 30][i % 30].s_open = 1;
        }
    }
    return;
}

void refresh_pp(void) {
    int i = 0;
    for (; i < MAXIMUM_NODE_NUM; ++i) {
        prv_pos[i] = -1;
        visited_mark[i] = 0;
        command_buffer[i] = -1;
    }
}

void bfs_with_weight_update(maze_map* current_map, int* target_point) {
    int target_x = target_point[0];
    int target_y = target_point[1];

    int visited_node_count = 0;

    refresh_pp();

    int queue[MAXIMUM_NODE_NUM * 2]; //at most 900!
    int queue_ptr = -2;
    queue[0] = target_y * 30 + target_x;
    queue[1] = 0; //weight
    int ava_spot_ptr = 2;
    visited_mark[queue[0]] = 1;
    // weight_mat[queue[0]] = 0;
    //prv_pos[queue[0]] = -1;
    //we dont need this line bc it's inited to be so

    while (visited_node_count < 900) {
        queue_ptr = queue_ptr + 2;
        // printf("queue_ptr: %d\n", queue_ptr);
        // if queue > end_ptr, we should end. but technically that should not happen.
        int current_node = queue[queue_ptr];
        int current_node_weight = queue[queue_ptr + 1];
        if (current_node_weight == 2)
            printf("GGOTYA\n");
        weight_mat[current_node] = current_node_weight;
        ++visited_node_count;
        int node_x = current_node % 30;
        int node_y = current_node / 30;
        //printf("cur x: %d\ncur y: %d\n", node_x, node_y);
        //add subsequent nodes to queue and update their prv positions
        //east
        if (current_map->map[node_y][node_x].e_open) {
            int next_pos = node_y * 30 + node_x + 1;
            //printf("E pos: %d\n", next_pos);
            if (next_pos / 30 == node_y && !(visited_mark[next_pos])) {
                visited_mark[next_pos] = 1; //mark
                queue[ava_spot_ptr++] = next_pos;
                queue[ava_spot_ptr++] = current_node_weight + 1;
            }
        }
        if (current_map->map[node_y][node_x].w_open) {
            int next_pos = node_y* 30 + node_x - 1;
            if (next_pos / 30 == node_y && !(visited_mark[next_pos])) {
                visited_mark[next_pos] = 1;
                queue[ava_spot_ptr++] = next_pos;
                queue[ava_spot_ptr++] = current_node_weight + 1;
            }
        }
        if (current_map->map[node_y][node_x].n_open) {
            int next_pos = node_y * 30 + node_x - 30;
            if (next_pos >= 0 && !(visited_mark[next_pos])) {
                visited_mark[next_pos] = 1;
                queue[ava_spot_ptr++] = next_pos;
                queue[ava_spot_ptr++] = current_node_weight + 1;
            }
        }
        if (current_map->map[node_y][node_x].s_open) {
            int next_pos = node_y * 30 + node_x + 30;
            if (next_pos < MAXIMUM_NODE_NUM && !(visited_mark[next_pos])) {
                visited_mark[next_pos] = 1;
                queue[ava_spot_ptr++] = next_pos;
                queue[ava_spot_ptr++] = current_node_weight + 1;
                //printf("Setting prv_pos[%d] = %d\n", next_pos, current_node);
            }
        }
    }
}
