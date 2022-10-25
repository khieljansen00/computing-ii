#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include "status.h"

typedef void* VECTOR; // Define a handle

VECTOR vector_init_default(void);
VECTOR vector_init(int cap);
void vector_destroy(VECTOR* phVector);

// Accessor functions
int vector_get_size(VECTOR hVector);
int vector_get_capacity(VECTOR hVector);
bool vector_empty(VECTOR hVector);

// Add and remove items
Status vector_push_back(VECTOR hVector, int value);
Status vector_pop_back(VECTOR hVector);

// Let's look at how to change the ith position
// Safe C Way
int vector_get_at(VECTOR hVector, int index, Status* pStatus);
Status vector_set_at(VECTOR hVector, int index, int value);
// Unsafe way, but closer to how C++ does it
int* vector_at(VECTOR hVector, int index);
#endif