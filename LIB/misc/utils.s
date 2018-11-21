.text
.globl am_i_on_treasure
#int am_i_on_treasure(void);
#if no standing on any treasure, return 0
#else return the point of the treasure
am_i_on_treasure:
    #ava. reg: a0, v0, t1, t2, t3, (t4, t5)
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
