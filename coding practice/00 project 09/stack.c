/***********************************************************
    Computing II -- COMP.1020 Honor Statement
    The practice of good ethical behavior is essential for maintaining good
   order in the classroom, providing an enriching learning experience for
   students, and as training as a practicing computing professional upon
   graduation.    This practice is manifested in the University's Academic
   Integrity policy.  Students are expected to strictly avoid academic
   dishonesty and adhere to the Academic Integrity policy as outlined in
   the course catalog.  Violations will be dealt with as outlined therein.
    All programming assignments in this class are to be done by the student
   alone.  No outside help is permitted except the instructor and approved
   tutors.
    I certify that the work submitted with this assignment is mine and was
   generated in a manner consistent with this document, the course academic
    policy on the course website on Blackboard, and the UMass Lowell
   academic code.
    Author: Khiel Mantilla
    Date: October 19, 2022
    Effort: 30 minutes
    Purpose: learning how to use a stack in an applicable manner
***********************************************************/

#include "stack.h"
#include <stdlib.h>

struct stack {
    int size;
    int capacity;
    char* data;
};
typedef struct stack Stack;

STACK stack_init_default(void)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack != NULL) {
        pStack->capacity = 8;
        pStack->size = 0;
        pStack->data = (char*)malloc(sizeof(char) * pStack->capacity);
        if (pStack->data == NULL) {
            free(pStack);
            return NULL;
        }
    }
    return pStack;
}

void stack_destroy(STACK* phStack)
{
    Stack* pStack = (Stack*)*phStack;
    free(pStack->data);
    free(pStack);
    *phStack = NULL;
}

Status stack_push(STACK hStack, char value)
{
    Stack* pStack = (Stack*)hStack;

    if (pStack->size >= pStack->capacity) {
        char* temp = (char*)malloc(sizeof(char) * pStack->capacity * 2);
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pStack->size; i++) {
            temp[i] = pStack->data[i];
        }
        free(pStack->data);
        pStack->data = temp;
        pStack->capacity *= 2;
    }
    pStack->data[pStack->size] = value;
    pStack->size++;

    return SUCCESS;
}

Status stack_pop(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;

    if (stack_empty(hStack)) {
        return FAILURE;
    }
    pStack->size--;
    return SUCCESS;
}

char stack_top(STACK hStack, Status* pStatus)
{
    Stack* pStack = (Stack*)hStack;
    if (stack_empty(hStack)) {
        if (pStatus != NULL) {
            *pStatus = FAILURE;
        }
        return '?';
    }
    if (pStatus != NULL) {
        *pStatus = SUCCESS;
    }
    return pStack->data[pStack->size - 1];
}

int stack_size(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    return pStack->size;
}

bool stack_empty(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    return pStack->size <= 0;
}