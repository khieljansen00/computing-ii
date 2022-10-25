#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    /*
    char string[50] = "elephant";
    strcat(string, " is fat.");

    char ok[] = "elephant";
    char aight[] = "elephant";

    printf("%s\n", string);

    printf("equality: %d\n", strcmp(string, ok));
    printf("equality: %d\n", strcmp(ok, aight));
    printf("equality: %d\n", strcmp(ok, '\t'));
    */

   char str1[] = "apple";
   char str2[] = {'a', 'p', 'p', 'l', 'e', '\0'};
   char str3[] = {'a', 'p', 'p', 'l', 'e'};
   char str4[5] = {'a', 'p', 'p', 'l', 'e'};
   char str5[5] = {'a', 'p', 'p', 'l', 'e', '\0'};

   printf("str1 ; %s\nlen: %d\n", str1, strlen(str1));
   printf("str2 ; %s\nlen: %d\n", str2, strlen(str2));
   printf("str3 ; %s\nlen: %d\n", str3, strlen(str3));
   printf("str4 ; %s\nlen: %d\n", str4, strlen(str4));
   printf("str5 ; %s\nlen: %d\n", str5, strlen(str5));
}