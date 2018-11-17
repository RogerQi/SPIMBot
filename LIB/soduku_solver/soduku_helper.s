.globl get_square_begin
get_square_begin:
	# round down to the nearest multiple of 4
	div	$v0, $a0, 4
	mul	$v0, $v0, 4
	jr	$ra


# UNTIL THE SOLUTIONS ARE RELEASED, YOU SHOULD COPY OVER YOUR VERSION FROM LAB 7
# (feel free to copy over the solution afterwards)
.globl has_single_bit_set
has_single_bit_set:
	li	$v0, 0
	beq $a0, $zero, has_single_bit_set_end #(if value == 0) return 0;

	li $t1, 1
	sub $t1, $a0, $t1
	and $t1, $t1, $a0
	bne $t1, $zero, has_single_bit_set_end
	j has_single_bit_set_ret_one

has_single_bit_set_ret_one:
	li $v0, 1
	j has_single_bit_set_end

has_single_bit_set_end:
	jr	$ra


# UNTIL THE SOLUTIONS ARE RELEASED, YOU SHOULD COPY OVER YOUR VERSION FROM LAB 7
# (feel free to copy over the solution afterwards)
get_lowest_set_bit:
	li $t0, 0
	j get_lowest_set_bit_loop

get_lowest_set_bit_end:
	li $v0, 0
	jr $ra

get_lowest_set_bit_ret_i:
	move $v0, $t0
	jr $ra

get_lowest_set_bit_loop:
	sltiu $t1, $t0, 16 #t0 is i
	beq $t1, $zero, get_lowest_set_bit_end #end if it's 0
	li $t1, 1
	sll $t1, $t1, $t0
	and $t1, $t1, $a0
	bne $t1, $zero, get_lowest_set_bit_ret_i
	addi $t0, $t0, 1
	j get_lowest_set_bit_loop

# UNTIL THE SOLUTIONS ARE RELEASED, YOU SHOULD COPY OVER YOUR VERSION FROM LAB 7
# (feel free to copy over the solution afterwards)
.globl print_board
print_board:
	#Start Saving S register...
	sub $sp, $sp, 24
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $s4, 16($sp)
	sw $ra, 20($sp)
	#End Saving Sx
	li $t0, 0 #t0 = i
	j print_board_i_loop

print_board_i_loop:
	slt $t7, $t0, 16
	bne $t7, 1, print_board_end
	li $t1, 0 #t1 = j
	j print_board_j_loop

print_board_i_loop_end:
	move $s0, $a0
	addi $t0, $t0, 1
	li $v0, 11
	li $a0, '\n'
	syscall #putchar \n
	move $a0, $s0
	j print_board_i_loop

print_board_j_loop:
	slt $t7, $t1, 16
	bne $t7, 1, print_board_i_loop_end
	mul $t2, $t0, 32 #i offset
	mul $t7, $t1, 2 #j offset
	add $t7, $t2, $t7 #ele offset
	add $t2, $a0, $t7 #true mem addr
	lhu $t2, 0($t2) #t2: int value = board[i][j]
	li $t3, '*' #t3: char c = '*'
	move $s0, $a0
	move $s1, $t0
	move $s2, $t1
	move $s3, $t2
	move $s4, $t3
	move $a0, $t2
	jal has_single_bit_set
	move $a0, $s0
	move $t0, $s1
	move $t1, $s2
	move $t2, $s3
	move $t3, $s4
	#if bit is not set; end loop.
	beq $v0, 0, print_board_j_loop_end
	#suppose bit is set; change c and end loop
	move $s0, $a0
	move $s1, $t0
	move $s2, $t1
	move $s3, $t2
	move $s4, $t3
	move $a0, $t2 #set input param to be value
	jal get_lowest_set_bit
	move $a0, $s0
	move $t0, $s1
	move $t1, $s2
	move $t2, $s3
	move $t3, $s4
	addi $t4, $v0, 1 #t4: int num = get_lowest_set_bit(value) + 1;
	la $t7, symbollist #t7 = &symbollist
	add $t7, $t7, $t4
	lbu $t3, 0($t7) #c = symbollist[num];
	j print_board_j_loop_end

print_board_j_loop_end:
	li $v0, 11
	move $s0, $a0
	move $a0, $t3
	syscall #putchar c
	addi $t1, $t1, 1
	move $a0, $s0
	j print_board_j_loop

print_board_end:
	#restore S register and SP...
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $ra, 20($sp)
	add $sp, $sp, 24
	#End restoring S/SP
	jr $ra
