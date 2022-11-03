#include <stdio.h>
#include <ctype.h>

#include "my_string.h"
#include "sort.h"

int main(int argc, const char* argv[]) {
    MY_STRING string01 = my_string_init_c_string("whenever");
    MY_STRING string02 = my_string_init_c_string("applA");
    MY_STRING string03 = my_string_init_c_string("the");
    MY_STRING string04 = my_string_init_c_string("Ingloo");
    MY_STRING string05 = my_string_init_c_string("elephansze");
    MY_STRING string06 = my_string_init_c_string("inimic");
    MY_STRING string07 = my_string_init_c_string("ratonsphonsz");

    int size = 7;
    
    MY_STRING array[] = { string01, string02, string03, string04, string05, string06, string07 };

    bool isSorted = is_sorted(array, size, order_str_ignore_case);

    if (isSorted == true) printf("array is sorted.\n");
    else printf("array is not sorted.\n");

    for (int i = 0; i < size; i++) {
        my_string_insertion(array[i], stdout);
        printf("\n");
    }

    printf("\nsort!\n\n");
    sort(array, size, order_str_ignore_case);

    isSorted = is_sorted(array, size, order_str_ignore_case);

    if (isSorted == true) printf("array is sorted.\n");
    else printf("array is not sorted.\n");

    for (int i = 0; i < size; i++) {
        my_string_insertion(array[i], stdout);
        printf("\n");
    }

    return 0;
}