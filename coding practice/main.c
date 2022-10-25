#include <stdio.h>

char *reverse(char *string);

int main(int argc, const char* argv[]) {

    /*
    char name[] = "hello world!";
    int len = 0;

    while (name[len] != '\0') {
        len++;
    }

    int j = len - 1;

    for (int i = 0; i < len - 1; i++) {
        if (i >= j) {
            break;
        }
        char letter1 = name[i];
        char letter2 = name[j];
        printf("%c %c\n", letter1, letter2);
        name[i] = letter2;
        name[j] = letter1;
        j--;
    }

    printf("%s\n", name);
    */

    char name[] = "and";

    /*
    printf("name:     %s\n", name);
    printf("*name:    %p\n", *name);
    printf("&name:    %p\n", &name);
    printf("&name[0]: %p\n", &name[0]);
    printf("&name[1]: %p\n", &name[1]);
    reverse(name);
    */

    printf("%s\n", name);
    reverse(name);
    printf("%s\n", name);
    printf("%s\n", reverse(name));
    printf("%s\n", name);

}

char *reverse(char *string) {

    int len = 0;

    while (string[len] != '\0') {
        len++;
    }

    // printf("string ; %s\n", string);
    // printf("len ; %d\n", len);

    int j = len - 1;

    for (int i = 0; i < len - 1; i++) {
        if (i >= j) {
            break;
        }
        char letter1 = string[i];
        char letter2 = string[j];
        // printf("chars %c %c\n", letter1, letter2);
        string[i] = letter2;
        string[j] = letter1;
        // printf("%c\n", string[i]);
        j--;
    }

    return string;
}