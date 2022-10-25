#include <stdio.h>

#include "deque.h"

int main(int argc, const char* argv[]) {
    DEQUE mydeq = deque_init_default();

    /*for (int i = 0; i < deque_size(mydeq); i++) {
        printf("%i ; %d\n", )
    }*/

    printf(mydeq);

    deque_destroy(mydeq);
    return 0;
}