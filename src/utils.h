
#ifndef UTILS_H
#define UTILS_H

#include "stack.h"

int calculate_fee(Vehicle v, int exit_hour, int exit_min);
void log_to_file(Vehicle v, int exit_hour, int exit_min, int fee);
int login();

#endif
