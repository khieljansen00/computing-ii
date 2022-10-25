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
    Author: Khiel Jansen Mantilla
    Date: September 6, 2022
    Effort: Two hours
    Purpose: To understand how functions work, how char arrays are, and how to use a
    loop to modify a string.
***********************************************************/

#include <stdio.h>

char* reverse(char* string) {

    int len = 0;

    while (string[len] != '\0') {
        len++;
    }

    int j = len - 1;

    for (int i = 0; i < len - 1; i++) {
        if (i >= j) {
            break;
        }
        char letter1 = string[i];
        char letter2 = string[j];
        string[i] = letter2;
        string[j] = letter1;

        j--;
    }

    return string;
}