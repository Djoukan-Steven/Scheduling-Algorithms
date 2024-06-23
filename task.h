

#ifndef tsk_H
#define tsk_H


typedef struct tsk {
    char *name;
    int tid;
    int priority;
    int burst_time;
    int remaining_burst_time;
} tsk;

#endif
