.data
queue:
.word 0:MAXIMUM_NODE_NUM

.text

.globl bfs
bfs:
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
    lw $s2, BOT_X($zero)
    #handle edge case: if this is 300 the program may fail
    div $s2, $s2, 10
    slt $t0, $s2, 30
    li $t1, 1
    xor $t0, $t0, $t1
    sub $s2, $s2, $t0 #s2: current_bot_x
    lw $s3, BOT_Y($zero)
    div $s3, $s3, 10
    slt $t0, $s3, 30
    xor $t0, $t0, $t1
    sub $s3, $s3, $t0 #s3: current_bot_y
    la $s4, queue #s4: queue[MAXIMUM_NODE_NUM]
    li $s5, -1 #s5: queue_ptr = -1
    li $s6, 1 #s6: ava_spot_ptr = 1
    mul $t0, $s3, 30
    add $t0, $t0, $s2
    sw $t0, 0($s4)
    mul $t0, $t0, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    sw $s6, 0($t0) #visited_mark[queue[0]] = 1

bfs_infinite_loop:
    add $s5, $s5, 1
    mul $t0, $s5, 4
    add $t0, $t0, $s4
    lw $s7, 0($t0) #s7: current_node = queue[queue_ptr];
    mul $t0, $s7, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)
    div $t7, $s7, 30 #t7 : node_y
    mul $t6, $t7, 30
    sub $t6, $s7, $t6 #t6: node_x
    sub $t0, $t6, $s0 #0 if node_x == target_x
    sub $t1, $t7, $s1 #0 if node_y == target_y
    or $t0, $t0, $t1 #0 if both are eqaul
    beq $t0, $zero, bfs_recurse_and_return
    #now we can suppose we haven't reached the target point.
    #fall to e_open_subroutine

bfs_e_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    #e open is fourth one
    add $t0, $t0, 3
    add $t0, $t0, $a0
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, bfs_w_open_subroutine
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
    bne $t0, $zero, bfs_w_open_subroutine
    #free: t0 t1
    mul $t0, $t5, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)
    mul $t0, $s6, 4
    add $t0, $t0, $s4
    sw $t5, 0($t0)
    add $s6, $s6, 1
    mul $t0, $t5, 4
    la $t1, prv_pos
    add $t0, $t0, $t1
    sw $s7, 0($t0)

bfs_w_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    add $t0, $t0, 1
    add $t0, $t0, $a0
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, bfs_n_open_subroutine
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
    bne $t0, $zero, bfs_n_open_subroutine
    mul $t0, $t5, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)
    mul $t0, $s6, 4
    add $t0, $t0, $s4
    sw $t5, 0($t0)
    add $s6, $s6, 1
    mul $t0, $t5, 4
    la $t1, prv_pos
    add $t0, $t0, $t1
    sw $s7, 0($t0)

bfs_n_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    add $t0, $t0, 2
    add $t0, $t0, $a0
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, bfs_s_open_subroutine
    mul $t5, $t7, 30
    add $t5, $t5, $t6
    sub $t5, $t5, 30 #t5: next_pos
    slt $t0, $t5, $zero #needs to be zero!
    mul $t1, $t5, 4
    la $t2, visited_mark
    add $t1, $t1, $t2
    lw $t1, 0($t1) #if both of em are zero, proceed
    or $t0, $t0, $t1
    bne $t0, $zero, bfs_s_open_subroutine
    mul $t0, $t5, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)
    mul $t0, $s6, 4
    add $t0, $t0, $s4
    sw $t5, 0($t0)
    add $s6, $s6, 1
    mul $t0, $t5, 4
    la $t1, prv_pos
    add $t0, $t0, $t1
    sw $s7, 0($t0)

bfs_s_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    add $t0, $t0, $a0
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, bfs_infinite_loop
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
    bne $t0, $zero, bfs_infinite_loop
    mul $t0, $t5, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)
    mul $t0, $s6, 4
    add $t0, $t0, $s4
    sw $t5, 0($t0)
    add $s6, $s6, 1
    mul $t0, $t5, 4
    la $t1, prv_pos
    add $t0, $t0, $t1
    sw $s7, 0($t0)
    j bfs_infinite_loop

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
bfs_recurse_and_return:
    move $t4, $s7 #t4: cur_pos = current_node;
    li $t5, 0 #t5: cnt = 0;
    la $t1, command_buffer
    la $t2, prv_pos

bfs_recurse_and_return_loop:
    beq $t4, -1, bfs_recurse_and_return_reverse_command_buffer
    mul $t0, $t5, 4
    add $t0, $t0, $t1
    sw $t4, 0($t0)
    add $t5, $t5, 1
    mul $t0, $t4, 4
    add $t0, $t0, $t2
    lw $t4, 0($t0)
    j bfs_recurse_and_return_loop

bfs_recurse_and_return_reverse_command_buffer:
    la $t2, command_buffer
    li $t3, 0 #t3: i
    div $a0, $t5, 2

bfs_recurse_and_return_reverse_command_buffer_loop:
    bge $t3, $a0, bfs_recurse_and_return_extract_command
    mul $t0, $t3, 4
    add $t0, $t0, $t2 #t0: &command_buffer[i]
    lw $a1, 0($t0) #a1: temp
    sub $t1, $t5, $t3
    mul $t1, $t1, 4
    add $t1, $t1, $t2
    sub $t1, $t1, 4 #t1: &command_buffer[cnt - i - 1]
    lw $t8, 0($t1)
    sw $t8, 0($t0)
    sw $a1, 0($t1)
    add $t3, $t3, 1
    j bfs_recurse_and_return_reverse_command_buffer_loop

bfs_recurse_and_return_extract_command:
    and $t3, $t3, 0 # i = 0
    sub $a0, $t5, 1

bfs_recurse_and_return_extract_command_loop:
    bge $t3, $a0, bfs_recurse_and_return_true_return
    mul $a1, $t3, 4
    add $a1, $a1, $t2 #&command_buffer[i]
    lw $s0, 0($a1) #cur_pos
    lw $s1, 4($a1) #next_pos
    #fall to south if

bfs_recurse_and_return_extract_command_loop_south_if:
    add $t0, $s0, 30
    bne $s1, $t0, bfs_recurse_and_return_extract_command_loop_north_if
    li $t0, SOUTH
    sw $t0, 0($a1)
    j bfs_recurse_and_return_extract_command_loop_end

bfs_recurse_and_return_extract_command_loop_north_if:
    sub $t0, $s0, 30
    bne $s1, $t0, bfs_recurse_and_return_extract_command_loop_east_if
    li $t0, NORTH
    sw $t0, 0($a1)
    j bfs_recurse_and_return_extract_command_loop_end

bfs_recurse_and_return_extract_command_loop_east_if:
    add $t0, $s0, 1
    bne $s1, $t0, bfs_recurse_and_return_extract_command_loop_west_if
    li $t0, EAST
    sw $t0, 0($a1)
    j bfs_recurse_and_return_extract_command_loop_end

bfs_recurse_and_return_extract_command_loop_west_if:
    sub $t0, $s0, 1
    bne $s1, $t0, bfs_recurse_and_return_extract_command_loop_end
    li $t0, WEST
    sw $t0, 0($a1)
    j bfs_recurse_and_return_extract_command_loop_end

bfs_recurse_and_return_extract_command_loop_end:
    add $t3, $t3, 1
    j bfs_recurse_and_return_extract_command_loop

bfs_recurse_and_return_true_return:
    mul $t3, $t3, 4
    add $t3, $t3, $t2
    li $t0, -1
    sw $t0, 0($t3)
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
