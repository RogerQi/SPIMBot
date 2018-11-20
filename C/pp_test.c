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

    int target_pt[2];
    target_pt[0] = 15;
    target_pt[1] = 15;
    printf("Prepare to bfs\n");
    bfs(&my_map, target_pt);
    int cnt = 0;
    do {
        printf("%d\n", command_buffer[cnt++]);
    } while(command_buffer[cnt] != -1);

    return 0;
}
