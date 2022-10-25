#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int (*arr)[30] = malloc(sizeof(int[20][30]));

    printf("%d", arr);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            arr[i][j] = i + j;
        }
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    /*
    int *x = (int*) malloc(sizeof(int));

    x = 100;
    printf("%d", x);
    */

    return 0;
}