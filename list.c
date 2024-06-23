/**
 * Various list operations
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "tsk.h"



void insert(struct node **header, tsk *newtsk) {
   
    struct node *newNode = malloc(sizeof(struct node));
    newNode->tsk = newtsk;
    newNode->next = *header;
    *header = newNode;
}


void delete(struct node **header, tsk *tsk) {
    struct node *temp;
    struct node *prev;
    temp = *header;
    
    if (strcmp(tsk->name, temp->tsk->name) == 0) {
        *header = (*header)->next;
    } else {
      
        prev = *header;
        temp = temp->next;
        while (strcmp(tsk->name, temp->tsk->name) != 0) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
    }
}


void traverse(struct node *header) {
    struct node *temp;
    temp = header;
    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n", temp->tsk->name, temp->tsk->priority, temp->tsk->burst_time);
        temp = temp->next;
    }
}
