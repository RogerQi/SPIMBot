.data
stack:
.word 0:5000

.text
#
.globl flood_fill_plan
flood_fill_plan:
    sub $sp, $sp, 12
    sw $ra, 0($sp)
    sw $a0, 4($sp)
    sw $a1, 8($sp) #target point ptr
    # move $a1, $a0
    # jal print_array_in_mat
    # lw $a0, 4($sp)
    # lw $a1, 8($sp)
    # jal bfs_all_with_weight #generate proper weight map
    jal flood_fill
    # la $a1, weight_mat
    # jal print_array_in_mat
    lw $a0, 8($sp) #note that variables order is reversed here for the sake of dev
    lw $a1, 4($sp)
    jal plan_next_move #write command buffer based on weight mat
    lw $ra, 0($sp)
    add $sp, $sp, 12
    jr $ra

plan_next_move:
    # la $t3, maze_map_buffer
    # sw $t3, MAZE_MAP($zero)
    move $t3, $a1 #t3: maze_map*
    lw $t8, BOT_X($zero)
    #handle edge case: if this is 300 the program may fail
    div $t8, $t8, 10
    slt $t0, $t8, 30
    li $t1, 1
    xor $t0, $t0, $t1
    sub $t8, $t8, $t0 #t8: cur_x = bot_x
    lw $t9, BOT_Y($zero)
    div $t9, $t9, 10
    slt $t0, $t9, 30
    xor $t0, $t0, $t1
    sub $t9, $t9, $t0 #t9: cur_y = bot_y
    lw $a1, 4($a0)  #a1: tar y
    lw $a0, 0($a0)  #a0: tar x
    li $v0, 0 #v0: command_buffer_ptr
    la $t7, command_buffer #t7: command_buffer[MAXIMUM_NODE_NUM]
    la $t6, weight_mat

plan_next_move_loop:
    sub $t0, $t8, $a0 #if nonzero, continue
    sub $t1, $t9, $a1 #if nonzero, continue
    or $t0, $t0, $t1 #if either is nonzero, continue
    beq $t0, $zero, plan_next_move_ret
    mul $t5, $t9, 30
    add $t5, $t5, $t8 #t5: cur_node
    mul $t0, $t5, 4
    add $t0, $t0, $t6
    lw $t4, 0($t0) #t4: cur_weight

plan_next_move_loop_e:
    add $t0, $t5, 1
    div $t1, $t0, 30
    bne $t1, $t9, plan_next_move_loop_w
    mul $t0, $t0, 4
    add $t0, $t0, $t6
    lw $t0, 0($t0) #weight_mat[cur_node + 1]
    sub $t1, $t4, 1
    bne $t0, $t1, plan_next_move_loop_w
    mul $t0, $t9, 120
    mul $t1, $t8, 4
    add $t0, $t0, $t1
    add $t0, $t0, $t3
    lb $t0, 3($t0)
    beq $t0, $zero, plan_next_move_loop_w
    add $t8, $t8, 1
    mul $t0, $v0, 4
    add $t0, $t0, $t7
    li $t1, EAST
    sw $t1, 0($t0)
    add $v0, $v0, 1
    j plan_next_move_ret

plan_next_move_loop_w:
    sub $t0, $t5, 1
    div $t1, $t0, 30
    bne $t1, $t9, plan_next_move_loop_n
    mul $t0, $t0, 4
    add $t0, $t0, $t6
    lw $t0, 0($t0) #weight_mat[cur_node + 1]
    sub $t1, $t4, 1
    bne $t0, $t1, plan_next_move_loop_n
    mul $t0, $t9, 120
    mul $t1, $t8, 4
    add $t0, $t0, $t1
    add $t0, $t0, $t3
    lb $t0, 1($t0)
    beq $t0, $zero, plan_next_move_loop_n
    sub $t8, $t8, 1
    mul $t0, $v0, 4
    add $t0, $t0, $t7
    li $t1, WEST
    sw $t1, 0($t0)
    add $v0, $v0, 1
    j plan_next_move_ret

plan_next_move_loop_n:
    sub $t0, $t5, 30
    ble $t0, 0, plan_next_move_loop_s
    mul $t0, $t0, 4
    add $t0, $t0, $t6
    lw $t0, 0($t0) #weight_mat[cur_node + 1]
    sub $t1, $t4, 1
    bne $t0, $t1, plan_next_move_loop_s
    mul $t0, $t9, 120
    mul $t1, $t8, 4
    add $t0, $t0, $t1
    add $t0, $t0, $t3
    lb $t0, 2($t0)
    beq $t0, $zero, plan_next_move_loop_s
    sub $t9, $t9, 1
    mul $t0, $v0, 4
    add $t0, $t0, $t7
    li $t1, NORTH
    sw $t1, 0($t0)
    add $v0, $v0, 1
    j plan_next_move_ret

