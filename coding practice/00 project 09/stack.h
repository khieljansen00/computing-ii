#pragma once
#ifndef STACK_H
#define STACK_H
#include "status.h"

typedef void* STACK;

STACK stack_init_default(void);
void stack_destroy(STACK* phStack);

Status stack_push(STACK hStack, char value);
Status stack_pop(STACK hStack);
char stack_top(STACK hStack, Status* pStatus);
int stack_size(STACK hStack);
bool stack_empty(STACK hStack);

#endif // !STACK_H