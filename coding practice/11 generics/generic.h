#pragma once
#ifndef GENERIC_H
#define GENERIC_H
#include "status.h"

typedef void* GENERIC_VECTOR;
typedef void* ITEM;

GENERIC_VECTOR generic_vector_init_default(void (*fpAssignment)(ITEM* pLeft, ITEM right),
    void (*fpDestroy)(ITEM* phItem));
void generic_vector_destroy(GENERIC_VECTOR* phVector);

int generic_vector_get_size(GENERIC_VECTOR hVector);
int generic_vector_get_capacity(GENERIC_VECTOR hVector);

Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM hItem);
Status generic_vector_pop_back(GENERIC_VECTOR hVector);

ITEM generic_vector_at(GENERIC_VECTOR hVector, int index);

int generic_vector_count(GENERIC_VECTOR hVector, bool (*fpCriteria)(ITEM hItem));
#endif