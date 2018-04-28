/*
 * sQueue.c
 *
 *  Created on: Feb 22, 2018
 *      Author: hsahu
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "sQueue.h"

struct sQueue* createSQ() {
	struct sQueue *sq = (struct sQueue *)malloc(sizeof(struct sQueue));

	sq->stack1 = NULL;
	sq->stack2 = NULL;

	return sq;
}

/** sPush - push an item on to the stack (Stack by linked List) */
void sPush(struct sNode** top_ref, int key){
	struct sNode *nsNode = (struct sNode*)malloc(sizeof(struct sNode));

	nsNode->data = key;
	nsNode->next = (*top_ref);		// Link the old sNode to the new sNode
	(*top_ref) = nsNode;			// new sNode will become the new Top pointer

	return;
}

/** sPop - Pop an item from the Stack (Stack by linked List )*/
int sPop(struct sNode** top_ref) {
	int pop;
	struct sNode* top;

	if(*top_ref == NULL){
		printf("Stack is Empty\n");
		return INT_MIN;
	}
	else{
		// Get the top node
		top = *top_ref;
		pop = top->data;
		// Link the new top Node
		*top_ref = top->next;
		free(top);
		printf("Pop from Stack = %d", pop);
		return pop;
	}
}

/**
 * sEnqueue - Enqueue an element in the sQueue (Queue by stacks)
 * Enqueue the coming element by pushing it on Stack 1.
 */
void sEnqueue(struct sQueue* sq, int key){
	sPush(&sq->stack1, key);
	printf("Enqueue %d on sQueue\n", key);
	return;
}

/**
 * sDequeue - Dequeue an element from the sQueue (Queue by Stacks)
 * 1. Push all the elements from Stack 1 to Stack 2
 * 2. Pop the first element of Stack 2 to return the dequeued item.
 */
void sDequeue(struct sQueue* sq){

	/* If both the Stacks are Empty then return */
	if (sq->stack1 == NULL && sq->stack2 == NULL){
		printf("sQueue is Empty. Nothing to sDequeue.\n");
		return;
	}

	/* Push elements from stack1 to stack2 only when stack2 is empty */
	if (sq->stack2 == NULL){				// Check if Stack2 is empty
		while(sq->stack1 != NULL){			// Push all elements from stack1 to stack2
			int pop1 = sPop(&sq->stack1);
			sPush(&sq->stack2, pop1);
		}
	}

	/* Pop an element from stack2 and dequeue it*/
	int pop = sPop(&sq->stack2);
	printf("Dequeue item from sQueue = %d", pop);
}




