#include "list.h"

#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

struct list {
    int size;
    Node* head;
    Node* tail;
};
typedef struct list List;

LIST list_init_default(void)
{
    List* pList = (List*)malloc(sizeof(List));
    if (pList) {
        pList->size = 0;
        pList->head = NULL;
        pList->tail = NULL;
    }
    return (LIST)pList;
}

void list_destroy(LIST* phList)
{
    List* pList = (List*)*phList;

    while (pList->head != NULL) {
        Node* temp = pList->head;
        pList->head = pList->head->next;
        free(temp);
    }

    free(pList);
    *phList = NULL;
}

int list_get_size(LIST hList)
{
    List* pList = (List*)hList;
    return pList->size;
}
bool list_empty(LIST hList)
{
    List* pList = (List*)hList;
    return pList->size == 0;
}

Status list_insert_head(LIST hList, int item)
{
    List* pList = (List*)hList;
    Node* pNode = (Node*)malloc(sizeof(Node));
    if (pNode) {
        pNode->data = item;
        pNode->next = pList->head;
        pNode->prev = NULL;
        if (pList->head != NULL) {
            pList->head->prev = pNode;
        }
        pList->head = pNode;
        if (pList->tail == NULL) {
            pList->tail = pNode;
        }
        pList->size++;
        return SUCCESS;
    }
    return FAILURE;
}
Status list_insert_tail(LIST hList, int item)
{
    List* pList = (List*)hList;
    Node* pNode = (Node*)malloc(sizeof(Node));
    if (pNode) {
        pNode->data = item;
        pNode->next = NULL;
        pNode->prev = pList->tail;
        if (pList->tail) {
            pList->tail->next = pNode;
        }
        if (!pList->head) {
            pList->head = pNode;
        }
        pList->tail = pNode;
        pList->size++;
        return SUCCESS;
    }
    return FAILURE;
}
Status list_remove_head(LIST hList)
{
    List* pList = (List*)hList;
    if (pList->head != NULL) {
        Node* pNode = pList->head;
        pList->head = pNode->next;
        if (pList->head) {
            pList->head->prev = NULL;
        } else {
            pList->tail = NULL;
        }
        pList->size--;
        free(pNode);
        return SUCCESS;
    }
    return FAILURE;
}

Status list_remove_tail(LIST hList)
{
    List* pList = (List*)hList;
    if (pList->tail != NULL) {
        Node* pNode = pList->tail;
        pList->tail = pNode->prev;
        if (pList->tail) {
            pList->tail->next = NULL;
        } else {
            pList->head = NULL;
        }
        pList->size--;
        free(pNode);
        return SUCCESS;
    }
    return FAILURE;
}

ITER list_begin(LIST hList)
{
    List* pList = (List*)hList;
    return pList->head;
}
void iter_end(ITER* phIter)
{
    Node* pNode = (Node*)*phIter;
    *phIter = pNode->next;
}

void iter_prev(ITER* phIter)
{
    Node* pNode = (Node*)*phIter;
    *phIter = pNode->prev;
}
int iter_get(ITER hIter, Status* pStatus)
{
    Node* pNode = (Node*)hIter;
    if (pNode) {
        if (pStatus) {
            *pStatus = SUCCESS;
        }
        return pNode->data;
    } else {
        if (pStatus) {
            *pStatus = FAILURE;
        }
        return -1;
    }
}
Status iter_set(ITER hIter, int item)
{
    Node* pNode = (Node*)hIter;
    if (pNode) {
        pNode->data = item;
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

Status list_insert_after(LIST hList, ITER hIter, int item)
{
    List* pList = (List*)hList;
    Node* pNode = (Node*)hIter;
    Node* pNew = (Node*)malloc(sizeof(Node));
    if (pNew) {
        pNew->data = item;
        pNew->next = pNode->next;
        if (pNew->next != NULL) {
            pNew->next->prev = pNew;
        }
        pNew->prev = pNode;
        pNode->next = pNew;
        if (pNode == pList->tail) {
            pList->tail = pNew;
        }
        pList->size++;
        return SUCCESS;
    }
    return FAILURE;
}

Status list_insert_before(LIST hList, ITER hIter, int item)
{
    List* pList = (List*)hList;
    Node* pNode = (Node*)hIter;
    Node* pNew = (Node*)malloc(sizeof(Node));
    if (pNew) {
        pNew->data = item;
        pNew->next = pNode;
        if (pNode != NULL) {
            pNew->prev = pNode->prev;
            pNode->prev = pNew;
        } else {
            pList->tail = pNew;
        }
        if (pNew->prev != NULL) {
            pNew->prev->next = pNew;
        }
        if (pNode == pList->head) {
            pList->head = pNew;
        }
        pList->size++;
        return SUCCESS;
    }
    return FAILURE;
}

Status list_remove_at(LIST hList, ITER hIter)
{
    List* pList = (List*)hList;
    Node* pNode = (Node*)hIter;
    if (pNode) {
        if (pNode->prev) {
            pNode->prev->next = pNode->next;
        } else {
            pList->head = pNode->next;
        }
        if (pNode->next) {
            pNode->next->prev = pNode->prev;
        } else {
            pList->tail = pNode->prev;
        }
        free(pNode);
        pList->size--;
        return SUCCESS;
    }
    return FAILURE;
}