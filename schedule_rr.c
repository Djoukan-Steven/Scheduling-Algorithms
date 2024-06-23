#include<string.h>
#include<stdlib.h>

#include "scheduler.h"
#include "tsk.h"
#include "cpu.h"
#include "list.h"

struct node *tskList = NULL;
struct node *next_node;


void add(char *name, int priority, int burst_time) {
    tsk *ts = malloc(sizeof(tsk));
  
    ts->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(ts->name, name);
    
    ts->priority = priority;
    ts->burst_time = t->remaining_burst_time = burst_time;
  
    insert(&tskList, ts);
}


tsk *pickNexttsk() {
    tsk *retr = next_node->tsk;
    next_node = (next_node -> next) ? next_node->next : tskList;
    return retr;
}


void schedule() {
    next_node = tskList;
    while(tskList) {
        tsk *t = pickNexttsk();
        int slice = QUANTUM < ts->remaining_burst_time ? QUANTUM : ts->remaining_burst_time;
        run(ts, slice);
        ts->remaining_burst_time -= slice;
        if(!t->remaining_burst_time) {
            delete(&tskList, ts);
        }
    }
}
