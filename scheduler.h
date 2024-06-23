#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10


void add(char *name, int priority, int burst_time);


void schedule();

#endif
