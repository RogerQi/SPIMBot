#include <stdio.h>
#include "path_planning.h"
#include "make_map.h"

int main(void) {
    maze_map my_map;
    my_map.map[0][0].s_open = 0;
    my_map.map[0][0].n_open = 0;
    make_map(&my_map);

    if (my_map.map[0][0].s_open) {
        printf("South is open!\n");
    } else {
        printf("South is closed!\n");
    }

    if (my_map.map[0][0].n_open) {
        printf("North is open!\n");
    } else {
        printf("North is closed!\n");
    }

    return 0;
}
