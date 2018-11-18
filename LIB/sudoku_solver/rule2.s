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

.globl rule2

rule2: #pass
    li $v0, 0 #do nothing for now
    jr $ra
    sub $sp, $sp, 36
    sw $s0, 0($sp)
    sw $s1, 4($sp)
    sw $s2, 8($sp)
    sw $s3, 12($sp)
    sw $s4, 16($sp)
    sw $s5, 20($sp)
    sw $s6, 24($sp)
    sw $s7, 28($sp)
    sw $ra, 32($sp)
    move $s3, $a0 #s3: ptr to board
    li $s0, 0 #s0: changed
    li $s1, 0 #s1: int i
    j rule2_i_loop

#grid_squared = 16
rule2_i_loop: #p
    bge $s1, 16, rule2_end
    li $s2, 0 #s2: int j
    j rule2_j_loop

rule2_i_loop_end: #p
    add $s1, $s1, 1
    j rule2_i_loop

rule2_j_loop:
    bge $s2, 16, rule2_i_loop_end
    mul $t0, $s1, 32 #16 * 2
    mul $t1, $s2, 2
    add $t0, $t0, $t1 #offset
    add $t0, $t0, $s3 #ptr to board[i][j]
    lhu $s4, 0($t0) #s4: value
    move $a0, $s4
    jal has_single_bit_set
    bne $v0, $zero, rule2_j_loop_end
    li $s5, 0 #s5: int k
    j rule2_k_loop

#ALL_VALUES: 65535
rule2_j_loop_end:
    add $s2, $s2, 1
    j rule2_j_loop

rule2_k_loop:


rule2_k_loop_end:
    add $s5, $s5, 1
    j rule2_k_loop

#another part
#k
#Recall:
# int ii = get_square_begin(i);
# int jj = get_square_begin(j);
# for (int k = ii ; k < ii + GRIDSIZE ; ++ k) {
#     for (int l = jj ; l < jj + GRIDSIZE ; ++ l) {
#         if ((k == i) && (l == j)) {
#             continue;
#         }
#         if (board[k][l] & value) {
#             board[k][l] &= ~value;
#             changed = true;
#         }
#     }
# }
#s0: changed
#s1: int i
#s2: int j
#s3: ptr to board
#s4: value
#s5 is released
rule2_eliminate_from_square:
    move $a0, $s1
    jal get_square_begin
    move $s5, $v0 #s5: ii
    move $a0, $s2
    jal get_square_begin
    move $t0, $s5 #t0: k = ii
    add $t1, $s5, 4 # t1: ii + GRIDSIZE
    j rule2_kk_loop

rule2_kk_loop:
    bge $t0, $t1, rule2_j_loop_end
    move $t2, $v0 #t2: l = jj
    add $t3, $v0, 4 #t3: jj + GRIDSIZE
    j rule2_jj_loop

rule2_jj_loop:
    bge $t2, $t3, rule2_kk_loop_end
    sub $t7, $s1, $t0
    sub $t6, $s2, $t2
    #if both are zero, continue
    or $t7, $t6, $t7
    beq $t7, $zero, rule2_jj_loop_end
    #get board[k][l]
    mul $t7, $t0, 32
    mul $t6, $t2, 2
    add $t7, $t7, $t6
    add $t7, $t7, $s3 #ptr
    lhu $t6, 0($t7) #board[k][l]
    and $t5, $t6, $s4
    beq $t5, $zero, rule2_jj_loop_end
    #start subroutine
    #board[k][l] &= ~value; => board[k][l] = board[k][l] & ~value;
    not $t5, $s4
    and $t5, $t5, $t6
    sh $t5, 0($t7)
    li $s0, 1

rule2_jj_loop_end:
    add $t2, $t2, 1
    j rule2_jj_loop

rule2_kk_loop_end:
    add $t0, $t0, 1
    j rule2_kk_loop

rule2_end: #p
    move $v0, $s0
    lw $s0, 0($sp)
    lw $s1, 4($sp)
    lw $s2, 8($sp)
    lw $s3, 12($sp)
    lw $s4, 16($sp)
    lw $s5, 20($sp)
    lw $s6, 24($sp)
    lw $s7, 28($sp)
    lw $ra, 32($sp)
    add $sp, $sp, 36
    jr $ra
