/*
 * queue.c
 *
 *  Created on: Feb 22, 2018
 *      Author: hsahu
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "queue.h"

/*// This structure represents each node of the Queue
struct Qnode{
	int data;
	struct Qnode* next;
};

// This structure keeps track of the whole queue's front and rear ends.
struct queue {
	struct Qnode* front;
	struct Qnode* rear;
};
*/
/**
 * createQueue - Creates and empty queue
 * In the beginning, the front and rear both of the queue will be NULL as the
 * queue has no items.
 * But this function will create an object of the type queue to keep track of
 * any future queue's created.
 */
struct queue *createQueue(){
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;

	return q;
}

// Enqueue at the rear
void enqueue(struct queue* q, int key) {
	/* Allocate memory for a new Q node */
	struct Qnode *newQnode = (struct Qnode*)malloc(sizeof(struct Qnode));

	newQnode->data = key;
	newQnode->next = NULL;

	/* If this is the first node in the queue then
	 * the front and rear will both be pointing to this node */
	if((q->front == NULL) && (q->rear == NULL)){
		q->front = q->rear = newQnode;
	}
	else{
		/* Add this node at the end of the queue and also
		 * update the rear, pointing to this node */
		q->rear->next = newQnode;
		q->rear = newQnode;
	}

	printf("Enqueue %d \n", key);
	return;
}

// Dequeue from front
struct Qnode* dequeue(struct queue* q) {

	// Check for empty queue first
	if (q->front == NULL){
		printf("Queue is empty.\n");
		return NULL;
	}

	printf("Dequeue from Front = %d \n", q->front->data);

	// update front
	struct Qnode* newFront = q->front->next;
	q->front = newFront;

	// If newFront becomes NULL, then change rear also to NULL
	if (q->front == NULL){
		q->rear = NULL;
	}

	return newFront;
}

void printQueue(struct queue *q) {
	struct Qnode* temp = q->front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
