.data
# syscall constants
PRINT_STRING            = 4
PRINT_CHAR              = 11
PRINT_INT               = 1

# memory-mapped I/O
VELOCITY                = 0xffff0010
ANGLE                   = 0xffff0014
ANGLE_CONTROL           = 0xffff0018

BOT_X                   = 0xffff0020
BOT_Y                   = 0xffff0024

TIMER                   = 0xffff001c

RIGHT_WALL_SENSOR 		= 0xffff0054
PICK_TREASURE           = 0xffff00e0
TREASURE_MAP            = 0xffff0058

REQUEST_PUZZLE          = 0xffff00d0
SUBMIT_SOLUTION         = 0xffff00d4

BONK_INT_MASK           = 0x1000
BONK_ACK                = 0xffff0060

TIMER_INT_MASK          = 0x8000
TIMER_ACK               = 0xffff006c

REQUEST_PUZZLE_INT_MASK = 0x800
REQUEST_PUZZLE_ACK      = 0xffff00d8

.data
#
#Put any static memory you need here
#

.text
main:
	#we only need bonk interrupt in part 1
	li $t0, 10
	sw $t0, VELOCITY($zero)
	li $t4, 0x1000 #bonk interrupt bit
	or $t4, $t4, 1 #global interrupt enable mask
	mtc0 $t4, $12
	#finished setting up interrupt!
	li $t0, RIGHT_WALL_SENSOR
	lw $t0, 0($t0) #t0: prv_wall

right_turn_loop:
	li $t1, RIGHT_WALL_SENSOR
	lw $t1, 0($t1) #t1: cur_wall
	#turn right if prv == 1 and cur_wall == 0
	not $t2, $t1
	and $t2, $t2, 0x00000001
	and $t2, $t0, $t2 #1 to turn
	move $t0, $t1 #prv = cur
	beq $t2, $zero, right_turn_loop
	#turn right 90
	li $t2, 90
	sw $t2, ANGLE($zero)
	sw $zero, ANGLE_CONTROL($zero)
	j right_turn_loop

end:
	#should never get here?
	jr $ra


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

    li        $v0, PRINT_STRING    # Unhandled interrupt types
    la        $a0, unhandled_str
    syscall
    j    done

bonk_interrupt:
    #Fill in your code here
	li $t2, 180
	sw $t2, ANGLE($zero)
	sw $zero, ANGLE_CONTROL($zero)
	li $t2, 10
	sw $t2, VELOCITY($zero)
	sw $a1, BONK_ACK($zero)
    j       interrupt_dispatch    # see if other interrupts are waiting

timer_interrupt:
    #Fill in your code here
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
