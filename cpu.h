#ifndef CPU_H
#define CPU_H

// length of a time quantum
#define QUANTUM 10

// run the specified tsk for the following time slice
void run(tsk *tsk, int slice);

#endif
