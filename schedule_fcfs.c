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
    struct node *lastNode = tskList;
    while(1) {
        if(!lastNode->next) {
            break;
        }
        lastNode = lastNode->next;
    }
    return lastNode->tsk;
}


void schedule() {
    while(tskList) {
        tsk *ts = pickNexttsk();
        run(ts, t->burst_time);
        delete(&tskList, ts);
    }
}
