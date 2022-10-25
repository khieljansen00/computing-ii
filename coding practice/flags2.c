#include <stdio.h>

const int MAX_BIT_POSITION = 31;
const int MAX_BIT_VALUE = (1 << 31);

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[]) {
    unsigned int flag_holder[5] = { 0 }; //Set the first integer to zero and all others to zero by default.

    /*
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
    */

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

    /*
    // find length of array
    int lenofarray = 0;

    while (flag_holder[lenofarray]) {
        lenofarray++;
    }

    printf("len of array: %d\n", lenofarray);

    // variable for found index
    int index = 0;
    // variable for index searching in array
    int i = 0;
    // upper bound
    int lower;
    // lower bound
    int higher;
    // find proper index position
    lower = index;
    higher = lower + 31;
    while(i < lenofarray) {
        // printf("lower: %d\n", lower);
        // printf("higher %d\n", higher);
        if (flag_position > (lower - 1) && flag_position < (higher + 1)) {
            // printf("found index\n");
            index = i;
            break;
        } else {
            i += 1;
            lower = (31 * i + (1 * i));
            higher = lower + 31;
        }
    }
    */

    // printf("index: %d\n", index);

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

    //printf("position is %d\n", posit);
    //printf("count is %d\n", index);

    // set flag
    // index searching
    unsigned int x;
    unsigned int j;
    int iterator = 0;
    j = 1 << posit;
    for (x = 1 << MAX_BIT_POSITION; x > 0; x = x >> 1) {
        if (j & x) {
            flag_holder[index] |= j;
            // flag_holder[index] = ~flag_holder[index];
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

    // printf("position is %d\n", posit);
    // printf("count is %d\n", index);

    // set flag
    // index searching
    unsigned int x;
    unsigned int j;
    int iterator = 0;
    j = 1 << posit;
    for (x = 1 << MAX_BIT_POSITION; x > 0; x = x >> 1) {
        if (j & x) {
            flag_holder[index] &= ~j;
            // flag_holder[index] = ~flag_holder[index];
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

    /*
    for(i = MAX_BIT_POSITION; i>=0; i--)
    {
        printf("%d", check_flag(array, i));
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    */

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