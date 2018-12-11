#include <stdio.h>
#include "path_planning.h"
#include "make_map.h"
#include "astar.h"


int test_pq(void) {
    node_t test_arr[900];
    test_arr[0].index = 6;
    test_arr[0].f = 5;
    test_arr[0].g = 0;
    test_arr[0].prv_node = NULL;
    pq_push(&test_arr[0]);
    test_arr[1].index = 13;
    test_arr[1].f = 4;
    test_arr[1].g = 2;
    test_arr[1].prv_node = NULL;
    pq_push(&test_arr[1]);
    test_arr[2].index = 16;
    test_arr[2].f = 5;
    test_arr[2].g = 0;
    test_arr[2].prv_node = NULL;
    pq_push(&test_arr[2]);
    test_arr[3].index = 42;
    test_arr[3].f = 1;
    test_arr[3].g = 1;
    test_arr[3].prv_node = NULL;
    pq_push(&test_arr[3]);
    node_t* ret;
    ret = pq_pop();
    printf("Current pop node Index: %d\n", ret->index);
    return 0;
}

/*
int main(void) {
    maze_map my_map;
    my_map.map[0][0].s_open = 0;
    my_map.map[0][0].n_open = 0;
    make_map(&my_map);

    if (my_map.map[0][0].w_open) {
        printf("West is open!\n");
    } else {
        printf("West is closed!\n");
    }

    if (my_map.map[0][0].n_open) {
        printf("North is open!\n");
    } else {
        printf("North is closed!\n");
    }

    printf("Size of maze_map: %lu\n", sizeof(maze_map));
    printf("Size of maze_cell: %lu\n", sizeof(maze_cell));

    for (int i = 0; i < MAXIMUM_NODE_NUM; ++i)
        command_buffer[i] = -1;

    int target_pt[2];
    target_pt[0] = 19;
    target_pt[1] = 2;
    // printf("Prepare to bfs\n");
    // bfs(&my_map, target_pt);
    printf("Prepare to floodfill\n");
    make_weight();
    prv_target_pts[0] = 19;
    prv_target_pts[1] = 2;
    int y = 0;
    int x;
    for (; y < 30; ++y) {
        x = 0;
        for (; x < 30; ++x) {
            printf("%d ", weight_mat[y * 30 + x]);
        }
        printf("\n");
    }
    flood_fill(&my_map, target_pt);
    printf("Flood fill completed!\n");
    y = 0;
    for (; y < 30; ++y) {
        x = 0;
        for (; x < 30; ++x) {
            printf("%d ", weight_mat[y * 30 + x]);
        }
        printf("\n");
    }
    printf("Dumping command buffer.\n");
    plan_next_move(&my_map, target_pt);
    int cnt = 0;
    do {
        printf("%d\n", command_buffer[cnt++]);
    } while(command_buffer[cnt] != -1);

    return 0;
}*/

int main(void){
    test_pq();
    return 0;
}