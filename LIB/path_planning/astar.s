.data
frontier:
.word 0:3600

astar_flag: .word 0:1

.text
.globl astar_plan
astar_plan:
    sub $sp, $sp, 4
    sw $ra, 0($sp)
    jal astar
    #now command buffer is filled with command
    la $t0, step_to_plan
    lw $t0, 0($t0)
    mul $t0, $t0, 4
    la $t1, command_buffer
    add $t0, $t0, $t1
    li $t1, -1
    sw $t1, 0($t0) #set a stop somewhere
    lw $ra, 0($sp)
    add $sp, $sp, 4
    jr $ra

astar_ff_mix_plan:
    sub $sp, $sp, 4
    sw $ra, 0($sp)


.globl astar
astar:
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
    move $s6, $a0 #s6: my_map
    la $t0, visited_mark
    add $t1, $t0, 3600

astar_clear_visit_mark:
    bge $t0, $t1, astar_true
    sw $zero, 0($t0)
    add $t0, $t0, 4
    j astar_clear_visit_mark

astar_true:
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
    sub $sp, $sp, 8
    sw $a0, 0($sp)
    sw $a1, 4($sp)
    jal pq_init #TODO: use Vivian's init
    lw $a0, 0($sp)
    lw $a1, 4($sp)
    add $sp, $sp, 8
    la $s4, frontier #s4: frontier pointer: 3600 words
    #be careful with this pointer!
    #set index
    mul $t0, $s3, 30
    add $t0, $t0, $s2
    sw $t0, 0($s4) #index
    la $t1, visited_mark
    mul $t2, $t0, 4
    add $t1, $t2, $t1
    li $t2, 1
    sw $t2, 0($t1) #mark init cell as visited
    sw $zero, 8($s4) #g
    sub $t1, $s2, $s0
    abs $t1, $t1
    sub $t2, $s3, $s1
    abs $t2, $t2
    add $t1, $t1, $t2
    sw $t1, 4($s4)  #f
    sw $zero, 12($s4) #prv_node
    #finish setting up a frontier node
    move $a0, $s4
    jal pq_push

astar_infinite_loop:
    jal pq_pop
    lw $s7, 0($v0) #s7: index of current node
    div $t7, $s7, 30 #t7 : node_y
    mul $t6, $t7, 30
    sub $t6, $s7, $t6 #t6: node_x
    sub $t0, $t6, $s0 #0 if node_x == target_x
    sub $t1, $t7, $s1 #0 if node_y == target_y
    or $t0, $t0, $t1 #0 if both are eqaul
    beq $t0, $zero, astar_recurse_and_return
    #now we can suppose we haven't reached the target point.
    #fall to e_open_subroutine

astar_e_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    #e open is fourth one
    add $t0, $t0, 3
    add $t0, $t0, $s6
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, astar_w_open_subroutine
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
    bne $t0, $zero, astar_w_open_subroutine
    #true routine
    #free: t0 t1 a0
    mul $t0, $t5, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)
    #finished setting up visited mark
    add $s4, $s4, 16 #increment frontier_ptr
    sw $t5, 0($s4) #index
    #t5 is free from here
    #by default, add 1
    lw $t0, 4($v0) #get cur_node->f
    add $t0, $t0, 1
    #this expression mimic its C implementation
    bge $t6, $s0, astar_e_open_subroutine_f_save_f
    #minus 2 instead
    sub $t0, $t0, 2

astar_e_open_subroutine_f_save_f:
    sw $t0, 4($s4)
    #save g
    lw $t0, 8($v0)
    add $t0, $t0, 1
    sw $t0, 8($s4)
    #save prv_node
    sw $v0, 12($s4)
    move $a0, $s4
    jal pq_push

# typedef struct {
#     int index;
#     int f;
#     int g;
#     struct node_t *prv_node;
# } node_t;

astar_w_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    add $t0, $t0, 1
    add $t0, $t0, $s6
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, astar_n_open_subroutine
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
    bne $t0, $zero, astar_n_open_subroutine
    #true routine
    mul $t0, $t5, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)
    #finished setting up visited mark
    add $s4, $s4, 16 #increment frontier_ptr
    sw $t5, 0($s4) #index
    #t5 is free from here
    #by default, add 1
    lw $t0, 4($v0) #get cur_node->f
    add $t0, $t0, 1
    #this expression mimic its C implementation
    ble $t6, $s0, astar_w_open_subroutine_f_save_f
    #minus 2 instead
    sub $t0, $t0, 2

astar_w_open_subroutine_f_save_f:
    sw $t0, 4($s4)
    #save g
    lw $t0, 8($v0)
    add $t0, $t0, 1
    sw $t0, 8($s4)
    #save prv_node
    sw $v0, 12($s4)
    move $a0, $s4
    jal pq_push

