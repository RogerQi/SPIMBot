.data

MAXIMUM_NODE_NUM = 900
EAST = 0
SOUTH = 1
WEST = 2
NORTH = 3
STILL = 4
STOP = 5

# .globl
command_buffer:
.word 0:MAXIMUM_NODE_NUM

visited_mark:
.word 0:MAXIMUM_NODE_NUM

prv_pos:
.word 0:MAXIMUM_NODE_NUM

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

.globl map_preprocess
map_preprocess:
    # process raw map to bfs-friendly map
    # by transforming all undiscovered cells (closed on all direction)
    # to cells that are open on all direction
    # a0: ptr to raw map; a1: ptr to allocated processed map
    li $t0, 0 #t0: i

map_preprocess_loop:
    bge $t0, 900, map_preprocess_end
    mul $t1, $t0, 4
    add $t2, $t1, $a1 #processed_map[i]
    add $t1, $t1, $a0 #raw_map[i]
    lb $t3, 3($t1) #e open
    lb $t4, 1($t1) #w open
    lb $t5, 2($t1) #n open
    lb $t6, 0($t1) #s open
    or $t7, $t3, $t4
    or $t7, $t7, $t5
    or $t7, $t7, $t6
    bne $t7, $zero, map_preprocess_loop_end
    li $t3, 1
    sb $t3, 3($t2) #e open
    sb $t3, 1($t2) #w open
    sb $t3, 2($t2) #n open
    sb $t3, 0($t2) #s open

map_preprocess_loop_end:
    add $t0, $t0, 1
    j map_preprocess_loop

map_preprocess_end:
    jr $ra
