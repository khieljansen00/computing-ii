/***********************************************************
    Computing II -- COMP.1020 Honor Statement
    The practice of good ethical behavior is essential for maintaining good
   order in the classroom, providing an enriching learning experience for
   students, and as training as a practicing computing professional upon
   graduation.    This practice is manifested in the University's Academic
   Integrity policy.  Students are expected to strictly avoid academic
   dishonesty and adhere to the Academic Integrity policy as outlined in
   the course catalog.  Violations will be dealt with as outlined therein.
    All programming assignments in this class are to be done by the student
   alone.  No outside help is permitted except the instructor and approved
   tutors.
    I certify that the work submitted with this assignment is mine and was
   generated in a manner consistent with this document, the course academic
    policy on the course website on Blackboard, and the UMass Lowell
   academic code.
    Author: Khiel Mantilla
    Date: October 22, 2022
    Effort: 3 hours
    Purpose: planning an algorithm to make the ferry cross properly and to set up all the helper functions
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferry.h"

struct node {
    int length;
    char* side;
    struct node* next;
};
typedef struct node Node;

struct list {
    Node* head;
    Node* tail;
};
typedef struct list List;

int main(int argc, const char* argv[]) {

    // for reading the input
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    char* token = strtok(line, " ");
    int number_of_tests = atoi(token);
    // printf("number of tests: %d\n", number_of_tests);

    // for each test
    for (int i = 0; i < number_of_tests; i++) {

        // read information about a test
        // how long the ferry is
        // how many cars to load in the test
        read = getline(&line, &len, stdin);
        // char* length_ferry = NULL;
        char* token = strtok(line, " ");
        int meters = atoi(token);
        // printf("length of ferry: %d\n", meters);
        token = strtok(NULL, " ");
        int number_of_cars = atoi(token);
        // printf("number of cars: %d\n", number_of_cars);

        // for queueing up the cars in the ferry
        LIST ferry = list_init_default();
        int curr_length_storage = 0;
        int length_of_ferry = meters * 100;
        int side = 1; // 1 is left; 0 is right;
        Status status;
        int crosses = 0;

        for (int j = 0; j < number_of_cars; j++) {
            // read a car
            // get its length and arrival side
            read = getline(&line, &len, stdin);
            token = strtok(line, " ");
            int length_of_car = atoi(token);
            token = strtok(NULL, " ");
            char* arrival = NULL;
            if (strcmp(token, "left\n") == 0) arrival = "left";
            if (strcmp(token, "right\n") == 0) arrival = "right";
            if (strcmp(token, "left") == 0) arrival = "left";
            if (strcmp(token, "right") == 0) arrival = "right";
            // printf("%d %s", length_of_car, arrival);

            // we have the car's information!

            // check if you can unload cars
            if (list_empty(ferry) == true) {
                // do nothing

            } else  {
                // while there is a car on the ferry
                while(list_empty(ferry) == false) {
                    ITER car = list_begin(ferry);
                    // check if on the proper side
                    if (side == 1 && strcmp(iter_get_side(car, &status), "right") == 0) {
                        curr_length_storage -= iter_get_length(car, &status);
                        list_remove_head(ferry); // unload car
                    } else if (side == 0 && strcmp(iter_get_side(car, &status), "left") == 0) {
                        curr_length_storage -= iter_get_length(car, &status);
                        list_remove_head(ferry); // unload car
                    } else {
                        break;
                    }
                }
            }

            // HOW TO check if ferry can cross the river
            // ferry can cross when car cannot fit, in which case we cross twice
            // or when car is on the other side, in which case we cross once
            // side case if car is the last car, so you check at the end if ferry has a car

            // printf("%d %d %d\n", length_of_car, curr_length_storage, length_of_ferry);
            // check if car can fit
            if ((length_of_car + curr_length_storage) <= length_of_ferry) { // car fits, so load it
                if ((strcmp(arrival, "left") == 0 && side == 1) || (strcmp(arrival, "right") == 0 && side == 0)) {
                    curr_length_storage += length_of_car;
                    // printf("insert fits %d\n", curr_length_storage);
                    list_insert_tail(ferry, length_of_car, arrival);
                } else if ((strcmp(arrival, "right") == 0 && side == 1) || (strcmp(arrival, "left") == 0 && side == 0)) {
                    // if the car is on the other side
                    // cross and then load it
                    crosses++;
                    if (side == 1) {
                        side = 0;
                    } else {
                        side = 1;
                    }
                    // printf("car to be loaded is on the other side so cross!\n");

                    // then you queue the car
                    if ((strcmp(arrival, "left") == 0 && side == 1) || (strcmp(arrival, "right") == 0 && side == 0)) {
                        curr_length_storage += length_of_car;
                        list_insert_tail(ferry, length_of_car, arrival);
                    }
                }
            } else if ((length_of_car + curr_length_storage) > length_of_ferry) { // car doesn't fit

                // printf("insert doesn't fit %d\n", curr_length_storage);
                if ((strcmp(arrival, "left") == 0 && side == 1) || (strcmp(arrival, "right") == 0 && side == 0)) { // check if car is on this side
                    // then you cross and unload all cars, and then cross back
                    crosses++;
                    if (side == 1) {
                        side = 0;
                    } else {
                        side = 1;
                    }
                    // printf("cross because car doesn't fit!\n");

                    // while there is a car on the ferry
                    while(list_empty(ferry) == false) {
                        ITER car = list_begin(ferry);
                        // check if on the proper side
                        if (side == 1 && strcmp(iter_get_side(car, &status), "right") == 0) {
                            curr_length_storage -= iter_get_length(car, &status);
                            list_remove_head(ferry); // unload car
                        } else if (side == 0 && strcmp(iter_get_side(car, &status), "left") == 0) {
                            curr_length_storage -= iter_get_length(car, &status);
                            list_remove_head(ferry); // unload car
                        } else {
                            break;
                        }
                    }

                    // then cross back
                    crosses++;
                    if (side == 1) {
                        side = 0;
                    } else {
                        side = 1;
                    }
                    // printf("cross to go back and load the car.\n");

                    // then you queue the car
                    if ((strcmp(arrival, "left") == 0 && side == 1) || (strcmp(arrival, "right") == 0 && side == 0)) {
                        curr_length_storage += length_of_car;
                        list_insert_tail(ferry, length_of_car, arrival);
                    }
                } else { // this means that the car is on the other side
                    // so, cross and unload all cars
                    crosses++;
                    if (side == 1) {
                        side = 0;
                    } else {
                        side = 1;
                    }
                    // printf("cross because car is on the other side!\n");

                    // validate if car can be unloaded (correct side)
                    while(list_empty(ferry) == false) {
                        ITER car = list_begin(ferry);
                        // check if on the proper side
                        if (side == 1 && strcmp(iter_get_side(car, &status), "right") == 0) {
                            curr_length_storage -= iter_get_length(car, &status);
                            list_remove_head(ferry); // unload car
                        } else if (side == 0 && strcmp(iter_get_side(car, &status), "left") == 0) {
                            curr_length_storage -= iter_get_length(car, &status);
                            list_remove_head(ferry); // unload car
                        } else {
                            break;
                        }
                    }

                    // then queue the car
                    if ((strcmp(arrival, "left") == 0 && side == 1) || (strcmp(arrival, "right") == 0 && side == 0)) {
                        curr_length_storage += length_of_car;
                        list_insert_tail(ferry, length_of_car, arrival);
                    }
                }
            }
        }

        // check if car is the last car on the list
        // then you load it and unload it (so you cross)
        while(list_empty(ferry) == false) {
            ITER car = list_begin(ferry);
            // check if on the proper side
            if (side == 1 && strcmp(iter_get_side(car, &status), "right") == 0) { // yes proper side
                curr_length_storage -= iter_get_length(car, &status);
                list_remove_head(ferry); // unload car
            } else if (side == 0 && strcmp(iter_get_side(car, &status), "left") == 0) { // yes proper side
                curr_length_storage -= iter_get_length(car, &status);
                list_remove_head(ferry); // unload car
            } else if (side == 1 && strcmp(iter_get_side(car, &status), "left") == 0) { // must cross
                crosses++;
                if (side == 1) {
                    side = 0;
                } else {
                    side = 1;
                }
                // printf("cross because last car needs to be unloaded!\n");
                curr_length_storage -= iter_get_length(car, &status);
                list_remove_head(ferry); // unload car
            } else if (side == 0 && strcmp(iter_get_side(car, &status), "right") == 0) { // must cross
                crosses++;
                if (side == 1) {
                    side = 0;
                } else {
                    side = 1;
                }
                // printf("cross because last car needs to be unloaded!\n");
                curr_length_storage -= iter_get_length(car, &status);
                list_remove_head(ferry); // unload car
            }
        }

        printf("%d\n", crosses);
    }

}

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

Status list_insert_head(LIST hList, int lengthAttribute, char* sideAttribute) {
    List* pList = (List*)hList;
    Node* pNode = (Node*)malloc(sizeof(Node));
    if (pNode) {
        pNode->length = lengthAttribute;
        pNode->side = sideAttribute;
        pNode->next = pList->head;
        pList->head = pNode;
        if (pList->tail == NULL) {
            pList->tail = pNode;
        }
        return SUCCESS;
    }
    return FAILURE;
}

Status list_insert_tail(LIST hList, int lengthAttribute, char* sideAttribute) {
    List* pList = (List*)hList;
    Node* pNode = (Node*)malloc(sizeof(Node));
    if (pNode) {
        pNode->length = lengthAttribute;
        pNode->side = sideAttribute;
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

int iter_get_length(ITER hIter, Status* pStatus) {
    Node* pNode = (Node*)hIter;
    if (pNode) {
        if (pStatus) {
            *pStatus = SUCCESS;
        }
        // printf("LENGTH: %d\n", pNode->length);
        return pNode->length;
    } else {
        if (pStatus) {
            *pStatus = FAILURE;
        }
        return -1;
    }
}

char* iter_get_side(ITER hIter, Status* pStatus) {
    Node* pNode = (Node*)hIter;
    if (pNode) {
        if (pStatus) {
            *pStatus = SUCCESS;
        }
        return pNode->side;
    } else {
        if (pStatus) {
            *pStatus = FAILURE;
        }
        return NULL;
    }
}

Status iter_set(ITER hIter, int item) {
    Node* pNode = (Node*)hIter;
    if (pNode) {
        pNode->length = item;
        return SUCCESS;
    } else {
        return FAILURE;
    }
}