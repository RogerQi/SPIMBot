.text

## bool
## rule1(unsigned short board[GRID_SQUARED][GRID_SQUARED]) {
##   bool changed = false;
##   for (int i = 0 ; i < GRID_SQUARED ; ++ i) {
##     for (int j = 0 ; j < GRID_SQUARED ; ++ j) {
##       unsigned value = board[i][j];
##       if (has_single_bit_set(value)) {
##         for (int k = 0 ; k < GRID_SQUARED ; ++ k) {
##           // eliminate from row
##           if (k != j) {
##             if (board[i][k] & value) {
##               board[i][k] &= ~value;
##               changed = true;
##             }
##           }
##           // eliminate from column
##           if (k != i) {
##             if (board[k][j] & value) {
##               board[k][j] &= ~value;
##               changed = true;
##             }
##           }
##         }
##
##         // elimnate from square
##         int ii = get_square_begin(i);
##         int jj = get_square_begin(j);
##         for (int k = ii ; k < ii + GRIDSIZE ; ++ k) {
##           for (int l = jj ; l < jj + GRIDSIZE ; ++ l) {
##             if ((k == i) && (l == j)) {
##               continue;
##             }
##             if (board[k][l] & value) {
##               board[k][l] &= ~value;
##               changed = true;
##             }
##           }
##         }
##       }
##     }
##   }
##   return changed;
## }

.globl rule1
rule1:
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
    j rule1_i_loop

#grid_squared = 16
rule1_i_loop:
    bge $s1, 16, rule1_end
    li $s2, 0 #s2: int j
    j rule1_j_loop

rule1_i_loop_end:
    add $s1, $s1, 1
    j rule1_i_loop

rule1_j_loop:
    bge $s2, 16, rule1_i_loop_end
    mul $t0, $s1, 32 #16 * 2
    mul $t1, $s2, 2
    add $t0, $t0, $t1 #offset
    add $t0, $t0, $s3 #ptr to board[i][j]
    lhu $s4, 0($t0) #s4: value
    move $a0, $s4
    jal has_single_bit_set
    beq $v0, $zero, rule1_j_loop_end
    li $s5, 0 #s5: int k
    j rule1_k_loop

rule1_j_loop_end:
    add $s2, $s2, 1
    j rule1_j_loop

rule1_k_loop:
    bge $s5, 16, rule1_eliminate_from_square
    beq $s2, $s5, rule1_eliminate_from_column
    #need board[i][k]
    mul $t0, $s1, 32
    mul $t1, $s5, 2
    add $t0, $t0, $t1 #offset
    add $t0, $s3, $t0 #true addr
    li $t2, 0
    lhu $t2, 0($t0) #board[i][k]
    and $t1, $t2, $s4
    beq $t1, $zero, rule1_eliminate_from_column
    #board[i][k] &= ~value; => board[i][k] = board[i][k] & ~value;
    #changed = true;
    not $t1, $s4 #expect: $t1 = ~$s4; $t1 = ~value
    and $t1, $t1, $t2
    sh $t1, 0($t0)
    li $s0, 1
    #expected to go to next line.

rule1_eliminate_from_column:
    beq $s5, $s1, rule1_k_loop_end
    mul $t0, $s5, 32
    mul $t1, $s2, 2
    add $t0, $t0, $t1
    add $t0, $s3, $t0 #addr to board[k][j]
    lhu $t1, 0($t0) #board[k][j]
    and $t2, $t1, $s4
    beq $t2, $zero, rule1_k_loop_end
    #subroutine from here
    #board[k][j] &= ~value; => board[k][j] = board[k][j] & (~value)
    #hanged = true;
    not $t2, $s4 #expected: $t2 = ~value
    and $t2, $t2, $t1
    sh $t2, 0($t0)
    li $s0, 1
    #expected to go to end loop here.

rule1_k_loop_end:
    add $s5, $s5, 1
    j rule1_k_loop

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
rule1_eliminate_from_square:
    move $a0, $s1
    jal get_square_begin
    move $s5, $v0 #s5: ii
    move $a0, $s2
    jal get_square_begin
    move $t0, $s5 #t0: k = ii
    add $t1, $s5, 4 # t1: ii + GRIDSIZE
    j rule1_kk_loop

rule1_kk_loop:
    bge $t0, $t1, rule1_j_loop_end
    move $t2, $v0 #t2: l = jj
    add $t3, $v0, 4 #t3: jj + GRIDSIZE
    j rule1_jj_loop

rule1_jj_loop:
    bge $t2, $t3, rule1_kk_loop_end
    sub $t7, $s1, $t0
    sub $t6, $s2, $t2
    #if both are zero, continue
    or $t7, $t6, $t7
    beq $t7, $zero, rule1_jj_loop_end
    #get board[k][l]
    mul $t7, $t0, 32
    mul $t6, $t2, 2
    add $t7, $t7, $t6
    add $t7, $t7, $s3 #ptr
    lhu $t6, 0($t7) #board[k][l]
    and $t5, $t6, $s4
    beq $t5, $zero, rule1_jj_loop_end
    #start subroutine
    #board[k][l] &= ~value; => board[k][l] = board[k][l] & ~value;
    not $t5, $s4
    and $t5, $t5, $t6
    sh $t5, 0($t7)
    li $s0, 1

rule1_jj_loop_end:
    add $t2, $t2, 1
    j rule1_jj_loop

rule1_kk_loop_end:
    add $t0, $t0, 1
    j rule1_kk_loop

rule1_end:
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
