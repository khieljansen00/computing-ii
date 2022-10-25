#include "linkedlist.h"

#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node Node;


struct list {
    Node* head;
    Node* tail;
};
typedef struct list List;

LIST list_init_default(void) {
    List* pList = (List*)malloc(sizeof(List));
    if (pList) {
        pList->head = NULL;
        pList->tail = NULL;
    }
    return (LIST)pList;
}

void list_destroy(LIST* phList) {
    List* pList = (List*)*phList;

    while (pList->head != NULL) {
        Node* temp = pList->head;
        pList->head = pList->head->next;
        free(temp);
    }

    free(pList);
    *phList = NULL;
}

int list_get_size(LIST hList) {
    List* pList = (List*)hList;
    int size = 0;
    Node* pNode = pList->head;
    while (pNode != NULL) {
        size++;
        pNode = pNode->next;
    }
    return size;
}

bool list_empty(LIST hList) {
    List* pList = (List*)hList;
    return pList->head == NULL;
}

Status list_insert_head(LIST hList, int item) {
    List* pList = (List*)hList;
    Node* pNode = (Node*)malloc(sizeof(Node));
    if (pNode) {
        pNode->data = item;
        pNode->next = pList->head;
        pList->head = pNode;
        if (pList->tail == NULL) {
            pList->tail = pNode;
        }
        return SUCCESS;
    }
    return FAILURE;
}

Status list_insert_tail(LIST hList, int item) {
    List* pList = (List*)hList;
    Node* pNode = (Node*)malloc(sizeof(Node));
    if (pNode) {
        pNode->data = item;
        pNode->next = NULL;
        if (pList->tail) {
            pList->tail->next = pNode;
        }
        if (!pList->head) {
            pList->head = pNode;
        }
        pList->tail = pNode;
        return SUCCESS;
    }
    return FAILURE;
}

Status list_remove_head(LIST hList) {
    List* pList = (List*)hList;
    if (pList->head != NULL) {
        Node* pNode = pList->head;
        pList->head = pList->head->next;
        if (pList->head == NULL) {
            pList->tail = NULL;
        }
        free(pNode);
        return SUCCESS;
    }
    return FAILURE;
}

ITER list_begin(LIST hList) {
    List* pList = (List*)hList;
    return pList->head;
}

ITER list_end(LIST hList) {
    return NULL;
}

void iter_next(ITER* phIter) {
    Node* pNode = (Node*)phIter;
    if (pNode) {
        *phIter = pNode->next;
    }
}

int iter_get(ITER hIter, Status* pStatus) {
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

Status iter_set(ITER hIter, int item) {
    Node* pNode = (Node*)hIter;
    if (pNode) {
        pNode->data = item;
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

Status list_insert_after(LIST hList, ITER hIter, int item) {
    List* pList = (List*)hList;
    Node* pNode = (Node*)hIter;
    Node* pNew = (Node*)malloc(sizeof(Node));
    if (pNew) {
        pNew->data = item;
        pNew->next = pNode->next;
        pNode->next = pNew;
        if (pNode == pList->tail) {
            pList->tail = pNew;
        }
        return SUCCESS;
    }
    return FAILURE;
}