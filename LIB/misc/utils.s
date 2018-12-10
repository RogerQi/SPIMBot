.text
.globl am_i_on_treasure
#int am_i_on_treasure(void);
#if no standing on any treasure, return 0
#else return the point of the treasure
# int am_i_on_treasure(void) {
# 	int cur_x = bot_x();
# 	int cur_y = bot_y();
#   int target_x = target_x();
#   int target_y = target_y();
#   int enemy_x = enemy_x();
#   int enemy_y = enemy_y();
# 	int i = 0;
#   int ret = 0;
#   int targetStillAvailable = 0;
# 	for(; i < treasure_map.length; ++i) {
#     if (target_x == treasure_map.treasure[i].x and target_x == ... y and enemy_x != treasure_map.treasure[i].x and enemy_y == ... y) {
#       targetStillAvailable = 1;
#     }
# 		if(cur_x == treasure_map.treasures[i].x and cur_y == ... y) {
# 			ret = 1;
# 		}
# 	}
#
#   if (!targetStillAvailable) {
#       set_target_x(-1);
#       set_target_y(-1);
#   }
#
# 	return ret;
# }
am_i_on_treasure:
    lw $a0, BOT_X($zero)
    lw $v0, BOT_Y($zero)
    div $a0, $a0, 10
    div $v0, $v0, 10
	  lw $s6, OTHER_BOT_X($zero)
    lw $s7, OTHER_BOT_Y($zero)
	  div $s6, $s6, 10
    div $s7, $s7, 10
    la $t0, target_point_buffer
    lw $t6, 0($t0) #target_pt[0]
    lw $t7, 4($t0) #target_pt[1]

    li $t1, 0 #t1: i
    li $s0, 0 #targetStillAvailable
    li $s1, 0 #ret
    la $t2, treasure_map_buffer
    sw $t2, TREASURE_MAP($zero) #request treasure map again
    lw $t3, 0($t2) #t3: length

am_i_on_treasure_loop:
    bge $t1, $t3, update_target_if_necessary
    mul $t4, $t1, 8 #offset struct
    add $t4, $t4, 4 #true offset from treasure_map
    add $t4, $t4, $t2 #&treasure_map.treasures[i]
    lhu $t5, 2($t4) #t5: treasure y
    lhu $t4, 0($t4) #t4: treasure x

    sub $s2, $t6, $t4
    sub $s3, $t7, $t5
    or  $s2, $s2, $s3
	sub $s4, $s6, $t4
    sub $s5, $s7, $t5
    nor  $s4, $s4, $s5
	or  $s2, $s2, $s4
    bne $s2, $zero, determine_if_on_a_treasure

    li $s0, 1

determine_if_on_a_treasure:
    sub $s2, $t4, $a0
    sub $s3, $t5, $v0


    or $s2, $s2, $s3 #if both are zero, then return points
    bne $s2, $zero, am_i_on_treasure_loop_continue

    mul $s2, $t1, 8 #offset struct
    add $s2, $s2, 4
    add $s3, $s2, $t2
    lw $s1, 4($s3)

am_i_on_treasure_loop_continue:
    add $t1, $t1, 1
    j am_i_on_treasure_loop

update_target_if_necessary:
    bne $s0, $zero, am_i_on_treasure_loop_ret

    li $s2, -1
    sw $s2, 0($t0)
    sw $s2, 4($t0)

am_i_on_treasure_loop_ret:
    move $v0, $s1

    move $s6, $a0
    move $s7, $v0

    li $a0, '\n'
    li $v0, PRINT_CHAR
    syscall

    move $a0, $s6
    move $v0, $s7

    jr $ra

# int target_pt[2];
# void get_nearest_treasure(distance_metric functor) {
#   if (target_pt[0] != -1 && target_pt[1] != -1)
#       return;
#   int cur_x = bot_x();
#   int cur_y = bot_y();
#   int enemy_x = enemy_x();
#   int enemy_y = enemy_y();
#   if (trasure_map.length == 0)
#       return;
#   int min_dist = functor(cur_x, cur_y, treasure_map[0].x, treasure_map[0].y);
#   int i = 0;
#   for(; i < treasure_map.length; ++i) {
#		if (enemy_x != treasure_map[i].x && enemy_y != treasure_map[i].y) {
#			int cur_dist = functor(cur_x, cur_y, treasure_map[i].x, treasure_map[i].y);
#		    if (cur_dist < min_dist) {
#				target_pt[0] = treasure_map[i].x;
#				target_pt[1] = treasure_map[i].y;
#			}
#       }
#   }
#   return 0;
# }

.data
big_prizes: .word 0:10 #[x, y], [x, y] should be 0:3 but for sanity

.text
.globl get_nearest_treasure
get_nearest_treasure:
    la $t0, big_prizes
    sw $t0, 0($t0) #a big number
    sw $t0, 4($t0)
    sw $t0, 8($t0) #a big number
    sw $t0, 12($t0)
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
	  lw $s6, OTHER_BOT_X($zero)
    lw $s7, OTHER_BOT_Y($zero)
    div $s6, $s6, 10 #a0: bot_x
    div $s7, $s7, 10 #v0: bot_y
    la $t2, treasure_map_buffer #t2: TREASURE_MAP
    sw $t2, TREASURE_MAP($zero) #request treasure map again
    lw $t3, 0($t2) #t3: length
    li $t1, 0 #t1: i = 0
    li $t8, 0

get_nearest_treasure_loop:
    bge $t1, $t3, get_nearest_treasure_ret
    mul $t4, $t1, 8 #offset struct
    add $t4, $t4, 4 #true offset from treasure_map
    add $t4, $t4, $t2 #&treasure_map.treasures[i]
    lw $t6, 4($t4) #t6: treasure award point
    bne $t6, 5, get_nearest_treasure_loop_end
    #this is a big treasure! Jackpot!
    la $t7, big_prizes
    add $t7, $t7, $t8
    add $t8, $t8, 8
    lhu $t5, 2($t4) #y
    lhu $t4, 0($t4) #x

    sub $s0, $s6, $t4
    sub $s1, $s7, $t5
    or $s0, $s0, $s1
    beq $s0, $zero, get_nearest_treasure_loop_end

    sw $t4, 0($t7)
    sw $t5, 4($t7)
    #fall to loop end

get_nearest_treasure_loop_end:
    add $t1, $t1, 1
    j get_nearest_treasure_loop

get_nearest_treasure_ret:
    #first x/y
    la $t7, big_prizes
    lw $t4, 0($t7)
    lw $t5, 4($t7)
    lw $t2, 8($t7)
    lw $t3, 12($t7)
    sub $t0, $t4, $a0
    sub $t2, $t2, $a0
    abs $t0, $t0
    abs $t2, $t2
    sub $t1, $t5, $v0
    sub $t3, $t3, $v0
    abs $t1, $t1
    abs $t3, $t3
    add $t0, $t0, $t1 #first manhattan dist
    add $t2, $t2, $t3 #second manhattan dist
    #t4 t5 are coordinates for first treasure
    ble $t0, $t2, get_nearest_treasure_true_true_ret
    #second is smaller
    lw $t4, 8($t7)
    lw $t5, 12($t7)

get_nearest_treasure_true_true_ret:
    la $t1, target_point_buffer
    sw $t4, 0($t1) #x
    sw $t5, 4($t1) #y

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
