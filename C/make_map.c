#include "make_map.h"

void make_map(maze_map* allocated_struct) {
    maze_cell cur_cell;
    
    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[3][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[4][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[5][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[6][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[7][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[10][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[11][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[12][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[13][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[14][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[15][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[16][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[17][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[20][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[22][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[25][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[26][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[27][0] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[28][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[29][0] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[1][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[2][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[4][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[5][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[6][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[9][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[10][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[11][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[12][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[14][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[15][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[19][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[20][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[22][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[23][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[25][1] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[26][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[27][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[28][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[29][1] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[1][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[3][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[4][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[5][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[8][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[9][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[10][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[11][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[12][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[14][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[15][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[17][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[18][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[22][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[23][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[26][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[27][2] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[28][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[29][2] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][3] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[1][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[2][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[4][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[5][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][3] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[8][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[9][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[10][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[11][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[12][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][3] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[14][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[15][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[17][3] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[18][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[19][3] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[20][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[22][3] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[23][3] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[24][3] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[25][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][3] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[27][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][3] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[1][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[2][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[4][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[5][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[8][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[9][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[10][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[11][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[13][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[14][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[15][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[19][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[21][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[22][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[23][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[25][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[26][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[27][4] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[29][4] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[1][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[2][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[4][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[8][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[9][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[10][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[11][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[12][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[14][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[15][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[16][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[18][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[21][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[22][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[23][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[24][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[25][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[27][5] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[28][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[29][5] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[1][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[2][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[3][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[4][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[6][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[7][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[9][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[10][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[11][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[12][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[14][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[15][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[20][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[21][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[22][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[23][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[25][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[27][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][6] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][6] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[2][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[4][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[5][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[6][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[7][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[8][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[10][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[11][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[12][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[13][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[14][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[15][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[17][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[19][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[21][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[22][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[23][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[24][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[25][7] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[26][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[27][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[28][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][7] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[1][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[2][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[4][8] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[5][8] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[6][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[7][8] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[8][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[10][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[11][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[12][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[14][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[15][8] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[18][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[19][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[20][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[21][8] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[22][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][8] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[25][8] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][8] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[27][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][8] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][8] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[1][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[2][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[3][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[4][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[10][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[11][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[12][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[14][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[15][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[16][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[20][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[21][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[22][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][9] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[27][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[28][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][9] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[0][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[1][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[3][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[4][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[5][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[6][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[7][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[8][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[9][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[10][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[11][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[13][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[14][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[15][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[18][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[19][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[20][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[21][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[22][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[27][10] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[28][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[29][10] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][11] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[1][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[3][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[4][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[5][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[6][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[7][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[8][11] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][11] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[10][11] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[11][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[12][11] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[13][11] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[14][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[15][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[16][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][11] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[22][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[27][11] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][11] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[29][11] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[2][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[3][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[4][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[6][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[7][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[10][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[11][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[13][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[14][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[15][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[16][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[17][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[18][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[19][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[22][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[23][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[25][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][12] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[27][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][12] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[0][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[1][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[2][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[4][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[8][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[9][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[10][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[11][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[14][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[15][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[16][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[18][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[19][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[21][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[22][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[23][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[25][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[27][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][13] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[29][13] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[0][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[2][14] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[3][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[4][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[5][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[6][14] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[7][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[9][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[10][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[11][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[12][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[13][14] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[14][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[15][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[16][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[18][14] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[20][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[22][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[23][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[24][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][14] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][14] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[27][14] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[28][14] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][14] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[1][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[2][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[3][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[4][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[5][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[7][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[10][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[11][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[13][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[14][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[15][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[16][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[17][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[18][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[19][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[21][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[22][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[23][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[24][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[26][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[27][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][15] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[29][15] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[2][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[3][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[4][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[6][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[7][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[8][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[9][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[10][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[11][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[12][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[13][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[14][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[15][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[16][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[19][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[22][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[26][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[27][16] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[28][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[29][16] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[1][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[2][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[3][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[4][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[7][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[8][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[9][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[10][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[11][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[12][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[13][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[14][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[15][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[16][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[18][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[20][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[22][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[23][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[26][17] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[27][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][17] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[1][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[2][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[3][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[4][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[6][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[8][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[9][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[10][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[11][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[12][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[13][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[14][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[15][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[16][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[18][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[19][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[21][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[22][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[25][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[26][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[27][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][18] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[29][18] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[1][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[4][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[5][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[6][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[7][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[9][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[10][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[11][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[13][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[14][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[15][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[16][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[17][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[18][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[19][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[22][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[23][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[24][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[25][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[26][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[27][19] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[29][19] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[1][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[2][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[3][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[4][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[5][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[6][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[7][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[8][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[10][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[11][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[13][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[14][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[15][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[16][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[19][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[20][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[22][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[23][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[26][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[27][20] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[28][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[29][20] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[1][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[2][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[3][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[4][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[5][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[7][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[8][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[10][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[11][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[12][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[13][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[14][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[15][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[21][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[22][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[23][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[24][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[25][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[26][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[27][21] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[28][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[29][21] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[0][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[1][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[3][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[4][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[6][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[7][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[8][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[9][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[10][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[11][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[14][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[15][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[16][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[18][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[21][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[22][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[23][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[25][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[26][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[27][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[28][22] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[29][22] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[3][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[4][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[5][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[7][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[8][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[9][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[10][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[11][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[12][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[13][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[14][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[15][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[16][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[17][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[18][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[19][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[21][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[22][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[26][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[27][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[28][23] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][23] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[1][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[2][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[4][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[7][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[8][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[9][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[10][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[11][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[12][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[14][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[15][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[16][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[17][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[19][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[20][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[21][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[22][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[23][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[27][24] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[28][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[29][24] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[1][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[3][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[4][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[5][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[6][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[7][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[9][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[10][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[11][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[14][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[15][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[16][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[18][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[19][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[20][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[22][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[23][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[26][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[27][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[28][25] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[29][25] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[3][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[4][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[5][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[6][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[8][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[9][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[10][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[11][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[12][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[13][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[14][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[15][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[16][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[18][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[19][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[22][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[24][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[25][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[26][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[27][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[28][26] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][26] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[2][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[3][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[4][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[5][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[6][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[7][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[9][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[10][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[11][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[12][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[13][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[14][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[15][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[16][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[18][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[19][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[20][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[22][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[23][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[24][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[25][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[26][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[27][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[28][27] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[29][27] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[0][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[3][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[4][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[5][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[6][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[7][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[8][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[9][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[10][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[11][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[12][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[13][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[14][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[15][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[16][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[17][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[19][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[20][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[22][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[23][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[24][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[25][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[26][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 1;
    allocated_struct->map[27][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 1;
    allocated_struct->map[28][28] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[29][28] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[0][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[1][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[2][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[3][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[4][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[5][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[6][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[7][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[8][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[9][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[10][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[11][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[12][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[13][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[14][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[15][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[16][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[17][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[18][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[19][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[20][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[21][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[22][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[23][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[24][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[25][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[26][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 1;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[27][29] = cur_cell;

    cur_cell.s_open = 1;
    cur_cell.w_open = 1;
    cur_cell.n_open = 0;
    cur_cell.e_open = 0;
    allocated_struct->map[28][29] = cur_cell;

    cur_cell.s_open = 0;
    cur_cell.w_open = 0;
    cur_cell.n_open = 1;
    cur_cell.e_open = 0;
    allocated_struct->map[29][29] = cur_cell;
}
