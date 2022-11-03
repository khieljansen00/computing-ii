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
    Date: Oct 26 2022
    Effort: 45 minutes
    Purpose: learning how to sort properly, and using function pointers as parameters
***********************************************************/

#include <stdio.h>

#include "sort.h"

bool is_sorted(MY_STRING* array, int size, CompareFP compare) {
    for (int i = 0; i < size - 1; i++) {
        if (compare(array[i], array[i+1]) > 0) {
            return false;
        }
    }

    return true;
}

void sort(MY_STRING* array, int size, CompareFP compare) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && compare(array[j - 1], array[j]) > 0) {
            MY_STRING temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
    }
}