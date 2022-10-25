#pragma once
#ifndef LIST_H
#define LIST_H

#include "status.h"

typedef void* LIST;
typedef void* ITER;

LIST list_init_default(void);
void list_destroy(LIST* phList);

int list_get_size(LIST hList);
bool list_empty(LIST hList);

Status list_insert_head(LIST hList, int item);
Status list_insert_tail(LIST hList, int item);
Status list_remove_head(LIST hList);
Status list_remove_tail(LIST hList); // Doubly-linked lists can remove from both ends

ITER list_begin(LIST hList);
ITER list_end(LIST hList);
void iter_next(ITER* phIter);
void iter_prev(ITER* phIter);
int iter_get(ITER hIter, Status* pStatus);
Status iter_set(ITER hIter, int item);

Status list_insert_after(LIST hList, ITER hIter, int item);
Status list_insert_before(LIST hList, ITER hIter, int item);
Status list_remove_at(LIST hList, ITER hIter); // Can remove items in the middle

#endif