#include "vector.h"

#include <stdlib.h>

const int MIN_CAPACITY = 4;

struct vector {
    int size; // How many items weâ€™re storing
    int capacity; // How many items we can hold
    int* data; // Dynamically-allocated array
};
typedef struct vector Vector;


VECTOR vector_init_default(void)
{
    return vector_init(10);
}

VECTOR vector_init(int cap)
{
    Vector* pVector = (Vector*)malloc(sizeof(Vector));
    if (pVector != NULL) {
        pVector->capacity = cap;
        pVector->size = 0;
        pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);
        if (pVector->data == NULL) {
            // quasimodo state
            free(pVector);
            return NULL;
        }
    }
    return (VECTOR)pVector;
}

void vector_destroy(VECTOR* phVector)
{
    Vector* pVector = (Vector*)*phVector;
    free(pVector->data);
    free(pVector);
    *phVector = NULL;
}

int vector_get_size(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    return pVector->size;
}

int vector_get_capacity(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    return pVector->capacity;
}

bool vector_empty(VECTOR hVector)
{
    return vector_get_size(hVector) <= 0;
}

Status vector_push_back(VECTOR hVector, int value)
{
    Vector* pVector = (Vector*)hVector;
    if (pVector->size >= pVector->capacity) {
        // Array is full
        int* temp = (int*)malloc(sizeof(int) * pVector->capacity * 2);
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pVector->size; i++) {
            temp[i] = pVector->data[i];
        }
        free(pVector->data);
        pVector->data = temp;
        pVector->capacity *= 2;
        
    }
    pVector->data[pVector->size] = value;
    pVector->size++;
    return SUCCESS;
}

Status vector_pop_back(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    if (vector_empty(hVector)) {
        return FAILURE;
    }
    pVector->size--;
    if (pVector->size < pVector->capacity / 4 && pVector->capacity > MIN_CAPACITY) {
        // Array is underutilized
        int* temp = (int*)malloc(sizeof(int) * (pVector->capacity / 2));
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pVector->size; i++) {
            temp[i] = pVector->data[i];
        }
        free(pVector->data);
        pVector->data = temp;
        pVector->capacity /= 2;
    }
    return SUCCESS;
}

int vector_get_at(VECTOR hVector, int index, Status* pStatus)
{
    Vector* pVector = (Vector*)hVector;
    if (index < 0 || index >= pVector->size) {
        *pStatus = FAILURE;
    } else {
        *pStatus = SUCCESS;
    }
    return pVector->data[index];
}

Status vector_set_at(VECTOR hVector, int index, int value)
{
    Vector* pVector = (Vector*)hVector;
    if (index < 0 || index >= pVector->size) {
        return FAILURE;
    } else {
        pVector->data[index] = value;
        return SUCCESS;
    }
}

int* vector_at(VECTOR hVector, int index)
{
    Vector* pVector = (Vector*)hVector;
    if (index < 0 || index >= pVector->size) {
        return NULL;
    }
    return &(pVector->data[index]);
}