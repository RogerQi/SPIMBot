#include "astar.h"
#include "path_planning.h"

node_t frontier[900];

//to get pos in node array based on x, y
// pos = y * 30 + x

//to get x, y in terms of pos
// y = pos / 30
// x = pos % 30

int my_abs__(int val) {
    if (val >= 0)
        return val;
    return -val;
}

int manhattan_distance(int cur_x, int cur_y, int tar_x, int tar_y) {
    return my_abs__(cur_x - tar_x) + my_abs__(cur_y - tar_y);
}

//note that when accessing, for example, current_map->map[i][j]
//is equivalent to (word) current_map[i][j]
void astar(maze_map* current_map, int* target_point) {
    for (int i = 0; i < 900; ++i) visited_mark[i] = 0; //set all cells to be unvisited!
    init(); //reset priority queue
    int target_x = target_point[0];
    int target_y = target_point[1];

    int current_bot_x = 0; // in MIPS, modify this to get data from interrupt IO
    int current_bot_y = 0; // see above

    int frontier_ptr = 0;

    frontier[0].index = current_bot_y * 30 + current_bot_x;
    frontier[0].g = 0;
    frontier[0].f = manhattan_distance(current_bot_x, current_bot_y, target_x, target_y);
    frontier[0].prv_node = 0; //null pointer
    printf("index: %d\n", frontier[0].index);
    pq_push(&frontier[0]);

    while (1) {
        node_t* current_node = pq_pop(); //a ptr to some element in frontier
        int node_x = current_node->index % 30;
        int node_y = current_node->index / 30;
        printf("cur x: %d\ncur y: %d\n", node_x, node_y);
        if (node_x == target_x && node_y == target_y) {
            //finished! Recurse and get traveled path
            node_t* cur_pos = current_node;
            int cnt = 0;
            do {
                command_buffer[cnt++] = cur_pos->index;
                cur_pos = cur_pos->prv_node;
            } while (cur_pos != 0);
            // now cnt = length of command, command buffer is filled reversely with visited position (backward)
            int i = 0;
            //this loop can be avoided by expanding from target point
            for (; i < cnt / 2; ++i) {
                int temp = command_buffer[i];
                command_buffer[i] = command_buffer[cnt - i - 1];
                command_buffer[cnt - i - 1] = temp;
            }
            i = 0;
            for (; i < cnt - 1; ++i) {
                int cur_pos = command_buffer[i];
                int next_pos = command_buffer[i + 1];
                if (next_pos == cur_pos + 30)
                    command_buffer[i] = SOUTH; //move south
                if (next_pos == cur_pos - 30)
                    command_buffer[i] = NORTH;
                if (next_pos == cur_pos + 1)
                    command_buffer[i] = EAST;
                if (next_pos == cur_pos - 1)
                    command_buffer[i] = WEST;
            }
            command_buffer[i] = -1;
            return;
        }
        //add subsequent nodes to queue and update their prv positions
        //east
        if (current_map->map[node_y][node_x].e_open) {
            int next_pos = node_y * 30 + node_x + 1;
            //printf("E pos: %d\n", next_pos);
            if (next_pos / 30 == node_y && !(visited_mark[next_pos])) {
                ++frontier_ptr;
                visited_mark[next_pos] = 1; //mark as visited
                frontier[frontier_ptr].index = next_pos;
                frontier[frontier_ptr].f = (node_x >= target_x)? current_node->f + 1 : current_node->f - 1; //heuristic
                frontier[frontier_ptr].g = current_node->g + 1; //current cost
                frontier[frontier_ptr].prv_node = current_node;
                pq_push(&frontier[frontier_ptr]);
            }
        }
        if (current_map->map[node_y][node_x].w_open) {
            int next_pos = node_y* 30 + node_x - 1;
            if (next_pos / 30 == node_y && !(visited_mark[next_pos])) {
                ++frontier_ptr;
                visited_mark[next_pos] = 1;
                frontier[frontier_ptr].index = next_pos;
                frontier[frontier_ptr].f = (node_x <= target_x)? current_node->f + 1 : current_node->f - 1; //heuristic
                frontier[frontier_ptr].g = current_node->g + 1; //current cost
                frontier[frontier_ptr].prv_node = current_node;
                pq_push(&frontier[frontier_ptr]);
            }
        }
        if (current_map->map[node_y][node_x].n_open) {
            int next_pos = node_y * 30 + node_x - 30;
            if (next_pos >= 0 && !(visited_mark[next_pos])) {
                ++frontier_ptr;
                visited_mark[next_pos] = 1;
                frontier[frontier_ptr].index = next_pos;
                frontier[frontier_ptr].f = (node_y <= target_y)? current_node->f + 1 : current_node->f - 1; //heuristic
                frontier[frontier_ptr].g = current_node->g + 1; //current cost
                frontier[frontier_ptr].prv_node = current_node;
                pq_push(&frontier[frontier_ptr]);
            }
        }
        if (current_map->map[node_y][node_x].s_open) {
            int next_pos = node_y * 30 + node_x + 30;
            if (next_pos < MAXIMUM_NODE_NUM && !(visited_mark[next_pos])) {
                ++frontier_ptr;
                visited_mark[next_pos] = 1;
                frontier[frontier_ptr].index = next_pos;
                frontier[frontier_ptr].f = (node_y >= target_y)? current_node->f + 1 : current_node->f - 1; //heuristic
                frontier[frontier_ptr].g = current_node->g + 1; //current cost
                frontier[frontier_ptr].prv_node = current_node;
                pq_push(&frontier[frontier_ptr]);
            }
        }
    }
}