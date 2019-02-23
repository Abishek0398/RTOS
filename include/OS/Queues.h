#ifndef QUEUES_H
#define QUEUES_H
#include "Process.h"
extern struct tcb *ready_queue_head;
void add_ready_queue(struct tcb *temp);
#endif