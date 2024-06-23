
#ifndef LIST_H
#define LIST_H

#include "tsk.h"

struct node {
    tsk *tsk;
    struct node *next;
};


void insert(struct node **header, tsk *tsk);
void delete(struct node **header, tsk *tsk);
void traverse(struct node *header);


