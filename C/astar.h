#ifndef ASTAR_H_
#define ASTAR_H_

struct node_t; //pre declaration

typedef struct {
    int index;
    int f;
    int g;
    struct node_t *prv_node;
} node_t;

void pq_push(node_t* current_node);

node_t* pq_pop(void);

void init(void);

#endif