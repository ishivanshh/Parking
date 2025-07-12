
#include <stdio.h>
#include <string.h>
#include "stack.h"

Vehicle stack[MAX];
int top = -1;

int isFull() { return top == MAX - 1; }
int isEmpty() { return top == -1; }

void push(Vehicle v) {
    stack[++top] = v;
    printf("Vehicle %s (%s) parked at slot %d.\n", v.plate, v.type, top + 1);
}

Vehicle pop() {
    return stack[top--];
}

void display_parking() {
    if (!isEmpty()) {
        printf("\nVehicles currently in parking:\n");
        for (int i = top; i >= 0; i--) {
            printf("Slot %d: %s (%s) Entry Time: %02d:%02d\n", i + 1, stack[i].plate, stack[i].type, stack[i].entry_hour, stack[i].entry_min);
        }
    } else {
        printf("No vehicles parked.\n");
    }
}
