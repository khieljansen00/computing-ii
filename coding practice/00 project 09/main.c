#include <stdio.h>

#include "stack.h"

int main(int argc, const char* argv[]) {
    STACK myStack = stack_init_default();
    Status status;

    char chr;

    while(!feof(stdin)) {
        chr = fgetc(stdin);
        if (chr == '[' || chr == '(' || chr == '{') {
            stack_push(myStack, chr);
        } else if (chr == ']' || chr == ')' || chr == '}') {
            // check if stack is empty
            // if so, there is no character to match this one
            if (stack_empty(myStack)) {
                printf("No");
                return 0;
            }
            // check if the characters match
            char check = stack_top(myStack, &status);
            if (status == SUCCESS) {
                if (check == '[' && chr == ']') {
                    stack_pop(myStack);
                } else if (check == '(' && chr == ')') {
                    stack_pop(myStack);
                } else if (check == '{' && chr == '}') {
                    stack_pop(myStack);
                } else {
                    printf("No");
                    return 0;
                }
            }
        } else {
            // not an acceptable char or newline
            break;
        }
    }

    // if the stack is not empty, then that means there were no characters to match the remaining characters in the stack
    if (stack_empty(myStack) == false) {
        printf("No");
        return 0;
    }

    printf("Yes");

    return 0;
}