#include "deque.h"
#include <stdlib.h>

struct deque {
    int size;
    int capacity;
    int index_of_front;
    int* data;
};
typedef struct deque Deque;

int phys_index(Deque* pDeque, int index);

DEQUE deque_init_default(void)
{
    Deque* pQ = (Deque*)malloc(sizeof(Deque));
    if (pQ != NULL) {
        pQ->size = 0;
        pQ->capacity = 7;
        pQ->index_of_front = 0;
        pQ->data = (int*)malloc(sizeof(int) * pQ->capacity);
        if (pQ->data == NULL) {
            free(pQ);
            return NULL;
        }
    }
    return pQ;
}

void deque_destroy(DEQUE* phQ)
{
    Deque* pQ = (Deque*)*phQ;
    free(pQ->data);
    free(pQ);
    *phQ = NULL;
}

Status deque_push_front(DEQUE hQ, int item)
{
    Deque* pQ = (Deque*)hQ;

    // If not enough room, make room
    if (pQ->size >= pQ->capacity) {
        int* temp = (int*)malloc(sizeof(int) * pQ->capacity * 2);
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pQ->size; i++) {
            temp[i] = pQ->data[phys_index(pQ, i)];
        }
        pQ->index_of_front = 0;
        free(pQ->data);
        pQ->data = temp;
        pQ->capacity *= 2;
    }
    pQ->index_of_front = phys_index(pQ, -1);
    pQ->data[pQ->index_of_front] = item;
    pQ->size++;
    
    return SUCCESS;
}
Status deque_push_back(DEQUE hQ, int item)
{
    Deque* pQ = (Deque*)hQ;

    // If not enough room, make room
    if (pQ->size >= pQ->capacity) {
        int* temp = (int*)malloc(sizeof(int) * pQ->capacity * 2);
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pQ->size; i++) {
            temp[i] = pQ->data[phys_index(pQ, i)];
        }
        pQ->index_of_front = 0;
        free(pQ->data);
        pQ->data = temp;
        pQ->capacity *= 2;
    }
    pQ->data[phys_index(pQ, pQ->size)] = item;
    pQ->size++;
    return SUCCESS;
}

Status deque_pop_front(DEQUE hQ)
{
    Deque* pQ = (Deque*)hQ;

    if (deque_empty(hQ)) {
        return FAILURE;
    }

    pQ->size--;
    pQ->index_of_front = phys_index(pQ, 1);
    return SUCCESS;
}
Status deque_pop_back(DEQUE hQ)
{
    Deque* pQ = (Deque*)hQ;

    if (deque_empty(hQ)) {
        return FAILURE;
    }

    pQ->size--;
    return SUCCESS;
}

int deque_front(DEQUE hQ, Status* pStatus)
{
    Deque* pQ = (Deque*)hQ;
    if (deque_empty(hQ)) {
        if (pStatus != NULL) {
            *pStatus = FAILURE;
        }
        return -1337;
    }
    if (pStatus != NULL) {
        *pStatus = SUCCESS;
    }
    return pQ->data[pQ->index_of_front];
}

int deque_back(DEQUE hQ, Status* pStatus)
{
    Deque* pQ = (Deque*)hQ;
    if (deque_empty(hQ)) {
        if (pStatus != NULL) {
            *pStatus = FAILURE;
        }
        return -1337;
    }
    if (pStatus != NULL) {
        *pStatus = SUCCESS;
    }
    return pQ->data[phys_index(pQ, pQ->size - 1)];
}

int deque_size(DEQUE hQ)
{
    Deque* pQ = (Deque*)hQ;
    return pQ->size;
}

bool deque_empty(DEQUE hQ)
{
    Deque* pQ = (Deque*)hQ;
    return pQ->size <= 0;
}

int phys_index(Deque* pDeque, int index)
{
    return (pDeque->index_of_front + index + pDeque->capacity) % pDeque->capacity;
}