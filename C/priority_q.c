#include <stdio.h>
#include "astar.h"

static node_t *heap[900]; //use large stack space to avoid heap allocation
static int current_length = 1; //note that length of 1 is invalid.

void swap_node(int ind_a, int ind_b) {
    /*
    int temp_ind = heap[ind_a].index;
    int temp_f = heap[ind_a].f;
    int temp_g = heap[ind_a].g;
    node_t* prv_node = heap[ind_a].prv_node;
    heap[ind_a].index = heap[ind_b].index;
    heap[ind_a].f = heap[ind_b].f;
    heap[ind_a].g = heap[ind_b].g;
    heap[ind_a].prv_node = heap[ind_b].prv_node;
    heap[ind_b].index = temp_ind;
    heap[ind_b].f = temp_f;
    heap[ind_b].g = temp_g;
    heap[ind_b].prv_node = prv_node;*/
    node_t *temp = heap[ind_a];
    heap[ind_a] = heap[ind_b];
    heap[ind_b] = temp;
}

int root(void) {
    return 1;
}

int left_child(int cur_id) {
    return cur_id * 2;
}

int right_child(int cur_id) {
    return cur_id * 2 + 1;
}

int parent(int cur_id) {
    return cur_id / 2;
}

int has_a_child(int cur_id) {
    return left_child(cur_id) < current_length;
}

int max_priority_child(int cur_id) {
    int left_child_id = left_child(cur_id);
    int right_child_id = right_child(cur_id);
    if (right_child_id >= current_length)
        return left_child_id;
    if (heap[right_child_id]->f + heap[right_child_id]->g <= heap[left_child_id]->f + heap[left_child_id]->g)
        return right_child_id;
    return left_child_id;
}

void heapify_down(int cur_id) {
    if (!has_a_child(cur_id)) //base case
        return;
    int highest_priority_child = max_priority_child(cur_id);
    if (heap[cur_id]->f + heap[cur_id]->g <= heap[highest_priority_child]->f + heap[highest_priority_child]->g) //base case; heap rule not violated
        return;
    //recursive case: heap rule violated
    //swap parent and high priority child
    swap_node(cur_id, highest_priority_child);
    heapify_down(highest_priority_child);
}

//law of this heap: parent.val >= child.val

void heapify_up(int cur_id) {
    if (cur_id == 1)
        return; //is root; base case
    int parent_id = parent(cur_id);
    if (heap[cur_id]->f + heap[cur_id]->g >= heap[parent_id]->f + heap[parent_id]->g)
        return;
    swap_node(cur_id, parent_id);
    heapify_up(parent_id);
}

void init(void) {
    current_length = 1; //reset length
}

node_t* pq_pop(void) {
    node_t* ret = heap[1];
    heap[1] = heap[--current_length];
    heapify_down(1);
    return ret;
}

void pq_push(node_t* current_node) {
    heap[current_length] = current_node;
    heapify_up(current_length);
    ++current_length;
}