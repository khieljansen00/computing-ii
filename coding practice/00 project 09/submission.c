#include <stdio.h>

struct stack {
    int size;
    int capacity;
    char* data;
};
typedef struct stack Stack;

Stack stack_init_default(void);
void stack_destroy(Stack* phStack);

Status stack_push(Stack hStack, char value);
Status stack_pop(Stack hStack);
char stack_top(Stack hStack, Status* pStatus);
int stack_size(Stack hStack);
bool stack_empty(Stack hStack);

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

Stack stack_init_default(void)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack != NULL) {
        pStack->capacity = 8;
        pStack->size = 0;
        pStack->data = (char*)malloc(sizeof(char) * pStack->capacity);
        if (pStack->data == NULL) {
            free(pStack);
            return NULL;
        }
    }
    return pStack;
}

void stack_destroy(Stack* phStack)
{
    Stack* pStack = (Stack*)*phStack;
    free(pStack->data);
    free(pStack);
    *phStack = NULL;
}

void stack_push(Stack hStack, char value)
{
    if (hStack->size >= hStack->capacity) {
        char* temp = (char*)malloc(sizeof(char) * pStack->capacity * 2);
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pStack->size; i++) {
            temp[i] = pStack->data[i];
        }
        free(pStack->data);
        pStack->data = temp;
        pStack->capacity *= 2;
    }
    pStack->data[pStack->size] = value;
    pStack->size++;
}

void stack_pop(Stack* hStack)
{

    if (stack_empty(hStack)) {
        printf("stack is empty\n");
    } else {
        hStack->size--;
    }
}

char stack_top(Stack hStack)
{
    if (stack_empty(hStack)) {
        return '?';
    }
    return hStack.data[hStack.size - 1];
}

int stack_size(Stack hStack)
{
    return hStack.size;
}

bool stack_empty(Stack hStack)
{
    return hStack.size <= 0;
}