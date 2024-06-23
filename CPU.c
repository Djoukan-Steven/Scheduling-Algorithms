
#include <stdio.h>

#include "tsk.h"


void run(tsk *tsk, int slice) {
    printf("Running tsk = [%s], priority = [%d], burst = [%d] for %d units.\n", tsk->name, tsk->priority, tsk->burst_time, slice);
}
