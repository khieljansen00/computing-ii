#include "generic.h"

#include <stdlib.h>

struct generic_vector {
    int size;
    int capacity;
    ITEM* data;
    // Function Pointers
    void (*item_assignment)(ITEM* pLeft, ITEM right);
    void (*item_destroy)(ITEM* phItem);
};
typedef struct generic_vector GenericVector;

GENERIC_VECTOR generic_vector_init_default(void (*fpAssignment)(ITEM* pLeft, ITEM right),
    void (*fpDestroy)(ITEM* phItem))
{
    GenericVector* pVector = (GenericVector*)malloc(sizeof(GenericVector));
    if (pVector != NULL) {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->item_assignment = fpAssignment;
        pVector->item_destroy = fpDestroy;
        pVector->data = (ITEM*)malloc(sizeof(ITEM) * pVector->capacity);
        if (pVector->data == NULL) {
            free(pVector);
            return NULL;
        }
        for (int i = 0; i < pVector->capacity; i++) {
            pVector->data[i] = NULL;
        }
    }
    return pVector;
}

void generic_vector_destroy(GENERIC_VECTOR* phVector)
{
    GenericVector* pVector = (GenericVector*)*phVector;
    for (int i = 0; i < pVector->size; i++) {
        pVector->item_destroy(&(pVector->data[i]));
    }
    free(pVector->data);
    free(pVector);
    *phVector = NULL;
}

int generic_vector_get_size(GENERIC_VECTOR hVector)
{
    GenericVector* pVector = (GenericVector*)hVector;
    return pVector->size;
}

int generic_vector_get_capacity(GENERIC_VECTOR hVector)
{
    GenericVector* pVector = (GenericVector*)hVector;
    return pVector->capacity;
}

Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM hItem)
{
    GenericVector* pVector = (GenericVector*)hVector;

    if (pVector->size >= pVector->capacity) {
        ITEM* temp = (ITEM*)malloc(sizeof(ITEM) * pVector->capacity * 2);
        if (temp == NULL) {
            return FAILURE;
        }
        int i;
        for (i = 0; i < pVector->size; i++) {
            temp[i] = pVector->data[i];
        }
        pVector->capacity *= 2;
        for (; i < pVector->capacity; i++) {
            temp[i] = NULL;
        }
        free(pVector->data);
        pVector->data = temp;
    }
    pVector->item_assignment(&pVector->data[pVector->size], hItem);
    pVector->size++;

    return SUCCESS;
}

Status generic_vector_pop_back(GENERIC_VECTOR hVector)
{
    GenericVector* pVector = (GenericVector*)hVector;
    if (pVector <= 0) {
        return FAILURE;
    }
    pVector->size--;
    pVector->item_destroy(&pVector->data[pVector->size]);
    return SUCCESS;
}

ITEM generic_vector_at(GENERIC_VECTOR hVector, int index)
{
    GenericVector* pVector = (GenericVector*)hVector;
    if (index < 0 || index >= pVector->size) {
        return NULL;
    }
    return pVector->data[index];
}

int generic_vector_count(GENERIC_VECTOR hVector, bool (*fpCriteria)(ITEM hItem))
{
    GenericVector* pVector = (GenericVector*)hVector;
    int result = 0;
    for (int i = 0; i < pVector->size; ++i) {
        if (fpCriteria(pVector->data[i])) {
            result++;
        }
    }
    return result;
}