#include <stdio.h>
#include <stdbool.h>

#include "sorting.h"

struct steps {
    long long int numCompares;
    long long int numAssign;
};
typedef struct steps Steps;

Steps vanilla_bubble_sort(int numbers[], int size) {
    Steps steps = { 0, 0 };
    steps.numAssign++; // Initialize i
    for (int i = 0; i < size - 1; i++) {
        steps.numCompares++; // Loop comparison
        steps.numAssign++; // Initialize j
        for (int j = 0; j < size - 1; j++) {
            steps.numCompares++; // Loop comparison
            steps.numCompares++; // If
            if (numbers[j] > numbers[j + 1]) {
                swap_int(&numbers[j], &numbers[j + 1], &steps);
            }
            steps.numAssign++; // Loop j increment
        }
        steps.numCompares++; // Loop j last compare
        steps.numAssign++; // Loop i increment
    }
    steps.numCompares++; // Loop i last compare
    return steps;
}

Steps improved_bubble_sort(int numbers[], int size) {
    Steps steps = { 0, 0 };
    steps.numAssign++; // Initialize i
    for (int i = 0; i < size - 1; i++) {
        steps.numCompares++; // Loop comparison steps.numAssign++; // Initialize j
        for (int j = 0; j < size - 1 - i; j++) {
            steps.numCompares++; // Loop comparison
            steps.numCompares++; // If
            if (numbers[j] > numbers[j + 1]) {
                swap_int(&numbers[j], &numbers[j + 1], &steps);
            }
            steps.numAssign++; // Loop j increment
        }
        steps.numCompares++; // Loop j last compare
        steps.numAssign++; // Loop i increment
    }
    steps.numCompares++; // Loop i last compare
    return steps;
}

Steps final_bubble_sort(int numbers[], int size) {
    Steps steps = { 0, 0 };
    bool somethingSwapped = true;
    int i = 0;
    steps.numAssign++; // Init i
    while (somethingSwapped) {
        steps.numCompares++; // While comparison somethingSwapped = false;
        steps.numAssign++; // somethingSwappedAssignment steps.numAssign++; // Initizize j
        for (int j = 0; j < size - 1 - i; j++) {
            steps.numCompares++; // Loop comparison steps.numCompares++; // If
            if (numbers[j] > numbers[j + 1]) {
                swap_int(&numbers[j], &numbers[j + 1], &steps);
                somethingSwapped = true;
                steps.numAssign++; // somethingSwapped
            }
            steps.numAssign++; // Loop j increment
        }
        steps.numCompares++; // Loop j last compare
        i++;
        steps.numAssign++; // Loop i increment
    }
    steps.numCompares++; // while last compare
    return steps;
}

int find_index_of_min(int numbers[], int size, int startIndex, Steps* steps) {
    int bestIndex = startIndex; steps->numAssign++; // best index init steps->numAssign++; // init i
    for (int i = startIndex + 1; i < size; i++) {
        steps->numCompares++; // Loop compare
        steps->numAssign++; // If
        if (numbers[i] < numbers[bestIndex]) {
            bestIndex = i;
            steps->numAssign++; // best index
        }
        steps->numAssign++; // Loop increment
    }
    steps->numAssign++; // Last loop compare
    return bestIndex;
}

Steps selection_sort(int numbers[], int size) {
    Steps steps = { 0, 0 };
    steps.numAssign++; // Init i
    for (int i = 0; i < size - 1; i++) {
        steps.numCompares++; // for condition
        swap_int(
        &numbers[i],
        &numbers[find_index_of_min(numbers, size, i, &steps)], &steps);
        steps.numAssign++; // for loop increment
    }   
    steps.numCompares++; // Last loop compare
    return steps;
}

