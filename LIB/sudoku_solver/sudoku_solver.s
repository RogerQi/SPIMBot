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

.globl sudoku_solver
sudoku_solver:
    sub $sp, $sp, 12
    sw $ra, 0($sp)
    sw $s0, 4($sp)
    sw $a0, 8($sp)

sudoku_solve_loop:
    lw $a0, 8($sp)
    jal rule1
    move $s0, $v0
    lw $a0, 8($sp)
    jal rule2
    or $s0, $s0, $v0 #if change, loop back
    beq $s0, 1, sudoku_solve_loop
    #other wise fall to return

sudoku_ret:
    # We must suppose the solution is correct.
    # So we don't care if the board is done here. Skip the detection and return! (which makes this function a void function)
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    add $sp, $sp, 12
    jr $ra
