#include<string.h>
#include<stdlib.h>

#include "scheduler.h"
#include "tsk.h"
#include "cpu.h"
#include "list.h"

struct node *tskList[MAX_PRIORITY + 1];
struct node *next_node;


void add(char *name, int priority, int burst_time) {
    tsk *ts = malloc(sizeof(tsk));
    
    ts->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(ts->name, name);
 
    ts->priority = priority;
    ts->burst_time = ts->remaining_burst_time = burst_time;
   
    insert(&tskList[priority], ts);
}


tsk *pickNexttsk(struct node *tl) {
    tsk *retr = next_node->tsk;
    next_node = (next_node -> next) ? next_node->next : tl;
    return retr;
}


void schedule() {
    
    for(size_t q = MAX_PRIORITY; q >= MIN_PRIORITY; --q) {
        next_node = tskList[q];
        while(tskList[q]) {
            tsk *ts = pickNexttsk(tskList[q]);
            int slice = QUANTUM < ts->remaining_burst_time ? QUANTUM : ts->remaining_burst_time;
            run(ts, slice);
            ts->remaining_burst_time -= slice;
            if(!ts->remaining_burst_time) {
                delete(&tskList[q], ts);
            }
        }
    }
}
