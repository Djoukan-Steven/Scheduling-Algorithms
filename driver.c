

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tsk.h"
#include "list.h"
#include "scheduler.h"

#define SIZE    100

int main(int argc, char *argv[]) {
    FILE *in;
    char *temp;
    char tsk[SIZE];
    char *name;
    int priority;
    int burst_time;
    in = fopen(argv[1], "r");
    while (fgets(tsk, SIZE, in) != NULL) {
        temp = strdup(tsk);
        name = strsep(&temp, ",");
        priority = atoi(strsep(&temp, ","));
        burst_time = atoi(strsep(&temp, ","));
       
        add(name, priority, burst_time);
        free(temp);
    }
    fclose(in);
  
    schedule();
    return 0;
}
