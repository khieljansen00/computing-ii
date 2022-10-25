#pragma once
#ifndef FERRY_H
#define FERRY_H

#include "status.h"

typedef void* LIST;
typedef void* ITER;

LIST list_init_default(void);
void list_destroy(LIST* phList);

int list_get_size(LIST hList);
bool list_empty(LIST hList);

Status list_insert_head(LIST hList, int lengthAttribute, char* sideAttribute);
Status list_insert_tail(LIST hList, int lengthAttribute, char* sideAttribute);
Status list_remove_head(LIST hList);

ITER list_begin(LIST hList);
ITER list_end(LIST hList);
void iter_next(ITER* phIter);
int iter_get_length(ITER hIter, Status* pStatus);
char* iter_get_side(ITER hIter, Status* pStatus);
Status iter_set(ITER hIter, int item);

#endif