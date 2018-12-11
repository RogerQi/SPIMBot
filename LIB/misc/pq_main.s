# syscall constants
PRINT_INT = 1
PRINT_CHAR = 11

.data 
arr0:   .word 6 5 0 0
arr1:   .word 13 4 2 0
arr2:   .word 16 5 0 0
arr3:   .word 42 1 1 0

.text

print_int_and_space:
	li	$v0, PRINT_INT	# load the syscall option for printing ints
	syscall			# print the number

	li   	$a0, ' '       	# print a black space
	li	$v0, PRINT_CHAR	# load the syscall option for printing chars
	syscall			# print the char
	
	jr	$ra		# return to the calling procedure


.globl main
main:
	sub	$sp, $sp, 12
	sw	$ra, 0($sp)		# save $ra on stack
    sw  $t0, 4($sp)
    sw  $t1, 8($sp)

	la	$a0, arr0
	jal	pq_push

    la  $a0, arr1
    jal pq_push

    la  $a0, arr2
    jal pq_push

    la  $a0, arr3
    jal pq_push

    jal pq_pop

    lw  $t0, 4($v0)
    lw  $t1, 8($v0)

	move	$a0, $t0
	jal	print_int_and_space	# this should print 1

	move	$a0, $t1
	jal	print_int_and_space	# this should print 1

    lw  $t1, 8($sp)
    lw  $t0, 4($sp)
	lw	$ra, 0($sp)
	add	$sp, $sp, 12
	jr	$ra
