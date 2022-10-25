#include <stdio.h>

void add(int array[], int value);

int main(int argc, char* argv[]) {
    int tel[5] = { 0 };

    add(tel, 5);

    int i = 0;
    while(tel[i]) {
        printf("%d ", tel[i]);
        i++;
    }

    return 0;
}

void add(int array[], int value) {
    array[1] += value;
    printf("in the function -> %d\n", array[1]);
}