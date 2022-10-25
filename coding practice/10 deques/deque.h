#pragma once
#ifndef DEQUE_H
#define DEQUE_H
#include "status.h"

typedef void* DEQUE;

DEQUE deque_init_default(void);
void deque_destroy(DEQUE* phQ);

Status deque_push_front(DEQUE hQ, int value);
Status deque_push_back(DEQUE hQ, int value);
Status deque_pop_front(DEQUE hQ);
Status deque_pop_back(DEQUE hQ);
int deque_front(DEQUE hQ, Status* pStatus);
int deque_back(DEQUE hQ, Status* pStatus);
bool deque_empty(DEQUE hQ);

int deque_size(DEQUE hQ);

#endif // ! DEQUE_H