.data
node_weight_queue:
.word 0:1800 #maximum_node_num * 2

.text

.globl bfs_all_with_weight
bfs_all_with_weight:
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
    jal refresh_pp #this function does not modify a0/a1
    lw $s0, 0($a1) #s0: target_x
    lw $s1, 4($a1) #s1: target_y
    #s2 s3 is free here
    la $s4, node_weight_queue #s4: queue[MAXIMUM_NODE_NUM]
    li $s5, -2 #s5: queue_ptr = -2
    li $s6, 2 #s6: ava_spot_ptr = 2
    mul $t0, $s1, 30
    add $t0, $t0, $s0
    sw $t0, 0($s4) #queue[0] = target_y * 30 + target_x
    sw $zero, 4($s4) #queue[1] = 0
    mul $t0, $t0, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0) #visited_mark[queue[0]] = 1
    li $s2, 0 #s2: visited_node_count = 0

bfs_all_with_weight_infinite_loop:
    bge $s2, 900, bfs_all_with_weight_return
    add $s5, $s5, 2 #queue_ptr += 2
    mul $t0, $s5, 4
    add $t0, $t0, $s4
    lw $s7, 0($t0) #s7: current_node = queue[queue_ptr];
    lw $s3, 4($t0) #s3: current_node_weight = queue[queue_ptr + 1];
    mul $t0, $s7, 4
    la $t1, weight_mat
    add $t0, $t0, $t1 #&weight_mat[current_node]
    sw $s3, 0($t0)
    add $s2, $s2, 1 #increment visited node count
    div $t7, $s7, 30 #t7 : node_y
    mul $t6, $t7, 30
    sub $t6, $s7, $t6 #t6: node_x
    #fall to e_open_subroutine

bfs_all_with_weight_e_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    #e open is fourth one
    add $t0, $t0, 3
    add $t0, $t0, $a0
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, bfs_all_with_weight_w_open_subroutine
    mul $t5, $t7, 30
    add $t5, $t5, $t6
    add $t5, $t5, 1 #t5: next_pos
    div $t0, $t5, 30
    sub $t0, $t0, $t7 #0 if next_pos / 30 == node_y
    mul $t1, $t5, 4
    la $t2, visited_mark
    add $t1, $t1, $t2
    lw $t1, 0($t1) #if both of em are zero, proceed
    or $t0, $t0, $t1
    bne $t0, $zero, bfs_all_with_weight_w_open_subroutine
    #free: t0 t1
    mul $t0, $t5, 4
    add $t0, $t0, $t2 #&visited_mark[next_pos]
    li $t1, 1
    sw $t1, 0($t0)
    mul $t0, $s6, 4
    add $t0, $t0, $s4
    sw $t5, 0($t0) #queue[ava_spot_ptr++] = next_pos
    add $t5, $s3, 1 #current_node_weight + 1
    sw $t5, 4($t0)
    add $s6, $s6, 2

bfs_all_with_weight_w_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    add $t0, $t0, 1
    add $t0, $t0, $a0
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, bfs_all_with_weight_n_open_subroutine
    mul $t5, $t7, 30
    add $t5, $t5, $t6
    sub $t5, $t5, 1 #t5: next_pos
    div $t0, $t5, 30
    sub $t0, $t0, $t7 #0 if next_pos / 30 == node_y
    mul $t1, $t5, 4
    la $t2, visited_mark
    add $t1, $t1, $t2
    lw $t1, 0($t1) #if both of em are zero, proceed
    or $t0, $t0, $t1
    bne $t0, $zero, bfs_all_with_weight_n_open_subroutine
    mul $t0, $t5, 4
    add $t0, $t0, $t2 #&visited_mark[next_pos]
    li $t1, 1
    sw $t1, 0($t0)
    mul $t0, $s6, 4
    add $t0, $t0, $s4
    sw $t5, 0($t0) #queue[ava_spot_ptr++] = next_pos
    add $t5, $s3, 1 #current_node_weight + 1
    sw $t5, 4($t0)
    add $s6, $s6, 2

bfs_all_with_weight_n_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    add $t0, $t0, 2
    add $t0, $t0, $a0
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, bfs_all_with_weight_s_open_subroutine
    mul $t5, $t7, 30
    add $t5, $t5, $t6
    sub $t5, $t5, 30 #t5: next_pos
    slt $t0, $t5, $zero #needs to be zero!
    mul $t1, $t5, 4
    la $t2, visited_mark
    add $t1, $t1, $t2
    lw $t1, 0($t1) #if both of em are zero, proceed
    or $t0, $t0, $t1
    bne $t0, $zero, bfs_all_with_weight_s_open_subroutine
    mul $t0, $t5, 4
    add $t0, $t0, $t2 #&visited_mark[next_pos]
    li $t1, 1
    sw $t1, 0($t0)
    mul $t0, $s6, 4
    add $t0, $t0, $s4
    sw $t5, 0($t0) #queue[ava_spot_ptr++] = next_pos
    add $t5, $s3, 1 #current_node_weight + 1
    sw $t5, 4($t0)
    add $s6, $s6, 2

bfs_all_with_weight_s_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    add $t0, $t0, $a0
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, bfs_all_with_weight_infinite_loop
    mul $t5, $t7, 30
    add $t5, $t5, $t6
    add $t5, $t5, 30 #t5: next_pos
    slt $t0, $t5, MAXIMUM_NODE_NUM #needs to be one!
    li $t1, 1
    xor $t0, $t0, $t1 #needs to be zero!
    mul $t1, $t5, 4
    la $t2, visited_mark
    add $t1, $t1, $t2
    lw $t1, 0($t1) #if both of em are zero, proceed
    or $t0, $t0, $t1
    bne $t0, $zero, bfs_all_with_weight_infinite_loop
    mul $t0, $t5, 4
    add $t0, $t0, $t2 #&visited_mark[next_pos]
    li $t1, 1
    sw $t1, 0($t0)
    mul $t0, $s6, 4
    add $t0, $t0, $s4
    sw $t5, 0($t0) #queue[ava_spot_ptr++] = next_pos
    add $t5, $s3, 1 #current_node_weight + 1
    sw $t5, 4($t0)
    add $s6, $s6, 2
    j bfs_all_with_weight_infinite_loop

#s0: target_x
#s1: target_y
#s2: current_bot_x
#s3: current_bot_y
#s4: queue[MAXIMUM_NODE_NUM]
#s5: queue_ptr = -1
#s6: ava_spot_ptr = 1
#s7: current_node = queue[queue_ptr];
#
#t6: node_x
#t7: node_y
#
#a0: maze_map* current_map
#a1: int* target_point
bfs_all_with_weight_return:
    #restore registers
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
