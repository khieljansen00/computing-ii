#pragma once
#ifndef  QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);
void queue_destroy(QUEUE* phQ);

Status queue_enqueue(QUEUE hQ, int value);
Status queue_dequeue(QUEUE hQ);
int queue_front(QUEUE hQ, Status* pStatus);
bool queue_empty(QUEUE hQ);

#endif // ! QUEUE_H