astar_n_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    add $t0, $t0, 2
    add $t0, $t0, $s6
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, astar_s_open_subroutine
    mul $t5, $t7, 30
    add $t5, $t5, $t6
    sub $t5, $t5, 30 #t5: next_pos
    slt $t0, $t5, $zero #needs to be zero!
    mul $t1, $t5, 4
    la $t2, visited_mark
    add $t1, $t1, $t2
    lw $t1, 0($t1) #if both of em are zero, proceed
    or $t0, $t0, $t1
    bne $t0, $zero, astar_s_open_subroutine
    #true routine
    mul $t0, $t5, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)
    #finished setting up visited mark
    add $s4, $s4, 16 #increment frontier_ptr
    sw $t5, 0($s4) #index
    #t5 is free from here
    #by default, add 1
    lw $t0, 4($v0) #get cur_node->f
    add $t0, $t0, 1
    #this expression mimic its C implementation
    ble $t7, $s1, astar_n_open_subroutine_f_save_f
    #minus 2 instead
    sub $t0, $t0, 2

astar_n_open_subroutine_f_save_f:
    sw $t0, 4($s4)
    #save g
    lw $t0, 8($v0)
    add $t0, $t0, 1
    sw $t0, 8($s4)
    #save prv_node
    sw $v0, 12($s4)
    move $a0, $s4
    jal pq_push

astar_s_open_subroutine:
    #note that size of maze_cell is 4
    #4 * 30 = 120 (bytes per row)
    mul $t0, $t7, 120
    mul $t1, $t6, 4
    add $t0, $t0, $t1 #offset
    add $t0, $t0, $s6
    lb $t0, 0($t0) #t0 is e_open of current cell
    beq $t0, $zero, astar_infinite_loop
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
    bne $t0, $zero, astar_infinite_loop
    #true routine
    mul $t0, $t5, 4
    la $t1, visited_mark
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)
    #finished setting up visited mark
    add $s4, $s4, 16 #increment frontier_ptr
    sw $t5, 0($s4) #index
    #t5 is free from here
    #by default, add 1
    lw $t0, 4($v0) #get cur_node->f
    add $t0, $t0, 1
    #this expression mimic its C implementation
    bge $t7, $s1, astar_s_open_subroutine_f_save_f
    #minus 2 instead
    sub $t0, $t0, 2

astar_s_open_subroutine_f_save_f:
    sw $t0, 4($s4)
    #save g
    lw $t0, 8($v0)
    add $t0, $t0, 1
    sw $t0, 8($s4)
    #save prv_node
    sw $v0, 12($s4)
    move $a0, $s4
    jal pq_push
    j astar_infinite_loop

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

# typedef struct {
#     int index;
#     int f;
#     int g;
#     struct node_t *prv_node;
# } node_t;
astar_recurse_and_return:
    li $t5, 0 #t5: cnt = 0;
    la $t4, command_buffer
    #v0 is current node and is not used afterwards

#t2 t0 t1
astar_recurse_and_return_loop:
    lw $t0, 0($v0) #cur_pos->index
    mul $t1, $t5, 4
    add $t1, $t1, $t4
    sw $t0, 0($t1)
    add $t5, $t5, 1
    lw $v0, 12($v0)
    beq $v0, $zero, astar_recurse_and_return_reverse_command_buffer
    j astar_recurse_and_return_loop

#t5 needs to be set to correct cnt here! (already)
astar_recurse_and_return_reverse_command_buffer:
    la $t2, command_buffer
    li $t3, 0 #t3: i
    div $a0, $t5, 2

astar_recurse_and_return_reverse_command_buffer_loop:
    bge $t3, $a0, astar_recurse_and_return_extract_command
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
    j astar_recurse_and_return_reverse_command_buffer_loop

astar_recurse_and_return_extract_command:
    and $t3, $t3, 0 # i = 0
    sub $a0, $t5, 1

astar_recurse_and_return_extract_command_loop:
    bge $t3, $a0, astar_recurse_and_return_true_return
    mul $a1, $t3, 4
    add $a1, $a1, $t2 #&command_buffer[i]
    lw $s0, 0($a1) #cur_pos
    lw $s1, 4($a1) #next_pos
    #fall to south if

astar_recurse_and_return_extract_command_loop_south_if:
    add $t0, $s0, 30
    bne $s1, $t0, astar_recurse_and_return_extract_command_loop_north_if
    li $t0, SOUTH
    sw $t0, 0($a1)
    j astar_recurse_and_return_extract_command_loop_end

astar_recurse_and_return_extract_command_loop_north_if:
    sub $t0, $s0, 30
    bne $s1, $t0, astar_recurse_and_return_extract_command_loop_east_if
    li $t0, NORTH
    sw $t0, 0($a1)
    j astar_recurse_and_return_extract_command_loop_end

astar_recurse_and_return_extract_command_loop_east_if:
    add $t0, $s0, 1
    bne $s1, $t0, astar_recurse_and_return_extract_command_loop_west_if
    li $t0, EAST
    sw $t0, 0($a1)
    j astar_recurse_and_return_extract_command_loop_end

astar_recurse_and_return_extract_command_loop_west_if:
    sub $t0, $s0, 1
    bne $s1, $t0, astar_recurse_and_return_extract_command_loop_end
    li $t0, WEST
    sw $t0, 0($a1)
    j astar_recurse_and_return_extract_command_loop_end

astar_recurse_and_return_extract_command_loop_end:
    add $t3, $t3, 1
    j astar_recurse_and_return_extract_command_loop

astar_recurse_and_return_true_return:
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
