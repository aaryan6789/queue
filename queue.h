/*
 * queue.h
 *
 *  Created on: Feb 22, 2018
 *      Author: hsahu
 */

#ifndef QUEUE_H_
#define QUEUE_H_

/*
 * Queue: has the following members:
 * data
 * front
 * rear
 * next
 */
// This structure represents each node of the Queue
struct Qnode{
	int data;
	struct Qnode* next;
};

// This structure keeps track of the whole queue's fron tnad rear ends.
struct queue {
	struct Qnode* front;
	struct Qnode* rear;
};


struct queue *createQueue();
void enqueue(struct queue* q, int key);
struct Qnode* dequeue(struct queue* q);
void printQueue(struct queue *q);

#endif /* QUEUE_H_ */
