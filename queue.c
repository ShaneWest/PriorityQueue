#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
	Initializing a Queue
	
	Using pass by reference, this subprogram allocates memory for 
	the size of an endpointer, assigns it to q, and sets the front
	and back pointers to null.
*/

void init_queue(queue *q) {
	(*q) = (queue)malloc(sizeof(struct endpointer));
	(*q) -> front = NULL;
	(*q) -> back = NULL;
}

/*
	Checks to see if a queue is empty
	
	This subprogram determines whether or not the front and back pointers
	are pointing to null. It returns a "true" value if they are, and if not
	it returns a "false" value.
*/
boolean is_empty(queue q) {
	if((q -> front == NULL) && (q -> back == NULL))
		return TRUE;
	else
		return FALSE;
}

/*
	Check to see if a queue is full
	
	This programs creates a temporary nodepointer and attempts
	to allocate memory the size of a queuenode structure.
	If sucessful, temp will point to that memory, the subprogram
	will return FALSE, and temp will be freed. If unsucessful temp
	will point to null and return TRUE.
*/

boolean is_full(void) {
	node_pointer temp;
	temp = (node_pointer)malloc(sizeof(struct queuenode));
	if (temp == NULL)
		return TRUE;
	else {
		free (temp);
		return FALSE;
	}
}

/*
	Adding to a priority queue
	
	This subprogram receives a queue using pass by reference and data/priority to
	be added using pass by value. It creates a temporary nodepointer and
	allocates memory the size of a queuenode structure that is assigned to temp.
	It then assigns the data and prtiority portion of the structure to the item to be added,
	and sets the next pointer to point to null. If the queue is empty, it will
	set both front and back pointers to temp. If the priority belongs in the back of the
	queue, the back node's next pointer will be set to the new node and the back pointer will
	be moved to the new node. If the priority belongs in the front, the new node's pointer will
	be set to the front node and the front pointer will be moved to the new node. If the priority
	belongs in the middle of the queue, a temporary node pointer will be created and set the front
	node, and, while the new node's priority doesn't belong in the front of temporary's next node's
	priority, temp will be moved to temp's next pointer. Then the new node's next pointer will be set
	to temp's next pointer and temp's next pointer willl be set the new node.
*/

void add(queue *q, int x, int p) {
	node_pointer new;
	new = (node_pointer)malloc(sizeof(struct queuenode));
	new -> data = x;
	new -> pri = p;
	new -> next = NULL;
	if ((is_empty(*q))) {
		(*q) -> front = new;
		(*q) -> back = new;
	} else if (new -> pri <= (*q) -> back -> pri) {
		(*q) -> back -> next = new;
		(*q) -> back = new;
	} else if (new -> pri > (*q) -> front -> pri) {
		new -> next = (*q) -> front;
		(*q) -> front = new;
	} else {
		node_pointer temp;
		temp = (node_pointer)malloc(sizeof(struct queuenode));
		temp = (*q) -> front;
		while (new -> pri <= temp -> next -> pri) {
			temp = temp -> next;
		}
		new -> next = temp -> next;
		temp -> next = new;
	}
}

/*
	Fetching items from a queue
	
	This subprogram receives a queue using pass by reference. It creates a
	temporary nodepointer called temp. It then sets the temporary nodepointer
	to the front of the queue, and sets the data to be fetched equal to temp's data.
	If the queuenode to be removed is the only one in the queue, then both front and
	back pointers will be set to null. If not, the front pointer is moved to the next
	queuenode structure. Temp is then freed and the data fetched is returned.
*/

int fetch(queue *q) {
	node_pointer temp;
	temp = (*q) -> front;
	int data_fetched;
	data_fetched = temp -> data;
	if ((*q) -> front == (*q) -> back) {
		(*q) -> front = NULL;
		(*q) -> back = NULL;
	} else {
		(*q) -> front = temp -> next;
	}
	free(temp);
	return data_fetched;
}

/*
	Printing a queue
	
	This subprogram creates a temporary node pointer and is set to the front queuenode
	structure. While temp is not equal to null, the data portion of temp will print, 
	and temp will be moved to point to the next queuenode structure.
*/
void print_queue(queue q) {
	node_pointer temp;
	temp = q -> front;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp -> next;
	}
}