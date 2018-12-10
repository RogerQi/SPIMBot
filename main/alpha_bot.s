.data
# IMPORTANT! MUST BE CORRECTLY SET!
# syscall constants
PRINT_STRING = 4
PRINT_CHAR   = 11
PRINT_INT    = 1

# memory-mapped I/O
VELOCITY                = 0xffff0010
ANGLE                   = 0xffff0014
ANGLE_CONTROL           = 0xffff0018

BOT_X                   = 0xffff0020
BOT_Y                   = 0xffff0024
OTHER_BOT_X				      = 0xffff00a0
OTHER_BOT_Y				      = 0xffff00a4

TIMER                   = 0xffff001c

RIGHT_WALL_SENSOR       = 0xffff0054
PICK_TREASURE           = 0xffff00e0
TREASURE_MAP            = 0xffff0058
MAZE_MAP                = 0xffff0050

REQUEST_PUZZLE          = 0xffff00d0
SUBMIT_SOLUTION         = 0xffff00d4

BONK_INT_MASK           = 0x1000
BONK_ACK                = 0xffff0060

TIMER_INT_MASK          = 0x8000
TIMER_ACK               = 0xffff006c

REQUEST_PUZZLE_INT_MASK = 0x800
REQUEST_PUZZLE_ACK      = 0xffff00d8

#begin user added I/O
GET_KEYS = 0xffff00e4
#end user added I/O

# struct spim_treasure
#{
#   short x;
#   short y;
#   int points;
#};
#
#struct spim_treasure_map
#{
#    unsigned length;
#    struct spim_treasure treasures[50];
#};
.data

#flags
puzzle_request_flag: #1 - waiting for IO to finish; 0 - data looks good
.word 0

#Insert whatever static memory you need here
.align 4 #note that we can't use double buffer or circular buffer (multiple buffer in general)
sudoku_buffer:      .word 0:511 #512 bytes
treasure_map_buffer: .word 0:101

maze_map_buffer:      .word 0:3600 #3600 bytes
target_point_buffer: .word 0:2

key_required_lut:
.word 0 1 0 0 0 2

function_vector_table:
    .word bfs
    .word map_preprocess
    .word am_i_on_treasure
    .word get_nearest_treasure

.text
main:
    la $t0, target_point_buffer
    li $t1, -1 #request new target points
    sw $t1, 0($t0)
    sw $t1, 4($t0)
    # START SETTING UP INTERRUPTS
    li $t0, REQUEST_PUZZLE_INT_MASK
    or $t0, $t0, TIMER_INT_MASK
    or $t0, $t0, 1 #global interrupt enable
    mtc0 $t0, $12 #write to status register
    lw $t0, TIMER($zero) #get current time
    add $t0, $t0, 20
    sw $t0, TIMER($zero)
    # END SETTING UP INTERRUPTS

puzzle_solve_loop: #infinite loop
    la $t0, puzzle_request_flag
    li $t1, 1
    sw $t1, 0($t0)
    la $t0, sudoku_buffer
    sw $t0, REQUEST_PUZZLE($zero)
    la $t0, puzzle_request_flag

puzzle_solve_loop_wait:
    lw $t1, 0($t0) #if flag is zero, then we can proceed
    bne $t1, $zero, puzzle_solve_loop_wait

puzzle_solve_loop_call_solver:
    #the puzzle has been successfully written to the designated static memory address
    la $a0, sudoku_buffer
    jal sudoku_solver
    #now we can suppose the puzzle has already been solved
    la $t0, sudoku_buffer
    sw $t0, SUBMIT_SOLUTION($zero)
    j puzzle_solve_loop

# Kernel Text
.kdata
chunkIH:    .space 92
non_intrpt_str:    .asciiz "Non-interrupt exception\n"
unhandled_str:    .asciiz "Unhandled interrupt type\n"
.ktext 0x80000180
interrupt_handler:
.set noat
        move      $k1, $at        # Save $at
.set at
    la $k0, chunkIH
    sw $a0, 0($k0)        # Get some free registers
    sw $a1, 4($k0)
    sw $v0, 8($k0)
    sw $t0, 12($k0)
    sw $t1, 16($k0)
    sw $t2, 20($k0)
    sw $t3, 24($k0)
    sw $t4, 28($k0)
    sw $t5, 32($k0)
    sw $t6, 36($k0)
    sw $t7, 40($k0)
    sw $t8, 44($k0)
    sw $t9, 48($k0)
    sw $s0, 52($k0)
    sw $s1, 56($k0)
    sw $s2, 60($k0)
    sw $s3, 64($k0)
    sw $s4, 68($k0)
    sw $s5, 72($k0)
    sw $s6, 76($k0)
    sw $s7, 80($k0)
    sw $ra, 84($k0)

    mfc0      $k0, $13             # Get Cause register
    srl       $a0, $k0, 2
    and       $a0, $a0, 0xf        # ExcCode field
    bne       $a0, 0, non_intrpt

