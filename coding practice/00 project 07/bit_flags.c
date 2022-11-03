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
    Date: October 6th, 2022
    Effort: 3 hours or so
    Purpose: understanding how to configure the data structure
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bit_flags.h"

const int bit_size_index = 31;
const int bit_size = 32;

// comments
// it is a strange data struct
// i propose a function in which you can change the number of bits the data struct held and can hold.
// the relationship between flag_position and bits is a bit strange.
struct bit_flags {
    int size;
    int capacity;
    unsigned int* data;
};
typedef struct bit_flags Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits) {
    if (number_of_bits < 0) return NULL;
    Bit_flags* pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
    if (pBit_flags != NULL) {
        pBit_flags->size = number_of_bits;
        // just need to figure out the length of array AND round up
        // pBit_flags->flag_holder = (unsigned int*)malloc(sizeof());

        // wait...
        // would number_of_bits be like 32 or 64 or 96?
        int l = 0;
        int lower = 0;
        int higher = bit_size_index;
        while (!(number_of_bits > (lower-1) && number_of_bits < (higher+1))) {
            if (number_of_bits > (lower-1) && number_of_bits < (higher+1)) break;
            lower += bit_size_index;
            lower += 1;
            higher = lower + bit_size_index;
            l++;
        }

        // add one because capacity is a representation
        // 32 capacity is from 0 to 31
        // 64 capacity is from 0 to 63
        pBit_flags->capacity = higher + 1;
        pBit_flags->data = (unsigned int*)malloc(sizeof(unsigned int) * (l + 1));

        return pBit_flags;
        
        // fix this (j << 31) won't work because variable can't hold
        // remember that number of bits can be bigger than 32 or 64
        // wait capacity and size will initially be the same
        /*
        int j = 1;
        while (number_of_bits > j) {
            j = j << 31;
        }
        pBit_flags->capacity = j;
        */

        /*
        unsigned int bits = (unsigned int)number_of_bits;
        // unsigned int remainder;

        int posit = 31;

        // number of bits can be bigger than 32 or 64
        while (bits >= 0) {
            for (int i = 1 << 31; i > 0; i = i >> 1) {
                if (bits >= i) {
                    Status ok = bit_flags_set_flag(pBit_flags, posit);
                    if (ok == FAILURE) return NULL;
                    bits &= ~i;
                    break;
                }
                posit--;
            }
            posit = 31;
        }
        */
    }

    return NULL;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position) {
    if (flag_position < 0) return FAILURE;
    if (hBit_flags) {
        Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
        if (pBit_flags) {
            // resize
            if ((flag_position + 1) > pBit_flags->size) {
                if (flag_position > pBit_flags->capacity) {
                    // variables for resize
                    // i is capacity of array
                    int i = (pBit_flags->capacity)/bit_size;
                    // minus one because flag_position starts at 0
                    int rest = flag_position - (bit_size*i) - 1;

                    int posit = rest;
                    // index is how much to add to resize
                    int temp;
                    int index = 0;

                    while(posit >= 0) {
                        temp = posit;
                        temp = temp - bit_size_index;
                        temp = temp - 1;
                        if (temp < 0) break;
                        else {
                            posit = temp;
                            index++;
                        }
                    }
                    pBit_flags->size = flag_position + 1;
                    pBit_flags->capacity = (i * 32) + (index + 1) * bit_size;
                    free(pBit_flags->data);
                    // add one because index 0 means to add 1 index to the array
                    pBit_flags->data = (unsigned int*)malloc(sizeof(int) * (i + index + 1));
                }
            }

            int posit = flag_position;
            int temp;
            int index = 0;
            while (posit >= 0) {
                temp = posit;
                temp = temp - bit_size_index;
                temp = temp - 1;
                if (temp < 0) break;
                else {
                    posit = temp;
                    index++;
                }
            }

            // set flag
            // index searching
            unsigned int x;
            unsigned int j;
            int iterator = 0;
            j = 1 << posit;
            for (x = 1 << bit_size_index; x > 0; x = x >> 1) {
                if (j & x) {
                    pBit_flags->data[index] |= j;
                }
                iterator++;
            }

            return SUCCESS;
        }
    }

    return FAILURE;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position) {
    if (flag_position < 0) return FAILURE;
    if (hBit_flags) {
        Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
        if (pBit_flags) {
            // resize
            // variables for resize
            // i is capacity of array
            // index is how much to add to resize
            int i;
            int index;
            if ((flag_position + 1) > pBit_flags->size) {
                if (flag_position > pBit_flags->capacity) {
                    i = (pBit_flags->capacity)/bit_size;
                    // minus one because flag_position starts at 0
                    int rest = flag_position - (bit_size*i) - 1;
                    int posit = rest;
                    int temp;
                    int index = 0;
                    while(posit >= 0) {
                        temp = posit;
                        temp = temp - 31;
                        temp = temp - 1;
                        if (temp < 0) break;
                        else {
                            posit = temp;
                            index++;
                        }
                    }
                    pBit_flags->size = flag_position + 1;
                    pBit_flags->capacity = (i * bit_size) + (index + 1) * bit_size;
                    free(pBit_flags->data);
                    // add one because index 0 means to add 1 index to the array
                    pBit_flags->data = (unsigned int*)malloc(sizeof(int) * (i + index + 1));
                }
            }

            int posit = flag_position;
            int temp;
            index = 0;
            while (posit >= 0) {
                temp = posit;
                temp = temp - bit_size_index;
                temp = temp - 1;
                if (temp < 0) break;
                else {
                    posit = temp;
                    index++;
                }
            }

            // set flag
            // index searching
            unsigned int x;
            unsigned int j;
            int iterator = 0;
            j = 1 << posit;
            for (x = 1 << bit_size_index; x > 0; x = x >> 1) {
                if (j & x) {
                    pBit_flags->data[index] &= ~j;
                }
                iterator++;
            }

            return SUCCESS;
        }
    }

    return FAILURE;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position) {
    if (flag_position < 0) return -1;
    if (hBit_flags) {
        Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
        if (pBit_flags) {
            if (flag_position > pBit_flags->size) return -1;
            int posit = flag_position;
            // index
            int i = 0;
            int temp;

            while (posit >= 0) {
                temp = posit - bit_size_index;
                temp = temp - 1;
                if (temp <= bit_size_index) break;
                else {
                    posit = temp;
                    i++;
                }
            }

            int singular_flag_position = temp;

            int j = 1 << singular_flag_position;
            if ((pBit_flags->data[i] & j) > 0) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return -1;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags) {
    if (hBit_flags) {
        Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
        if (pBit_flags) {
            return pBit_flags->size;
        }
    }
    return -1;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags) {
    if (hBit_flags) {
        Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
        if (pBit_flags) {
            return pBit_flags->capacity;
        }
    }
    return -1;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags) {
    if (phBit_flags) {
        Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
        if (pBit_flags) {
            free(pBit_flags->data);
            free(pBit_flags);
            *phBit_flags = NULL;
            // printf("destroyed!\n");
        }
    }
}