
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "utils.h"

void menu() {
    int choice, exit_hour, exit_min, fee;
    Vehicle v, exited;

    while (1) {
        printf("\n1. Add Vehicle\n2. Remove Vehicle\n3. Display Status\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Plate No: ");
                scanf("%s", v.plate);
                printf("Enter Vehicle Type (car/bike): ");
                scanf("%s", v.type);
                printf("Enter Entry Time (HH MM): ");
                scanf("%d %d", &v.entry_hour, &v.entry_min);

                if (!isFull()) {
                    push(v);
                } else {
                    enqueue(v);
                }
                break;

            case 2:
                if (!isEmpty()) {
                    exited = pop();
                    printf("Enter Exit Time (HH MM): ");
                    scanf("%d %d", &exit_hour, &exit_min);
                    fee = calculate_fee(exited, exit_hour, exit_min);
                    printf("Vehicle %s (%s) removed. Parking Fee: Rs.%d\n", exited.plate, exited.type, fee);
                    log_to_file(exited, exit_hour, exit_min, fee);
                    if (!isWaitEmpty()) {
                        Vehicle next = dequeue();
                        push(next);
                    }
                } else {
                    printf("Parking is empty.\n");
                }
                break;

            case 3:
                display_parking();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    if (login()) {
        menu();
    }
    return 0;
}
