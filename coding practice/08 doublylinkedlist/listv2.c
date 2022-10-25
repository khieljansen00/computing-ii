#include "list.h"

#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

struct linkedlist {
    int size;
    Node sentinel;
};
typedef struct linkedlist List;

LIST list_init_default(void)
{
    List* pList = (List*)malloc(sizeof(List));
    if (pList) {
        pList->size = 0;
        pList->sentinel.data = -9999;
        pList->sentinel.next = &pList->sentinel;
        pList->sentinel.prev = &pList->sentinel;
    }
    return (LIST)pList;
}

void list_destroy(LIST* phList)
{
    List* pList = (List*)*phList;

    while (pList->sentinel.next != &pList->sentinel) {
        Node* temp = pList->sentinel.next;
        pList->sentinel.next = temp->next;
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
    return list_insert_before(hList, pList->sentinel.next, item);
}
Status list_insert_tail(LIST hList, int item)
{
    List* pList = (List*)hList;
    return list_insert_after(hList, pList->sentinel.prev, item);
}
Status list_remove_head(LIST hList)
{
    List* pList = (List*)hList;
    return list_remove_at(pList, pList->sentinel.next);
}

Status list_remove_tail(LIST hList)
{
    List* pList = (List*)hList;
    return list_remove_at(pList, pList->sentinel.prev);
}

ITER list_front(LIST hList)
{
    List* pList = (List*)hList;
    return pList->sentinel.next;
}

ITER list_back(LIST hList)
{
    List* pList = (List*)hList;
    return &pList->sentinel;
}

void iter_next(ITER* phIter)
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
        pNew->prev = pNode;
        pNew->next->prev = pNew;
        pNode->next = pNew;
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
        pNew->prev = pNode->prev;
        pNew->next->prev = pNew;
        pNew->prev->next = pNew;
        pList->size++;
        return SUCCESS;
    }
    return FAILURE;
}

Status list_remove_at(LIST hList, ITER hIter)
{
    List* pList = (List*)hList;
    Node* pNode = (Node*)hIter;
    if (pNode != &pList->sentinel) {
        pNode->next->prev = pNode->prev;
        pNode->prev->next = pNode->next;
        free(pNode);
        pList->size--;
        return SUCCESS;
    }
    return FAILURE;
}