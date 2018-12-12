.data 
#static node_t* heap[900];
pq_heap:        .word 0:900
#static int current_length = 1;
pq_curr_len:    .word 1

#====================================================================================================================

# int max_priority_child(int cur_id) {
#     int left_child_id = left_child(cur_id);
#     int right_child_id = right_child(cur_id);
#     if (right_child_id >= current_length)
#         return left_child_id;
#     if (heap[right_child_id]->f + heap[right_child_id]->g <= heap[left_child_id]->f + heap[left_child_id]->g)
#         return right_child_id;
#     return left_child_id;
# }
.text
.globl pq_max_priority_child
pq_max_priority_child:
	sub	$sp, $sp, 28
    sw $t0, 0($sp)
    sw $t1, 4($sp)
    sw $t2, 8($sp)
    sw $t3, 12($sp)
    sw $t4, 16($sp)
    sw $t5, 20($sp)
    sw $ra, 24($sp)


    mul $t0, $a0, 2     # leftchild => $t0
    add $t1, $t0, 1     # rightchild => $t1
    la $t2, pq_heap     # &pq_heap
    la $t3, pq_curr_len
    lw $t3, 0($t3)      # pq_curr_len
    bge $t1, $t3, pq_max_priority_child_ret #right_child_id >= current_length

    mul $t3, $t1, 4     # right_child_id*4
    add $t3, $t3, $t2   # &heap[right_child_id]
    lw $t3, 0($t3)      # heap[right_child_id]
    lw $t4, 4($t3)      # heap[right_child_id]->f
    lw $t5, 8($t3)     # heap[right_child_id]->g
    add $t4, $t4, $t5   # heap[right_child_id]->f + heap[right_child_id]->g

    mul $t3, $t0, 4     # left_child_id*4
    add $t3, $t3, $t2   # &heap[left_child_id]
    lw $t3, 0($t3)      # heap[left_child_id]
    lw $t0, 4($t3)      # heap[left_child_id]->f
    lw $t5, 8($t3)     # heap[left_child_id]->g
    add $t5, $t0, $t5   # heap[left_child_id]->f + heap[left_child_id]->g

    bgt $t4, $t5, pq_max_priority_child_ret
    move $v0, $t1       # return right


    lw $t0, 0($sp)
    lw $t1, 4($sp)
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    lw $t4, 16($sp)
    lw $t5, 20($sp)
    lw $ra, 24($sp)
    add	$sp, $sp, 28

    jr $ra

pq_max_priority_child_ret:  #return left
    move $v0, $t0

    lw $t0, 0($sp)
    lw $t1, 4($sp)
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    lw $t4, 16($sp)
    lw $t5, 20($sp)
    lw $ra, 24($sp)
    add	$sp, $sp, 28

    jr $ra


#====================================================================================================================

# void heapify_down(int cur_id) {
#     if (!has_a_child(cur_id)) //base case
#         return;
#     int highest_priority_child = max_priority_child(cur_id);
#     if (heap[cur_id]->f + heap[cur_id]->g <= heap[highest_priority_child]->f + heap[highest_priority_child]->g) //base case; heap rule not violated
#         return;
#     //recursive case: heap rule violated
#     //swap parent and high priority child
#     swap_node(cur_id, highest_priority_child);
#     heapify_down(highest_priority_child);
# }
# int has_a_child(int cur_id) {
#     return left_child(cur_id) < current_length;
# }

.globl pq_heapify_down
pq_heapify_down:
    sub	$sp, $sp, 32
    sw $t0, 0($sp)
    sw $t1, 4($sp)
    sw $t2, 8($sp)
    sw $t3, 12($sp)
    sw $t4, 16($sp)
    sw $t5, 20($sp)
    sw $t6, 24($sp)
    sw $ra, 28($sp)


    la $t0, pq_heap     # &pq_heap
    la $t1, pq_curr_len # &pq_curr_len
    lw $t1, 0($t1)      # int curr_len
        
    mul $t2, $a0, 2     # leftchild => $t2
    bge $t2, $t1, pq_heapify_down_ret

    jal pq_max_priority_child   #highest_priority_child

    mul $t1, $v0, 4     # highest_priority_child*4
    add $t1, $t1, $t0   # &heap[highest_priority_child]
    lw $t2, 0($t1)      # heap[highest_priority_child]
    lw $t3, 4($t2)      # heap[highest_priority_child]->f
    lw $t4, 8($t2)     # heap[highest_priority_child]->g
    add $t3, $t3, $t4   # heap[highest_priority_child]->f + heap[highest_priority_child]->g

    mul $t4, $a0, 4     # curr_id*4
    add $t4, $t4, $t0   # &heap[curr_id]
    lw $t5, 0($t4)      # heap[curr_id]
    lw $t0, 4($t5)      # heap[curr_id]->f
    lw $t6, 8($t5)     # heap[curr_id]->g
    add $t5, $t0, $t6   # heap[curr_id]->f + heap[curr_id]->g

    ble $t5, $t3, pq_heapify_down_ret

    #swap nodes
    sw $t5, 0($t1)       
    sw $t2, 0($t4)
    move $a0, $v0
    jal pq_heapify_down

