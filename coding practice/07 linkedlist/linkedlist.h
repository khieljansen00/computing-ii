#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

ITER list_begin(LIST hList);
ITER list_end(LIST hList);
void iter_next(ITER* phIter);
int iter_get(ITER hIter, Status* pStatus);
Status iter_set(ITER hIter, int item);

Status list_insert_after(LIST hList, ITER hIter, int item);

// Status list_remove_at(LIST hList, ITER hIter); // Needs doubly-linked list

#endif