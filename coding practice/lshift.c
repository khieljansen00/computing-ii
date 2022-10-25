/***********************************************************
    Computing II -- COMP.1020 Honor Statement
    The practice of good ethical behavior is essential for maintaining good
    order in the classroom, providing an enriching learning experience for
    students, and as training as a practicing computing professional upon
    graduation. This practice is manifested in the University's Academic
    Integrity policy. Students are expected to strictly avoid academic
    dishonesty and adhere to the Academic Integrity policy as outlined in
    the course catalog. Violations will be dealt with as outlined therein.
    All programming assignments in this class are to be done by the student
    alone. No outside help is permitted except the instructor and approved
    tutors.
    I certify that the work submitted with this assignment is mine and was
    generated in a manner consistent with this document, the course academic
    policy on the course website on Blackboard, and the UMass Lowell
    academic code.
    Author: Khiel Mantilla
    Date: September 10, 2022
    Effort: half an hour.
    Purpose: to understand and use bit-shift operators.
***********************************************************/

#include <stdio.h>

int main(int argc, const char* argv[]) {
    unsigned int x = 1;

    for (int i = 0; x != 0; i++) {
        printf("%d: %u\n", i, x);
        x = x<<1;
    }

    return 0;
}