pq_heapify_down_ret:

    lw $t0, 0($sp)
    lw $t1, 4($sp)
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    lw $t4, 16($sp)
    lw $t5, 20($sp)
    lw $t6, 24($sp)
    lw $ra, 28($sp)
    add	$sp, $sp, 32

    jr $ra

#====================================================================================================================

# void heapify_up(int cur_id) {
#     if (cur_id == 1)
#         return; //is root; base case
#     int parent_id = parent(cur_id);
#     if (heap[cur_id]->f + heap[cur_id]->g >= heap[parent_id]->f + heap[parent_id]->g)
#         return;
#     swap_node(cur_id, parent_id);
#     heapify_up(parent_id);
# }

.globl pq_heapify_up
pq_heapify_up:
    bne  $a0, 1, pq_heapify_up_cont
    jr $ra
pq_heapify_up_cont:
    sub	$sp, $sp, 44
    sw $t0, 0($sp)
    sw $t1, 4($sp)
    sw $t2, 8($sp)
    sw $t3, 12($sp)
    sw $t4, 16($sp)
    sw $t5, 20($sp)
    sw $t6, 24($sp)
    sw $t7, 28($sp)
    sw $t8, 32($sp)
    sw $t9, 36($sp)
    sw $ra, 40($sp)

    la $t0, pq_heap     # &pq_heap
    div $t1, $a0, 2

    mul $t2, $a0, 4     # curr_id*4
    add $t2, $t2, $t0   # &heap[curr_id]
    lw $t9, 0($t2)      # heap[curr_id]
    lw $t5, 4($t9)      # heap[curr_id]->f
    lw $t6, 8($t9)     # heap[curr_id]->g
    add $t7, $t5, $t6   # heap[curr_id]->f + heap[curr_id]->g

    mul $t3, $t1, 4     # parent*4
    add $t3, $t3, $t0   # &heap[parent]
    lw $t4, 0($t3)      # heap[parent]
    lw $t5, 4($t4)      # heap[parent]->f
    lw $t6, 8($t4)     # heap[parent]->g
    add $t8, $t5, $t6   # heap[parent]->f + heap[parent]->g
    
    bge $t7, $t8, pq_heapify_up_ret

    #swap nodes
    sw $t9, 0($t3)       
    sw $t4, 0($t2)
    move $a0, $t1
    jal pq_heapify_up

pq_heapify_up_ret:
    lw $t0, 0($sp)
    lw $t1, 4($sp)
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    lw $t4, 16($sp)
    lw $t5, 20($sp)
    lw $t6, 24($sp)
    lw $t7, 28($sp)
    lw $t8, 32($sp)
    lw $t9, 36($sp)
    lw $ra, 40($sp)
    add	$sp, $sp, 44

    jr $ra

#====================================================================================================================

# node_t* pq_pop(void) {
#     node_t* ret = heap[1];
#     heap[1] = heap[--current_length];
#     heapify_down(1);
#     return ret;
# }

.globl pq_pop
pq_pop:
	sub	$sp, $sp, 24
    sw $t0, 0($sp)
    sw $t1, 4($sp)
    sw $t2, 8($sp)
    sw $t3, 12($sp)
    sw $t4, 16($sp)
    sw $ra, 20($sp)


    la $t0, pq_heap     # &pq_heap
    la $t1, pq_curr_len # &pq_curr_len
    lw $t2, 0($t1)      # int curr_len

    lw $t4, 4($t0)

    add $t2, $t2, -1
    sw $t2, 0($t1)      #--current_length

    mul $t2, $t2, 4
    add $t2, $t2, $t0
    lw  $t3, 0($t2)
    sw  $t3, 4($t0) 

    li $a0, 1
    jal pq_heapify_down
    move $v0, $t4


    lw $t0, 0($sp)
    lw $t1, 4($sp)
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    lw $t4, 16($sp)
    lw $ra, 20($sp)
    add	$sp, $sp, 24
    
    jr $ra


#====================================================================================================================
# void pq_push(node_t* current_node) {
#     heap[current_length] = current_node;
#     heapify_up(current_length);
#     ++current_length;
# }

.globl pq_push
pq_push:

	sub	$sp, $sp, 20
    sw $t0, 0($sp)
    sw $t1, 4($sp)
    sw $t2, 8($sp)
    sw $t3, 12($sp)
    sw $ra, 16($sp)

    
    la $t0, pq_heap     # &pq_heap
    la $t1, pq_curr_len # &pq_curr_len
    lw $t2, 0($t1)      # int curr_len

    mul $t3, $t2, 4
    add $t3, $t3, $t0
    sw  $a0, 0($t3)

    move $a0, $t2
    jal pq_heapify_up

    add $t2, $t2, 1
    sw $t2, 0($t1)      #++current_length


    lw $t0, 0($sp)
    lw $t1, 4($sp)
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    lw $ra, 16($sp)
    add	$sp, $sp, 20
    
    jr $ra

#====================================================================================================================
.globl pq_init
pq_init:
	sub	$sp, $sp, 12
    sw $t0, 0($sp)
    sw $t1, 4($sp)
    sw $ra, 8($sp)


    la $t0, pq_curr_len
    li $t1, 1
    sw $t1, 0($t0)
    

    lw $t0, 0($sp)
    lw $t1, 4($sp)
    lw $ra, 8($sp)
    add	$sp, $sp, 12

    jr $ra