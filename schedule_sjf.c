#include<string.h>
#include<stdlib.h>

#include "scheduler.h"
#include "tsk.h"
#include "cpu.h"
#include "list.h"

struct node *tskList = NULL;


void add(char *name, int priority, int burst_time) {
    tsk *ts = malloc(sizeof(tsk));
    
    ts->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(ts->name, name);
  
    ts->priority = priority;
    ts->burst_time = burst_time;
   
    insert(&tskList, ts);
}


tsk *pickNexttsk() {
    tsk *shortest_job = tskList->tsk;
    struct node *s = tskList;
    while(s){
        if(s->tsk->burst_time <= shortest_job->burst_time){
            shortest_job = s->tsk;
        }
        s = s->next;
    }
    return shortest_job;
}

// invoke the scheduler
void schedule() {
    while(tskList) {
        tsk *ts = pickNexttsk();
        run(ts, t->burst_time);
        delete(&tskList, ts);
    }
}
