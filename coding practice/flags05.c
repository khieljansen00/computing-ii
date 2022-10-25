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
    Date: September 17, 2022
    Effort: 3 hours
    Purpose: to learn how to set and check flags
***********************************************************/

#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);

int main(int argc, const char* argv[]) {

    unsigned int flag_holder = 0;
    int i;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);

    for(i=31; i>=0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if(i%4 == 0)
        {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}

void set_flag(unsigned int* flag_holder, int flag_position) {
    unsigned int i;
    unsigned int j;
    int iterator = 0;
    j = 1 << flag_position;
    for (i = 1 << 31; i > 0; i = i >> 1) {
        if (j & i) {
            *flag_holder |= j;
        }
        iterator++;
    }
}

int check_flag(unsigned int flag_holder, int flag_position) {
    int j = 1 << flag_position;
    if ((flag_holder & j) > 0) {
        return 1;
    } else if ((flag_holder & j) == 0) {
        return 0;
    } else {
        return 0;
    }
}