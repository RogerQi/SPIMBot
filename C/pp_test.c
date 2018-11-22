#include <stdio.h>
#include "path_planning.h"
#include "make_map.h"

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
    target_pt[0] = 7;
    target_pt[1] = 1;
    // printf("Prepare to bfs\n");
    // bfs(&my_map, target_pt);
    printf("Prepare to floodfill\n");
    prv_target_pts[0] = 10000;
    prv_target_pts[1] = 10000;
    flood_fill(&my_map, target_pt);
    printf("Flood fill completed!\n");
    int y = 0;
    int x;
    for (; y < 30; ++y) {
        x = 0;
        for (; x < 30; ++x) {
            printf("%d ", weight_mat[y * 30 + x]);
        }
        printf("\n");
    }
    plan_next_move(target_pt);
    printf("Dumping command buffer.\n");
    int cnt = 0;
    do {
        printf("%d\n", command_buffer[cnt++]);
    } while(command_buffer[cnt] != -1);

    return 0;
}