plan_next_move_loop_s:
    add $t0, $t5, 30
    bge $t0, MAXIMUM_NODE_NUM, plan_next_move_loop
    mul $t0, $t0, 4
    add $t0, $t0, $t6
    lw $t0, 0($t0) #weight_mat[cur_node + 1]
    sub $t1, $t4, 1
    bne $t0, $t1, plan_next_move_loop
    mul $t0, $t9, 120
    mul $t1, $t8, 4
    add $t0, $t0, $t1
    add $t0, $t0, $t3
    lb $t0, 0($t0)
    beq $t0, $zero, plan_next_move_loop
    add $t9, $t9, 1
    mul $t0, $v0, 4
    add $t0, $t0, $t7
    li $t1, SOUTH
    sw $t1, 0($t0)
    add $v0, $v0, 1
    j plan_next_move_ret

plan_next_move_ret:
    mul $v0, $v0, 4
    add $v0, $v0, $t7
    li $t7, -1
    sw $t7, 0($v0)
    jr $ra

flood_fill:
    la $t0, prv_target_pts
    lw $t1, 0($t0) #x
    lw $t2, 4($t0) #y
    lw $t3, 0($a1) #new x
    lw $t4, 4($a1) #new y
    sub $t1, $t1, $t3
    sub $t2, $t2, $t4 #if both are zero, proceed
    or $t0, $t1, $t2
    beq $t0, $zero, official_flood_fill
    #else logic
    la $t0, prv_target_pts
    sw $t3, 0($t0)
    sw $t4, 4($t0)
    j bfs_all_with_weight #a trick to avoid saving $ra

official_flood_fill:
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
    lw $s2, BOT_X($zero)
    #handle edge case: if this is 300 the program may fail
    div $s2, $s2, 10
    slt $t0, $s2, 30
    li $t1, 1
    xor $t0, $t0, $t1
    sub $s2, $s2, $t0
    lw $s3, BOT_Y($zero)
    div $s3, $s3, 10
    slt $t0, $s3, 30
    xor $t0, $t0, $t1
    sub $s3, $s3, $t0
    mul $t0, $s3, 30
    add $t0, $t0, $s2 #current_node = bot_y * 30 + bot_x;
    #s2 and s3 are freed here
    li $s0, 0 #s0: stack_ptr = 0
    la $s1, stack #s1: stack[900]
    sw $t0, 0($s1)
    la $t9, weight_mat #t9: weight_mat
#free: t1, t2
official_flood_fill_west_expand:
    beq $s2, $zero, official_flood_fill_east_expand
    add $s0, $s0, 1
    mul $t1, $s0, 4
    add $t1, $t1, $s1
    sub $t2, $t0, 1
    sw $t2, 0($t1)

official_flood_fill_east_expand:
    beq $s2, 29, official_flood_fill_north_expand
    add $s0, $s0, 1
    mul $t1, $s0, 4
    add $t1, $t1, $s1
    add $t2, $t0, 1
    sw $t2, 0($t1)

official_flood_fill_north_expand:
    beq $s3, $zero, official_flood_fill_south_expand
    add $s0, $s0, 1
    mul $t1, $s0, 4
    add $t1, $t1, $s1
    sub $t2, $t0, 30
    sw $t2, 0($t1)
    #north west
    beq $s2, $zero, official_flood_fill_north_expand_north_east
    add $s0, $s0, 1
    mul $t1, $s0, 4
    add $t1, $t1, $s1
    sub $t2, $t0, 31
    sw $t2, 0($t1)

official_flood_fill_north_expand_north_east:
    beq $s2, 29, official_flood_fill_south_expand
    add $s0, $s0, 1
    mul $t1, $s0, 4
    add $t1, $t1, $s1
    sub $t2, $t0, 29
    sw $t2, 0($t1)

official_flood_fill_south_expand:
    beq $s3, 29, flood_fill_stack_loop
    add $s0, $s0, 1
    mul $t1, $s0, 4
    add $t1, $t1, $s1
    add $t2, $t0, 30
    sw $t2, 0($t1)
    #south west
    beq $s2, $zero, official_flood_fill_south_expand_south_east
    add $s0, $s0, 1
    mul $t1, $s0, 4
    add $t1, $t1, $s1
    add $t2, $t0, 29
    sw $t2, 0($t1)

official_flood_fill_south_expand_south_east:
    beq $s2, 29, flood_fill_stack_loop
    add $s0, $s0, 1
    mul $t1, $s0, 4
    add $t1, $t1, $s1
    add $t2, $t0, 31
    sw $t2, 0($t1)

