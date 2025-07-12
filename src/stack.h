
#ifndef STACK_H
#define STACK_H

#define MAX 5

typedef struct {
    char plate[20];
    int entry_hour, entry_min;
    char type[10];
} Vehicle;

extern Vehicle stack[MAX];
extern int top;

int isFull();
int isEmpty();
void push(Vehicle v);
Vehicle pop();
void display_parking();

#endif
