
#include <stdio.h>
#include "queue.h"

Vehicle waitQueue[WAIT_MAX];
int front = 0, rear = -1;

int isWaitFull() { return rear == WAIT_MAX - 1; }
int isWaitEmpty() { return front > rear; }

void enqueue(Vehicle v) {
    if (!isWaitFull()) {
        waitQueue[++rear] = v;
        printf("Parking full! %s added to waiting list.\n", v.plate);
    } else {
        printf("Waiting list full!\n");
    }
}

Vehicle dequeue() {
    return waitQueue[front++];
}
