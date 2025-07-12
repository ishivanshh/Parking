
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "utils.h"

int calculate_fee(Vehicle v, int exit_hour, int exit_min) {
    int minutes = (exit_hour - v.entry_hour) * 60 + (exit_min - v.entry_min);
    if (minutes <= 0) minutes += 1440;
    int base_rate = strcmp(v.type, "bike") == 0 ? 5 : 10;
    return (minutes / 60 + 1) * base_rate;
}

void log_to_file(Vehicle v, int exit_hour, int exit_min, int fee) {
    FILE *fp = fopen("parking_log.txt", "a");
    if (fp == NULL) {
        printf("Error writing log!\n");
        return;
    }
    fprintf(fp, "%s,%s,%02d:%02d,%02d:%02d,Rs.%d\n", v.plate, v.type,
            v.entry_hour, v.entry_min, exit_hour, exit_min, fee);
    fclose(fp);
}

int login() {
    char user[20], pass[20], ch;
    int i = 0;
    printf("Enter Username: ");
    scanf("%s", user);

    printf("Enter Password: ");
    while ((ch = getch()) != 13) {
        pass[i++] = ch;
        printf("*");
    }
    pass[i] = '\0';

    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        printf("\nAccess granted.\n");
        return 1;
    } else {
        printf("\nAccess denied.\n");
        return 0;
    }
}
