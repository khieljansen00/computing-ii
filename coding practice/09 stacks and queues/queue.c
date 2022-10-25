#include "queue.h"
#include <stdlib.h>

struct queue {
    int size;
    int capacity;
    int index_of_front;
    int* data;
};
typedef struct queue Queue;

QUEUE queue_init_default(void)
{
    Queue* pQ = (Queue*)malloc(sizeof(Queue));
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

void queue_destroy(QUEUE* phQ)
{
    Queue* pQ = (Queue*)*phQ;
    free(pQ->data);
    free(pQ);
    *phQ = NULL;
}

Status queue_enqueue(QUEUE hQ, int item) {
    Queue* pQ = (Queue*)hQ;

    // If not enough room, make room
    if (pQ->size >= pQ->capacity) {
        int* temp = (int*)malloc(sizeof(int) * pQ->capacity * 2);
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pQ->size; i++) {
            temp[i] = pQ->data[(pQ->index_of_front + i) % pQ->capacity];
        }
        pQ->index_of_front = 0;
        free(pQ->data);
        pQ->data = temp;
        pQ->capacity *= 2;
    }
    pQ->data[(pQ->index_of_front + pQ->size) % pQ->capacity] = item;
    pQ->size++;
    return SUCCESS;
}

Status queue_dequeue(QUEUE hQ) {
    Queue* pQ = (Queue*)hQ;

    if (queue_empty(hQ)) {
        return FAILURE;
    }

    pQ->size--;
    pQ->index_of_front = (pQ->index_of_front + 1) % pQ->capacity;
    return SUCCESS;
}

int queue_front(QUEUE hQ, Status* pStatus) {
    Queue* pQ = (Queue*)hQ;
    if (queue_empty(hQ)) {
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

int queue_size(QUEUE hQ) {
    Queue* pQ = (Queue*)hQ;
    return pQ->size;
}

bool queue_empty(QUEUE hQ) {
    Queue* pQ = (Queue*)hQ;
    return pQ->size <= 0;
}