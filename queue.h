#ifndef queue_h
#define queue_h
#include "boolean.h"

typedef struct queuenode {
	int data;
    int pri;
	struct queuenode *next;
} *node_pointer;

typedef struct endpointer {
    node_pointer front;
    node_pointer back;
} *queue;

void init_queue(queue *);
boolean is_empty(queue);
boolean is_full(void);
void add(queue *, int, int);
int fetch(queue *);
void print_queue(queue);

#endif