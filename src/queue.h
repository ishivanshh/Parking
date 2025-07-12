
#ifndef QUEUE_H
#define QUEUE_H

#define WAIT_MAX 5

#include "stack.h"

extern Vehicle waitQueue[WAIT_MAX];
extern int front, rear;

int isWaitFull();
int isWaitEmpty();
void enqueue(Vehicle v);
Vehicle dequeue();

#endif
