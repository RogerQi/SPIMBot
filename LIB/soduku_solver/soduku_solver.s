.text
# bool solve(unsigned short board[GRID_SQUARED][GRID_SQUARED]) {
#     bool changed;
#     do {
#         changed = rule1(board);
#         changed |= rule2(board);
#     } while (changed);
#
#     if (board_done(board)) {
#         printf("SUCCESS!\n");
#         print_board(board);
#     } else {
#         printf("FAILED!\n");
#         print_board_verbose(board);
#     }
#     printf("\n");
# }

# .globl soduku_solver
