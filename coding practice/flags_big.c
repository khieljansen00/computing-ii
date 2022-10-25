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
    Date: September 27th, 2022
    Effort: about 2 to 3 hours
    Purpose: to understand how arrays work, setting and unsetting flags,
        clearing flags, and displaying an array of integer bits.
***********************************************************/

#include <stdio.h>

const int MAX_BIT_POSITION = 31;

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[]) {
    unsigned int flag_holder[5] = { 0 };

    set_flag(flag_holder, 0);
    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    
    display_flags(flag_holder, 5);
    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);

    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position) {
    if (flag_position < 0) return;

    int posit = flag_position;
    int temp;
    int index = 0;
    while (posit >= 0) {
        temp = posit;
        temp = temp - 31;
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
    for (x = 1 << MAX_BIT_POSITION; x > 0; x = x >> 1) {
        if (j & x) {
            flag_holder[index] |= j;
        }
        iterator++;
    }
}


void unset_flag(unsigned int flag_holder[], int flag_position) {
    if (flag_position < 0) return;

    int posit = flag_position;
    int temp;
    int index = 0;
    while (posit > 0) {
        temp = posit;
        temp = temp - 31;
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
    for (x = 1 << MAX_BIT_POSITION; x > 0; x = x >> 1) {
        if (j & x) {
            flag_holder[index] &= ~j;
        }
        iterator++;
    }
}

int check_flag(unsigned int flag_holder[], int flag_position) {
    // if (flag_position < 0) exit(-1);

    int j = 1 << flag_position;
    if ((flag_holder[0] & j) > 0) {
        return 1;
    } else {
        return 0;
    }
}

void display_32_flags_as_array(unsigned int flag_holder) {
    int i;
    unsigned int array[1] = { flag_holder };

    for(i = 0; i <= MAX_BIT_POSITION; i++) {
        printf("%d", check_flag(array, i));
        if((i+1)%4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void display_flags(unsigned int flag_holder[], int size) {
    for (int i = 0; i < size; i++) {
        display_32_flags_as_array(flag_holder[i]);
    }
}