flood_fill_stack_loop:
    blt $s0, 0, flood_fill_return
    # sub $sp, $sp, 8
    # sw $a0, 0($sp)
    # sw $v0, 4($sp)
    # li $v0, PRINT_INT
    # move $a0, $s0
    # syscall
    # li $v0, PRINT_CHAR
    # li $a0, ' '
    # syscall
    # lw $a0, 0($sp)
    # lw $v0, 4($sp)
    # add $sp, $sp, 8
    mul $t0, $s0, 4
    add $t0, $t0, $s1
    lw $s2, 0($t0) #s2: cur_pos = stack[stack_ptr]
    # sub $sp, $sp, 8
    # sw $a0, 0($sp)
    # sw $v0, 4($sp)
    # li $v0, PRINT_INT
    # move $a0, $s2
    # syscall
    # li $v0, PRINT_CHAR
    # li $a0, '\n'
    # syscall
    # lw $a0, 0($sp)
    # lw $v0, 4($sp)
    # add $sp, $sp, 8
    sub $s0, $s0, 1
    div $t8, $s2, 30 #t8: node_y
    mul $t7, $t8, 30
    sub $t7, $s2, $t7 #t7: node_x
    li $s3, 2000 #s3: min_val = 2000
    mul $t0, $t8, 120
    mul $t1, $t7, 4
    add $t0, $t0, $t1
    add $t0, $t0, $a0
    lb $s4, 3($t0) #s4: current_map->map[node_y][node_x].e_open
    lb $s5, 1($t0) #s5: current_map->map[node_y][node_x].w_open
    lb $s6, 2($t0) #s6: current_map->map[node_y][node_x].n_open
    lb $s7, 0($t0) #s7: current_map->map[node_y][node_x].s_open

flood_fill_stack_loop_minval_e:
    beq $s4, $zero, flood_fill_stack_loop_minval_w
    beq $t7, 29, flood_fill_stack_loop_minval_w
    add $t0, $s2, 1
    mul $t0, $t0, 4
    add $t0, $t0, $t9 #&weight_mat[cur_pos + 1]
    lw $t1, 0($t0)
    bge $t1, $s3, flood_fill_stack_loop_minval_w
    move $s3, $t1

flood_fill_stack_loop_minval_w:
    beq $s5, $zero, flood_fill_stack_loop_minval_n
    beq $t7, $zero, flood_fill_stack_loop_minval_n
    sub $t0, $s2, 1
    mul $t0, $t0, 4
    add $t0, $t0, $t9 #&weight_mat[cur_pos - 1]
    lw $t1, 0($t0)
    bge $t1, $s3, flood_fill_stack_loop_minval_n
    move $s3, $t1

flood_fill_stack_loop_minval_n:
    beq $s6, $zero, flood_fill_stack_loop_minval_s
    beq $t8, $zero, flood_fill_stack_loop_minval_s
    sub $t0, $s2, 30
    mul $t0, $t0, 4
    add $t0, $t0, $t9 #&weight_mat[cur_pos - 30]
    lw $t1, 0($t0)
    bge $t1, $s3, flood_fill_stack_loop_minval_s
    move $s3, $t1

flood_fill_stack_loop_minval_s:
    beq $s7, $zero, flood_fill_stack_loop_inconsistency_check
    beq $t8, 29, flood_fill_stack_loop_inconsistency_check
    add $t0, $s2, 30
    mul $t0, $t0, 4
    add $t0, $t0, $t9 #&weight_mat[cur_pos + 30]
    lw $t1, 0($t0)
    bge $t1, $s3, flood_fill_stack_loop_inconsistency_check
    move $s3, $t1

flood_fill_stack_loop_inconsistency_check:
    mul $t0, $s2, 4
    add $t0, $t0, $t9
    lw $t1, 0($t0)
    beq $t1, $zero, flood_fill_stack_loop #if zero, go back
    sub $t1, $t1, 1
    beq $s3, $t1, flood_fill_stack_loop
    #inconsistency found
    add $s3, $s3, 1
    sw $s3, 0($t0) #weight_mat[cur_pos] = ++min_val;

flood_fill_stack_loop_inconsistency_check_e:
    beq $s4, $zero, flood_fill_stack_loop_inconsistency_check_w
    add $s0, $s0, 1
    mul $t0, $s0, 4
    add $t0, $t0, $s1
    add $t1, $s2, 1
    sw $t1, 0($t0)

flood_fill_stack_loop_inconsistency_check_w:
    beq $s5, $zero, flood_fill_stack_loop_inconsistency_check_n
    add $s0, $s0, 1
    mul $t0, $s0, 4
    add $t0, $t0, $s1
    sub $t1, $s2, 1
    sw $t1, 0($t0)

flood_fill_stack_loop_inconsistency_check_n:
    beq $s6, $zero, flood_fill_stack_loop_inconsistency_check_s
    add $s0, $s0, 1
    mul $t0, $s0, 4
    add $t0, $t0, $s1
    sub $t1, $s2, 30
    sw $t1, 0($t0)

flood_fill_stack_loop_inconsistency_check_s:
    beq $s7, $zero, flood_fill_stack_loop
    add $s0, $s0, 1
    mul $t0, $s0, 4
    add $t0, $t0, $s1
    add $t1, $s2, 30
    sw $t1, 0($t0)
    j flood_fill_stack_loop

flood_fill_return:
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
