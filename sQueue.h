/*
 * sQueue.h
 *
 *  Created on: Feb 22, 2018
 *      Author: hsahu
 */

#ifndef SQUEUE_H_
#define SQUEUE_H_

/* Implement Queue by Stacks CTCI */

// Stack Node Structure
struct sNode {
	int data;
	struct sNode* next;
};

/* sQueue Structure - Queue by Stacks
 * This Queue will have 2 stacks inside it.
 */
struct sQueue{
	struct sNode* stack1;
	struct sNode* stack2;
};

struct sQueue* createSQ();
void sEnqueue(struct sQueue* sq, int key);
void sDequeue(struct sQueue* sq);

void sPush(struct sNode** top_ref, int key);
int sPop(struct sNode** top_ref);


#endif /* SQUEUE_H_ */
