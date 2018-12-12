.data
processed_map:
.word 0:3600

discovered_cell:
.word 0:MAXIMUM_NODE_NUM

.text
#for initial run: set all walls to be open
.globl map_preprocess_init
map_preprocess_init:
    li $t0, 0 #t0 : i = 0
    la $t1, discovered_cell
    la $t2, processed_map

map_preprocess_init_loop:
    bge $t0, 3600, map_preprocess_init_end
    add $t3, $t0, $t1
    sw $zero, 0($t3)
    add $t3, $t0, $t2
    li $t4, 1
    sb $t4, 0($t3) #can be optimized
    sb $t4, 1($t3)
    sb $t4, 2($t3)
    sb $t4, 3($t3)
    add $t0, $t0, 4
    j map_preprocess_init_loop

map_preprocess_init_end:
    jr $ra

.globl update_map_around_large_treasure
update_map_around_large_treasure:
    jr $ra
    sub $sp, $sp, 20
    sw $ra, 0($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)
    sw $a0, 12($sp)
    sw $a1, 16($sp)
    #we may suppose robot is standing on large treasure now
    la $a0, maze_map_buffer #a0: raw map
    sw $a0, MAZE_MAP($zero) #request raw maze map
    lw $t8, BOT_X($zero)
    #handle edge case: if this is 300 the program may fail
    div $t8, $t8, 10
    slt $t0, $t8, 30
    li $t1, 1
    xor $t0, $t0, $t1
    sub $s0, $t8, $t0 #s0: bot_x
    lw $t9, BOT_Y($zero)
    div $t9, $t9, 10
    slt $t0, $t9, 30
    xor $t0, $t0, $t1
    sub $s1, $t9, $t0 #s1: bot_y
    blt $s1, 3, update_map_around_large_treasure_lower
    #update_upper
    add $t8, $s0, $zero
    sub $t9, $s1, 1
    jal custom_cell_iterative_preprocess
    blt $s0, 3, update_map_around_large_treasure_upper_right
    #update upper left
    sub $t9, $s1, 2
    sub $t8, $s0, 2
    jal custom_cell_iterative_preprocess
    #fall to if upper right

update_map_around_large_treasure_upper_right:
    bgt $s0, 26, update_map_around_large_treasure_lower
    #update upper right
    sub $t9, $s1, 2
    add $t8, $s0, 2
    jal custom_cell_iterative_preprocess
    #fall to if lower

update_map_around_large_treasure_lower:
    bgt $s1, 26, update_map_around_large_treasure_left
    #update lower
    add $t8, $s0, $zero
    add $t9, $s1, 1
    jal custom_cell_iterative_preprocess
    blt $s0, 3, update_map_around_large_treasure_lower_right
    #update lower left!
    sub $t8, $s0, 2
    add $t9, $s1, 2
    jal custom_cell_iterative_preprocess
    #fall to if lower right

update_map_around_large_treasure_lower_right:
    bgt $s0, 26, update_map_around_large_treasure_left
    #update lower right
    add $t9, $s1, 2
    add $t8, $s0, 2
    jal custom_cell_iterative_preprocess

update_map_around_large_treasure_left:
    blt $s0, 3, update_map_around_large_treasure_right
    #update left
    add $t9, $s1, $zero
    sub $t8, $s0, 2
    jal custom_cell_iterative_preprocess

update_map_around_large_treasure_right:
    bgt $s0, 26, update_map_around_large_treasure_ret
    #update right
    add $t9, $s1, $zero
    add $t8, $s0, 2
    jal custom_cell_iterative_preprocess
    #fall to ret

update_map_around_large_treasure_ret:
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    lw $a0, 12($sp)
    lw $a1, 16($sp)
    add $sp, $sp, 20
    jr $ra

# if (y >= 3) {
#     update_upper();
#     if (x >= 3)
#         update_upper_left();
#     if (x <= 26)
#         update_upper_right();
# }
# if (y <= 26) {
#     update_lower();
#     if (x >= 3)
#         update_lower_left();
#     if (x <= 26)
#         update_lower_right();
# }
# if (x >= 3)
#     update_left();
# if (x <= 26)
#     update_right();

.globl custom_cell_iterative_preprocess
custom_cell_iterative_preprocess:
    #a0: raw_map from SPIMBot client
    #t8: x, t9: y
    j map_iterative_preprocess_true_true_process

