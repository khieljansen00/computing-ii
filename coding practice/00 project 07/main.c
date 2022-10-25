#include <stdio.h>

#include "bit_flags.h"

int main(int argc, const char* argv[]) {

    BIT_FLAGS mybit = bit_flags_init_number_of_bits(98);

    bit_flags_set_flag(mybit, 10);

    printf("size of bit_flag object: %d\n", bit_flags_get_size(mybit));
    printf("capacity of bit_flag object: %d\n", bit_flags_get_capacity(mybit));

    bit_flags_set_flag(mybit, 132);

    printf("size of bit_flag object: %d\n", bit_flags_get_size(mybit));
    printf("capacity of bit_flag object: %d\n", bit_flags_get_capacity(mybit));

    bit_flags_set_flag(mybit, 67);

    bit_flags_destroy(&mybit);
}