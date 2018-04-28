/*
 * main.c *  Created on: Feb 22, 2018 * Author: hsahu
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "queue.h"
#include "sQueue.h"

int main(){

	printf(" ------------------ QUEUE ----------------\n");

	struct queue *q = createQueue();

	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	printQueue(q);
	dequeue(q);
	enqueue(q, 10);
	printQueue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	enqueue(q, 30);

	printQueue(q);

	printf("\n ------------------ sQUEUE ----------------\n");

	struct sQueue* sq = createSQ();

	sEnqueue(sq, 10);
	sEnqueue(sq, 20);
	return 0;
}
