#include <stdio.h>
#include <stdlib.h>

#include "rational.h"

int main(int argc, const char* argv[]) {
    RATIONAL myRational = NULL;

    myRational = rational_init(3, 7);

    printf("numerator is %d\n", rational_get_numerator(myRational));

    rational_destroy(&myRational);

    return 0;
}