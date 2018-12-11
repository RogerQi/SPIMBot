.data

MAXIMUM_NODE_NUM = 900
EAST = 0
SOUTH = 1
WEST = 2
NORTH = 3
STILL = 4
STOP = -1

# .globl
command_buffer:
.word 0:MAXIMUM_NODE_NUM

visited_mark:
.word 0:MAXIMUM_NODE_NUM

prv_pos:
.word 0:MAXIMUM_NODE_NUM

weight_mat:
.word 0:MAXIMUM_NODE_NUM

prv_target_pts:
.word -100, -100

.text
.globl refresh_pp
refresh_pp:
    li $t0, 0 #t0: i
    li $t6, -1
    la $t1, prv_pos
    la $t2, visited_mark
    la $t3, command_buffer

refresh_pp_loop:
    bge $t0, MAXIMUM_NODE_NUM, refresh_pp_end
    mul $t4, $t0, 4
    add $t5, $t4, $t1
    sw $t6, 0($t5)
    add $t5, $t4, $t2
    sw $zero, 0($t5)
    add $t5, $t4, $t3
    sw $t6, 0($t5)
    add $t0, $t0, 1
    j refresh_pp_loop

refresh_pp_end:
    jr $ra

.globl fill_weight_map_with_manhattan
fill_weight_map_with_manhattan:
    #a0: tar x, a1: tar y
    la $t6, weight_mat
    li $t5, 0 #t5: i

fill_weight_map_with_manhattan_loop:
    bge $t5, 900, fill_weight_map_with_manhattan_ret
    div $t4, $t5, 30 #t4: y
    mul $t3, $t4, 30
    sub $t3, $t5, $t3 #t3: x
    sub $t0, $t3, $a0 #x diff
    sub $t1, $t4, $a1 #y diff
    abs $t0, $t0
    abs $t1, $t1
    add $t0, $t0, $t1 #man dist
    mul $t1, $t5, 4
    add $t1, $t1, $t6
    sw $t0, 0($t1)
    add $t5, $t5, 1
    j fill_weight_map_with_manhattan_loop

fill_weight_map_with_manhattan_ret:
    jr $ra

# .globl map_preprocess
# map_preprocess:
#     # process raw map to bfs-friendly map
#     # by transforming all undiscovered cells (closed on all direction)
#     # to cells that are open on all direction
#     # a0: ptr to raw map; a1: ptr to allocated processed map
#     li $t0, 0 #t0: i
#
# map_preprocess_loop:
#     bge $t0, 900, map_preprocess_loop_loop_start
#     mul $t1, $t0, 4
#     la $t3, discovered_cell
#     add $t3, $t3, $t1
#     sw $zero, 0($t3)
#     add $t2, $t1, $a1 #processed_map[i]
#     add $t1, $t1, $a0 #raw_map[i]
#     lb $t3, 3($t1) #e open
#     lb $t4, 1($t1) #w open
#     lb $t5, 2($t1) #n open
#     lb $t6, 0($t1) #s open
#     or $t7, $t3, $t4
#     or $t7, $t7, $t5
#     or $t7, $t7, $t6
#     bne $t7, $zero, map_preprocess_loop_pre_end
#     li $t3, 1
#     sb $t3, 3($t2) #e open
#     sb $t3, 1($t2) #w open
#     sb $t3, 2($t2) #n open
#     sb $t3, 0($t2) #s open
#     j map_preprocess_loop_end
#
# map_preprocess_loop_pre_end:
#     la $t1, discovered_cell
#     mul $t2, $t0, 4
#     add $t1, $t1, $t2
#     li $t2, 1
#     sw $t2, 0($t1)
#     #fall to end
#
# map_preprocess_loop_end:
#     add $t0, $t0, 1
#     j map_preprocess_loop
#
# map_preprocess_loop_loop_start:
#     li $t0, 0 #t0: i
#
# map_preprocess_loop_loop:
#     bge $t0, 900, map_preprocess_end
#     div $t1, $t0, 30 #t1: i / 30
#     mul $t2, $t1, 30
#     sub $t2, $t0, $t2 #t2: i % 30
#     la $t3, discovered_cell #t3: ptr
#
# map_preprocess_loop_loop_east_cell:
#     beq $t2, 29, map_preprocess_loop_loop_west_cell
#     add $t4, $t0, 1
#     mul $t4, $t4, 4
#     add $t4, $t4, $t3
#     lw $t4, 0($t4)
#     beq $t4, $zero, map_preprocess_loop_loop_west_cell
#     mul $t4, $t0, 4
#     add $t4, $t4, $a1
#     lb $t5, 5($t4)
#     sb $t5, 3($t4)
#
# map_preprocess_loop_loop_west_cell:
#     beq $t2, $zero, map_preprocess_loop_loop_north_cell
#     sub $t4, $t0, 1
#     mul $t4, $t4, 4
#     add $t4, $t4, $t3
#     lw $t4, 0($t4)
#     beq $t4, $zero, map_preprocess_loop_loop_north_cell
#     mul $t4, $t0, 4
#     add $t4, $t4, $a1
#     sub $t5, $t4, 1
#     lb $t5, 0($t5)
#     sb $t5, 1($t4)
#
# map_preprocess_loop_loop_north_cell:
#     beq $t1, $zero, map_preprocess_loop_loop_south_cell
#     sub $t4, $t0, 30
#     mul $t4, $t4, 4
#     add $t4, $t4, $t3
#     lw $t4, 0($t4)
#     beq $t4, $zero, map_preprocess_loop_loop_south_cell
#     mul $t4, $t0, 4
#     add $t4, $t4, $a1
#     sub $t5, $t4, 120
#     lb $t5, 0($t5)
#     sb $t5, 2($t4)
#
# map_preprocess_loop_loop_south_cell:
#     beq $t1, 29, map_preprocess_loop_loop_end
#     add $t4, $t0, 30
#     mul $t4, $t4, 4
#     add $t4, $t4, $t3
#     lw $t4, 0($t4)
#     beq $t4, $zero, map_preprocess_loop_loop_end
#     mul $t4, $t0, 4
#     add $t4, $t4, $a1
#     lb $t5, 122($t4)
#     sb $t5, 0($t4)
#
# map_preprocess_loop_loop_end:
#     add $t0, $t0, 1
#     j map_preprocess_loop_loop
#
# map_preprocess_end:
#     jr $ra
