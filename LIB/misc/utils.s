.text
.globl am_i_on_treasure
#int am_i_on_treasure(void);
#if no standing on any treasure, return 0
#else return the point of the treasure
# int am_i_on_treasure(void) {
# 	int cur_x = bot_x();
# 	int cur_y = bot_y();
# 	int i = 0;
# 	for(; i < treasure_map.length; ++i) {
# 		if(cur_x == treasure_map.treasures[i].x and cur_y == ... y) {
# 			return 1;
# 		}
# 	}
# 	return 0;
# }
am_i_on_treasure:
    lw $a0, BOT_X($zero)
    lw $v0, BOT_Y($zero)
    div $a0, $a0, 10
    div $v0, $v0, 10
    li $t1, 0 #t1: i
    la $t2, treasure_map_buffer
    sw $t2, TREASURE_MAP($zero) #request treasure map again
    lw $t3, 0($t2) #t3: length

am_i_on_treasure_loop:
    bge $t1, $t3, am_i_on_treasure_loop_ret_zero
    mul $t4, $t1, 8 #offset struct
    add $t4, $t4, 4 #true offset from treasure_map
    add $t4, $t4, $t2 #&treasure_map.treasures[i]
    lhu $t5, 2($t4) #t5: treasure y
    lhu $t4, 0($t4) #t4: treasure x
    sub $t4, $t4, $a0
    sub $t5, $t5, $v0
    or $t4, $t4, $t5 #if both are zero, then ret one
    beq $t4, $zero, am_i_on_treasure_loop_ret_pts
    add $t1, $t1, 1
    j am_i_on_treasure_loop

am_i_on_treasure_loop_ret_pts:
    mul $v0, $t1, 8 #offset struct
    add $v0, $v0, 4
    add $v0, $v0, $t2
    lw $v0, 4($v0)
    jr $ra

am_i_on_treasure_loop_ret_zero:
    li $v0, 0
    jr $ra

# int target_pt[2];
# void get_nearest_treasure(distance_metric functor) {
#   if (target_pt[0] != -1 && target_pt[1] != -1)
#       return;
#   int cur_x = bot_x();
#   int cur_y = bot_y();
#   if (trasure_map.length == 0)
#       return;
#   target_pt[0] = treasure_map[0].x;
#   target_pt[1] = treasure_map[0].y;
#   int min_dist = functor(cur_x, cur_y, treasure_map[0].x, treasure_map[0].y);
#   int i = 1;
#   for(; i < treasure_map.length; ++i) {
#       int cur_dist = functor(cur_x, cur_y, treasure_map[i].x, treasure_map[i].y);
#       if (cur_dist < min_dist) {
#           target_pt[0] = treasure_map[i].x;
#           target_pt[1] = treasure_map[i].y;
#       }
#   }
#   return 0;
# }

.globl get_nearest_treasure
get_nearest_treasure:
    la $t0, target_point_buffer
    lw $t1, 0($t0) #target_pt[0]
    lw $t2, 4($t0) #target_pt[1]
    beq $t1, -1, get_nearest_treasure_true_routine
    beq $t2, -1, get_nearest_treasure_true_routine
    #if we get here, that means both coordinates are no -1
    jr $ra

get_nearest_treasure_true_routine:
    #for now, it's hardcoded to use manhattan distance
    lw $a0, BOT_X($zero)
    lw $v0, BOT_Y($zero)
    div $a0, $a0, 10 #a0: bot_x
    div $v0, $v0, 10 #v0: bot_y
    la $t2, treasure_map_buffer #t2: TREASURE_MAP
    sw $t2, TREASURE_MAP($zero) #request treasure map again
    lw $t3, 0($t2) #t3: length
    beq $t3, $zero, get_nearest_treasure_ret
    lhu $t6, 4($t2) #for some reason this is x
    la $t1, target_point_buffer
    sw $t6, 0($t1)
    lhu $t7, 6($t2) #for some reason this is y
    sw $t7, 4($t1)
    sub $t6, $t6, $a0
    abs $t6, $t6 #x abs
    sub $t7, $t7, $v0
    abs $t7, $t7 #y abs
    add $t6, $t6, $t7 #t6: min_dist
    li $t1, 1 #t1: i = 1

get_nearest_treasure_loop:
    bge $t1, $t3, get_nearest_treasure_ret
    mul $t4, $t1, 8 #offset struct
    add $t4, $t4, 4 #true offset from treasure_map
    add $t4, $t4, $t2 #&treasure_map.treasures[i]
    lhu $t5, 2($t4) #t5: treasure y
    lhu $t4, 0($t4) #t4: treasure x
    sub $t7, $t4, $a0
    sub $t8, $t5, $v0
    abs $t7, $t7 #x abs
    abs $t8, $t8 #y abs
    add $t7, $t7, $t8 #t7: cur_dist
    bge $t7, $t6, get_nearest_treasure_loop_end
    la $t1, target_point_buffer
    sw $t4, 0($t1)
    sw $t5, 4($t1)

get_nearest_treasure_loop_end:
    add $t1, $t1, 1
    j get_nearest_treasure_loop

get_nearest_treasure_ret:
    jr $ra

#void print_array_in_mat(int trash, int array[900]);
.globl print_array_in_mat
print_array_in_mat:
    move $t0, $zero #t0: y

print_array_in_mat_y_loop:
    bge $t0, 30, print_array_in_mat_end
    li $t1, 0 #t1: x

print_array_in_mat_x_loop:
    bge $t1, 30, print_array_in_mat_y_loop_end
    mul $a0, $t0, 30
    add $a0, $a0, $t1
    mul $a0, $a0, 4
    add $a0, $a0, $a1
    lb $a0, 0($a0)
    li $v0, PRINT_INT
    syscall
    li $a0, ' '
    li $v0, PRINT_CHAR
    syscall

print_array_in_mat_x_loop_end:
    add $t1, $t1, 1
    j print_array_in_mat_x_loop

print_array_in_mat_y_loop_end:
    li $a0, '\n'
    li $v0, PRINT_CHAR
    syscall
    add $t0, $t0, 1
    j print_array_in_mat_y_loop

print_array_in_mat_end:
    li $a0, '\n'
    li $v0, PRINT_CHAR
    syscall
    jr $ra