interrupt_dispatch:            # Interrupt:
        mfc0       $k0, $13        # Get Cause register, again
        beq        $k0, 0, done        # handled all outstanding interrupts

        and        $a0, $k0, BONK_INT_MASK    # is there a bonk interrupt?
        bne        $a0, 0, bonk_interrupt

        and        $a0, $k0, TIMER_INT_MASK    # is there a timer interrupt?
        bne        $a0, 0, timer_interrupt

        and 	$a0, $k0, REQUEST_PUZZLE_INT_MASK
        bne 	$a0, 0, request_puzzle_interrupt

        li        $v0, PRINT_STRING    # Unhandled interrupt types
        la        $a0, unhandled_str
        syscall
        j    done

bonk_interrupt:
        sw      $v0, BONK_ACK        # acknowledge interrupt
        j       interrupt_dispatch    # see if other interrupts are waiting

request_puzzle_interrupt:
    la $t0, puzzle_request_flag
    sw $zero, 0($t0)
    sw $a1, REQUEST_PUZZLE_ACK($zero)
    j	interrupt_dispatch

timer_interrupt_try_to_open:
    #get current key number
    lw $t0, GET_KEYS($zero)
    #get needed key number
    #note that $v0 holds points of current treasure
    la $t1, key_required_lut
    mul $v0, $v0, 4
    add $v0, $v0, $t1
    lw $v0, 0($v0) #v0 - keys required to open
    bge $t0, $v0, timer_interrupt_try_to_open_open
    #keys insufficient. Stall until we have enough keys
    j timer_interrupt_finish_up

timer_interrupt_try_to_open_open:
    #we have enough keys!
    sw $a1, PICK_TREASURE($zero) #pick up!
    #set target_pt to -1, -1
    li $t0, -1
    la $t1, target_point_buffer
    sw $t0, 0($t1)
    sw $t0, 4($t1)
    j timer_interrupt_plan_and_move

timer_interrupt:
    #first, come to a complete stop
    sw $zero, VELOCITY($zero)
    #see if we are standing on a treasure
    la $t0, function_vector_table
    lw $t0, 8($t0)
    jalr $t0 #am i on treasure
    bne $v0, $zero, timer_interrupt_try_to_open

timer_interrupt_plan_and_move:
    #get current desired point
    la $t0, function_vector_table
    lw $t0, 12($t0)
    jalr $t0 #get_nearest_treasure
    #request current map and update command buffer!
    la $t0, maze_map_buffer
    sw $t0, MAZE_MAP($zero)
    move $a0, $t0
    move $a1, $t0
    la $t0, function_vector_table
    lw $t0, 4($t0) #preprocess
    jalr $t0
    la $a1, target_point_buffer
    la $t0, function_vector_table
    lw $t0, 0($t0)
    jalr $t0 #path planning
    #get first move and move to that direction
    la $t0, command_buffer
    lw $t0, 0($t0) #first command
    mul $t0, $t0, 90
    sw $t0, ANGLE($zero) #desired direction
	li $t0, 1
	sw $t0, ANGLE_CONTROL($zero) #absolute control
    li $t0, 10
    sw $t0, VELOCITY($zero)

timer_interrupt_finish_up:
    #request a timer interrupt after 10000 cycles
    #and acknowledge
    sw $v0, TIMER_ACK        # acknowledge interrupt
    lw $t0, TIMER($zero)
	add $t0, $t0, 10000
    sw $t0, TIMER($zero)
    j interrupt_dispatch    # see if other interrupts are waiting

non_intrpt:                # was some non-interrupt
    li        $v0, PRINT_STRING
    la        $a0, non_intrpt_str
    syscall                # print out an error message
    # fall through to done

done:
    la $k0, chunkIH
    lw $a0, 0($k0)        # Free them
    lw $a1, 4($k0)
    lw $v0, 8($k0)
    lw $t0, 12($k0)
    lw $t1, 16($k0)
    lw $t2, 20($k0)
    lw $t3, 24($k0)
    lw $t4, 28($k0)
    lw $t5, 32($k0)
    lw $t6, 36($k0)
    lw $t7, 40($k0)
    lw $t8, 44($k0)
    lw $t9, 48($k0)
    lw $s0, 52($k0)
    lw $s1, 56($k0)
    lw $s2, 60($k0)
    lw $s3, 64($k0)
    lw $s4, 68($k0)
    lw $s5, 72($k0)
    lw $s6, 76($k0)
    lw $s7, 80($k0)
    lw $ra, 84($k0)

.set noat
    move    $at, $k1        # Restore $at
.set at
    eret
