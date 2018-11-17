.text
# bool rule2(unsigned short board[GRID_SQUARED][GRID_SQUARED]) {
#     bool changed = false;
#     for (int i = 0 ; i < GRID_SQUARED ; ++ i) {
#         for (int j = 0 ; j < GRID_SQUARED ; ++ j) {
#             unsigned value = board[i][j];
#             if (has_single_bit_set(value)) {
#                 continue;
#             }
#
#             int jsum = 0, isum = 0;
#             for (int k = 0 ; k < GRID_SQUARED ; ++ k) {
#                 if (k != j) {
#                     jsum |= board[i][k];        // summarize row
#                 }
#                 if (k != i) {
#                     isum |= board[k][j];         // summarize column
#                 }
#             }
#             if (ALL_VALUES != jsum) {
#                 board[i][j] = ALL_VALUES & ~jsum;
#                 changed = true;
#                 continue;
#             } else if (ALL_VALUES != isum) {
#                 board[i][j] = ALL_VALUES & ~isum;
#                 changed = true;
#                 continue;
#             }
#
#             // eliminate from square
#             int ii = get_square_begin(i);
#             int jj = get_square_begin(j);
#             unsigned sum = 0;
#             for (int k = ii ; k < ii + GRIDSIZE ; ++ k) {
#                 for (int l = jj ; l < jj + GRIDSIZE ; ++ l) {
#                     if ((k == i) && (l == j)) {
#                         continue;
#                     }
#                     sum |= board[k][l];
#                 }
#             }
#
#             if (ALL_VALUES != sum) {
#                 board[i][j] = ALL_VALUES & ~sum;
#                 changed = true;
#             }
#         }
#     }
#     return changed;
# }

# .globl rule2
