.data
# IMPORTANT! MUST BE CORRECTLY SET!
TEST_PP_FUNCTOR = bfs
TEST_TARGET_X = 29
TEST_TARGET_Y = 29
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
maze_map_buffer:      .word 0:3600 #3600 bytes
target_point_buffer: .word 0:2

.text
print_command_buffer:
    li $t0, 0
    la $t1, command_buffer
    mul $t2, $t0, 4
    add $t2, $t2, $t1
    lw $t2, 0($t2) #command_buffer[cnt]

print_command_buffer_loop:
    #print "%d ", command_buffer[cnt++]
    li $v0, PRINT_INT
    move $a0, $t2
    syscall
    li $v0, PRINT_CHAR
    li $a0, ' '
    syscall
    add $t0, $t0, 1
    mul $t2, $t0, 4
    add $t2, $t2, $t1
    lw $t2, 0($t2) #command_buffer[cnt]
    beq $t2, -1, print_command_buffer_end
    j print_command_buffer_loop

print_command_buffer_end:
    jr $ra

main:
    # In this test, we don't use interrupts.
    # It prints out the planned path to a set point.
    la $t0, maze_map_buffer
    sw $t0, MAZE_MAP($zero)
    move $a0, $t0
    move $a1, $t0
    jal map_preprocess
    li $t0, TEST_TARGET_X
    la $a1, target_point_buffer
    sw $t0, 0($a1)
    li $t0, TEST_TARGET_Y
    sw $t0, 4($a1)
    jal bfs
    jal print_command_buffer

main_infinite_loop:
    j main_infinite_loop

# Kernel Text
.kdata
chunkIH:    .space 28
non_intrpt_str:    .asciiz "Non-interrupt exception\n"
unhandled_str:    .asciiz "Unhandled interrupt type\n"
.ktext 0x80000180
interrupt_handler:
.set noat
        move      $k1, $at        # Save $at
.set at
        la        $k0, chunkIH
        sw        $a0, 0($k0)        # Get some free registers
        sw        $v0, 4($k0)        # by storing them to a global variable
        sw        $t0, 8($k0)
        sw        $t1, 12($k0)
        sw        $t2, 16($k0)
        sw        $t3, 20($k0)

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

timer_interrupt:
        sw       $v0, TIMER_ACK        # acknowledge interrupt
        j        interrupt_dispatch    # see if other interrupts are waiting

non_intrpt:                # was some non-interrupt
        li        $v0, PRINT_STRING
        la        $a0, non_intrpt_str
        syscall                # print out an error message
        # fall through to done

done:
        la      $k0, chunkIH
        lw      $a0, 0($k0)        # Restore saved registers
        lw      $v0, 4($k0)
	lw      $t0, 8($k0)
        lw      $t1, 12($k0)
        lw      $t2, 16($k0)
        lw      $t3, 20($k0)
.set noat
        move    $at, $k1        # Restore $at
.set at
        eret
