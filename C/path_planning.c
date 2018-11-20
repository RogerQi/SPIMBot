#include "path_planning.h"
#include <stdio.h>

void refresh_pp(void) {
    int i = 0;
    for (; i < MAXIMUM_NODE_NUM; ++i) {
        prv_pos[i] = -1;
        visited_mark[i] = 0;
        command_buffer[i] = 0;
    }
}

//to get pos in node array based on x, y
// pos = y * 30 + x

//to get x, y in terms of pos
// y = pos / 30
// x = pos % 30

//note that when accessing, for example, current_map->map[i][j]
//is equivalent to (word) current_map[i][j]
void bfs(maze_map* current_map, int* target_point) {
    int target_x = target_point[0];
    int target_y = target_point[1];

    int current_bot_x = 0; // in MIPS, modify this to get data from interrupt IO
    int current_bot_y = 0; // see above

    refresh_pp();

    int queue[MAXIMUM_NODE_NUM]; //at most 900!
    int queue_ptr = -1;
    int ava_spot_ptr = 1;
    queue[0] = current_bot_y * 30 + current_bot_x;
    //prv_pos[queue[0]] = -1;
    //we dont need this line bc it's inited to be so

    while (1) {
        ++queue_ptr;
        // if queue > end_ptr, we should end. but technically that should not happen.
        int current_node = queue[queue_ptr];
        //printf("current_node: %d\n", current_node);
        //printf("Current_node: %d\n", current_node);
        // if (visited_mark[current_node]) {
        //     continue;
        // }
        visited_mark[current_node] = 1;
        int node_x = current_node % 30;
        int node_y = current_node / 30;
        //printf("cur x: %d\ncur y: %d\n", node_x, node_y);
        if (node_x == target_x && node_y == target_y) {
            //finished! Recurse and get traveled path
            int cur_pos = current_node;
            int cnt = 0;
            while (cur_pos != -1) {
                // printf("Pushing: %d\n", cur_pos);
                command_buffer[cnt++] = cur_pos;
                // printf("prv_pos[%d] = %d\n", cur_pos, prv_pos[cur_pos]);
                cur_pos = prv_pos[cur_pos];
            }
            return;
        }
        //add subsequent nodes to queue and update their prv positions
        //east
        if (current_map->map[node_y][node_x].e_open) {
            int next_pos = node_y * 30 + node_x + 1;
            //printf("E pos: %d\n", next_pos);
            if (next_pos / 30 == node_y && !(visited_mark[next_pos])) {
                queue[ava_spot_ptr++] = next_pos;
                prv_pos[next_pos] = current_node;
            }
        }
        if (current_map->map[node_y][node_x].w_open) {
            int next_pos = node_y* 30 + node_x - 1;
            if (next_pos / 30 == node_y && !(visited_mark[next_pos])) {
                queue[ava_spot_ptr++] = next_pos;
                prv_pos[next_pos] = current_node;
            }
        }
        if (current_map->map[node_y][node_x].n_open) {
            int next_pos = node_y * 30 + node_x - 30;
            if (next_pos >= 0 && !(visited_mark[next_pos])) {
                queue[ava_spot_ptr++] = next_pos;
                prv_pos[next_pos] = current_node;
            }
        }
        if (current_map->map[node_y][node_x].s_open) {
            int next_pos = node_y * 30 + node_x + 30;
            if (next_pos < MAXIMUM_NODE_NUM && !(visited_mark[next_pos])) {
                queue[ava_spot_ptr++] = next_pos;
                prv_pos[next_pos] = current_node;
                //printf("Setting prv_pos[%d] = %d\n", next_pos, current_node);
            }
        }
    }
}