.globl map_iterative_preprocess
map_iterative_preprocess:
    lw $t8, BOT_X($zero)
    #handle edge case: if this is 300 the program may fail
    div $t8, $t8, 10
    slt $t0, $t8, 30
    li $t1, 1
    xor $t0, $t0, $t1
    sub $t8, $t8, $t0 #t8: bot_x
    lw $t9, BOT_Y($zero)
    div $t9, $t9, 10
    slt $t0, $t9, 30
    xor $t0, $t0, $t1
    sub $t9, $t9, $t0 #t9: bot_y
    #fall to true process

map_iterative_preprocess_true_true_process:
    #a0 raw_map, t8: center x, t9: center y
    la $a1, processed_map #a1: processed_map
    mul $t7, $t9, 30
    add $t7, $t7, $t8
    mul $t7, $t7, 4 #t7 center ptr offset
    la $t1, discovered_cell
    add $t1, $t1, $t7
    lw $t0, 0($t1) #t0
    beq $t0, 1, map_iterative_preprocess_end #already discovered! End.
    li $t0, 1
    sw $t0, 0($t1) #mark as discovered.
    add $a0, $a0, $t7 #raw_map center ptr
    add $a1, $a1, $t7 #processed_map center ptr
    lw $t0, 0($a0) #should be doable!
    sw $t0, 0($a1)

map_iterative_preprocess_left:
    beq $t8, $zero, map_iterative_preprocess_right
    lw $t0, -4($a0) #doable?
    sw $t0, -4($a1)
    beq $t8, 1, map_iterative_preprocess_right
    lb $t0, -3($a0)
    sb $t0, -5($a1)

map_iterative_preprocess_right:
    beq $t8, 29, map_iterative_preprocess_upper
    lw $t0, 4($a0)
    sw $t0, 4($a1)
    beq $t8, 28, map_iterative_preprocess_upper
    lb $t0, 7($a0)
    sb $t0, 9($a1)

map_iterative_preprocess_upper:
    beq $t9, $zero, map_iterative_preprocess_lower
    lw $t0, -120($a0)
    sw $t0, -120($a1)
    beq $t9, 1, map_iterative_preprocess_upper_left
    lb $t0, -118($a0)
    sb $t0, -240($a1)

map_iterative_preprocess_upper_left:
    beq $t8, $zero, map_iterative_preprocess_upper_right
    lw $t0, -124($a0)
    sw $t0, -124($a1)
    beq $t8, 1, map_iterative_preprocess_upper_left_upper_wing
    lb $t0, -123($a0)
    sb $t0, -125($a1)

map_iterative_preprocess_upper_left_upper_wing:
    beq $t9, 1, map_iterative_preprocess_upper_right
    lb $t0, -122($a0)
    sb $t0, -244($a1)

map_iterative_preprocess_upper_right:
    beq $t8, 29, map_iterative_preprocess_lower
    lw $t0, -116($a0)
    sw $t0, -116($a1)
    beq $t8, 28, map_iterative_preprocess_upper_right_upper_wing
    lb $t0, -113($a0)
    sb $t0, -111($a1)

map_iterative_preprocess_upper_right_upper_wing:
    beq $t9, 1, map_iterative_preprocess_lower
    lb $t0, -114($a0)
    sb $t0, -236($a1)

map_iterative_preprocess_lower:
    beq $t9, 29, map_iterative_preprocess_end
    lw $t0, 120($a0)
    sw $t0, 120($a1)
    beq $t9, 28, map_iterative_preprocess_lower_left
    lb $t0, 120($a0)
    sb $t0, 242($a1)

map_iterative_preprocess_lower_left:
    beq $t8, $zero, map_iterative_preprocess_lower_right
    lw $t0, 116($a0)
    sw $t0, 116($a1)
    beq $t8, 1, map_iterative_preprocess_lower_left_lower_wing
    lb $t0, 117($a0)
    sb $t0, 115($a1)

map_iterative_preprocess_lower_left_lower_wing:
    beq $t9, 28, map_iterative_preprocess_lower_right
    lb $t0, 116($a0)
    sb $t0, 238($a1)

# typedef struct {
#     char s_open;
#     char w_open;
#     char n_open;
#     char e_open;
# } maze_cell;
map_iterative_preprocess_lower_right:
    beq $t8, 29, map_iterative_preprocess_end
    lw $t0, 124($a0)
    sw $t0, 124($a1)
    beq $t8, 28, map_iterative_preprocess_lower_right_lower_wing
    lb $t0, 127($a0)
    sb $t0, 129($a1)

map_iterative_preprocess_lower_right_lower_wing:
    beq $t9, 28, map_iterative_preprocess_end
    lb $t0, 124($a0)
    sb $t0, 246($a1)

map_iterative_preprocess_end:
    jr $ra
